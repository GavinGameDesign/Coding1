#include <iostream>
#include <stdlib.h>
#include <cmath> 

using namespace std;

string gear[10];

class character {
public:
  int health;
  string weapon;
  string name;
  string catchphrase;

  character(string weapon1, string name1, string catchphrase1) {
    health = rand() % 20 + 10;
    weapon = weapon1;
    name = name1;
    catchphrase = catchphrase1;
  }

  void status() {
    cout << endl << name << " has " << health << " health and a " << weapon << ".\n";
    cout << catchphrase << "\n\n";
  }

  void searchForGear() {
    int test = rand() % 2 + 1;
    int randGear = rand() % 10;
    string input;
    
    cout << name << " looks around for some gear!\n\n";

    if (test == 1) {
      cout << name << " found a " << gear[randGear] << "!\n";
      cout << "Would you like to equip the " << gear[randGear] << "? (y or n) ";
      cin >> input;

      if (input == "y" || input == "Y") {
        cout << name << " equips the " << gear[randGear] << "!\n\n";
        weapon = gear[randGear];
      }
    }
    else {
      cout << name << " found nothing!\n\n";
    }
  }
};

int main() {

  srand(time(NULL));

  string nameInput;
  string weaponInput;
  string catchphraseInput;

  gear[0] = "Longsword";
  gear[1] = "Shortsword";
  gear[2] = "Broadsword";
  gear[3] = "Dagger";
  gear[4] = "Bow and Arrow";
  gear[5] = "Double Daggers";
  gear[6] = "Shortsword and Shield";
  gear[7] = "Scythe";
  gear[8] = "Spiked Shield";
  gear[9] = "Bat";
  
  cout << "What would you like to name the character? ";
  cin >> nameInput;

  cout << "\nWhat weapon does the character have? ";
  cin >> weaponInput;

  cout << "\nAnd what is their catchphrase? ";
  cin >> catchphraseInput;

  character character1(weaponInput, nameInput, catchphraseInput);
  character1.status();
  character1.searchForGear();
  character1.status();
  character1.searchForGear();
  character1.status();
  character1.searchForGear();
  character1.status();
  
}