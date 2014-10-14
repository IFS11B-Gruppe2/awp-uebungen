#include <iostream>
#include <stdlib.h>
#define N_PLAYERS 10

using namespace std;

int main() {
  // vars
  int aiValues[N_PLAYERS][10];
  int aiTimes[6] = {0};

  // logic
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int k = 0; k < 10; k++) {
      aiValues[player_number][k] = rand() % 6 + 1;
    }
  }

  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int k = 0; k < 10; k++) {
      aiTimes[aiValues[player_number][k] - 1] ++;
    }
  }

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen der Spieler 1-" << N_PLAYERS << ":" << endl;
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    cout << "Spieler " << player_number << ":  ";

    for(int k = 0; k < 10; k++) {
      cout << aiValues[player_number][k] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-6:" << endl;
  for(int k = 0; k < 6; k++) {
    cout << "Die Zahl " << k + 1 << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
