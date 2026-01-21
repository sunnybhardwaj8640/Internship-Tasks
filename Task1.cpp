#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>     
using namespace std;

void createFile() {
    string filename;
    cout << "Enter file name to create (with .txt): ";
    cin >> filename;

    ofstream file(filename);
    if (!file) {
        cout << "Error creating the file!" << endl;
        return;
    }

    cout << "Enter text to write into the file: ";
    cin.ignore();
    string content;
    getline(cin, content);

    file << content;
    file.close();
    cout << "File created and text saved successfully.\n";
}

void readFile() {
    string filename;
    cout << "Enter file name to read: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "File does not exist!" << endl;
        return;
    }

    cout << "\n--- File Content ---\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    cout << "---------------------\n";

    file.close();
}

void deleteFile() {
    string filename;
    cout << "Enter file name to delete: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Unable to delete the file. File may not exist.\n";
    }
}

int main() {
    int choice;

    cout << "====== SIMPLE FILE SYSTEM SIMULATOR ======\n";

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Create File\n";
        cout << "2. Read File\n";
        cout << "3. Delete File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: deleteFile(); break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
