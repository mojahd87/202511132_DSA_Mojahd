// Name: Mojahd Omar
// Course: Data Structure
// Assignment 2

#include <iostream>
using namespace std;

// function to calculate total
float calcTotal(float marks[]) {

    float total = 0;

    for(int i = 0; i < 3; i++) {
        total = total + marks[i];
    }

    return total;
}

int main() {

    string name;
    float marks[3];

    char choice;

    do {

        cout << "Enter student name: ";
        cin >> name;

        // input marks
        for(int i = 0; i < 3; i++) {

            cout << "Enter mark " << i + 1 << ": ";
            cin >> marks[i];
        }

        // calculations
        float total = calcTotal(marks);
        float average = total / 3;

        // output
        cout << "\nStudent Name: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average: " << average << endl;

        // pass or fail
        if(average >= 50) {
            cout << "Result: Pass" << endl;
        }
        else {
            cout << "Result: Fail" << endl;
        }

        // loop
        cout << "\nDo you want to enter another student? (y/n): ";
        cin >> choice;

        cout << endl;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}