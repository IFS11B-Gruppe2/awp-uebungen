#include <iostream>
#include <stdlib.h>
#include <time.h>
#define GAMES 12
#define MAX_VALUE 49
#define THROWS 6

using namespace std;

int main() {
  // vars
  int aiValues[GAMES][THROWS];
  int aiTimes[MAX_VALUE] = {0};

  /* beginning of logic */

  // Get random numbers.
  for(int game_number = 0; game_number < GAMES; game_number++) {
    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      aiValues[game_number][throw_number] = rand() % MAX_VALUE + 1;
    }
  }

  // Get number occurrences
  for(int game_number = 0; game_number < GAMES; game_number++) {
    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      aiTimes[aiValues[game_number][throw_number] - 1] ++;
    }
  }

  /* end of logic */

  // output
  cout << "--------------------------------------" << endl;
  cout << "Das Lottospiel" << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;

  cout << "Die Zahlen der Wochen 1-" << GAMES << ":" << endl;
  for(int game_number = 0; game_number < GAMES; game_number++) {
    cout << "Woche " << game_number + 1 << ":  ";

    for(int throw_number = 0; throw_number < THROWS; throw_number++) {
      cout << aiValues[game_number][throw_number] << "\t";
    }
    cout << endl;
  }
  cout << endl << endl;

  cout << "Ziehungshäufigkeiten der Zahlen 1-" << MAX_VALUE << ":" << endl;
  for(int throw_number = 0; throw_number < MAX_VALUE; throw_number++) {
    cout << "Die Zahl " << throw_number + 1 << "  " << aiTimes[throw_number] << " mal" << endl;
  }
  cout << endl;

  return 0;
}
