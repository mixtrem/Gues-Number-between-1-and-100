#include <iostream> 

//Gegebene Globale Variablen 
unsigned int upperLimit;
unsigned int lowerLimit;

//Die folgenden drei Funktion müsst ihr selbst Schreiben 😉
void startGame(unsigned int lowerLimit, unsigned int upperLimit)
{
	::lowerLimit = lowerLimit;
	::upperLimit = upperLimit;
}

int getCurrentGuess()
{
	int z=0;
	if (upperLimit - lowerLimit == 0)
	{
		z = (lowerLimit - 2 * upperLimit);
	}
	else 
		z = (lowerLimit + upperLimit)/2;
	return z;
}

void answer(bool answer)
{
	
	switch (answer)
	{
	case true: 
		upperLimit = (lowerLimit + upperLimit) / 2; break;
	case false: 
		lowerLimit = (lowerLimit + upperLimit )/ 2 + 1; break;
		break;
	} 
}

int main()
{
	std::cout << "Hausaufgabe Nr.1 \n\n";
	startGame(1, 100); //Starte das Spiel, es wird eine Zahl zwischen 1 und 100 gesucht 
	while (true)
	{
		int guess = getCurrentGuess();//Nach welcher Zahl soll gefragt werden? 
		if (guess > 0)//Wenn eine positive Zahl zurückgegeben wird, frage nach der Zahl
		{
			std::cout << "Is your number smaller or equal to " << guess << "? y/n\n";
		}
		else if (guess < 0)//Wenn eine negative Zahl zurückgegeben wird
		{
			std::cout << "Your number is " << -1 * guess << "!\n";
			break;
		}
		char input;
		do
		{
			input = std::cin.get(); //Erhalte die Antwort des Benutzers 
			if (input == 'y') // Wenn der Benutzer antwortet, dass seine Zahl kleiner oder gleich der gefragten Zahl ist, rufe die answer Funktion mit true auf
			{
				answer(true);
			}
			else if (input == 'n') //Wenn der Benutzer antwortet, dass seine Zahl größer als die gefragte Zahl ist, rufe die answer Funktion mit false auf.
			{
				answer(false);
			}
			std::cin.ignore(1000, '\n'); //Fehleingaben abfangen (müsst ihr noch nicht verstehen)
		} while (input != 'n' && input != 'y');
	}
	system("pause");
	return 0;
}
