#include <iostream>
#include <string>
using namespace std;

int main() {
    const int DEFAULT_PIN = 12345;
    int pin;
    int attempts = 3;
    int choice;
    int balance = 0;
    int amount;

    string history[100];
    int historyCount = 0;

    cout << "= ATM SYSTEM =" << endl;

    // Login process
    while (attempts > 0) {
        cout << "Enter PIN: ";
        cin >> pin;

        if (pin == DEFAULT_PIN) {
            cout << "Login Successful!" << endl;
            break;
        } else {
            attempts--;
            cout << "Wrong PIN. Attempts left: " << attempts << endl;
        }
    }

    if (attempts == 0) {
        cout << "ATM Blocked!" << endl;
        return 0;
    }

    // Main menu
    do {
        cout << "\n= MENU =" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current Balance: " << balance << endl;
                break;

            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount > 0) {
                    balance += amount;
                    history[historyCount++] = "Deposited: " + to_string(amount);
                    cout << "Amount deposited successfully!" << endl;
                } else {
                    cout << "Invalid amount entered. Please try again." << endl;
                }
                break;

            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount <= balance && amount > 0) {
                    balance -= amount;
                    history[historyCount++] = "Withdrew: " + to_string(amount);
                    cout << "Withdrawal successful!" << endl;
                } else if (amount > balance) {
                    cout << "Insufficient funds!" << endl;
                } else {
                    cout << "Invalid amount entered. Please try again." << endl;
                }
                break;

            case 4:
                if (historyCount == 0) {
                    cout << "\nNo transactions recorded yet." << endl;
                } else {
                    cout << "\n- TRANSACTION HISTORY -" << endl;
                    for (int i = 0; i < historyCount; i++) {
                        cout << history[i] << endl;
                    }
                }
                break;

            case 5:
                cout << "Thank you for using the ATM System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}