// Files Assignment.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <stdio.h>
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
	int num = 0;
	char menu = 0;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "\nREAL ESTATE AGENCY SALES REPORT GENERATOR" << endl;

	do {
		cout << "\n------------------------------------------------------------------------" << endl;
		cout << "\nMAIN MENU" << endl << endl;

		cout << "1) Enter Agents Sales" << endl;
		cout << "2) View most recent sales report" << endl;
		cout << "Enter your selection and press ENTER: ";
		cin >> num;

		cout << "\n------------------------------------------------------------------------" << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			cout << "\n***ERROR*** Invalid Input --> Return to Main Menu?  (Enter Y for YES): ";
			cin >> menu;
		}

		else if (num == 1)
		{
			ofstream outFile;
			outFile.open("agentSales.txt");

			cout << "\nENTER AGENT SALES" << endl;

			do {
				cout << "\nEnter the name of the agent: ";
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
							cout << "\n*** ERROR! *** House Price must be greater than 0 and less than or equal to 200 --> Re-enter: ";
							cin >> housePrice;
							cout << endl; 
						}
						outFile << housePrice << " ";
					}
				}

				outFile << endl;

				cout << endl << "Would you like to enter another agent? (Enter Y for YES):";
				cin >> reset;
			} while (reset == 'y' || reset == 'Y');

			outFile.close();

		}
		else if (num == 2)
		{
			double sum = 0;
			double avg = 0;
			double totalSum = 0;
			double totalAvg = 0;
			double count = 0;

			ifstream inFile;
			inFile.open("agentSales.txt");

			if (inFile)
			{	
				cout << "\nAGENT SALES REPORT" << endl << endl;

				while (inFile >> name)
				{

					for (int i = 1; i <= 4; i++)
					{
						inFile >> housePrice;
						sum += housePrice;
					}

					avg = sum / 4;

					cout << fixed << setprecision(2);
					cout << "Agent " << name << "'s total sales were $" << sum << " average sales were $" << avg << endl;

					totalAvg += avg;
					totalSum += sum;
					sum = 0;
					count += 1;
				}

				cout << "\nThe total sales for all agents was $" << totalSum << endl;
				cout << "The total average sales for all agents is $" << (totalAvg / count) << endl;

				inFile.close();

				cout << endl << "Would you like to return to the main menu? (Enter Y for YES):";
				cin >> menu;
			}
			else
			{
				cout << "\n***ERROR*** No file defined. --> Return to Main Menu?  (Enter Y for YES): ";
				cin >> menu;

			}


		}

		else
		{
			cout << "\n***ERROR*** Invalid Input --> Return to Main Menu?  (Enter Y for YES): ";
			cin >> menu;
		}

	} while (menu == 'y' || menu == 'Y');

	/*****************************************PART 2*********************************************/


	return 0;
}


