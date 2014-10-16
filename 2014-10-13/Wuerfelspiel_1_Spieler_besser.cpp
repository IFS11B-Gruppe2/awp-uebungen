#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 6
#define THROWS 10

using namespace std;

int main() {
  // vars
  int aiValues[THROWS];
  int aiTimes[MAX_VALUE + 1] = {0};

  /* beginning of logic */

  // Get random numbers.
  for(int k = 0; k < THROWS; k++) {
    aiValues[k] = rand() % MAX_VALUE + 1;
  }

  // Get number occurrences
  for(int k = 0; k < THROWS; k++) {
    aiTimes[aiValues[k]] ++;
  }

  /* end of logic */

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen der Spieler" << endl;
  for(int k = 0; k < THROWS; k++) {
    cout << aiValues[k] << " ";
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-" << MAX_VALUE << ":" << endl;
  for(int k = 1; k <= MAX_VALUE; k++) {
    cout << "Die Zahl " << k << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
