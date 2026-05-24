#include <iostream>
using namespace std;

// function
float totalMarks(float m[]) {

    float total = 0;

    for(int i = 0; i < 3; i++) {
        total += m[i];
    }

    return total;
}

int main() {

    string name;
    float marks[3], total, avg;
    char again;

    do {

        cout << "Enter name: ";
        cin >> name;

        for(int i = 0; i < 3; i++) {
            cout << "Enter mark " << i + 1 << ": ";
            cin >> marks[i];
        }

        total = totalMarks(marks);
        avg = total / 3;

        cout << "\nTotal = " << total << endl;
        cout << "Average = " << avg << endl;

        if(avg >= 50)
            cout << "Pass\n";
        else
            cout << "Fail\n";

        cout << "\nAnother student? (y/n): ";
        cin >> again;

    } while(again == 'y');

    return 0;
}