#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  // vars
  int aiValues[10];
  int aiTimes[7] = {0};

  // logic
  for(int k = 0; k < 10; k++) {
    aiValues[k] = rand() % 6 + 1;
  }

  for(int k = 0; k < 10; k++) {
    if (aiValues[k] == 1) {
      aiTimes[1] ++;
    }
    if (aiValues[k] == 2) {
      aiTimes[2] ++;
    }
    if (aiValues[k] == 3) {
      aiTimes[3] ++;
    }
    if (aiValues[k] == 4) {
      aiTimes[4] ++;
    }
    if (aiValues[k] == 5) {
      aiTimes[5] ++;
    }
    if (aiValues[k] == 6) {
      aiTimes[6] ++;
    }
  }

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen der Spieler" << endl;
  for(int k = 0; k < 10; k++) {
    cout << aiValues[k] << " ";
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-6:" << endl;
  for(int k = 1; k <= 6; k++) {
    cout << "Die Zahl " << k << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
