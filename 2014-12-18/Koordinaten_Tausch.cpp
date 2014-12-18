#include <iostream>

using namespace std;

struct T_Kartesich {
	int iX;
	int iY;
};

void Tausch(T_Kartesich *pPunkt);

int main() {
	T_Kartesich *pPunkt_Blau = new(T_Kartesich);
	T_Kartesich *pPunkt_Gruen = new(T_Kartesich);

	cout << "Blau X: ";
	cin >> pPunkt_Blau->iX;
	cout << "Blau Y: ";
	cin >> pPunkt_Blau->iY;
	cout << "Gruen X: ";
	cin >> pPunkt_Gruen->iX;
	cout << "Gruen Y: ";
	cin >> pPunkt_Gruen->iY;
	cout << endl;

	cout << "Vorher:" << endl;
	cout << "Blau: (" << pPunkt_Blau->iX << ", " << pPunkt_Blau->iY << ")" << endl;
	cout << "Gruen: (" << pPunkt_Gruen->iX << ", " << pPunkt_Gruen->iY << ")" << endl;
	cout << endl;

	Tausch(pPunkt_Blau);
	Tausch(pPunkt_Gruen);

	cout << "Nachher:" << endl;
	cout << "Blau: (" << pPunkt_Blau->iX << ", " << pPunkt_Blau->iY << ")" << endl;
	cout << "Gruen: (" << pPunkt_Gruen->iX << ", " << pPunkt_Gruen->iY << ")" << endl;
	cout << endl;

	return 0;
}

void Tausch(T_Kartesich *pPunkt) {
	int tmp = pPunkt->iX;
	pPunkt->iX = pPunkt->iY;
	pPunkt->iY = tmp;
}
