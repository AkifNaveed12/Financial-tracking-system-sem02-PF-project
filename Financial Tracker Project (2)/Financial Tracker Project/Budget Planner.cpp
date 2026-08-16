#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const int MAX_CATEGORIES = 10;

struct Budget {
    string category;
    float budgetAmount;
    float spentAmount;
};

float getValidFloat(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "? Enter a valid non-negative number.\n";
        } else {
            return value;
        }
    }
}


void saveToFile(Budget budgets[], int n) {
    ofstream outFile("budget_data.txt");
    for (int i = 0; i < n; i++) {
        outFile << budgets[i].category << " "
                << budgets[i].budgetAmount << " "
                << budgets[i].spentAmount << endl;
    }
    outFile.close();
    cout << "? Budgets saved.\n";
}


int loadFromFile(Budget budgets[]) {
    ifstream inFile("budget_data.txt");
    int count = 0;
    while (inFile >> budgets[count].category >> budgets[count].budgetAmount >> budgets[count].spentAmount) {
        count++;
    }
    inFile.close();
    return count;
}

void inputBudgets(Budget budgets[], int &n) {
    cout << "How many categories to add? ";
    int addCount;
    cin >> addCount;

    for (int i = n; i < n + addCount; i++) {
        cout << "\nCategory name: ";
        cin >> budgets[i].category;
        budgets[i].budgetAmount = getValidFloat("Budget amount: ");
        budgets[i].spentAmount = getValidFloat("Amount spent: ");
        cout << "Type: Monthly (default)\n";
    }
    n += addCount;
    saveToFile(budgets, n);
}


void displayBudgetStatus(Budget budgets[], int n) {
    cout << "\n--- Monthly Budget Summary ---\n";
    cout << "Category\tBudget\tSpent\tStatus\n";

    for (int i = 0; i < n; i++) {
        float percent = (budgets[i].spentAmount / budgets[i].budgetAmount) * 100;
        cout << budgets[i].category << "\t\t"
             << budgets[i].budgetAmount << "\t"
             << budgets[i].spentAmount << "\t";

        if (percent < 80)
            cout << "Under Budget\n";
        else if (percent <= 100)
            cout << "Near Limit\n";
        else
            cout << "Over Budget\n";
    }
}


void editBudget(Budget budgets[], int n) {
    string cat;
    cout << "Enter category to edit: ";
    cin >> cat;

    int i, flag = 0;
    for (i = 0; i < n; i++) {
        if (budgets[i].category == cat) {
            cout << "New budget amount: ";
            budgets[i].budgetAmount = getValidFloat("");
            cout << "New spent amount: ";
            budgets[i].spentAmount = getValidFloat("");
            cout << "Type: Monthly (default)\n";
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << "? Budget updated.\n";
        saveToFile(budgets, n);
    } else {
        cout << "? Category not found.\n";
    }
}

// The full Budget Planner function to be called from main
void BudgetPlanner() {
    Budget budgets[MAX_CATEGORIES];
    int budgetCount = loadFromFile(budgets);
    int choice;

    do {
        cout << "\n=== Budget Menu ===\n";
        cout << "1. Add Budgets\n";
        cout << "2. View Budget Status\n";
        cout << "3. Edit Budget\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            inputBudgets(budgets, budgetCount);
        else if (choice == 2)
            displayBudgetStatus(budgets, budgetCount);
        else if (choice == 3)
            editBudget(budgets, budgetCount);
        else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            cout << "? Invalid option.\n";
        }

    } while (choice != 4);
}

