// Thema: Zeiger (Pointers)
// Fuellen Sie ein Integer Array
// mit der ASCII Werte der Zeichen eines Zeichenarrays.
#include <iostream>

using namespace std;



// Functions headers
void Fuellen(char * p_char, int * p_int);



int main() {
  char acZeichen[20];
  int aiAscii[20];

  cout << "Geben Sie Ihren Namen ein: ";
  cin >> acZeichen;

  Fuellen(acZeichen, aiAscii);

  for (int i = 0; i < acZeichen[i] != '\0'; i++) {
    cout << acZeichen[i] << '\t';
  }
  cout << endl;

  for (int i = 0; i < acZeichen[i] != '\0'; i++) {
    cout << aiAscii[i] << '\t';
  }
  cout << endl;

  return 0;
}



// Function body
void Fuellen(char * p_char, int * p_int) {
  for (int i = 0; p_char[i] != '\0'; i++) {
    p_int[i] = p_char[i];
  }
}
