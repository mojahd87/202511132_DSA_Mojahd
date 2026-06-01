#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Student {
public:
    string rollNumber;
    string name;
    int age;
};

vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("student.txt");

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;

        getline(ss, s.rollNumber, ',');
        getline(ss, s.name, ',');

        string ageStr;
        getline(ss, ageStr, ',');
        s.age = stoi(ageStr);

        students.push_back(s);
    }

    file.close();
    return students;
}

void saveStudents(vector<Student>& students) {
    ofstream file("student.txt");

    for (auto& s : students) {
        file << s.rollNumber << ","
             << s.name << ","
             << s.age << endl;
    }

    file.close();
}

void displayStudents() {
    vector<Student> students = loadStudents();

    cout << "\nStudent Records\n";

    for (auto& s : students) {
        cout << "Roll Number: " << s.rollNumber
             << "\nName: " << s.name
             << "\nAge: " << s.age
             << "\n--\n";
    }
}

void searchStudent() {
    vector<Student> students = loadStudents();

    string roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    bool found = false;

    for (auto& s : students) {
        if (s.rollNumber == roll) {
            cout << "\nStudent Found\n";
            cout << "Roll Number: " << s.rollNumber << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found\n";
    }
}

void updateStudent() {
    vector<Student> students = loadStudents();

    string roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;

    bool found = false;

    for (auto& s : students) {
        if (s.rollNumber == roll) {
            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            found = true;
            break;
        }
    }

    if (found) {
        saveStudents(students);
        cout << "Student updated successfully\n";
    }
    else {
        cout << "Student not found\n";
    }
}

void deleteStudent() {
    vector<Student> students = loadStudents();
    vector<Student> updatedList;

    string roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    bool found = false;

    for (auto& s : students) {
        if (s.rollNumber == roll) {
            found = true;
        }
        else {
            updatedList.push_back(s);
        }
    }

    if (found) {
        saveStudents(updatedList);
        cout << "Student deleted successfully\n";
    }
    else {
        cout << "Student not found\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n= MENU =\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayStudents();
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}