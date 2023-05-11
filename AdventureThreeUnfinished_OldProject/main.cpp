#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*Use this to wait for player input:
        cout << "\nEnter anything to continue ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ignoreInput; */


//displayHealth(Character1.health, Character2.health, Character3.health, Character1.name, Character2.name, Character3.name, EHealth1, EHealth2, EHealth3);
void displayHealth(int A, int B, int C, string name1, string name2, string name3, int D, int E, int F) {
    cout << "\n" << name1 << "'s Health: " << A;
    cout << "\n" << name2 << "'s Health: " << B;
    cout << "\n" << name3 << "'s Health: " << C;
    cout << "\nEnemy 1 Health: " << D;
    cout << "\nEnemy 2 Health: " << E;
    cout << "\nEnemy 3 Health: " << F;
}

int characterAttack(int maxAttack, int minAttack, int randDamage, int damage, int EHealth, int enemy, string CName) {
    randDamage = maxAttack - minAttack + 1;
    damage = rand() % randDamage + minAttack;
    EHealth = EHealth - damage;
    cout << CName << " attacks Enemy " << enemy << " for " << damage << " damage!\n";
    return EHealth;
}

int enemyAttack(int enemy, int minAttack, int maxAttack, int randDamage, int damage, int CHealth, string CName) {
    randDamage = maxAttack - minAttack + 1;
    damage = rand() % randDamage + minAttack;
    CHealth = CHealth - damage;
    cout << "Enemy " << enemy << " attacks " << CName << " for " << damage << " damage!\n";
    return CHealth;
}

