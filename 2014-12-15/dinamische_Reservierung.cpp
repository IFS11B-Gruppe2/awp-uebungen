#include <iostream>

using namespace std;

void copyArray(int *paiSource, int iHowMany, int *paiTarget);
int* resizeArray(int *pai, int &iCurrentLength);
void showIntArray(int *pai, int paiLength);

int main() {
	int iArrayLength = 0, iValue, *paiList = NULL;

	do {
		cout << "[" << iArrayLength << "]: ";
		cin >> iValue;

		if (iValue != 0) {
			paiList = resizeArray(paiList, iArrayLength);
			paiList[iArrayLength - 1] = iValue;
		}
	} while(iValue != 0);

	cout << endl << "List:" << endl;
	showIntArray(paiList, iArrayLength);
	cout << endl;

	if (paiList != NULL) {
		delete[] paiList;
		paiList = NULL;
	}

	return 0;
}

void copyArray(int *paiSource, int iHowMany, int *paiTarget) {
	for (int i = 0; i < iHowMany; ++i) {
		paiTarget[i] = paiSource[i];
	}
}

int* resizeArray(int *pai, int &iCurrentLength) {
	int *tmp = pai;

	pai = new int[iCurrentLength + 1];

	copyArray(tmp, iCurrentLength, pai);

	++iCurrentLength;

	if (tmp != NULL) {
		delete[] tmp;
		tmp = NULL;
	}

	return pai;
}

void showIntArray(int *pai, int paiLength) {
	for(int i = 0; i < paiLength; i++) {
		cout << pai[i] << " ";
	}
}
