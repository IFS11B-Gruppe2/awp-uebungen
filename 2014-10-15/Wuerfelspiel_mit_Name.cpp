#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N_PLAYERS 8
#define MAX_VALUE 6
#define THROWS 10

using namespace std;

struct T_Wuerfeln {
  char cName[20];
  int aiValues[THROWS];
};

int main() {
  // vars
  T_Wuerfeln Spieler[N_PLAYERS];
  int aiTimes[MAX_VALUE + 1] = {0};

  /* beginning of logic */

  // Get random numbers.
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    cout << "Name: ";
    cin >> Spieler[player_number].cName;
    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      Spieler[player_number].aiValues[throw_number] = rand() % MAX_VALUE + 1;
    }
  }

  // Get number occurrences
  for(int player_number = 0; player_number < N_PLAYERS; player_number++) {
    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      aiTimes[Spieler[player_number].aiValues[throw_number]] ++;
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
    cout << "Spieler " << Spieler[player_number].cName << ":\t";

    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      cout << Spieler[player_number].aiValues[throw_number] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-" << MAX_VALUE << ":" << endl;
  for(int throw_number = 1; throw_number <= MAX_VALUE; throw_number++) {
    cout << "Die Zahl " << throw_number << "  " << aiTimes[throw_number] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
