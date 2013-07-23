#include "TTT.h"

TTT::TTT()
{
}

//handles initialization
TTT::game TTT::createGame(player X, player O)
{
	cout << "initialized game board" << endl;
	TTT::game output;
	output.playerOne = X;
	output.playerTwo = O;


	return output;
}

//returns a basic player object
TTT::player TTT::createPlayer(string name, bool human = false)
{
	TTT::player output;

	output.human = human;
	output.setName(name);

	return output;
}

//main loop that plays the game
int TTT::play(game* instance)
{
	//preform modulo in gameTurn to see if its X's or O's turn
	int turn = 1;
	int winner = 0;
	while(true)
	{
		//print the current gameboard
		this->printGame(instance);

		//run the main function to determine whos turn it is
		this->gameTurn(instance, turn);

		//check if we have a winner yet
		winner = checkWinner(instance);

		//if we have a winner preform game over
		if(winner != 0)
		{
			this->gameOver(winner);
			break;
		}

		//add one to turn counter
		turn++;
	}

	//return the winner (1 or 2)
	return winner;
}

//prints the gameboard to console
void TTT::printGame(game* gi)
{
	//TODO: printGame logic
	system("cls");
}

//checks the entire board looking for a winner
int TTT::checkWinner(game* gi)
{
	//TODO: gameWinner logic
	return 0;
}

//basic void, prints game over and players name
void TTT::gameOver(int playerWon)
{
	//TODO: Game over logic
}

//main function that determins the players turn, and adds their mark to the board
void TTT::gameTurn(game* gi, int turn)
{
	int playerMove;
	TTT::player player;
	if(turn % 2 == 0 )
	{
		player = gi->playerTwo;
		if(player.human)
		{
			playerMove = playerTurn(player.name);
		}
		else
		{
			playerMove = computerTurn(gi);
		}
	}
	else
	{
		player = gi->playerOne;
		playerMove = playerTurn(player.name);
	}

	//TODO: Move Action
}

//the function to make the computer pick a square to place their piece in
int TTT::computerTurn(game* gi)
{
	//TODO: AI logic
	return 0;
}

//function that asks player his placement option
int TTT::playerTurn(string name)
{
	int option = 0;
	cout << endl << name << "'s turn" << endl;
	cout << "> " ;
	cin >> option;

	//TODO: Player Move Logic

	return 0;
}

