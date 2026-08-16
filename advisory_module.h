#ifndef ADVISORY_MODULE_H
#define ADVISORY_MODULE_H

#include <iostream>
#include <string>
#include <algorithm>

// Declare structures
struct vehicle {
    std::string model;
    int year;
};

struct userfinancialdata {
    bool permission;
    float cash, monthly_income, monthly_expenses;
    std::string real_estate;
    vehicle vehicles[3]; 
    int vehicle_num;
    int childern_no;
    int childern_age[10];  
    float education_exp, cc_debt, cc_intrest_rate;
};

// Declare all public functions
bool get_permission();
void validate_positive(float &value, const std::string &prompt);
void input_financial_data(userfinancialdata &data);
bool check_essential_expenses(const userfinancialdata &data);
bool check_emergency_fund(const userfinancialdata &data);
bool has_high_interest_debt(const userfinancialdata &data);
void educational_planning(const userfinancialdata &data);
void vehicle_recommendations(const userfinancialdata &data);
void generate_advice(const userfinancialdata &data);
void runAdvisoryModule();

#endif