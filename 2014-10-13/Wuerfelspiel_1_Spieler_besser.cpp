#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  // vars
  int aiValues[10];
  int aiTimes[6] = {0};

  // logic
  for(int k = 0; k < 10; k++) {
    aiValues[k] = rand() % 6 + 1;
  }

  for(int k = 0; k < 10; k++) {
    aiTimes[aiValues[k] - 1] ++;
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
  for(int k = 0; k < 6; k++) {
    cout << "Die Zahl " << k + 1 << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
