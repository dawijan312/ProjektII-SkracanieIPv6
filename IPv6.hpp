#pragma once

#include <string>
#include <array>

class IPv6
{
	struct IPv6address
	{
		uint16_t block[8];
	};

	static bool validate(std::string address);
	std::string shortened();
	std::string extended();
	bool store(std::string address);
};