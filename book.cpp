#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void historySection() {

    ifstream file("history.txt");

    string line;

    cout << "\n= History of C++ =\n\n";

    if(file.is_open()) {

        while(getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    else {
        cout << "File could not be opened.\n";
    }
}

void learnCPP() {

    int choice;

    do {

        cout << "\n= Learn C++ =\n";
        cout << "1. Data Types\n";
        cout << "2. Loops\n";
        cout << "3. Arrays\n";
        cout << "4. Conditions\n";
        cout << "0. Back\n";

        cout << "Choose : ";
        cin >> choice;

        switch(choice) {

            case 1:

                cout << "\nData Types:\n";
                cout << "int -> Integer\n";
                cout << "float -> Decimal\n";
                cout << "char -> Character\n";
                cout << "string -> Text\n";

                break;

            case 2:

                cout << "\nLoops Example:\n";
                cout << "for(int i=0; i<5; i++)\n";

                break;

            case 3:

                cout << "\nArrays Example:\n";
                cout << "int arr[5] = {1,2,3,4,5};\n";

                break;

            case 4:

                cout << "\nConditions Example:\n";
                cout << "if(condition)\n";
                cout << "else\n";

                break;

            case 0:
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 0);
}

int main() {

    int choice;

    do {

        cout << "\n= BOOK SYSTEM =\n";
        cout << "1. History of C++\n";
        cout << "2. Learn About C++\n";
        cout << "0. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice) {

            case 1:
                historySection();
                break;

            case 2:
                learnCPP();
                break;

            case 0:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 0);

    return 0;
}