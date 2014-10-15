#include <iostream>
#include <stdlib.h>

using namespace std;

struct T_Wuerfeln {
  char cName[20];
  int aiValues[10];
};

int main() {
  // vars
  T_Wuerfeln Spieler;
  int aiTimes[6] = {0};

  // logic
  cout << "Name des Spielers: ";
  cin >> Spieler.cName;
  for(int k = 0; k < 10; k++) {
    Spieler.aiValues[k] = rand() % 6 + 1;
  }

  for(int k = 0; k < 10; k++) {
    aiTimes[Spieler.aiValues[k] - 1] ++;
  }

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen von " << Spieler.cName << endl;
  for(int k = 0; k < 10; k++) {
    cout << Spieler.aiValues[k] << " ";
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-6:" << endl;
  for(int k = 0; k < 6; k++) {
    cout << "Die Zahl " << k + 1 << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
