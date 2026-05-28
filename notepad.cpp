#include "notepad.h"

void writeFile(string filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Could not create the file." << endl;
        return;
    }
    cout << "Type lines. Type END to stop:" << endl;
    string line;
    getline(cin, line);
    while (line != "END") {
        outFile << line << endl;
        getline(cin, line);
    }
    outFile.close();
    cout << "File saved: " << filename << endl;
}

void readFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: File not found." << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void appendFile(string filename) {
    fstream appFile(filename, ios::app);
    if (!appFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    cout << "Type lines. Type END to stop:" << endl;
    string line;
    getline(cin, line);
    while (line != "END") {
        appFile << line << endl;
        getline(cin, line);
    }
    appFile.close();
    cout << "Text appended to: " << filename << endl;
}