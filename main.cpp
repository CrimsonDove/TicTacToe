#include <iostream>
#include <string.h>
#include "TTT.h"
using namespace std;

int main()
{
	//print helo
	cout << "Welcome to TTT v0.01" << endl<< endl;
	cout << "How many humans are playing [1 or 2]" << endl << "> ";

	//ask how many humans are playing
	int players;
	while(true)
	{
		cin >> players;

		if(players == 1 || players == 2)
		{
			break;
		}
		else
		{
			cout << "Please enter a valid number [1 or 2]" << endl << "> ";
		}
	}

	//gathers the players names
	string player1;
	string player2;
	bool human = false;

	//obtain player 1s name
	cout << "Please enter player 1's name [human]" << endl << "> ";
	while(true)
	{
		cin >> player1;

		if(player1 != "")
		{
			break;
		}
		else
		{
			cout << "Please enter a valid name" << endl << "> ";
		}
	}

	//obtain player 2s name
	cout << "Please enter player 2's name";

	//if human or not
	if(players != 2)
	{
		cout << " [Computer]"<< endl << "> ";
	}
	else
	{
		cout << " [Human] "<< endl << "> ";
		human = true;
	}

	//gather input
	while(true)
	{
		cin >> player2;

		if(player2 != "")
		{
			break;
		}
		else
		{
			cout << "Please enter a valid name" << endl << "> ";
		}
	}

	//initialize TTT class
	TTT tictoe;
	TTT::game currentMatch = tictoe.createGame(tictoe.createPlayer(player1, true), tictoe.createPlayer(player2, human));

	//start game
	tictoe.play(&currentMatch);

	return 0;
}
