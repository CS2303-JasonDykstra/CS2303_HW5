/*
 * Production.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#include "Production.h"

namespace std {

Production::Production() {
	// TODO Auto-generated constructor stub
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::production(int argc, char* argv[]){
	Board board;
	int turn = 1;
	bool answer = false;
	string startCheckers = "";
	long numTurns_L = 0;
	int numTurns = 0;
	bool possibleMovesLeft = true;

	//clear output file upon start
	ofstream output;
	output.open("output.txt");
	output.close();




	if(argc == 1){
		cout << "Enter filepath for startCheckers.txt: ";
		cin >> startCheckers;
		cout << "Enter a number of turns to attempt: ";
		cin >> numTurns;
	} else if(argc == 2){
		startCheckers = argv[1];
		cout << "Enter a number of turns to attempt: ";
		cin >> numTurns;
	} else {
		//there is interesting info from command line
		printf("Found %d arguments.\n", argc - 1);
		fflush(stdout);

		for(int i = 1; i < argc; i++){
			//start at i=1 so you don't read the path
			char* ePtr = (char*) malloc(sizeof(char*));
			switch(i){
			case 1:
				//this is file path
				startCheckers = argv[i];
				break;
			case 2:
				//this is numTurns to test
				numTurns_L = strtol(argv[i], &ePtr, 10);
				break;
			default:
				puts("Unexpected argument count.");
				break;
			}
		}
	}


	//setup the board
	board.initializeBoard(startCheckers);

	//display the board
	board.displayBoard();

	cout << "num turns: " << numTurns << endl;

	for(int i = 0; i < numTurns; i++){
		//open output file for appending
		output.open("output.txt", std::ios_base::app);

		//make sure there are possible moves left
		moveSet possibleMoves = board.getPossibleMoves();
		if(possibleMoves.size == 0){
			possibleMovesLeft = false;
		}

		//if there are possible moves, continue
		if(possibleMovesLeft){
			//pick a random move
			move2 randomMove = board.pickMove(turn);

			cout << "turn: " << turn << endl;
			cout << "possible moves: " << possibleMoves.size << endl;
			output << "Possible moves: " << possibleMoves.size << endl;
			cout << "randomMove: " << "(" << randomMove.fromX << ", " << randomMove.fromY << ") to (" << randomMove.toX << ", " << randomMove.toY << ")" << endl;
			output << "Random move: " << "(" << randomMove.fromX << ", " << randomMove.fromY << ") to (" << randomMove.toX << ", " << randomMove.toY << ")" << endl;

			//close file
			output.close();

			//execute that move
			board.movePiece(randomMove);

			//check to see if any pieces become kings
			board.updateKings();

			//redisplay board after updating it
			board.displayBoard();

			//switch turns
			if(turn == 1){
				turn = 2;
			} else if(turn == 2){
				turn = 1;
			}
		} else {
			cout << "No possible moves left" << endl;
			output.close();
		}

	}


	cout << "done" << endl;

	return answer;
}

} /* namespace std */
