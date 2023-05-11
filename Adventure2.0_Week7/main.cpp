#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

//global vars
int health = 30;
int totalGold = 0;

//story function
void story() {
  cout << "You wake up...\n\n";
  cout << "You must set out on an adventure!\n\nYou have " << health << " health.\n\n";
}

//ask y/n function
bool askYesNo(string question) {
  string input = " ";

  while(true) {
    cout << question << endl;
    cout << "Y/N >> ";
    cin >> input;

    if (input == "y" || input == "Y") {
      return true;
    }
    else if (input == "n" || input == "N") {
      return false;
    }
    else {
      cout << "Invalid input, please try again\n\n";
    }
  }
}

//roll die function
int rollDie(int sides = 6) {
  return rand() % sides + 1;
}

//adventure function
bool adventure() {
  int attack = rollDie(10);
  int block = rollDie(10);
  int gold = rollDie(20);

  cout << "Let's go adventuring!\n\n";
  cout << "An enemy appears!\n";
  cout << "You attack for " << attack << " and the enemy blocks for " << block << "!\n\n";

  if (attack >= block) {
    cout << "Your attack was successful and you gained " << gold << " gold!\n\n";
    totalGold += gold;
  }
  else if (attack < block) {
    cout << "Your attack failed and you take " << block << " damage!\n";
    cout << "You also missed out on " << gold << " gold!\n\n";
    health -= block;
  }

  //is player dead
  if (health <= 0) {
    return true;
  }

  cout << "You currently have " << health << " health and " << totalGold << " gold.\n\n";
  return false;
}

//ending function
void ending() {
  cout << "You died with " << totalGold << " gold!\n\nThanks for playing!";
}

int main() {
  //srand
  srand(time(NULL));
  
  //code
  story();

  //main game loop
  while(true) {
    if (askYesNo("Would you like to go adventuring?")) {
      if (adventure()) {
        ending();
        break;
      }
    }
    else {
      cout << "\nYou survived with " << health << " health and " << totalGold << " gold!\n\n";
      cout << "Thanks for playing!";
      break;
    }
    
  }
}