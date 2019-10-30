/*
 * Piece.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#include "Piece.h"

namespace std {

Piece::Piece(int pieceType, int x, int y, int teamNum) {
	// TODO Auto-generated constructor stub
	//1 for pawn, 2 for king, 0 for nothing
	type = pieceType;
	posx = x;
	posy = y;
	//1 for red, 2 for black, 0 for neither
	team = teamNum;
}

Piece::~Piece() {
	// TODO Auto-generated destructor stub
}

int Piece::getType(){
	return type;
}

int Piece::getX(){
	return posx;
}

int Piece::getY(){
	return posy;
}

int Piece::getTeam(){
	return team;
}

void Piece::setType(int pieceType){
	type = pieceType;
}

void Piece::setX(int x){
	posx = x;
}

void Piece::setY(int y){
	posy = y;
}

void Piece::setTeam(int teamNum){
	team = teamNum;
}

} /* namespace std */
