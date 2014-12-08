#include <iostream>
#include <stdio.h>

using namespace std;

void fill(char *pac, int *pai);
void showIntArray(int *pai, int paiLenght);

int main() {
	char acZeichen[4] = "WER";
	int aiFeld[3] = {0};

	fill(acZeichen, aiFeld);

	printf("acZeichen: %s \n", acZeichen);
	cout << "aiFeld: ";
	for(int i = 0; i < 3; i++) {
		cout << aiFeld[i] << " ";
	}
	cout << endl;
}

void fill(char *pac, int *pai) {
	for (int i = 0; *(pac + i) != '\0'; i++) {
		*(pai + i) = *(pac + i);
	}
}

void showIntArray(int *pai, int paiLenght) {
	// TODO Hausaufgabe
}
