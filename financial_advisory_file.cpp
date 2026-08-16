#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<iomanip>
#include<algorithm>  

using namespace std;






bool get_permission() {
    char input;
    cout << "Grant permission to access financial data?\n'y'/'Y' for YES and 'n'/'N' for NO: ";
    cin >> input;
    bool granted = (toupper(input) == 'Y');
    cout << (granted ? "Permission granted" : "Permission denied") << endl;
    return granted;
}


void validate_positive(float &value, const string &prompt) {
    while (true) {
        cout << prompt;
        cin >> value;
        if (value >= 0) break;
        cout << "Invalid input! Please enter a non-negative value.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}


void input_financial_data(userfinancialdata &data) {
    validate_positive(data.monthly_expenses, "Please enter the monthly expenses: ");
    validate_positive(data.monthly_income, "Please enter the monthly income: ");
    validate_positive(data.cash, "Please enter your cash reserves: ");

    cout << "Enter number of vehicles (max 3): ";
    cin >> data.vehicle_num;
    data.vehicle_num = min(data.vehicle_num, 3);

    for (int i = 0; i < data.vehicle_num; i++) {
        cout << "Vehicle " << i + 1 << " Model: ";
        cin >> data.vehicles[i].model;
        cout << "Year of vehicle: ";
        cin >> data.vehicles[i].year;
    }

    cout << "Enter number of children (max 10): ";
    cin >> data.childern_no;
    data.childern_no = min(data.childern_no, 10);

    if (data.childern_no > 0) {
        for (int i = 0; i < data.childern_no; i++) {
            cout << "Enter age of child " << i + 1 << ": ";
            cin >> data.childern_age[i];
        }
        validate_positive(data.education_exp, "Enter current monthly education expense: ");
    }

    validate_positive(data.cc_debt, "Enter credit card debt: ");
    if (data.cc_debt > 0) {
        validate_positive(data.cc_intrest_rate, "Enter credit card interest rate: ");
    }
}


bool check_essential_expenses(const userfinancialdata &data) {
    return data.monthly_income >= (data.monthly_expenses * 0.7);
}

bool check_emergency_fund(const userfinancialdata &data) {
    return data.cash >= (data.monthly_expenses * 3);
}

bool has_high_interest_debt(const userfinancialdata &data) {
    return data.cc_debt > 0 && data.cc_intrest_rate > 7.0;
}


void educational_planning(const userfinancialdata &data) {
    for (int i = 0; i < data.childern_no; i++) {
        int years_to_college = 18 - data.childern_age[i];
        if (years_to_college > 0) {
            float required = (years_to_college * 12) * 1000;
            cout << "?? For child " << i + 1 << ": Save Rs. " << required / 12
                 << " per month for college.\n";
        }
    }
}

void vehicle_recommendations(const userfinancialdata &data) {
    for (int i = 0; i < data.vehicle_num; i++) {
        if (2025 - data.vehicles[i].year > 10) {
            cout << "?? Consider replacing " << data.vehicles[i].model
                 << " (over 10 years old).\n";
        }
    }
}

void generate_advice(const userfinancialdata &data) {
    cout << "\n-------------------- FINANCIAL ADVISORY REPORT --------------------\n";

    if (!check_essential_expenses(data)) {
        cout << "[Priority 1] Reduce your expenses by Rs. "
             << (data.monthly_expenses - data.monthly_income)
             << " to meet essential needs.\n";
        return;
    }

    if (!check_emergency_fund(data)) {
        float needed = data.monthly_expenses * 6 - data.cash;
        cout << "[Priority 2] Build emergency funds. Save Rs. " << needed << " more.\n";
    }

    if (has_high_interest_debt(data)) {
        cout << "[Priority 3] Pay off your high-interest debt (" << data.cc_intrest_rate
             << "% APR) before investing.\n";
        return;
    }

    if (data.childern_no > 0) {
        educational_planning(data);
    } else {
        cout << "[RETIREMENT] Invest 15% of income: Rs. " << data.monthly_income * 0.15
             << " into retirement accounts.\n";
    }

    vehicle_recommendations(data);
}


void runAdvisoryModule() {
    userfinancialdata data;
    data.permission = get_permission();

    if (!data.permission) {
        cout << "Access denied. Exiting...\n";
        return 0;
    }

    input_financial_data(data);
    generate_advice(data);

    return 0;
}
