#pragma once

#include <string>


class IPv6
{
	public:
		//IPv6() {};
		IPv6(std::string address);
		static bool validate(std::string address);
		std::string shortened();
		std::string extended();
		bool store(std::string address);
		std::string output();
	private:
		std::string inputAddress;
		uint16_t convertedAddress[8] = {};
		static bool checkCharacters(std::string address);
		static bool checkPattern(std::string address);
		void removeLeadingZeros(std::string& address);
		static void removeDoubleColon(std::string& address);
		void stringToStruct(std::string address);
};