// Auszugsweise: mit Call by Reference
// KoordinatenUmrechnung m.H. von Funktionen
// Koordinaten werden m.H. EINER Variablen und
// EINES Datentyps verwaltet
#include <iostream>
#include <cmath>
#define M_Pi 3.14159

using namespace std;

struct T_kp {
  float fx;
  float fy;
  float fWinkel;
  float fRadius;
};

// Functions headers
void kart_polar(T_kp & Koordi);
void polar_kart(T_kp & Koordi);
int menu(void);

int main() {
  T_kp Koordinaten;
  int iOption; // menu user input
  bool iExit = false; // main loop control flag

  while(! iExit) {
    iOption = menu();

    // Clear screen.
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

    switch(iOption) {
      case 1:
        cout << "Umrechnung Polar --> Kartesisch" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Radius: ";
        cin >> Koordinaten.fRadius;
        cout << "Winkel: ";
        cin >> Koordinaten.fWinkel;
        cout << endl;

        polar_kart(Koordinaten);

        cout << "X-Koordinate: " << Koordinaten.fx << endl;
        cout << "Y-Koordinate: " << Koordinaten.fy << endl;
        cout << endl;

        cout << "Pause... (Drücken Sie die 'Enter' Taste)";
        cin.get();
        cin.get();
      break;

      case 2:
        cout << "Umrechnung Kartesisch --> Polar" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "X-Koordinate: ";
        cin >> Koordinaten.fx;
        cout << "Y-Koordinate: ";
        cin >> Koordinaten.fy;
        cout << endl;

        kart_polar(Koordinaten);

        cout << "Radius: " << Koordinaten.fRadius << endl;
        cout << "Winkel: " << Koordinaten.fWinkel << endl;
        cout << endl;

        cout << "Pause... (Drücken Sie die 'Enter' Taste)";
        cin.get();
        cin.get();
      break;

      case 0:
        iExit = true;
      break;

      default:
        cout << "Option '" << iOption << "' nicht gultig!" << endl;
        cout << "Pause... (Drücken Sie die 'Enter' Taste)";
        cin.get();
        cin.get();
    }
  }

  return 0;
}


// Functions body

void kart_polar(T_kp & Koordi) {
  Koordi.fWinkel = 180 / M_Pi * atan(Koordi.fy / Koordi.fx);
  Koordi.fRadius = sqrt(Koordi.fx * Koordi.fx + Koordi.fy * Koordi.fy);
}

void polar_kart(T_kp & Koordi) {
  Koordi.fx = Koordi.fRadius * cos(Koordi.fWinkel * M_Pi / 180);
  Koordi.fy = Koordi.fRadius * sin(Koordi.fWinkel * M_Pi / 180);
}

int menu(void) {
  int iOption;

  // Clear screen.
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

  // Show menu
  cout << "Polarkoordinaten / Kartesische Koordinaten" << endl;
  cout << "------------------------------------------" << endl;
  cout << endl;
  cout << "Was wollen Sie tun?" << endl;
  cout << "(1) Polar      --> Kartesisch" << endl;
  cout << "(2) Kartesisch --> Polar" << endl;
  cout << endl;
  cout << "(0) Ende" << endl;
  cout << endl;
  cout << "Ihre Wahl: ";

  // Get user input
  cin >> iOption;

  // Clear screen.
  cout << "\n\n\n";

  return iOption;
}
