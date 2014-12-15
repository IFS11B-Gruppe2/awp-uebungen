#include <iostream>

using namespace std;

void copyArray(int *paiSource, int iHowMany, int *paiTarget);
void resizeArray(int *pai, int &iCurrentLength);
void showIntArray(int *pai, int paiLength);

int main() {
	int iArrayLength = 0, iValue, *paiList;

	do {
		cout << "[" << iArrayLength << "]: ";
		cin >> iValue;

		if (iValue != 0) {
			if (iArrayLength == 0) {
				paiList = new int;
				++iArrayLength;
				*paiList = iValue;
			}
		}
	} while(iValue != 0);

	cout << endl;
	showIntArray(paiList, iArrayLength);
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
