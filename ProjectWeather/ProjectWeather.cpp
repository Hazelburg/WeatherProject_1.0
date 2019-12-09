#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//STRUCT - fom h�ller medlemmarna i den array som resultaten sparas i.
struct result
{
	string date;
	float fallDate;
	float tempAverageIn;
	float tempAverageOut;
	int humAverageIn;
	int humAverageOut;
	int moldIndexIn;
	int moldIndexOut;
	result() :date(""), fallDate(0), tempAverageIn(0), tempAverageOut(0), humAverageIn(0), humAverageOut(0), moldIndexIn(0), moldIndexOut(0) {}
};

//GLOBAL CONST - f�r ber�kning av kurvans lutning (m�gelindex, Y=kx + m)
float xLineOne = 0;
float yLineOne = 100;
float xLineTwo = 15;
float yLineTwo = 78;
float k = (yLineTwo - yLineOne) / (xLineTwo - xLineOne);
float m = 100;

//SWAP - swapfunktion som till�ter att arrayen "swappar"-element vid bubblesort
void swap(result* xp, result* yp)
{
	result temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//BUBBLESORT - f�rdelarna �r att den �r enkel att implementera, nackdelarna �r att den �r l�ngsam. Kallar i sin tur p� swap-funktionen
//totalt finns sex olika bubblesort. Tv� per kategori Inne och Ute
//SORT - HUMIDITY
void bubbleSortHumIn(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].humAverageIn > arr[j + 1].humAverageIn)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void bubbleSortHumOut(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].humAverageOut > arr[j + 1].humAverageOut)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//SORT - TEMP
void bubbleSortTempIn(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].tempAverageIn > arr[j + 1].tempAverageIn)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void bubbleSortTempOut(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].tempAverageOut > arr[j + 1].tempAverageOut)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//SORT - MOLDINDEX
void bubbleSortMoldIndexIn(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].moldIndexIn > arr[j + 1].moldIndexIn)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void bubbleSortMoldIndexOut(result arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].moldIndexOut > arr[j + 1].moldIndexOut)
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


//PRINT - f�r att skriva ut resultat av diverse sortfunktion, h�gt till l�gt eller l�gt till h�gt
//PRINT - HUMIDITY
void printArrayHumInLowHigh(result arr[], int n)
{
	int i;
	for (i = 0; i < 5; i++)
		cout << arr[i].humAverageIn << " - " << arr[i].date << endl;

}
void printArrayHumInHighLow(result arr[], int n)
{
	int i;
	for (i = 126; i < 131; i++)
		cout << arr[i].humAverageIn << " - " << arr[i].date << endl;
	cout << endl;
}

void printArrayHumOutLowHigh(result arr[], int n)
{
	int i;
	for (i = 0; i < 5; i++)
		cout << arr[i].humAverageOut << " - " << arr[i].date << endl;

}
void printArrayHumOutHighLow(result arr[], int n)
{
	int i;
	for (i = 126; i < 131; i++)
		cout << arr[i].humAverageOut << " - " << arr[i].date << endl;

}

//PRINT - INDOORTEMP
void printArrayTempInLowHigh(result arr[], int n)
{
	int i;
	for (i = 4; i > -1; i--)
		cout << arr[i].tempAverageIn << " - " << arr[i].date << endl;

}
void printArrayTempInHighLow(result arr[], int n)
{
	int i;
	for (i = n - 1; i > 125; i--)
		cout << arr[i].tempAverageIn << " - " << arr[i].date << endl;

}

//PRINT - OUTDOORTEMP
void printArrayTempOutLowHigh(result arr[], int n)
{
	int i;
	for (i = 4; i > -1; i--)
		cout << arr[i].tempAverageOut << " - " << arr[i].date << endl;
}
void printArrayTempOutHighLow(result arr[], int n)
{
	int i;
	for (i = n - 1; i > 125; i--)
		cout << arr[i].tempAverageOut << " - " << arr[i].date << endl;
}

//PRINT - MOLDINDEX
void printArrayMoldIndexOutHighLow(result arr[], int n)
{
	int i;
	for (i = n - 1; i > 125; i--)
		cout << "Moldindex: " << arr[i].moldIndexOut << " | Date: " << arr[i].date << " | temp: " << arr[i].tempAverageOut << " | humidity: " << arr[i].humAverageOut << endl;
}
void printArrayMoldIndexInHighLow(result arr[], int n)
{
	int i;
	for (i = n - 1; i > 125; i--)
		cout << "Moldindex: " << arr[i].moldIndexIn << " | Date: " << arr[i].date << " | temp: " << arr[i].tempAverageIn << " | humidity: " << arr[i].humAverageIn << endl;
}


