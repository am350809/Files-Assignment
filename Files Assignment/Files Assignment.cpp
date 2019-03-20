// Files Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	
	string name;
	double housePrice = 0;
	char reset;

	/*
	ofstream outFile;
	outFile.open("agentSales.txt");

	do {
		cout << "Enter the name of the agent: ";
		cin >> name;

		outFile << name << " ";

		for (int i = 1; i <= 4; i++)
		{
			
			cout << "Enter the the sale price of home " << i << ": ";
			cin >> housePrice;
			if (housePrice >= 0 && housePrice <= 200)
			{
				outFile << housePrice << " ";
			}
			else 
			{
				while (housePrice < 0 || housePrice > 200)
				{
					cout << "ERROR! House Price must be greater than 0 and less than or equal to 200 --> Re-enter: ";
					cin >> housePrice;
				}
				outFile << housePrice << " ";
			}
		}

		outFile << endl;

		cout << endl << "Would you like to enter another agent? (Enter Y for YES):";
		cin >> reset;
	} while (reset == 'y' || reset == 'Y');

	outFile.close();
	
	*/

	/*****************************************PART 2*********************************************/
	double sum = 0;
	double avg = 0;
	double totalSum = 0;
	double totalAvg = 0;
	double count = 0;

	ifstream inFile;
	inFile.open("agentSales.txt");

	cout << "Agent Sales Reports" << endl << endl;


	while (inFile >> name)
	{

		for (int i = 1; i <= 4; i++)
		{
			inFile >> housePrice;
			sum += housePrice;
		}

		avg = sum / 4;

		cout << fixed << setprecision(2);
		cout << "Agent " << name << " total sales were $" << sum << " average sales were $" << avg << endl;

		totalAvg += avg;
		totalSum += sum;
		sum = 0;
		count += 1;
	} 

	cout << "\nThe total sales for all agents was $" << totalSum << endl;
	cout << "The total average sales for all agents is $" << (totalAvg / count) << endl;

		cout << endl << "Would you like to enter another agent? (Enter Y for YES):";
		cin >> reset;
	

    return 0;
}

