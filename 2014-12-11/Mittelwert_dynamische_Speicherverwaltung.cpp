#include <iostream>

using namespace std;

void Eingabe(int *piFeld, int iAnzahl);
float Mittelwert(int *piFeld, int iAnzahl);

int main() {
	int iAnzahl, *piWerte;
	float fMittelwert;

	cout << "Wie viele Zahlen? ";
	cin >> iAnzahl;

	piWerte = new int[iAnzahl];

	Eingabe(piWerte, iAnzahl);
	fMittelwert = Mittelwert(piWerte, iAnzahl);

	cout << "Mittelwert: " << fMittelwert << endl;

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

float Mittelwert(int *piFeld, int iAnzahl) {
	float fMittelwert = 0;

	for(int i = 0; i < iAnzahl; ++i) {
		fMittelwert += piFeld[i];
	}

	fMittelwert /= iAnzahl;

	return fMittelwert;
}
