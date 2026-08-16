#include <iostream>
#include <iomanip>
using namespace std;


float getExchangeRate(string from, string to) {
    if (from == "PKR" && to == "USD") return 0.0036;
    if (from == "USD" && to == "PKR") return 280.0;
    if (from == "PKR" && to == "EUR") return 0.0032;
    if (from == "EUR" && to == "PKR") return 310.0;
    if (from == "PKR" && to == "GBP") return 0.0027;
    if (from == "GBP" && to == "PKR") return 370.0;
    if (from == to) return 1.0;
    return 0.0;
}

void showSupportedCurrencies() {
    cout << "\nSupported Currencies: PKR, USD, EUR, GBP\n";
}

float convertCurrency(float amount, string from, string to) {
    float rate = getExchangeRate(from, to);
    if (rate == 0.0) {
        cout << "Invalid currency pair.\n";
        return -1;
    }
    return amount * rate;
}

void runCurrencyConverter() {
    string from, to;
    float amount;

    showSupportedCurrencies();
    cout << "\nEnter FROM currency (e.g. PKR): ";
    cin >> from;
    cout << "Enter TO currency (e.g. USD): ";
    cin >> to;
    cout << "Enter amount: ";
    cin >> amount;

    float result = convertCurrency(amount, from, to);

    if (result != -1)
        cout << fixed << setprecision(2) << "\nConverted Amount: " << result << " " << to << endl;
}

int curency() {
    cout << "====== Currency Converter ======\n";
    runCurrencyConverter();
    return 0;
}

