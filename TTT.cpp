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
			//print game then game over message
			this->printGame(instance);
			this->gameOver(instance, winner);
			break;
		}

		if(turn == 9)
		{
			this->printGame(instance);
			this->gameOver(instance, 0);
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
	system("cls");

	int block = 1;
	string buffer = "";
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			//tell us what we want printed to console
			int piece = gi->board[x][y];
			switch (piece)
			{
			case 0:
				buffer += i2s(block); break;

			case 1:
				buffer += "X"; break;

			case 2:
				buffer += "O"; break;
			}

			switch (block)
			{
			case 1:
				buffer += "|"; break;
			case 2:
				buffer += "|"; break;
			case 3:
				buffer +="\r\n-----\r\n"; break;
			case 4:
				buffer += "|"; break;
			case 5:
				buffer += "|"; break;
			case 6:
				buffer +="\r\n-----\r\n"; break;
			case 7:
				buffer += "|"; break;
			case 8:
				buffer += "|"; break;
			case 9:
				buffer +="\r\n"; break;
			}
			//add one to our block
			block++;
		}
	}
	//print to console
	cout << buffer;
}

//checks the entire board looking for a winner
int TTT::checkWinner(game* gi)
{
	int winner = 0;

	//horizontal check
	for(int i=0; i<3; i++)
	{
		if((gi->board[i][0] != 0) && gi->board[i][0] == gi->board[i][1]  && gi->board[i][1] == gi->board[i][2])
		{
			winner = gi->board[i][0];
			break;
		}
	}

	//vertical check
	if(winner == 0)
	{
		for(int i=0; i<3; i++)
		{
			if((gi->board[0][i] != 0) && gi->board[0][i] == gi->board[1][i]  && gi->board[1][i] == gi->board[2][i])
			{
				winner = gi->board[0][i];
				break;
			}
		}
	}

	//diagional check
	if(winner == 0)
	{
		if((gi->board[0][0] != 0) && gi->board[0][0] == gi->board[1][1]  && gi->board[1][1] == gi->board[2][2])
		{
			winner = gi->board[0][0];
		}
	}
	if(winner == 0)
	{
		if((gi->board[0][2] != 0) && gi->board[0][2] == gi->board[1][1]  && gi->board[1][1] == gi->board[2][0])
		{
			winner = gi->board[0][2];
		}
	}

	return winner;
}

//basic void, prints game over and players name
void TTT::gameOver(game* gi, int playerWon)
{
	cout << "\r\nGame Over!\r\n";
	if(playerWon == 1)
	{
		cout << gi->playerOne.name << " wins!";
	}
	else if(playerWon == 2)
	{
		cout << gi->playerTwo.name << " wins!";
	}
	else
	{
		cout << "CAT nobody wins!";
	}
	cout << endl;
	system("PAUSE");
}

//main function that determins the players turn, marks are added in the actual turn function
void TTT::gameTurn(game* gi, int turn)
{
	TTT::player player;

	//simple check to see whos turn it is
	if(turn % 2 == 0 )
	{
		player = gi->playerTwo;
		if(player.human)
		{
			//if the player is human run the human player function
			playerTurn(gi, player.name, 2);
		}
		else
		{
			//if player 2 is not AI run an AI turn function
			computerTurn(gi);
		}
	}
	else
	{
		//player one is always human
		player = gi->playerOne;
		playerTurn(gi, player.name, 1);
	}

	cout << "Turn: " << turn;
}

//check the block number to see if its occupied
int TTT::boardCheck(game* gi, int block)
{
	int sBlock = 1;
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			//tell us what we want printed to console
			if(block == sBlock)
			{
				return gi->board[x][y];
			}
			sBlock++;
		}
	}

	//returns if the block isnt found
	return 1;
}

//actually place the piece on the board
void TTT::placePiece(game* gi, int block, int piece)
{
	int sBlock = 1;
	bool done = false;
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			if(block == sBlock && gi->board[x][y] == 0)
			{
				gi->board[x][y] = piece;
				done = true;
				break;
			}
			sBlock++;
		}

		if(done)
				break;
	}
}

void TTT::computerTurn(game* gi)
{
	int finalPlacement = 0;
	int block = 1;

	//horrizontal checks
	for(int a=0; a<3; a++)
	{
		for(int b=0; b<3; b++)
		{
			if(gi->board[a][b] == 1)
				break;
			else if(gi->board[a][b] == 0)
			{
				finalPlacement = block;
				break;
			}
			block++;
		}
		if(finalPlacement  != 0) { break; }
	}

	//vertical check
	//how to block
	if(finalPlacement  == 0)
	{
		block = 1;

		for(int a=0; a<3; a++)
		{

			for(int b=0; b<3; b++)
			{
				if(gi->board[b][a] == 1)
					break;
				else if(gi->board[b][a] == 0)
				{
					finalPlacement = block;
					break;
				}

				block += 3;
			}
			if(finalPlacement  != 0) { break; }
			block -= 5;
		}
	}

	//diagional check 1
	if(finalPlacement  == 0)
	{
		block = 1;

		for(int a=0; a<3; a++)
		{
			if(gi->board[a][a] == 1)
				break;
			else if(gi->board[a][a] == 0)
			{
				finalPlacement = block;
				break;
			}
			block += 4;
		}
	}

	//diagional check 2
	if(finalPlacement  == 0)
	{
		block = 3;

		int a = 0;
		int b = 2;
		for(int c=0; c<3; c++)
		{
			if(gi->board[a][b] == 1)
				break;
			else if(gi->board[a][b] == 0)
			{
				finalPlacement = block;
				break;
			}

			a+= 1; b -= 1;
			block += 2;
		}
	}

	//if all else fails
	if(finalPlacement  == 0)
	{
		while(true)
		{
			int option = 0;

			//randomly picking places for a piece
			srand (time(NULL));
			option = rand() % 9 + 1;

			//place the piece
			if(boardCheck(gi, option) == 0)
			{
				//this->placePiece(gi,option, 2);
				finalPlacement = option;
				break;
			}
		}
	}

	this->placePiece(gi, finalPlacement, 2);
}

//function that asks player his placement option
void TTT::playerTurn(game* gi, string name, int piece)
{
	while(true)
	{
		//capture input
		int option = 0;
		cout << endl << name << "'s turn" << endl;
		cout << "> " ;
		cin >> option;

		//check if you can place it or go back through the loop
		if(boardCheck(gi, option) != 0)
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			this->placePiece(gi,option, piece);
			break;
		}
	}
}

//basic int to string function
string TTT::i2s(int input)
{
	stringstream ss;
	ss << input;
	return ss.str();
}

