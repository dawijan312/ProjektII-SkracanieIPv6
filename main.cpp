// Projekt II - Skracanie adresów IPv6
// Autorzy: Dawid Janduda, Marek Paluch

/*
* Zadanie 7:
* TRUDNE: Program konsolowy do generowania najkrótszej formy adresu IPv6 na podstawie
* podanego adresu, który też może być w formie skróconej.
* Przykład: program 2a01::78b4:0:0:0:1
* Wynik: 2a01:0:0:78b4::1
* komentarz do przykładu: adres w przykładzie to 2a01:0000:0000:78b4:0000:0000:0000:0001,
* poprawne skrócenie adresu do usunięcie drugiego ciągu zer, nie pierwszego.
*/

#include <iostream>
#include <windows.h>

#include "functions.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(65001);
	system("title IPv6 address shortener");

	if (argc == 1)
	{
		menu();
	}
	else if (argc == 2) 
	{
		cout << helpMessage();
		system("pause");
	}
	else if (argc == 3) 
	{
		inputMode(string(argv[1]), string(argv[2]));
	}
	else
	{
		cout << "To many arguments" << endl;
		system("pause");
	}

	return 0;
}