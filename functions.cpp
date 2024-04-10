#include "functions.hpp"

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
		cout << "0. Exit" << endl;
		cout << "Choose an option: ";
		{
			int option;
			option = _getch();
			switch (option)
			{
			case '1':
				cout << "Shortening address" << endl;
				break;
			case '2':
				cout << "Extending address" << endl;
				break;
			case '3':
				cout << "Checking address validity" << endl;
				break;
			case '0':
				cout << "Exit" << endl;
				exit = true;
				break;
			default:
				cout << "Unknown option" << endl;
				break;
			}

			Sleep(2000);
		}
	}
}