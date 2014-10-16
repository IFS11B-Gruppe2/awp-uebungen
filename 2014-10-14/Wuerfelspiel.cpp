#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N_PLAYERS 8
#define MAX_VALUE 6
#define THROWS 10

using namespace std;

int main() {
  // vars
  int aiValues[N_PLAYERS][THROWS];
  int aiTimes[MAX_VALUE + 1] = {0};

  /* beginning of logic */

  // Get random numbers.
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int k = 0; k < THROWS; k++) {
      aiValues[player_number][k] = rand() % MAX_VALUE + 1;
    }
  }

  // Get number occurrences
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int k = 0; k < THROWS; k++) {
      aiTimes[aiValues[player_number][k]] ++;
    }
  }

  /* end of logic */

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen der Spieler 1-" << N_PLAYERS << ":" << endl;
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    cout << "Spieler " << player_number + 1 << ":  ";

    for(int k = 0; k < THROWS; k++) {
      cout << aiValues[player_number][k] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-" << MAX_VALUE << ":" << endl;
  for(int k = 1; k <= MAX_VALUE; k++) {
    cout << "Die Zahl " << k << "  " << aiTimes[k] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
