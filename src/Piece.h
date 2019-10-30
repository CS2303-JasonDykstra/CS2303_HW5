/*
 * Piece.h
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string.h>
#include <cstring>

namespace std {

class Piece {

public:
	Piece(int pieceType, int x, int y, int teamNum);
	virtual ~Piece();
	int getType();
	int getX();
	int getY();
	int getTeam();
	void setType(int pieceType);
	void setX(int x);
	void setY(int y);
	void setTeam(int teamNum);

private:
	int type;
	int posx;
	int posy;
	int team;
};

} /* namespace std */

#endif /* PIECE_H_ */
