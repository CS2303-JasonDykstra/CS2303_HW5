/*
 * Board.h
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#ifndef BOARD_H_
#define BOARD_H_

#define CHECKERBOARDROWS 8
#define CHECKERBOARDCOLS 8

#include "Piece.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

typedef struct {
	int fromX;
	int fromY;
	int toX;
	int toY;
}move2;

typedef struct {
	move2* moves;
	int size;
} moveSet;

class Board {
public:
	virtual ~Board();
	void displayBoard();
	void initializeBoard(string filePath);
	void removeSpaces(char* str);
	//Move* getPossibleMoves();
	moveSet getPossibleMoves();
	//bool isValidMove(Move* m, Piece* p);
	bool isValidMove(move2 m, Piece* p);
	void movePiece(move2 m);
	move2 pickMove(int team);
	void updateKings();

private:
	Piece* checkerBoard[CHECKERBOARDCOLS][CHECKERBOARDROWS];
};



#endif /* BOARD_H_ */
