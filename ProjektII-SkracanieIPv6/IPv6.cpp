#include "IPv6.hpp"

#include <regex>
#include <format>

using namespace std;

inline bool IPv6::validate(string address)
{
	return checkCharacters(address) && checkPattern(address);
}

IPv6::IPv6(string address)
{
	if(!store(address))
    	throw invalid_argument("Invalid address");
}

string IPv6::shortened()
{
    // find the longest sequence of zeros
    int longest = 0;
    int current = 0;
    int position = 0;
    for (int i = 0; i < 8; i++)
    {
        if (convertedAddress[i] == 0)
        {
			current++;
            if (current > longest)
            {
				longest = current;
				position = i - longest + 1;
			}
		}
		else
			current = 0;
	}
    // if the longest sequence is only one zero, return the address
	if (longest == 0)
		return output();
    else if(longest == 8)
		return "::";
	// if the longest sequence is more than one zero, return the shortened address
    else
    {
		string output;
        for (int i = 0; i < 8; i++)
        {
			if (i == position)
				output += ":";
            if (i < position || i >= position + longest)
            {
				output += format("{:x}", convertedAddress[i]);
				if (i < 7 && (i < position || i >= position + longest - 1))
					output += ":";
			}
		}
		return output;
	}
}

string IPv6::extended()
{
    string output;
    for (int i = 0; i < 8; i++)
    {
        output += format("{:04x}", convertedAddress[i]);
        if (i < 7)
            output += ":";
    }
    return output;
}

bool IPv6::store(string address)
{
    if (validate(address))
    {
        removeDoubleColon(address);
        stringToStruct(address);
        return true;
        regex pattern("::");
        smatch match;
        regex_search(address, match, pattern);
        int position = match.position();
	}
    return false;
}

inline bool IPv6::checkCharacters(string address)
{
    return regex_match(address, regex("^[0-9a-fA-F:]+$"));
}

bool IPv6::checkPattern(string address)
{
    // if there is triple colon, return
    if (address.size() > 2 && address.find(":::") != string::npos)
        return false;

    // count "::" number occurences using regex_iterator
    regex patternDouble("::");
        
    int countDouble = distance(sregex_iterator(address.begin(), address.end(), patternDouble), sregex_iterator());
    if (countDouble > 1)
		return false;
    else if (countDouble == 1)
        removeDoubleColon(address);
    return std::regex_match(address, regex("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$"));
    /*else
    {
        if(!regex_match(address, regex("^([0-9a-fA-F]{1,4}:){0,6}::([0-9a-fA-F]{1,4}:){0,6}[0-9a-fA-F]{1,4}$")))
           return false;
        //count ":"
        regex patternSingle(":");
        int countSingle = distance(sregex_iterator(address.begin(), address.end(), patternSingle), sregex_iterator());
        return countSingle <= 7;
    }*/
}

void IPv6::removeLeadingZeros(string& address)
{
	// if there is a zero at the beginning of a block, remove it
	regex pattern("(:|^)0{1,3}");
	address = regex_replace(address, pattern, "$1");
	// if there is a zero at the end of a block, remove it
	regex pattern2("0{1,3}(:|$)");
	address = regex_replace(address, pattern2, "$1");
	// if there is a zero at the beginning of the address, remove it
	regex pattern3("^0{1,3}");
	address = regex_replace(address, pattern3, "");
	// if there is a zero at the end of the address, remove it
	regex pattern4("0{1,3}$");
	address = regex_replace(address, pattern4, "");
}

void IPv6::removeDoubleColon(string& address)
{
    // check position of a double colon
    regex pattern("::");
    smatch match;
    regex_search(address, match, pattern);
    int position = match.position();
    // if there is no double colon, return
    if (position == string::npos)
        return;
    else if (position == 0 && address.length() == 2)
    {
        address = "0:0:0:0:0:0:0:0";
        return;
    }

    regex patternSingle(":");
    int countSingle = distance(sregex_iterator(address.begin(), address.end(), patternSingle), sregex_iterator()) - 1;

    string replacement;
    if(countSingle == 7)
        if(position == 0)
			replacement = "0:";
		else if(position == address.length() - 2)
            replacement = ":0";
		else
		    replacement = ":0:";
    else if (position == 0)
        for(; countSingle < 8; countSingle++)
            replacement = "0:" + replacement;
	else if (position == address.length() - 2)
        for (; countSingle < 8; countSingle++)
            replacement = ":0" + replacement;
    else
    {
        replacement = ":";
        countSingle++;
        for (; countSingle < 8; countSingle++)
            replacement += "0:";
		address = regex_replace(address, pattern, replacement);
	}

    //replace double colon
    address = regex_replace(address, pattern, replacement);
}


void IPv6::stringToStruct(string address)
{
    size_t pos = 0;
    int i = 0;
    while ((pos = address.find(":")) != string::npos) {
        string block = address.substr(0, pos);
        //block to int
        convertedAddress[i] = stoi(block, nullptr, 16);
        address.erase(0, pos + 1);
        i++;
    }
    convertedAddress[i] = stoi(address, nullptr, 16);
}

string IPv6::output()
{
	string output;
    for (int i = 0; i < 8; i++)
    {
		output += format("{:x}", convertedAddress[i]);
		if (i < 7)
			output += ":";
	}
	return output;
}