bool inputTester(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

class Character {
public:
    int health;
    string name;
    string weaponName;
    int minDamage;
    int maxDamage;
    int protectionPercent;  //Research this
    Character(int x, string y, string z, int a, int b) {
        health = x;
        name = y;
        weaponName = z;
        minDamage = a;
        maxDamage = b;
    }
};


int main() {
    //srand
    srand(time(NULL));
    //Variables
    int EHealth1;
    int EHealth2;
    int EHealth3;
    int EAttack;
    string input;
    int inputInt;
    string ignoreInput;

    //Character 1 is created
    cout << "Welcome to Adventure Three!\nLet's get some things out of the way before we start.\n\nWhat is the name of your first adventurer? ";
    Character Character1(100, " ", "Wooden Sword", 5, 7);
    cin >> Character1.name;
    cout << "\nGood ol' " << Character1.name << " here will weild a Wooden Sword for now.  It deals 5-7 damage (Enter anything to continue) ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> ignoreInput;
    //Character 2 is created
    cout << "\nWhat is the name of the second adventurer? ";
    Character Character2(100, " ", "Wooden Bow", 7, 10);
    cin >> Character2.name;
    cout << "\n" << Character2.name << " will have a Wooden Bow that deals 7-10 damage (Enter anything to continue) ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> ignoreInput;
    //Character 3 is created
    cout << "\nWhat is the name of the third adventurer? ";
    Character Character3(100, " ", "Wooden Wand", 5, 9);
    cin >> Character3.name;
    cout << "\n" << Character3.name << " has a Wooden Wand which deals 5-9 damage (Enter anything to continue) ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> ignoreInput;


    //Code
    cout << "\nTesting Battle 1\n";
    EHealth1 = rand() % 6 + 15;
    EHealth2 = rand() % 6 + 15;
    EHealth3 = rand() % 6 + 15;

    //Battle 1
    while (EHealth1 >= 0 or EHealth2 >= 0 or EHealth3 >= 0) {
        displayHealth(Character1.health, Character2.health, Character3.health, Character1.name, Character2.name, Character3.name, EHealth1, EHealth2, EHealth3);
        
        //Character 1 Attacks
        while (true) {
            cout << "\n\n" << Character1.name << " weilds a " << Character1.weaponName << " (" << Character1.minDamage << "-" << Character1.maxDamage << " damage). Which Enemy is " << Character1.name << " attacking? ";
            cin >> input;
            if (inputTester(input)) {
                inputInt = stoi(input);
                if (inputInt == 1 and EHealth1 > 0) {
                    EHealth1 = characterAttack(Character1.maxDamage, Character1.minDamage, 0, 0, EHealth1, 1, Character1.name);
                    if (EHealth1 < 0) {
                        EHealth1 = 0;
                        cout << "Enemy 1 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 1) {
                    cout << "\nEnemy 1 is already down!\n";
                }
                else if (inputInt == 2 and EHealth2 > 0) {
                    EHealth2 = characterAttack(Character1.maxDamage, Character1.minDamage, 0, 0, EHealth2, 2, Character1.name);
                    if (EHealth2 < 0) {
                        EHealth2 = 0;
                        cout << "Enemy 2 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 2) {
                    cout << "\nEnemy 2 is already down!\n";
                }
                else if (inputInt == 3 and EHealth3 > 0) {
                    EHealth3 = characterAttack(Character1.maxDamage, Character1.minDamage, 0, 0, EHealth3, 3, Character1.name);
                    if (EHealth3 < 0) {
                        EHealth3 = 0;
                        cout << "Enemy 3 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 3) {
                    cout << "\nEnemy 3 is already down!\n";
                }
                else {
                    cout << "Number must be between 1 and 3!";
                }
            }
            else {
                cout << "\nWhat you entered is not valid! You must enter a number between 1 and 3";
            }
        }
        
        cout << "\nEnter anything to continue ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ignoreInput;
        
        if (EHealth1 <= 0 and EHealth2 <= 0 and EHealth3 <= 0) {
            break;
        }
        
        displayHealth(Character1.health, Character2.health, Character3.health, Character1.name, Character2.name, Character3.name, EHealth1, EHealth2, EHealth3);
        
        //Character 2 Attacks
        while (true) {
            cout << "\n\n" << Character2.name << " weilds a " << Character2.weaponName << " (" << Character2.minDamage << "-" << Character2.maxDamage << " damage). Which Enemy is " << Character2.name << " attacking? ";
            cin >> input;
            if (inputTester(input)) {
                inputInt = stoi(input);
                if (inputInt == 1 and EHealth1 > 0) {
                    EHealth1 = characterAttack(Character2.maxDamage, Character2.minDamage, 0, 0, EHealth1, 1, Character2.name);
                    if (EHealth1 < 0) {
                        EHealth1 = 0;
                        cout << "Enemy 1 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 1) {
                    cout << "\nEnemy 1 is already down!\n";
                }
                else if (inputInt == 2 and EHealth2 > 0) {
                    EHealth2 = characterAttack(Character2.maxDamage, Character2.minDamage, 0, 0, EHealth2, 2, Character2.name);
                    if (EHealth2 < 0) {
                        EHealth2 = 0;
                        cout << "Enemy 2 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 2) {
                    cout << "\nEnemy 2 is already down!\n";
                }
                else if (inputInt == 3 and EHealth3 > 0) {
                    EHealth3 = characterAttack(Character2.maxDamage, Character2.minDamage, 0, 0, EHealth3, 3, Character2.name);
                    if (EHealth3 < 0) {
                        EHealth3 = 0;
                        cout << "Enemy 3 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 3) {
                    cout << "\nEnemy 3 is already down!\n";
                }
                else {
                    cout << "Number must be between 1 and 3!";
                }
            }
            else {
                cout << "\nWhat you entered is not valid! You must enter a number between 1 and 3";
            }
        }
        
        cout << "\nEnter anything to continue ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ignoreInput;
        
        if (EHealth1 <= 0 and EHealth2 <= 0 and EHealth3 <= 0) {
            break;
        }
        
        displayHealth(Character1.health, Character2.health, Character3.health, Character1.name, Character2.name, Character3.name, EHealth1, EHealth2, EHealth3);
        
        //Character 3 Attacks
        while (true) {
            cout << "\n\n" << Character3.name << " weilds a " << Character3.weaponName << " (" << Character3.minDamage << "-" << Character3.maxDamage << " damage). Which Enemy is " << Character3.name << " attacking? ";
            cin >> input;
            if (inputTester(input)) {
                inputInt = stoi(input);
                if (inputInt == 1 and EHealth1 > 0) {
                    EHealth1 = characterAttack(Character3.maxDamage, Character3.minDamage, 0, 0, EHealth1, 1, Character3.name);
                    if (EHealth1 < 0) {
                        EHealth1 = 0;
                        cout << "Enemy 1 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 1) {
                    cout << "\nEnemy 1 is already down!\n";
                }
                else if (inputInt == 2 and EHealth2 > 0) {
                    EHealth2 = characterAttack(Character3.maxDamage, Character3.minDamage, 0, 0, EHealth2, 2, Character3.name);
                    if (EHealth2 < 0) {
                        EHealth2 = 0;
                        cout << "Enemy 2 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 2) {
                    cout << "\nEnemy 2 is already down!\n";
                }
                else if (inputInt == 3 and EHealth3 > 0) {
                    EHealth3 = characterAttack(Character3.maxDamage, Character3.minDamage, 0, 0, EHealth3, 3, Character3.name);
                    if (EHealth3 < 0) {
                        EHealth3 = 0;
                        cout << "Enemy 3 is downed!\n";
                    }
                    break;
                }
                else if (inputInt == 3) {
                    cout << "\nEnemy 3 is already down!\n";
                }
                else {
                    cout << "Number must be between 1 and 3!";
                }
            }
            else {
                cout << "\nWhat you entered is not valid! You must enter a number between 1 and 3";
            }
        }
        
        cout << "\nEnter anything to continue ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ignoreInput;
        cout << "\n";
        
        if (EHealth1 <= 0 and EHealth2 <= 0 and EHealth3 <= 0) {
            break;
        }
        
        //Enemy 1 Attacks
        if (EHealth1 > 0) {
            while(true) {
                EAttack = rand() % 3 + 1;
                if (EAttack == 1 and Character1.health > 0) {
                    Character1.health = enemyAttack(1, 2, 5, 0, 0, Character1.health, Character1.name);
                    break;
                }
                if (EAttack == 2 and Character2.health > 0) {
                    Character2.health = enemyAttack(1, 2, 5, 0, 0, Character2.health, Character2.name);
                    break;
                }
                if (EAttack == 3 and Character3.health > 0) {
                    Character3.health = enemyAttack(1, 2, 5, 0, 0, Character3.health, Character3.name);
                    break;
                }
            }
        }
        
        //Enemy 2 Attacks
        if (EHealth2 > 0) {
            while(true) {
                EAttack = rand() % 3 + 1;
                if (EAttack == 1 and Character1.health > 0) {
                    Character1.health = enemyAttack(2, 2, 5, 0, 0, Character1.health, Character1.name);
                    break;
                }
                if (EAttack == 2 and Character2.health > 0) {
                    Character2.health = enemyAttack(2, 2, 5, 0, 0, Character2.health, Character2.name);
                    break;
                }
                if (EAttack == 3 and Character3.health > 0) {
                    Character3.health = enemyAttack(2, 2, 5, 0, 0, Character3.health, Character3.name);
                    break;
                }
            }
        }
        
        //Enemy 3 Attacks
        if (EHealth3 > 0) {
            while(true) {
                EAttack = rand() % 3 + 1;
                if (EAttack == 1 and Character1.health > 0) {
                    Character1.health = enemyAttack(3, 2, 5, 0, 0, Character1.health, Character1.name);
                    break;
                }
                if (EAttack == 2 and Character2.health > 0) {
                    Character2.health = enemyAttack(3, 2, 5, 0, 0, Character2.health, Character2.name);
                    break;
                }
                if (EAttack == 3 and Character3.health > 0) {
                    Character3.health = enemyAttack(3, 2, 5, 0, 0, Character3.health, Character3.name);
                    break;
                }
            }
        }
        
        cout << "\nEnter anything to continue ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ignoreInput;
    }
    cout << "\nBattle Complete! Final Results: ";
    displayHealth(Character1.health, Character2.health, Character3.health, Character1.name, Character2.name, Character3.name, EHealth1, EHealth2, EHealth3);
    
    cout << "\nEnter anything to continue ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> ignoreInput;
    
    cout << "\n\nYou won your first battle! You earned a chest that will contain some equipment";
    

}

