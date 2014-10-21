// Auszugsweise: mit Call by Reference
// KoordinatenUmrechnung m.H. von Funktionen
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
void kart_polar(T_kart KartKoordi, T_polar & PolarKoordi);
void polar_kart(T_kart & KartKoordi, T_polar PolarKoordi);
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

        polar_kart(KartKoordinaten, PolarKoordinaten);

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

        kart_polar(KartKoordinaten, PolarKoordinaten);

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
    }
  }

  return 0;
}


// Functions body

void kart_polar(T_kart KartKoordi, T_polar & PolarKoordi) {
  PolarKoordi.fWinkel = 180 / M_Pi * atan(KartKoordi.fy / KartKoordi.fx);
  PolarKoordi.fRadius = sqrt(KartKoordi.fx * KartKoordi.fx + KartKoordi.fy * KartKoordi.fy);
}

void polar_kart(T_kart & KartKoordi, T_polar PolarKoordi) {
  KartKoordi.fx = PolarKoordi.fRadius * cos(PolarKoordi.fWinkel * M_Pi / 180);
  KartKoordi.fy = PolarKoordi.fRadius * sin(PolarKoordi.fWinkel * M_Pi / 180);
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
