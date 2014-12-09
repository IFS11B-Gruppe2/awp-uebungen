#include <iostream>
#include <stdio.h>
#define LENGTH_ACZEICHEN 4
#define LENGTH_AIFELD 3
#define BUBLE_SORT_ASC 0
#define BUBLE_SORT_DESC 1

using namespace std;

void fill(char *pac, int *pai);
void showIntArray(int *pai, int paiLenght);
void sortIntArray(int *pai, int paiLenght, int order);

int main() {
	char acZeichen[LENGTH_ACZEICHEN] = "WER";
	int aiFeld[LENGTH_AIFELD] = {0};

	fill(acZeichen, aiFeld);

	printf("acZeichen: %s \n", acZeichen);
	cout << "aiFeld: ";
	showIntArray(aiFeld, LENGTH_AIFELD);
	cout << endl;
	sortIntArray(aiFeld, LENGTH_AIFELD, BUBLE_SORT_ASC);
	cout << "aiFeld(geordnet): ";
	showIntArray(aiFeld, LENGTH_AIFELD);
	cout << endl;
}

void fill(char *pac, int *pai) {
	for (int i = 0; *(pac + i) != '\0'; i++) {
		*(pai + i) = *(pac + i);
	}
}

void showIntArray(int *pai, int paiLenght) {
	for(int i = 0; i < paiLenght; i++) {
		cout << pai[i] << " ";
	}
}

void sortIntArray(int *pai, int paiLenght, int order) {
	bool sorted;
	int i = 0;

	do {
		++i;
		sorted = true;

		for (int k = 0; k < paiLenght - 1; ++k) {
			if (
				order == BUBLE_SORT_ASC && pai[k] > pai[k + 1]
				||
				order == BUBLE_SORT_DESC && pai[k] < pai[k + 1]
			) {
				int tmp = pai[k];
				pai[k] = pai[k + 1];
				pai[k + 1] = tmp;
				sorted = false;
			}
		}
	} while(i < paiLenght && !sorted);
}
