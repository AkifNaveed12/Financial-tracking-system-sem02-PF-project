#ifndef TAX_MODULE_H
#define TAX_MODULE_H

#include <iostream>
#include <string>
#include <algorithm>


struct user_info {
    std::string name;
    double age;
    double taxable_income, deductions, annual_income, income_after_tax;
};


void validate_positive(double &value, const std::string &prompt);
void fetch_info(user_info &data);
void calculate_taxable_income(user_info &data);
double calculate_federal_income_tax(user_info &data);
double calculate_fica_tax(user_info &data);
double calculate_ltcg_tax(user_info &data);
void after_tax(user_info &data);
void runTaxModule();

#endif