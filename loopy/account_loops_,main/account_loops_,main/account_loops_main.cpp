#include <iostream>
#include "Account.h"
#include "CST171.hpp"

using namespace std;

int main(){
Account myAccount{"Edythe", 37500};

	cout << myAccount.getName() << " $" << myAccount.getBalance() << endl; 

	//need to stimulate interest calculator
	//assumed % per year
	//compounded monthly
	//run for 24 months
	int month = 1;
	int quarter = 3;
	while (month <= 24)
	{
		cout << "Month" << month << endl;
		//remainder 
		if(month %3 == 0) {
			float interestRate = 0.8 / 4;
			cout << interestRate << endl;
			float interest = interestRate * myAccount.getBalance();
			myAccount.deposit(interest);
	
	

			//quarter += 3;
		}
		//creating a deposit
		cout << "give me ur monies bicth (y/y)" << endl;
		char input = cst::getChar();
		if (input == 'y') {
			cout << "all of the monies bicht" << endl;
			float inputAmount;
				cin >> inputAmount;
			 myAccount.deposit(inputAmount); 
		}

		myAccount.print(); 
		//post increment evaluates and adds 1 to the month
		// ++n is pre increment 
		month++;
		
	}
	cst::pause();


}
