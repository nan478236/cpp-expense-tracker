
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Expense {
    double amount;
    string category;
    string description;
};

Expense expenses[100];
int count = 0;

// Function to add expense
void addExpense() {

    if (count >= 100) {
        cout << "Expense limit reached!" << endl;
        return;
    }

    string input;

    cout << "Enter amount: ";

    while (true) {
        getline(cin, input);
        stringstream ss(input);

        double amount;
        char extra;

        if (ss >> amount && !(ss >> extra) && amount > 0) {
            expenses[count].amount = amount;
            break;
        }

        cout << "Invalid amount! Enter a positive number: ";
    }

    cout << "Enter category: ";
    getline(cin, expenses[count].category);

    while (expenses[count].category.find_first_not_of(" \t") == string::npos) {
        cout << "Category cannot be empty. Enter again: ";
        getline(cin, expenses[count].category);
    }

    cout << "Enter description: ";
    getline(cin, expenses[count].description);

    count++;

    cout << "Expense added successfully!" << endl;
}

// Function to list expenses
void listExpenses() {

    if (count == 0) {
        cout << "No expenses recorded!" << endl;
        return;
    }

    cout << "\n===== ALL EXPENSES =====\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        cout << expenses[i].category << " - Rs. ";
        cout << expenses[i].amount << " - ";
        cout << expenses[i].description << endl;
    }
}

// Function to calculate category total
void categoryTotal() {

    string searchCategory;
    double total = 0;

    cout << "Enter category: ";
    getline(cin, searchCategory);

    for (int i = 0; i < count; i++) {
        if (expenses[i].category == searchCategory) {
            total = total + expenses[i].amount;
        }
    }

    cout << "Total spent on " << searchCategory
         << ": Rs. " << total << endl;
}

// Function to calculate overall total
void overallTotal() {

    double total = 0;

    for (int i = 0; i < count; i++) {
        total = total + expenses[i].amount;
    }

    cout << "Overall Expense: Rs. " << total << endl;
}

// Main function
int main() {

    int choice = 0;
    string input;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. List All Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        getline(cin, input);

        stringstream ss(input);
        char extra;

        if (!(ss >> choice) || (ss >> extra)) {
            cout << "Invalid input! Enter a number.\n";
            choice = 0;
            continue;
        }

        switch (choice) {

            case 1:
                addExpense();
                break;

            case 2:
                listExpenses();
                break;

            case 3:
                categoryTotal();
                break;

            case 4:
                overallTotal();
                break;

            case 5:
                cout << "Thank you for using Expense Tracker!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
