#include <iostream>

#define NUMBER_TO_SEARCH 1

using namespace std;

void Eingabe(int *piFeld, int iAnzahl);
bool isVorhanden(int *piFeld, int iAnzahl, int iGesucht);
float Mittelwert(int *piFeld, int iAnzahl);
void MaxMin(int *piFeld, int iAnzahl, int &iMax, int &iMin);
int Max(int *piFeld, int iAnzahl);
int Min(int *piFeld, int iAnzahl);
int* reserviertInt(int iAnzahl);

int main() {
	int iAnzahl, *piWerte;
	float fMittelwert;
	int iMax, iMin;
	bool gefunden;

	cout << "Wie viele Zahlen? ";
	cin >> iAnzahl;

	piWerte = reserviertInt(iAnzahl);

	Eingabe(piWerte, iAnzahl);
	fMittelwert = Mittelwert(piWerte, iAnzahl);
	//iMax = Max(piWerte, iAnzahl);
	//iMin = Min(piWerte, iAnzahl);
	MaxMin(piWerte, iAnzahl, iMax, iMin);
	gefunden = isVorhanden(piWerte, iAnzahl, NUMBER_TO_SEARCH);

	cout << "Mittelwert: " << fMittelwert << endl;
	cout << "Max: " << iMax << endl;
	cout << "Min: " << iMin << endl;
	cout << "Die Nummer " << NUMBER_TO_SEARCH << " wurde";
	if (!gefunden) {
		cout << " nicht";
	}
	cout << " gefunden." << endl;

	delete[] piWerte;
	piWerte = NULL;

	return 0;
}

void Eingabe(int *piFeld, int iAnzahl) {
	for(int i = 0; i < iAnzahl; ++i) {
		cout << "[" << i << "]: ";
		cin >> piFeld[i];
	}
}

bool isVorhanden(int *piFeld, int iAnzahl, int iGesucht) {
	bool gefunden = false;

	for (int i = 0; i < iAnzahl && !gefunden; ++i) {
		if (piFeld[i] == iGesucht) {
			gefunden = true;
		}
	}

	return gefunden;
}

void MaxMin(int *piFeld, int iAnzahl, int &iMax, int &iMin) {
	iMax = piFeld[0]; // first number
	iMin = piFeld[0]; // first number

	for(int i = 1; i < iAnzahl; ++i) {
		if (piFeld[i] > iMax) {
			iMax = piFeld[i];
		}

		if (piFeld[i] < iMin) {
			iMin = piFeld[i];
		}
	}
}

int Max(int *piFeld, int iAnzahl) {
	int iMax = piFeld[0]; // first number

	for(int i = 1; i < iAnzahl; ++i) {
		if (piFeld[i] > iMax) {
			iMax = piFeld[i];
		}
	}

	return iMax;
}

int Min(int *piFeld, int iAnzahl) {
	int iMin = piFeld[0]; // first number

	for(int i = 1; i < iAnzahl; ++i) {
		if (piFeld[i] < iMin) {
			iMin = piFeld[i];
		}
	}

	return iMin;
}

float Mittelwert(int *piFeld, int iAnzahl) {
	float fMittelwert = 0;

	for(int i = 0; i < iAnzahl; ++i) {
		fMittelwert += piFeld[i];
	}

	fMittelwert /= iAnzahl;

	return fMittelwert;
}

int* reserviertInt(int iAnzahl) {
	return new int[iAnzahl];
}
