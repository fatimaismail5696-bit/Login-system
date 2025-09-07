#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string DATABASE_FILE = "users.txt";

void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "? Username and password cannot be empty.\n";
        return;
    }

    // Check for duplicate
    ifstream infile(DATABASE_FILE.c_str());
    string u, p;
    while (infile >> u >> p) {
        if (u == username) {
            cout << "? Username already exists!\n";
            infile.close();
            return;
        }
    }
    infile.close();

    // Save new user
    ofstream outfile(DATABASE_FILE.c_str(), ios::app);
    outfile << username << " " << password << "\n";
    outfile.close();
    cout << "? Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile(DATABASE_FILE.c_str());
    string u, p;
    bool found = false;
    while (infile >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "? Login successful!\n";
    else
        cout << "? Invalid username or password.\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}





