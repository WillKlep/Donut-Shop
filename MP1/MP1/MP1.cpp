#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


//Don't forget while loop validation for donuts
//get rid of warnings
//delete any vars declared but not used
//go through code and comment, ask self "Why did I write this? Why is it necessary?"
//needs commas and periods
//run again loop

int main() {
	const double REG_INDV = 0.75;
	const double REG12 = 7.99;
	const double FAN_INDV = 0.85;
	const double FAN12 = 8.49;
	int regQuant, fanQuant, regRemainder, fanRemainder;
	double regTotal, fanTotal, regSubTotal, fanSubTotal, totalSalesTax, totalWithTax, total, salesTaxTotal;
	double tax = 0.075;
	double regSalesTax, fanSalesTax;
	double userChange, changeBack;
	
	cout << "Number of regular donuts ordered: ";
	cin >> regQuant;

/*	if (cin.fail()) {
		cout << "Please enter numbers only!" << endl;

		cin.clear();
		cin.ignore();

		cout << "Number of regular donuts ordered: ";
		cin >> regQuant;
	}*/
	
	cout << "Number of fancy donuts ordered: ";
	cin >> fanQuant;

	if (cin.fail()) {
		cout << "Please enter numbers only!" << endl;

		cin.clear();
		cin.ignore();

		cout << "Number of regular donuts ordered: ";
		cin >> regQuant;

		cout << "Number of fancy donuts ordered: ";
		cin >> fanQuant;
	}

	//if regQuant or fanQuant % 12.0 == 0
	//quant * 12cost ?

	regRemainder = regQuant % 12;
	regSubTotal = ((regQuant / 12) * REG12) + (regRemainder * REG_INDV);
	//regSalesTax = regSubTotal * tax;
	//regTotal = regSubTotal + regSalesTax;
	
	fanRemainder = fanQuant % 12;
	fanSubTotal = ((fanQuant / 12) * FAN12) + (fanRemainder * FAN_INDV);
	//fanSalesTax = fanSubTotal * tax;
	//fanTotal = fanSubTotal + fanSalesTax;

	total = regSubTotal + fanSubTotal;
	salesTaxTotal = (regSubTotal + fanSubTotal) * tax;
	totalWithTax = salesTaxTotal + (regSubTotal + fanSubTotal);


	//cout << "$" << fixed << setprecision(2) << regTotal;
	//cout << "$" << fixed << setprecision(2) << fanTotal;
	/* cout << "$" << fixed << setprecision(2) << regRemainder << endl;
	cout << "$" << fixed << setprecision(2) << regSubTotal << endl;
	cout << "$" << fixed << setprecision(2) << fanSubTotal << endl;
	cout << "$" << fixed << setprecision(2) << total << endl;
	cout << "$" << fixed << setprecision(2) << salesTaxTotal << endl;*/
	cout << "Customer owes: $" << fixed << setprecision(2) << totalWithTax << endl; 
	cout << "Customer pays: $";
	cin >> userChange;
	
	while (totalWithTax > userChange) {
		cout << "Not enough money. Please enter a new amount:";
		cin >> userChange;
	}

	changeBack = userChange - totalWithTax;

	int dollars, quarters, dimes, nickels, pennies;

	int wordChange = changeBack * 100;
	if (wordChange == 0) {
		cout << "Exact payment recieved - no change owed.";
	}
	else {


		cout << "Change back: $" << fixed << setprecision(2) << changeBack << " -";



		dollars = wordChange / 100;
		wordChange = wordChange - (dollars * 100);
		//cout << dollars << endl;

		quarters = wordChange / 25;
		wordChange = wordChange - (quarters * 25);

		dimes = wordChange / 10;
		wordChange = wordChange - (dimes * 10);

		nickels = wordChange / 5;
		wordChange = wordChange - (nickels * 5);

		pennies = wordChange / 1;
		wordChange = wordChange - (pennies * 1);

		if (dollars > 1) {
			if (dollars > quarters && quarters == 0) {
				cout << " " << dollars << " dollars.";
			}
			else {
				cout << " " << dollars << " dollars,";
			}
			
		}
		else if (dollars == 1) {
			if (dollars > quarters && quarters == 0) {
				cout << " " << dollars << " dollar.";
			}
			else {
			cout << " " << dollars << " dollar,";
			}
		}

		if (quarters > 1) {
			cout << " " << quarters << " quarters";
		}
		else if (quarters == 1) {
			cout << " " << quarters << " quarter";
		}

		if (dimes > 1) {
			cout << " " << dimes << " dimes";
		}
		else if (dimes == 1) {
			cout << " " << dimes << " dime";
		}

		if (nickels > 1) {
			cout << " " << nickels << " nickels";
		}
		else if (nickels == 1) {
			cout << " " << nickels << " nickel";
		}

		if (pennies > 1) {
			cout << " " << pennies << " pennies";
		}
		else if (pennies == 1) {
			cout << " " << pennies << " penny";
		}
		
	}
	//Don't forget while loop validation
	//get rid of warnings
	//delete any vars declared but not used
	//go through code and comment, ask self "Why did I write this? Why is it necessary?" 
}




//input from user about how many regular and fancy donuts they ordered

//take input and divide by 12 and multiply that result by the cost of 12 donuts,
//plus,
//multiply the remainder by the cost of an idividual donut

//Take both regular and fancy totals from equations above and multiply them by tax rate
//add tax rate to both fancy and regular totals for grand total

//take input for cash given for payment
//subtract given from amount due

//for converting to coins -- changeBack % or / by a dollar (1.00), subtract, then do quarters (0.25), dimes, nickels, pennies
// changeBack needs to go through the currency, so it needs to check if it's true, if not, on to the next statement
//if it is true, it needs to be subtracted until not true anymore, also needs to keep track of how many times it goes through true statement

//For wording --
// I know I'll need x to output difference between "penny" & "pennies" - somethnig like if(pennies == 1): cout "1 penny" else "pennies"
//need to somehow, get all the coins to print on one line, and if currency isn't used, don't display