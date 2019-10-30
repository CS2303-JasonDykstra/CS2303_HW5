/*
 * Tests.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#include "Tests.h"

namespace std {

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests(){
	bool answer;
	bool ok1 = testInitializeBoard();
	bool ok2 = testDisplayBoard();
	bool ok3 = testRemoveSpaces();
	bool ok4 = testGetPossibleMoves();
	bool ok5 = testIsValidMove();
	bool ok6 = testMovePiece();
	bool ok7 = testPickMove();
	bool ok8 = testUpdateKings();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	return answer;
}

bool Tests::testInitializeBoard(){
	cout << "Testing initializeBoard..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	answer = true;
	return answer;
}

bool Tests::testDisplayBoard(){
	cout << "Testing displayBoard..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	b.displayBoard();
	answer = true;
	return answer;
}

bool Tests::testRemoveSpaces(){
	cout << "Testing removeSpaces..." << endl;
	bool answer = false;
	char s[10] = {'h', ' ', 'e', ' ', 'l', 'l', 'o'};
	Board b;
	b.removeSpaces(s);
	if(s[1] != ' '){
		answer = true;
	}
	return answer;
}

bool Tests::testGetPossibleMoves(){
	cout << "Testing getPossibleMoves..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	moveSet m = b.getPossibleMoves();
	if(m.size != 0){
		answer = true;
	}
	return answer;
}

bool Tests::testIsValidMove(){
	cout << "Testing isValidMove..." << endl;
	bool answer = false;
	Board b;
	move2 m = {0, 5, 1, 4};
	Piece* p = new Piece(1, 0, 5, 2);
	if(b.isValidMove(m, p)){
		answer = true;
	}
	return answer;
}

bool Tests::testMovePiece(){
	cout << "Testing movePiece..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	move2 m = {0, 5, 1, 4};
	b.movePiece(m);
	answer = true;
	return answer;
}

bool Tests::testPickMove(){
	cout << "Testing pickMove..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	move2 m = b.pickMove(1);
	if(m.fromX != m.toX){
		answer = true;
	}
	return answer;
}

bool Tests::testUpdateKings(){
	cout << "Testing updateKings..." << endl;
	bool answer = false;
	Board b;
	b.initializeBoard("startCheckers.txt");
	b.updateKings();
	answer = true;
	return answer;
}

} /* namespace std */