//SEARCH - Enklaste formen av s�kning (Linj�r s�kning). likt bubblesort �r denna enkel att implementera, men �r lite l�ngsammare.
void searchOut(result arr[], string userSearch, int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (arr[i].date == userSearch)
		{
			cout << "You seached the date:" << userSearch << ". |Avg.temp (outdoor): " << arr[i].tempAverageOut << "| |Avg. humidity (outdoor): " << arr[i].humAverageOut << "|" << endl;
		}
	}
}
void searchIn(result arr[], string userSearch, int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (arr[i].date == userSearch)
		{
			cout << "You seached the date:" << userSearch << ". |Avg.temp (indoor): " << arr[i].tempAverageIn << "| |Avg. humidity (indoor): " << arr[i].humAverageIn << "|" << endl;
		}
	}
}


//CALCULATION - Ber�kning f�r h�st och vinter-fall. Sker i form av en for-loop med ifsatser som definierar villkoren f�r h�st/vinter
void fallCase(result arr[], float temp, int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((arr[i].fallDate > 0 && arr[i].fallDate < 10) && (arr[i + 1].fallDate > 0 && arr[i + 1].fallDate < 10) && (arr[i + 2].fallDate > 0 && arr[i + 2].fallDate < 10) && (arr[i + 3].fallDate > 0 && arr[i + 3].fallDate < 10) && (arr[i + 4].fallDate > 0 && arr[i + 4].fallDate < 10))
		{
			if ((arr[i + 1].fallDate < arr[i].fallDate) && (arr[i + 2].fallDate < arr[i + 1].tempAverageOut) && (arr[i + 3].fallDate < arr[i + 2].fallDate) && arr[i + 4].fallDate < arr[i + 3].fallDate)
			{
				cout << arr[i].date << endl;
				break;
			}
		}
	}
}
void winterCase(result arr[], float temp, int n)
{
	bool winterCase = false;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i].tempAverageOut < 0) && (arr[i + 1].tempAverageOut < 0) && (arr[i + 2].tempAverageOut < 0) && (arr[i + 3].tempAverageOut < 0) && (arr[i + 4].tempAverageOut < 0))
		{
			winterCase = true;
			cout << arr[i].date << endl;
			break;
		}
	}
	if (winterCase == false)
	{
		cout << "Winter is not found!" << endl;
	}
}

//CALCULATION - F�r ber�kning av m�gelindex. Jag har valt att ber�kna "diagonala"-l�ngden fr�n punkten till den lutande gr�ndslinjen i fallet (�ver 0 grader och under 15 grader, och �ver 78 % fuktighet
//med hj�lp av kontrollera avst�nden fr�n Input(temp,fukt) till gr�nslinjen kan man d�refter r�kna avst�ndet mellan de tv� punkterna p� gr�nslinjen, och efter det nyttja pytagoras sats
//f�r att r�kna ut "diagonalen" som d�r efter utg�r resultatet av m�gelindex. vid fallet �ver 15 grader och �ver 78 % fuktighet kontrollerar jag endast hur l�ngt punkter ligger fr�n gr�nslinjen i Y-led,
//dvs endast fuktigheten.
int moldIndex(float temp, int humidity)
{
	int moldIndex = 0;

	if (temp >= 15 && humidity >= 78)
	{
		if ((humidity - 78) <= 5)
		{
			moldIndex = 2;
		}
		if ((humidity - 78) <= 11)
		{
			moldIndex = 3;
		}
		if ((humidity - 78) <= 16)
		{
			moldIndex = 4;
		}
		if ((humidity - 78) <= 22)
		{
			moldIndex = 5;
		}
	}

	else if (((((temp < 15) || (temp < 0)) && (humidity <= 78)) || ((temp >= 15) && (humidity < 78)) || (temp <= 0 && humidity >= 78)))
	{
		moldIndex = 1;
	}

	else if (((temp > 0) && (temp < 15)) && (humidity > 78))
	{
		float yInputHum = humidity;
		float xInputTemp = temp;

		//1 R�kna ut gr�nsv�rde f�r y	
		float yLimit = 0;
		float xLimit = 0;
		yLimit = (k * xInputTemp) + m;

		//2 R�kna ut avst�ndet mellan y-punkterna. F�R INTE BLI UNDER 0
		float yDist = (yInputHum - yLimit);
		if (yDist < 0)
		{
			moldIndex = 1;
		}
		else if (yDist > 0)
		{
			//3 R�kna ut gr�nsv�rde f�r x
			xLimit = (yInputHum - m) / k;

			//4 R�kna ut avst�nd mellan punkterna p� gr�nslinjen
			float distLimitLine = 0;
			distLimitLine = (sqrt(pow((xInputTemp - xLimit), 2) + (pow((yLimit - yInputHum), 2))));
			distLimitLine = (distLimitLine / 2);

			//5 R�kna ut avst�ndet mellan inputPunkt och linje
			float distResult = 0;
			distResult = pow(yDist, 2) - pow(distLimitLine, 2);
			distResult = (sqrt(distResult));

			if (distResult > 0)
			{
				if (distResult >= 0.01)
				{
					moldIndex = 2;
				}
				if (distResult >= 2.76)
				{
					moldIndex = 3;
				}
				if (distResult >= 5.51)
				{
					moldIndex = 4;
				}
				if (distResult >= 8.26)
				{
					moldIndex = 5;
				}
				if (distResult >= 11.02)
				{
					moldIndex = 5;
				}
			}
		}
	}
	return moldIndex;
}

