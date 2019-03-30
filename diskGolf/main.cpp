/*
diskGolf.cpp
Zachary Elmore
6/15/16
Enter the amount of games you played and the total tosses throught the games and see if you beat your opponent's toss average

added a static variable for the Percentage factor and a getPercentage Factor in the Header Program; and added a handicap int,
avgDifference int, newAvg double, a handicap method, output if user wins, output if opponent wins, and output if they tied
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "diskGolf.h"
using namespace std;

int main()
{
	string firstName;
	string lastName;
	string iD;
	int games;
	int tosses;
	int handicap; //Int for the handicap
	int avgDifference; //Int for the difference between the two players
	double totalTosses;
	double tossAvg;
	double newAvg; //The resulting new average for the player with the handicap
	char answer = 'y' || 'n' || 'Y' || 'N';
	string winner;

	cout << "Enter your first name: "; //The user enters their first name
	cin >> firstName;

	cout << "Enter your last name: "; //The user enters their last name
	cin >> lastName;

	cout << "Enter your ID number (Please use only numbers and letters, five characters long): "; //The use enters their ID number
	cin >> iD;

	cout << "Enter the number of games you played: "; //The user enters the number of games they played
	cin >> games;

	while (games < 1) //Prevents the user from entering a negative number or zero
	{
		cout << "Error: Please enter a valid number."; //Displays an error message if the user enters a negative number or zero
		cin >> games;
	}

	cout << "Enter your total amount of tosses: "; //User enters the total number of tosses they had throughout their games
	cin >> tosses;

	while (tosses < games * 18) //Prevents the user from entering less than 18 tosses for each game
	{
		cout << "Error: Please enter a valid number."; /*Displays an error if user enters a number less than
													   18 tosses for each of their games*/
		cin >> tosses;
	}

	//Instantiate a Golfer
	Golfer myGolf(firstName, lastName, iD, games, tosses); //Object for user
	Golfer opponentGolf("Gary", "Oak", "C8342", 2, 54); //A set object for the opponent

	cout << "\nGolfer: " << myGolf.getFN() << " " << myGolf.getLN() << "\nID number: " << myGolf.getID() << "\nGames played: "
		<< myGolf.getGames() << "\nTotal number of tosses: " << myGolf.getTosses() << "\nToss Average: " << myGolf.getAvg()
		<< endl; //The output Golfer info for the user

	cout << "\nGolfer: " << opponentGolf.getFN() << " " << opponentGolf.getLN() << "\nID number: " << opponentGolf.getID()
		<< "\nGames played: " << opponentGolf.getGames() << "\nTotal number of tosses: " << opponentGolf.getTosses()
		<< "\nToss Average: " << opponentGolf.getAvg() << endl; //The output Golfer info for the opponent

	cout << "\nWould you like to change your Name and ID? [Y/N]"; //Gives the user the option to change their name and ID or not
	cin >> answer;

	if (answer == 'y' || answer == 'Y') //Outcome if the user enters yes(or y, or Y)
	{
		myGolf.nameChange("Ash", "Ketchum"); //The user recieves a new name
		myGolf.iDChange("C4891"); //The user recieves a new ID number

		//The new updated info for the Golfers are displayed
		cout << "\nGolfer: " << myGolf.getFN() << " " << myGolf.getLN() << "\nID number: " << myGolf.getID() << "\nGames played: "
			<< myGolf.getGames() << "\nTotal number of tosses: " << myGolf.getTosses() << "\nToss Average: " << myGolf.getAvg()
			<< endl;

		cout << "\nGolfer: " << opponentGolf.getFN() << " " << opponentGolf.getLN() << "\nID number: " << opponentGolf.getID()
			<< "\nGames played: " << opponentGolf.getGames() << "\nTotal number of tosses: " << opponentGolf.getTosses()
			<< "\nToss Average: " << opponentGolf.getAvg() << endl;
	}

	else if (answer == 'n' || answer == 'N') //Outcome if the user enters no(or n, or N)
	{
		cout << "\nGolfer: " << myGolf.getFN() << " " << myGolf.getLN() << "\nID number: " << myGolf.getID() << "\nGames played: "
			<< myGolf.getGames() << "\nTotal number of tosses: " << myGolf.getTosses() << "\nToss Average: " << myGolf.getAvg()
			<< endl;

		cout << "\nGolfer: " << opponentGolf.getFN() << " " << opponentGolf.getLN() << "\nID number: " << opponentGolf.getID()
			<< "\nGames played: " << opponentGolf.getGames() << "\nTotal number of tosses: " << opponentGolf.getTosses()
			<< "\nToss Average: " << opponentGolf.getAvg() << endl;
	}

	//Handicap method
	if (myGolf.getAvg() > opponentGolf.getAvg()) // result if the user's avg is greater than the opponent's
	{
		avgDifference = myGolf.getAvg() - opponentGolf.getAvg(); //the user's average is subtracted by the opponent's
		handicap = avgDifference * percentageFactor; //Handicap is found by multiplying the difference by the League's percentage factor
		newAvg = myGolf.getAvg() - handicap; //the user's new average is found by taking their old avg and subtracting it by the handicap

		if (newAvg < opponentGolf.getAvg())
		{
			winner = myGolf.getFN();
		}

		else if (newAvg > opponentGolf.getAvg())
		{
			winner = opponentGolf.getFN();
		}

		cout << "\nGolfer: " << myGolf.getFN() << " " << myGolf.getLN() << "\nID number: " << myGolf.getID() << "PLayer's Handicap: "
			<< handicap << "\nNew Toss Average: " << newAvg << endl;

		cout << "\nGolfer: " << opponentGolf.getFN() << " " << opponentGolf.getLN() << "\nID number: " << opponentGolf.getID()
			<< "Player's Handicap: " << 0 << "\nNew Toss Average: " << opponentGolf.getAvg() << endl;

		cout << "\nThe winner is " << winner << "!" << endl;//Winner is declared
	}

	else if (myGolf.getAvg() < opponentGolf.getAvg())//Result if the opponent's avg is greater than the user's
	{
		avgDifference = opponentGolf.getAvg() - myGolf.getAvg();
		handicap = avgDifference * percentageFactor;
		newAvg = opponentGolf.getAvg() - handicap;

		if (newAvg > myGolf.getAvg())
		{
			winner = myGolf.getFN();
		}

		else if (newAvg < myGolf.getAvg())
		{
			winner = opponentGolf.getFN();
		}

		cout << "\nGolfer: " << myGolf.getFN() << " " << myGolf.getLN() << "\nID number: " << myGolf.getID() << "PLayer's Handicap: "
			<< 0 << "\nNew Toss Average: " << myGolf.getAvg() << endl;

		cout << "\nGolfer: " << opponentGolf.getFN() << " " << opponentGolf.getLN() << "\nID number: " << opponentGolf.getID()
			<< "Player's Handicap: " << handicap << "\nNew Toss Average: " << newAvg << endl;

		cout << "\nThe winner is " << winner << "!" << endl;
	}

	else if (myGolf.getAvg() == opponentGolf.getAvg())//Result of a tie
	{
		cout << "\nTied game!!!" << endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}