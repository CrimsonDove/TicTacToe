#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct player;
struct game;
class TTT
{
	public:
		//object that handles each player
		struct player
		{
			player(bool human = false)	{ this->human = human; if(human){ this->name = "computer"; } }
			void setName(string name) 	{ this->name = name; }

			bool human;
			string name;
		};

		//object that handles entire game
		struct game
		{
			game()
			{
				//initalizate a blank board
				for(int x=0; x<3; x++)
				{
					for(int y=0; y<3; y++)
					{
						this->board[x][y] = 0;
					}
				}
			}

			int** board[3][3];
			TTT::player playerOne;
			TTT::player playerTwo;
		};

		//constructor
		TTT();

		//starts the game returns value on game over
		int		play(game* instance);

		//main initialization
		game		createGame(player X, player O);
		player	createPlayer(string name, bool human);

	protected:

	private:
		//prints board to console
		void	printGame(game* gi);

		//game logic
		int		checkWinner(game* gi);
		void	gameOver(int playerWon);
		void	gameTurn(game* gi, int turn);

		//player turn actions
		int		computerTurn(game* gi);
		int 		playerTurn(string name);
};

#endif // TTT_H
