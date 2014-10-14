#include <iostream>
#include <stdlib.h>

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
    switch(aiValues[k]) {
      case 1:
        aiTimes[1] ++;
        break;
      case 2:
        aiTimes[2] ++;
        break;
      case 3:
        aiTimes[3] ++;
        break;
      case 4:
        aiTimes[4] ++;
        break;
      case 5:
        aiTimes[5] ++;
        break;
      case 6:
        aiTimes[6] ++;
        break;
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