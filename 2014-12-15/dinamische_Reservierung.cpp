#include <iostream>

using namespace std;

void copyArray(int *paiSource, int iHowMany, int *paiTarget);
void resizeArray(int *pai, int &iCurrentLength);
void showIntArray(int *pai, int paiLength);

int main() {
	int iArrayLenght = 3,
	    *test = new int[iArrayLenght];

	test[0] = 0;
	test[1] = 1;
	test[2] = 2;

	resizeArray(test, iArrayLenght);
	test[3] = 3;
	showIntArray(test, iArrayLenght);
	cout << endl;

	return 0;
}

void copyArray(int *paiSource, int iHowMany, int *paiTarget) {
	for (int i = 0; i < iHowMany; ++i) {
		paiTarget[i] = paiSource[i];
	}
}

void resizeArray(int *pai, int &iCurrentLength) {
	int *tmp = pai;

	pai = new int[iCurrentLength + 1];

	copyArray(tmp, iCurrentLength, pai);

	++iCurrentLength;

	delete[] tmp;
	tmp = NULL;
}

void showIntArray(int *pai, int paiLength) {
	for(int i = 0; i < paiLength; i++) {
		cout << pai[i] << " ";
	}
}
