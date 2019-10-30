/*
 * Tests.h
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Board.h"

namespace std {

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testInitializeBoard();
	bool testDisplayBoard();
	bool testRemoveSpaces();
	bool testGetPossibleMoves();
	bool testIsValidMove();
	bool testMovePiece();
	bool testPickMove();
	bool testUpdateKings();
};

} /* namespace std */

#endif /* TESTS_H_ */
