#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N_PLAYERS 8
#define MAX_VALUE 6
#define THROWS 6

using namespace std;

int main() {
  // vars
  int aiValues[N_PLAYERS][THROWS];
  int aiTimes[MAX_VALUE] = {0};

  // logic
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int throw_number = 0; throw_number < 10; throw_number++) {
      aiValues[player_number][throw_number] = rand() % 6 + 1;
    }
  }

  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int throw_number = 0; throw_number < 10; throw_number++) {
      aiTimes[aiValues[player_number][throw_number] - 1] ++;
    }
  }

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Würfelspiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die gewürfelten Zahlen der Spieler 1-" << N_PLAYERS << ":" << endl;
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    cout << "Spieler " << player_number + 1 << ":  ";

    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      cout << aiValues[player_number][throw_number] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-6:" << endl;
  for(int throw_number = 0; throw_number < MAX_VALUE; throw_number++) {
    cout << "Die Zahl " << throw_number + 1 << "  " << aiTimes[throw_number] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
