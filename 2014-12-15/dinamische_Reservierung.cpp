#include <iostream>

using namespace std;

void copyArray(int *paiSource, int iHowMany, int *paiTarget);
void showIntArray(int *pai, int paiLength);

int main() {
	int test1[3] = {1,2,3}, test2[3];

	copyArray(test1, 3, test2);
	showIntArray(test2, 3);
	cout << endl;

	return 0;
}

void copyArray(int *paiSource, int iHowMany, int *paiTarget) {
	for (int i = 0; i < iHowMany; ++i) {
		paiTarget[i] = paiSource[i];
	}
}

void showIntArray(int *pai, int paiLength) {
	for(int i = 0; i < paiLength; i++) {
		cout << pai[i] << " ";
	}
}
