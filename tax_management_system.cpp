#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<iomanip>

using namespace std;

void validate_positive(double &value, const string &prompt) {
    while (true) {
        cout << prompt;
        cin >> value;
        if (value >= 0) {
        	break;
		}
        cout << "Invalid input! Please enter a non-negative value.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}



void fetch_info(user_info &data){
	system("cls");
	char ch;
	cout<<"Please enter your Name : "<<endl;
	cin.ignore();
	getline(cin, data.name);
	
	validate_positive(data.age,"Please enter your age : ");
	validate_positive(data.annual_income,"Please enter your annual income : ");
	
	cout<<"\n\n --------Deductions Calculations--------\n Please enter your filig type : "<<endl;
	cout<<"\n1. 's' for single.\n2. 'h' for household head.\n3. 'm' for married. "<<endl;
	cin>>ch;
	if(!(ch == 's'|| ch == 'S'|| ch == 'h'|| ch == 'H'|| ch == 'm'|| ch == 'M')){
		cout << "Invalid input! Please enter a valid character.\n";
        cin.clear();
        cin.ignore(1000, '\n');
	}
	if(ch == 's'|| ch =='S'){
		data.deductions = 13850;
	}
	else if(ch == 'M' || ch =='m'){
		data.deductions = 27700;
	}
	else{
		data.deductions = 20800;
	}
}

void calculate_taxable_income(user_info &data){
	data.taxable_income = data.annual_income - data.deductions;
}

double calculate_federal_income_tax(user_info &data){
	system("cls");
	char ch;
	int tax_rate;
	double federal_tax = 0;

	cout<<"Please enter your filing type!"<<endl;
	cout<<"\n1. 's' for single.\n2. 'h' for household head.\n3. 'm' for married. "<<endl;
	cin>>ch;
	if(!(ch == 's'|| ch == 'S'|| ch == 'h'|| ch == 'H'|| ch == 'm'|| ch == 'M')){
		cout << "Invalid input! Please enter a valid character.\n";
        cin.clear();
        cin.ignore(1000, '\n');
		return 0;
	}
	
	if(ch == 's' || ch =='S'){
		if(data.taxable_income >=0 && data.taxable_income<=11000){
			tax_rate=10;
			federal_tax= data.taxable_income * 0.1;
		}
		else if (data.taxable_income <=44725){
			tax_rate=12;
			federal_tax= data.taxable_income * 0.12;
		}
		else if (data.taxable_income <=95375){
			tax_rate=22;
			federal_tax= data.taxable_income * 0.22;
		}
		else if (data.taxable_income <=182100){
			tax_rate=24;
			federal_tax= data.taxable_income * 0.24;
	    }
	    else if (data.taxable_income <=231250){
			tax_rate=32;
			federal_tax= data.taxable_income * 0.32;
		}
		else if (data.taxable_income <=578125){
			tax_rate=35;
			federal_tax= data.taxable_income * 0.35;
		}
		else{
			tax_rate=37;
			federal_tax= data.taxable_income * 0.37;
		}
	}
	else if(ch == 'M' || ch =='m'){
		if(data.taxable_income >=0 && data.taxable_income<=22000){
			tax_rate=10;
			federal_tax= data.taxable_income * 0.1;
		}
		else if (data.taxable_income <=89450){
			tax_rate=12;
			federal_tax= data.taxable_income * 0.12;
		}
		else if (data.taxable_income <=190750){
			tax_rate=22;
			federal_tax= data.taxable_income * 0.22;
		}
		else if (data.taxable_income <=364200){
			tax_rate=24;
			federal_tax= data.taxable_income * 0.24;
	    }
	    else if (data.taxable_income <=462500){
			tax_rate=32;
			federal_tax= data.taxable_income * 0.32;
		}
		else if (data.taxable_income <=693750){
			tax_rate=35;
			federal_tax= data.taxable_income * 0.35;
		}
		else{
			tax_rate=37;
			federal_tax= data.taxable_income * 0.37;
		}
	}
	else{
		if(data.taxable_income >=0 && data.taxable_income<=15700){
			tax_rate=10;
			federal_tax= data.taxable_income * 0.1;
		}
		else if (data.taxable_income <=59850){
			tax_rate=12;
			federal_tax= data.taxable_income * 0.12;
		}
		else if (data.taxable_income <=95350){
			tax_rate=22;
			federal_tax= data.taxable_income * 0.22;
		}
		else if (data.taxable_income <=182100){
			tax_rate=24;
			federal_tax= data.taxable_income * 0.24;
	    }
	    else if (data.taxable_income <=231250){
			tax_rate=32;
			federal_tax= data.taxable_income * 0.32;
		}
		else if (data.taxable_income <=578100){
			tax_rate=35;
			federal_tax= data.taxable_income * 0.35;
		}
		else{
			tax_rate=37;
			federal_tax= data.taxable_income * 0.37;
		}
	}

	cout<<"Your FEDERAL INCOME TAX on your annual income of Rs."<<data.annual_income<<" with "<<tax_rate<<"% TAX RATE is Rs."<<federal_tax<<endl;
	return federal_tax;
}

double calculate_fica_tax(user_info &data){
	system("cls");
	cout<<"----------FICA TAXES----------"<<endl;
	cout<<"\nTax Type\t\tRate"<<endl;	
    cout<<"\n1.Social Security  \t6.2%"<<endl;
    cout<<"\n2.Medicare            \t1.45%"<<endl;
    cout<<"\n3.Additional Medicare \t0.9% (Income > $200k single / $250k married)"<<endl;

    double fica_ss = min(data.taxable_income, 160200.0) * 0.062;
    double fica_mc = data.taxable_income * 0.0145;
    double fica_amc = 0;

    char ch;
	cout<<"\nAre you Single or Married? \n please enter 's' for single or 'm' for married."<<endl;
    cin>>ch;

    if(ch == 's' || ch == 'S'){
	    if(data.taxable_income >= 200000 ){
		   fica_amc= (data.taxable_income - 200000) * 0.009;
	    }
    }
    else if(ch == 'm' || ch == 'M'){
	    if(data.taxable_income >= 250000 ){
		   fica_amc= (data.taxable_income - 250000) * 0.009;
	    }
    }

	double fica_tax = fica_amc + fica_mc + fica_ss;
	system("cls");
	cout<<"\n----------------TOTAL FICA TAX----------------\n";
	cout<<"Total FICA TAX on your annual income of Rs."<<data.annual_income<<" with all applicable tax types is Rs."<<fica_tax<<endl;
	return fica_tax;
}

double calculate_ltcg_tax(user_info &data){
	system("cls");
	char ch;
	double ltcst;
	double tax_rate = 0;
	cout<<"Please enter your filing type!"<<endl;
	cout<<"\n1. 's' for single.\n2. 'h' for household head.\n3. 'm' for married. "<<endl;
	cin>>ch;

	if(ch == 's' || ch == 'S'){
		if (data.taxable_income <=44625){
		    tax_rate =0;
		}
		else if (data.taxable_income <=492300){
			tax_rate= 0.15;
		}
		else {
			tax_rate= 0.20;
		}
	}
	else if(ch == 'm' || ch == 'M'){
		if (data.taxable_income <=89250){
		    tax_rate =0;
		}
		else if (data.taxable_income <=553850){
			tax_rate= 0.15;
		}
		else {
			tax_rate= 0.20;
		}
	}
	else{
		if (data.taxable_income <=59750){
		    tax_rate =0;
		}
		else if (data.taxable_income <=523050){
			tax_rate= 0.15;
		}
		else {
			tax_rate= 0.20;
		}
	}

	ltcst = data.taxable_income * tax_rate;
	system("cls");
	cout<<"\n----------------LONG TERM CAPITAL GAINS TAX----------------\n";
	cout<<"Total LTCG TAX on your annual income of Rs."<<data.annual_income<<" with tax rate of "<<tax_rate*100<<"% is Rs."<<ltcst<<endl;
	return ltcst;
}

void after_tax(user_info &data){
	system("cls");
	double fed = calculate_federal_income_tax(data);
	double fica = calculate_fica_tax(data);
	double ltcg = calculate_ltcg_tax(data);
	data.income_after_tax = data.annual_income - (fed + fica + ltcg) - data.deductions;
	cout<<"\nThe total income after paying taxes is Rs."<<data.income_after_tax<<endl;
}

void runTaxModule(){
	user_info user;
	char ch = 'y';
	cout<<"\n-----------------------WELCOME TO THE TAX MANAGEMENT SYSTEM----------------------------"<<endl;
	fetch_info(user);
	calculate_taxable_income(user);

	while(ch == 'y' || ch == 'Y'){
		cout<<"\n\n***********TAX MENU************\n";
		cout<<"press 1 for calculating federal income tax.\npress 2 for calculating fica tax.\npress 3 for calculating long term capital gains tax.\npress 4 for overall tax calculations.\npress 5 for exit."<<endl;
		cin>>ch;

		switch(ch){
			case '1':
				cout<<"---------------WELCOME TO FEDERAL INCOME TAX CALCULATION MODULE---------------------"<<endl;
				calculate_federal_income_tax(user);
				break;
			case '2':
				cout<<"----------------WELCOME TO FICA TAX CALCULATION MODULE----------------------"<<endl;
				calculate_fica_tax(user);
				break;
			case '3':
				cout<<"---------------WELCOME TO LONG TERM CAPITAL GAINS TAX CALCULATION MODULE-------------------- "<<endl;
				calculate_ltcg_tax(user);
				break;
			case '4':
				cout<<"--------------------WELCOME TO OVERALL TAX CALCULATION MODULE------------------------"<<endl;
				after_tax(user);
				break;
			case '5':
				cout<<"EXITING MODULE.... PRESS ANY KEY TO EXIT.."<<endl;
				getch();
				system("cls");
				cout<<"-----------------------THANK YOU FOR USING TAX MANAGEMENT MODULE------------------";
				return 0;
		}
		cout<<"\nWant to calculate taxes again?\nPress y/Y to continue, any other key to exit: ";
		cin>>ch;
	}
	return 0;
}
