#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 6
#define THROWS 10

using namespace std;

struct T_Wuerfeln {
  char cName[20];
  int aiValues[THROWS];
};

int main() {
  // vars
  T_Wuerfeln Spieler;
  int aiTimes[MAX_VALUE + 1] = {0};

  /* beginning of logic */

  // Get random numbers.
  cout << "Name des Spielers: ";
  cin >> Spieler.cName;
  for(int k = 0; k < THROWS; k++) {
    Spieler.aiValues[k] = rand() % MAX_VALUE + 1;
  }

  // Get number occurrences
  for(int k = 0; k < THROWS; k++) {
    aiTimes[Spieler.aiValues[k]] ++;
  }

  /* end of logic */

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen von " << Spieler.cName << endl;
  for(int k = 0; k < THROWS; k++) {
    cout << Spieler.aiValues[k] << " ";
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-" << MAX_VALUE << ":" << endl;
  for(int k = 1; k <= MAX_VALUE; k++) {
    cout << "Die Zahl " << k << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
