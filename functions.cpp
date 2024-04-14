#include "functions.hpp"
#include "IPv6.hpp"

using namespace std;

string helpMessage()
{
	string message = "IPv6 Address Shortening Program\n";
	message += "Authors: Dawid Janduda, Marek Paluch\n";
	message += "Usage: program [options] [address]\n";
	message += "Options:\n";
	message += "-h, --help - display help\n";
	message += "-s, --shorten - shorten address\n";
	message += "-e, --extend - extend address\n";
	message += "-c, --check - check address validity\n";
	return message;
}

void inputMode(string switcher, string address)
{
	if (switcher == "-s" || switcher == "--shorten")
	{
		cout << "Shortening address" << endl;
	}
	else if (switcher == "-e" || switcher == "--extend")
	{
		cout << "Extending address" << endl;
	}
	else if (switcher == "-c" || switcher == "--check")
	{
		cout << "Checking address validity" << endl;
	}
	else if (switcher == "-h" || switcher == "--help")
	{
		cout << helpMessage();
	}
	else
	{
		cout << "Unknown switch" << endl;
	}
}

string getAddr()
{
    string address;
    cout << "Enter IPv6 address: ";
    //cin.ignore(256, '\n');
    getline(cin, address);
    return address;
}

void menu()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "IPv6 Address Shortening Program" << endl;
		cout << "Menu:" << endl;
		cout << "1. Shorten address" << endl;
		cout << "2. Extend address" << endl;
		cout << "3. Check address validity" << endl;
		cout << "4. output" << endl;
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "Choose an option: ";
		{
            int option;
            option = _getch();
            if (option == '1')
            {
                cout << "Shortening address" << endl;
            }
            else if (option == '2')
            {
                cout << "Extending address" << endl;
				IPv6 ipv6(getAddr());
				cout << "Output: " << ipv6.extended() << endl;
            }
            else if (option == '3')
            {
                cout << "Checking address validity" << endl;
                if (IPv6::validate(getAddr()))
                    cout << "Address is valid" << endl;
                else
                    cout << "Address is invalid" << endl;
            }
            else if (option == '4')
            {
                cout << "Output" << endl;
                string address = getAddr();
                IPv6 ipv6(address);
                cout << "Output: " << ipv6.output() << endl;
            }
            else if (option == '0')
            {
                cout << "Exit" << endl;
                exit = true;
            }
            else
            {
                cout << "Unknown option" << endl;
            }

			Sleep(3000);
		}
	}
}