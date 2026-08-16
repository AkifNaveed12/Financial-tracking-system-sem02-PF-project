#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void BillReminder() {
    struct Bill {
        string title;
        int amount;
        int dueDay;
    };

    
    auto getTodayDay = []() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return ltm->tm_mday;
    };

    int n;
    cout << "How many bills do you want to enter? ";
    cin >> n;
    cin.ignore();

    Bill* bills = new Bill[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter title of bill #" << i + 1 << ": ";
        getline(cin, bills[i].title);
        cout << "Enter amount: ";
        cin >> bills[i].amount;
        cout << "Enter due day (1-31): ";
        cin >> bills[i].dueDay;
        while (bills[i].dueDay < 1 || bills[i].dueDay > 31) {
            cout << "? Invalid day! Please enter a valid day (1-31): ";
            cin >> bills[i].dueDay;
        }
        cin.ignore();
    }

    
    ofstream file("bills.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        delete[] bills;
        return;
    }

    file << "Bill Reminder Entries:\n";
    for (int i = 0; i < n; i++) {
        file << "Title: " << bills[i].title
             << " | Amount: " << bills[i].amount
             << " | Due Day: " << bills[i].dueDay << endl;
    }
    file.close();

    
    int today = getTodayDay();
    cout << "\n------------------------------\n";
    cout << "Upcoming Bills (Next 7 Days):\n";
    cout << "------------------------------\n";

    bool anyDue = false;
    for (int i = 0; i < n; i++) {
        if (bills[i].dueDay >= today && bills[i].dueDay <= today + 7) {
            cout << bills[i].title << " - Rs. " << bills[i].amount
                 << " (Due Day: " << bills[i].dueDay << ")\n";
            anyDue = true;
        }
    }

    if (!anyDue) {
        cout << "No bills due in the next 7 days.\n";
    }

    delete[] bills;
}

