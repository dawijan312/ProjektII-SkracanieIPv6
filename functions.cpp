#include "functions.hpp"

using namespace std;

string helpMessage()
{
	string message = "Program do skracania adresow IPv6\n";
	message += "Autorzy: Dawid Janduda, Marek Paluch\n";
	message += "U�ycie: program [opcje] [adres]\n";
	message += "Opcje:\n";
	message += "-h, --help - wy�wietla pomoc\n";
	message += "-s, --shorten - skracanie adresu\n";
	message += "-e, --extend - rozszerzanie adresu\n";
	message += "-c, --check - sprawdzanie poprawno�ci adresu\n";
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
		cout << "Sprawdzanie poprawno�ci adresu" << endl;
	}
	else if (switcher == "-h" || switcher == "--help")
	{
		cout << helpMessage();
	}
	else
	{
		cout << "Nieznany prze��cznik" << endl;
	}
}

void menu()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "Program do skracania adres�w IPv6" << endl;
		cout << "Menu:" << endl;
		cout << "1. Skracanie adresu" << endl;
		cout << "2. Rozszerzanie adresu" << endl;
		cout << "3. Sprawdzanie poprawno�ci adresu" << endl;
		cout << "0. Wyj�cie" << endl;
		cout << "Wybierz opcj�: ";
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
				cout << "Sprawdzanie poprawno�ci adresu" << endl;
				break;
			case '0':
				cout << "Wyj�cie" << endl;
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