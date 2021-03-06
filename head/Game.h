#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "GameState.h"

class Game{
	public:

		Game();
		Game(GameState * gs);
		~Game();

		//Get size of the board in terms of # of blocks in a row or col

		/*
		 * main game loop
		 */
		void loop();

		int getBoardSize() const;

	private:
		GameState * state;
		Player *p1;
		Player *p2;

		/*
		 * if curr points to p1, switch it to p2
		 * if curr points to p2, switch it to p1
		 */
		void switchPlayer(Player *& curr);

		/*
		 * check if the game is over, switch the currentPlayer
		 */
		void finishTurn(sf::RenderWindow & window, const Board * board,
				Player*& curr, const int moveMade);

		bool isGameOver(const Board* board, const Player* currPlayer) const;

};

#endif
