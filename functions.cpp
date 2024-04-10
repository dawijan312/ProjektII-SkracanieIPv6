#include "functions.hpp"

using namespace std;

string helpMessage()
{
	string message = "Program do skracania adresow IPv6\n";
	message += "Autorzy: Dawid Janduda, Marek Paluch\n";
	message += "U¿ycie: program [opcje] [adres]\n";
	message += "Opcje:\n";
	message += "-h, --help - wyœwietla pomoc\n";
	message += "-s, --shorten - skracanie adresu\n";
	message += "-e, --extend - rozszerzanie adresu\n";
	message += "-c, --check - sprawdzanie poprawnoœci adresu\n";
	return message;
}

void inputMode(string switcher, string address)
{
	if (switcher == "-s" || switcher == "--shorten")
	{
		cout << "Skracanie adresu" << endl;
	}
	else if (switcher == "-e" || switcher == "--extend")
	{
		cout << "Rozszerzanie adresu" << endl;
	}
	else if (switcher == "-c" || switcher == "--check")
	{
		cout << "Sprawdzanie poprawnoœci adresu" << endl;
	}
	else if (switcher == "-h" || switcher == "--help")
	{
		cout << helpMessage();
	}
	else
	{
		cout << "Nieznany prze³¹cznik" << endl;
	}
}

void menu()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "Program do skracania adresów IPv6" << endl;
		cout << "Menu:" << endl;
		cout << "1. Skracanie adresu" << endl;
		cout << "2. Rozszerzanie adresu" << endl;
		cout << "3. Sprawdzanie poprawnoœci adresu" << endl;
		cout << "0. Wyjœcie" << endl;
		cout << "Wybierz opcjê: ";
		{
			int option;
			option = _getch();
			switch (option)
			{
			case '1':
				cout << "Skracanie adresu" << endl;
				break;
			case '2':
				cout << "Rozszerzanie adresu" << endl;
				break;
			case '3':
				cout << "Sprawdzanie poprawnoœci adresu" << endl;
				break;
			case '0':
				cout << "Wyjœcie" << endl;
				exit = true;
				break;
			default:
				cout << "Nieznana opcja" << endl;
				break;
			}

			Sleep(2000);
		}
	}
}