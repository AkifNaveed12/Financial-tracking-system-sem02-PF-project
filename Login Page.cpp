#include <iostream>
#include <fstream>
#include <string>
#include "tax_module.h"
#include "advisory_module.h"

using namespace std;

void signUp() {
    string username, password;
    cout << "\n--- Sign Up ---\n";
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ifstream readFile("users.txt");
    string existingUser, existingPass;
    bool exists = false;
    while (readFile >> existingUser >> existingPass) {
        if (existingUser == username) {
            exists = true;
            break;
        }
    }
    readFile.close();

    if (exists) {
        cout << "Username already exists. Please choose another one.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Sign up successful!\n";
}

bool login() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string savedUser, savedPass;
    bool found = false;
    while (file >> savedUser >> savedPass) {
        if (username == savedUser && password == savedPass) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << "!\n";
        return true;
    } else {
        cout << "Login failed. Username or password is incorrect.\n";
        return false;
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout << "\n--- Module Menu ---\n";
        cout << "1. Tax Management Module\n";
        cout << "2. Financial Advisory Module\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            runTaxModule(); 
        } else if (choice == 2) {
            runAdvisoryModule(); 
        } else if (choice == 0) {
            cout << "Logged out.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            signUp();
        } else if (choice == 2) {
            if (login()) {
                mainMenu();
            }
        } else if (choice == 0) {
            cout << "Exiting... Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

