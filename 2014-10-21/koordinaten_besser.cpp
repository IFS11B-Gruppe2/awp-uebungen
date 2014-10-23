// Auszugsweise:
// KoordinatenUmrechnung m.H. von Funktionen
// OHNE Benutzung von call by reference und MIT Rueckgabewert
// Koordinaten werden m.H. ZWEIER Variablen und
// ZWEIER Datentypen verwaltet
#include <iostream>
#include <cmath>
#define M_Pi 3.14159

using namespace std;

// Datentypen

struct T_kart {
  float fx;
  float fy;
};

struct T_polar {
  float fWinkel;
  float fRadius;
};

// Functions headers
T_polar kart_polar(T_kart Koordi);
T_kart polar_kart(T_polar Koordi);
int menu(void);

int main() {
  // Vars
  T_kart KartKoordinaten;
  T_polar PolarKoordinaten;
  int iOption; // menu user input
  bool iExit = false; // main loop control flag

  // main loop
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
        cin >> PolarKoordinaten.fRadius;
        cout << "Winkel: ";
        cin >> PolarKoordinaten.fWinkel;
        cout << endl;

        KartKoordinaten = polar_kart(PolarKoordinaten);

        cout << "X-Koordinate: " << KartKoordinaten.fx << endl;
        cout << "Y-Koordinate: " << KartKoordinaten.fy << endl;
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
        cin >> KartKoordinaten.fx;
        cout << "Y-Koordinate: ";
        cin >> KartKoordinaten.fy;
        cout << endl;

        PolarKoordinaten = kart_polar(KartKoordinaten);

        cout << "Radius: " << PolarKoordinaten.fRadius << endl;
        cout << "Winkel: " << PolarKoordinaten.fWinkel << endl;
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

T_polar kart_polar(T_kart Koordi) {
  T_polar PKoordi;

  PKoordi.fWinkel = 180 / M_Pi * atan(Koordi.fy / Koordi.fx);
  PKoordi.fRadius = sqrt(Koordi.fx * Koordi.fx + Koordi.fy * Koordi.fy);

  return PKoordi;
}

T_kart polar_kart(T_polar Koordi) {
  T_kart KKoordi;

  KKoordi.fx = Koordi.fRadius * cos(Koordi.fWinkel * M_Pi / 180);
  KKoordi.fy = Koordi.fRadius * sin(Koordi.fWinkel * M_Pi / 180);

  return KKoordi;
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
