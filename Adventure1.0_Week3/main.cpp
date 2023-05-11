#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
  //srand
  srand(time(NULL));

  //vars
  int health = 10;
  int attack = 0;
  int block = 0;
  int turns = 0;

  string input = " ";
  string ignoreInput = " ";

  //start screen loop
  while(true) {
    cout << "Welcome to Adventure!\n\nAre you ready to play? (y or n) ";
    cin >> input;
    if (input == "y" || input == "Y") {
      cout << "\n\nGreat!  Let's get started";
      break;
    }
    else {
      cout << "\n\nWrong answer, please try again\n\n";
    }
  }

  //main game loop
  while(true) {
    turns = 0;
    health = 10;
    cout << "\n\nYou are about to be attacked!  You must survive 4 turns to escape!";
    while(true) {
      turns++;
      cout << "\n\nYou currently have " << health << " health and it is turn " << turns << ". (Enter any character to continue) ";
      cin >> ignoreInput;
      attack = rand() % 4 + 1;
      block = rand() % 4 + 1;
      cout << "\n\nYou block for " << block << " and are attacked for " << attack << "!";

      if (block >= attack) {
        cout << "\n\nSuccessful block!  You take no damage!";
      }
      else {
        cout << "\n\nYour block failed!  You took " << attack << " damage!";
        health = health - attack;
      }

      if (health <= 0) {
        cout << "\n\nYour health reached zero and you failed to escape!";
        break;
      }
      else if (turns == 4 && health > 0) {
        cout << "\n\nYou successfully escaped with " << health << " health!  Congrats!";
        break;
      }
    }

    //play again?
    cout << "\n\nWould you like to play again? (y or n) ";
    cin >> input;
    if (input == "n" || input == "N") {
      cout << "\n\nSee you later!";
      break;
    }
    else if (input == "y" || input == "Y") {
      cout << "\n\nGood luck!";
    }
    else {
      cout << "\n\nInvalid input, exitting game...";
      break;
    }
  }
}