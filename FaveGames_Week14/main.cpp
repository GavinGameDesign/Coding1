#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string favGame[100];
int index = 0;

ofstream file;

void add() {
  string input;
  
  cout << "\nWhat game would you like to add? ";
  getline(cin, input);

  favGame[index++] = input;
}

void show() {
  int count = 1;
  
  cout << "\nHere are all your favorite games:\n\n";
  
  for(int i = 0; i < index; i++) {
    if(favGame[i] == "") {
      continue;
    }
    cout << count++ << ". " << favGame[i] << endl;
  }
}

void remove() {
  string input;
  
  cout << "\nWhat game would you like to remove? ";

  getline(cin, input);

   for(int i = 0; i < index; i++) {
    if (favGame[i] == input) {
      cout << "\nGame removed.\n";
      favGame[i] = "";
      return;
    }
  }

  cout << "\nGame could not be found.\n";
}

bool edit() {
  string input;
  
  cout << "\nWhat game would you like to replace? ";
  cin >> input;

  for(int i = 0; i < index; i++) {
    if (favGame[i] == input) {
      cout << "\nGame found.  What would you like to replace it with? ";
      getline(cin, input);
      favGame[i] = input;
      cout << "\nReplaced!";
      return true;
    }
  }

  while(true) {
    cout << "\nGame could not be found, try again (y or n)? ";
    cin >> input;
    if(input == "y" || input == "Y") {
      return false;
    }
    else if(input == "n" || input == "N") {
      return true;
    }
  }
}

void load() {
  string line;

  ifstream file("data.txt");

  if(file.is_open()) {
    while(getline(file, line)) {
      favGame[index++] = line;
    }
  }
}

void save() {
  file.open("data.txt");

  for(int i = 0; i < index; i++) {
    file << favGame[i] << "\n";
  }

  file.close();
}

int main() {
  //srand
  srand(time(NULL));

  //vars
  string input = " ";
  
  //code

  load();
  
  while(true) {
    cout << "\n\nWould you like to add to, show, remove, or edit your favorite games? Or type quit to quit. ";
    cin >> input;

    if (input == "Add" || input == "add") {
      add();
    }
    else if (input == "Show" || input == "show") {
      show();
    }
    else if (input == "Edit" || input == "edit") {
      while(true) {
        if(edit()) {
          break;
        }
      }
    }
    else if (input == "Remove" || input == "remove") {
      remove();
    }
    else if (input == "Quit" || input == "quit") {
      cout << "\nSee you later!";
      break;
    }
    else {
      cout << "\nInvalid input, try again";
    }
  }

  save();
}