int main()
{
	//Deklarerar en array enligt min struct
	result resultArray[131];

	//Ber�knar och sparar storleken p� arrayen som "int n"
	int n = sizeof(resultArray) / sizeof(resultArray[0]);

	//En counter f�r att kunna skicka in i arrayen
	int i = 0;

	//Variablar f�r att hantera anv�ndarval fr�n meny
	int selection;
	string userSearchOut;
	string userSearchIn;

	//Variablar f�r att spara inl�sning av v�rden fr�n fil getline()
	string date;
	string time;
	string inOut;
	string temperature;
	string humidity;

	ifstream text("tempdata4.txt");
	if (text.is_open())
	{
		//Ett g�ng counters och str�ngar f�r att hantera ber�kning av medelv�rden och avg�ra om det �r ny dag. 
		//Initierar �ven "p" som till�ter att vi kommer �t variablarna i struct arrayen.
		float count = 0;
		float inCount = 0;
		float outCount = 0;
		string currentDate = "";
		string checkDate = "";
		result p;

		while (!text.eof())
		{
			//Inl�sning av "tempdata4.txt"
			getline(text, date, ' ');
			getline(text, time, ',');
			getline(text, inOut, ',');
			getline(text, temperature, ',');
			getline(text, humidity);

			//Kontrollerar om "date" �r samma som "checkDate" vilket inte �r sant under f�rsta varvet.
			if (date == checkDate)
			{
				if (inOut == "Inne")
				{
					//Summerar alla temperaturer och fuktighetsv�rden per dag samt en counter f�r att r�kna antal v�rden f�r att kunna r�kna medelv�rden
					p.tempAverageIn += stof(temperature);
					p.humAverageIn += stoi(humidity);
					inCount++;
				}
				if (inOut == "Ute")
				{
					//Summerar alla temperaturer och fuktighetsv�rden per dag samt en counter f�r att r�kna antal v�rden f�r att kunna r�kna medelv�rden
					p.tempAverageOut += stof(temperature);

					//Separat "fallDate" f�r att kunna kontrollera h�stfallet d�r temperaturen inte �r avrundad
					p.fallDate += stof(temperature);
					p.humAverageOut += stoi(humidity);
					outCount++;
				}
				currentDate = date;
				count++;
			}
			else
			{
				checkDate = date;
				if (count != 0)
				{
					//Utr�kningar av medelv�rden inne och ute
					p.date = currentDate;
					p.tempAverageIn = roundf((p.tempAverageIn / inCount) * 10) / 10;
					p.humAverageIn = p.humAverageIn / inCount;
					p.fallDate = p.fallDate / outCount;
					p.tempAverageOut = roundf((p.tempAverageOut / outCount) * 10) / 10;
					p.humAverageOut = p.humAverageOut / outCount;

					//Ber�kning av m�gelindex
					p.moldIndexOut = moldIndex(p.tempAverageOut, p.humAverageOut);
					p.moldIndexIn = moldIndex(p.tempAverageIn, p.humAverageIn);

					//Skickar in det i min array
					resultArray[i] = p;

					//Nollst�llning inf�r n�sta "varv"
					inCount = 0;
					outCount = 0;
					p.tempAverageIn = 0;
					p.humAverageIn = 0;
					p.tempAverageOut = 0;
					p.humAverageOut = 0;
					i++;
				}
			}
		}
	}
	//Meny d�r anv�ndar-valen i sig kallar p� funktioner/utr�kningar. Saknar funktioner f�r felhantering och eftersom jag i detta program inte har en funktion f�r att sortera efter datum
	//s� m�ste man k�ra val "5" och "6" f�rst/innan man b�rjar sortera andra fall
	do
	{
		cout << "  Menu for wheather analasys (2016-05-31 to 2017-01-10)\n";
		cout << "  ====================================\n";
		cout << "  1.  Search date for average outdoor-temperature and humidity\n";
		cout << "  2.  Sort average outdoor-temperature (high to low)\n";
		cout << "  3.  Sort average outdoor humidity (low to high)\n";
		cout << "  4.  Sort lowest to highest risk of mold (outdoor)\n";
		cout << "  5.  Print the date for fall\n"; //Kr�ver sortering efter datum (sant om vi v�ljer f�rsta g�ngen eftersom n�r vi l�ser in filen �r den sorterad efter datum)
		cout << "  6.  Print the date for winter\n"; //Kr�ver sortering efter datum (sant om vi v�ljer f�rsta g�ngen eftersom n�r vi l�ser in filen �r den sorterad efter datum)
		cout << "  7.  Search date for average indoor-temperature and humidity\n";
		cout << "  8.  Sort average indoor temperature (high to low)\n";
		cout << "  9.  Sort average indoor humidity (low to high)\n";
		cout << "  10. Sort lowest to highest risk of mold (indoor)\n";
		cout << "\n";		
		cout << "  ====================================\n";
		cout << "  Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case 1:
			cout << "\n Search for Date in this format: YYYY-MM-DD: ";
			cin >> userSearchOut;
			searchOut(resultArray, userSearchOut, n);
			cout << endl;
			break;

		case 2:
			cout << endl;
			cout << "(Outdoor temp) The five Highest :" << endl;
			bubbleSortTempOut(resultArray, n);
			printArrayTempOutHighLow(resultArray, n);
			cout << "..." << endl;
			cout << "(Outdoor temp) The five lowest :" << endl;
			printArrayTempOutLowHigh(resultArray, n);
			cout << endl;
			break;

		case 3:
			cout << endl;
			cout << "(Outdoor humidity) The five lowest:" << endl;
			bubbleSortHumOut(resultArray, n);
			printArrayHumOutLowHigh(resultArray, n);
			cout << "..." << endl;
			cout << "(Outdoor humidity) The five highest:" << endl;
			printArrayHumOutHighLow(resultArray, n);
			cout << endl;
			break;

		case 4:
			cout << endl;
			bubbleSortMoldIndexOut(resultArray, n);
			cout << "(Outdoor) Moldindex has been sorted. Here is the result sorted from high risk to low risk:" << endl;
			printArrayMoldIndexOutHighLow(resultArray, n);
			cout << endl;
			break;

		case 5:
			cout << endl;
			fallCase(resultArray, resultArray[i].fallDate, n);
			cout << endl;
			break;

		case 6:
			cout << endl;
			winterCase(resultArray, resultArray[i].tempAverageOut, n);
			cout << endl;
			break;

		case 7:
			cout << endl;
			cout << "\n Search for Date in this format: YYYY-MM-DD: ";
			cin >> userSearchIn;
			searchIn(resultArray, userSearchIn, n);
			cout << endl;
			break;

		case 8:
			cout << endl;
			cout << "(Indoor temp) The five highest:" << endl;
			bubbleSortTempIn(resultArray, n);
			printArrayTempInHighLow(resultArray, n);
			cout << "..." << endl;
			cout << "(Indoor temp) The five lowest:" << endl;
			printArrayTempInLowHigh(resultArray, n);
			cout << endl;
			break;

		case 9:
			cout << endl;
			cout << "(Indoor humidity) The five lowest:" << endl;
			bubbleSortHumIn(resultArray, n);
			printArrayHumInLowHigh(resultArray, n);
			cout << "..." << endl;
			cout << "(Indoor humidity) The five highest:" << endl;
			printArrayHumInHighLow(resultArray, n);
			cout << endl;
			break;

		case 10:
			cout << endl;
			bubbleSortMoldIndexIn(resultArray, n);
			cout << "(Inddoor) Moldindex has been sorted. Here is the result sorted from high risk to low risk:" << endl;
			cout << "Result showing indoor data. (1) meaning there is no risk of mold, due to dry air (low humidity)" << endl;
			printArrayMoldIndexInHighLow(resultArray, n);
			cout << endl;
			break;

		default: cout << selection << " is not a valid menu item.\n";
			cout << endl;
		}
	} while (selection != 0);
}