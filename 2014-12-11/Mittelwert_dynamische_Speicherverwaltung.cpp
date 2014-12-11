#include <iostream>

using namespace std;

float EingabeMittelwert(int *piFeld, int iAnzahl);

int main() {
	int iAnzahl, *piWerte;
	float fMittelwert;

	cout << "Wie viele Zahlen? ";
	cin >> iAnzahl;

	piWerte = new int[iAnzahl];

	fMittelwert = EingabeMittelwert(piWerte, iAnzahl);

	cout << "Mittelwert: " << fMittelwert << endl;

	delete[] piWerte;
	piWerte = NULL;

	return 0;
}

float EingabeMittelwert(int *piFeld, int iAnzahl) {
	float fMittelwert = 0;

	for(int i = 0; i < iAnzahl; ++i) {
		cout << "[" << i << "]: ";
		cin >> piFeld[i];

		fMittelwert += piFeld[i];
	}

	fMittelwert /= iAnzahl;

	return fMittelwert;
}
