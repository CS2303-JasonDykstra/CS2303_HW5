/*
 * Board.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#include "Board.h"

Board::~Board(){
	// TODO Auto-generated destructor stub
}

void Board::displayBoard(){
	//output to file
	ofstream output;
	output.open("output.txt", std::ios_base::app);

	for(int i = 0; i < CHECKERBOARDROWS; i++){
		for(int j = 0; j < CHECKERBOARDCOLS; j++){
			cout << checkerBoard[j][i]->getTeam();
			output << checkerBoard[j][i]->getTeam();
		}
		cout << endl;
		output << endl;
	}

	output.close();
}

void Board::initializeBoard(string filePath){
	ifstream in(filePath);
	if(!in) {
		cout << "Cannot open input file.\n";
	}

	char str[255];
	int row = 0;

	while(in && row < 8) {
		in.getline(str, 255);  // delim defaults to '\n'

		removeSpaces(str);

		//if(in) cout << str;

		for(int i = 0; i < strlen(str) - 1; i++){
			//subtract 48 since when you convert a char to int, ascii starts at 48 for numbers
			switch ((int)(str[i]) - 48){
			case 0:
				checkerBoard[i][row] = new Piece(0, i, row, 0);
				break;
			case 1:
				checkerBoard[i][row] = new Piece(1, i, row, 1);
				break;
			case 2:
				checkerBoard[i][row] = new Piece(1, i, row, 2);
				break;
			default:
				cout << "unexpected formatting of file startCheckers.txt" << endl;
			}

		}
		row++;
	}

	in.close();
}

//code from https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
void Board::removeSpaces(char* str) {
	// To keep track of non-space character count
	int count = 0;

	// Traverse the given string. If current character
	// is not space, then place it at index 'count++'
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is
	// incremented
	str[count] = '\0';
}


//return a type that has the pointer array, and the length
moveSet Board::getPossibleMoves(){
	move2* possibleMoves = 0;
	possibleMoves = new move2[CHECKERBOARDROWS];

	int pos = 0;
	//check all moves to see if they are possible
	for(int i = 0; i < CHECKERBOARDROWS; i++){
		for(int j = 0; j < CHECKERBOARDCOLS; j++){
			if(checkerBoard[j][i]->getTeam() == 1){
				move2 mLeft = {checkerBoard[j][i]->getX(), checkerBoard[j][i]->getY(), checkerBoard[j][i]->getX() - 1, checkerBoard[j][i]->getY() + 1};
				move2 mRight = {checkerBoard[j][i]->getX(), checkerBoard[j][i]->getY(), checkerBoard[j][i]->getX() + 1, checkerBoard[j][i]->getY() + 1};
				if(isValidMove(mLeft, checkerBoard[j][i])){
					possibleMoves[pos] = mLeft;
					pos++;
				}

				if(isValidMove(mRight, checkerBoard[j][i])){
					possibleMoves[pos] = mRight;
					pos++;
				}
			} else if(checkerBoard[j][i]->getTeam() == 2){
				move2 mLeft = {checkerBoard[j][i]->getX(), checkerBoard[j][i]->getY(), checkerBoard[j][i]->getX() - 1, checkerBoard[j][i]->getY() - 1};
				move2 mRight = {checkerBoard[j][i]->getX(), checkerBoard[j][i]->getY(), checkerBoard[j][i]->getX() + 1, checkerBoard[j][i]->getY() - 1};
				if(isValidMove(mLeft, checkerBoard[j][i])){
					possibleMoves[pos] = mLeft;
					pos++;
				}

				if(isValidMove(mRight, checkerBoard[j][i])){
					possibleMoves[pos] = mRight;
					pos++;
				}
			}

		}
	}
	moveSet mSet = {possibleMoves, pos};
	return mSet;
}



bool Board::isValidMove(move2 m, Piece* p){
	bool answer = false;

	//if pawn
	if(p->getType() == 1){
		//cout << "is pawn" << endl;
		//check if diagonal move
		if((m.fromX == m.toX - 1 || m.fromX == m.toX + 1)
				&& (m.toY == m.fromY - 1 || m.toY == m.fromY + 1)){
			//cout << "is diagonal move" << endl;

			//check if moving in correct direction
			if((p->getTeam() == 1 && m.toY - m.fromY == 1)
					|| (p->getTeam() == 2 && m.toY - m.fromY == -1)){
				//cout << "is in correct direction" << endl;

				//check if inside board
				if(m.toX >= 0 && m.toX < CHECKERBOARDCOLS && m.toY < CHECKERBOARDROWS && m.toY >= 0){
					//cout << "is inside board" << endl;

					//check if theres a piece there
					if(checkerBoard[m.toX][m.toY]->getTeam() == 0){
						//cout << "no piece there" << endl;
						answer = true;

						//if there is a piece there, see if you can jump it
					} else {
						//cout << "piece there, checking if it's on opposite team" << endl;

						//if piece is red, check if there's a black there
						if(p->getTeam() == 1){
							if(checkerBoard[m.toX][m.toY]->getTeam() == 2){

								//make sure there's space in the next diagonal
								int xDirection = m.toX - m.fromX;

								//if moving to left
								if(xDirection == -1){

									//make sure next diagonal is in the board
									if(m.toX - 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY + 1 < CHECKERBOARDCOLS && m.toY + 1 >= 0){

										//see if spot is free
										if(checkerBoard[m.toX - 1][m.toY + 1]->getTeam() == 0){
											answer = true;
										}
									}
									//if moving to right
								} else if(xDirection == 1){
									//make sure next diagonal is in the board
									if(m.toX + 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY + 1 < CHECKERBOARDCOLS && m.toY + 1 >= 0){
										//see if spot is free
										if(checkerBoard[m.toX + 1][m.toY + 1]->getTeam() == 0){
											answer = true;
										}
									}
								}
							}
							//if piece is black, check if there's a red there
						} else if(p->getTeam() == 2){
							if(checkerBoard[m.toX][m.toY]->getTeam() == 1){
								//make sure there's space in the next diagonal
								int xDirection = m.toX - m.fromX;
								//if moving to left
								if(xDirection == -1){
									//make sure next diagonal is in the board
									if(m.toX - 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY - 1 < CHECKERBOARDCOLS && m.toY - 1 >= 0){
										//see if spot is free
										if(checkerBoard[m.toX - 1][m.toY - 1]->getTeam() == 0){
											answer = true;
										}
									}
									//if moving to right
								} else if(xDirection == 1){
									//make sure next diagonal is in the board
									if(m.toX + 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY - 1 < CHECKERBOARDCOLS && m.toY - 1 >= 0){
										//see if spot is free
										if(checkerBoard[m.toX + 1][m.toY - 1]->getTeam() == 0){
											answer = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	//if king
	if(p->getType() == 2){
		if((m.fromX == m.toX - 1 || m.fromX == m.toX + 1)
				&& (m.toY == m.fromY - 1 || m.toY == m.fromY + 1)){
			//cout << "is diagonal move" << endl;

			//check if inside board
			if(m.toX >= 0 && m.toX < CHECKERBOARDCOLS && m.toY < CHECKERBOARDROWS && m.toY >= 0){
				//cout << "is inside board" << endl;

				//check if theres a piece there
				if(checkerBoard[m.toX][m.toY]->getTeam() == 0){
					//cout << "no piece there" << endl;
					answer = true;

					//if there is a piece there, see if you can jump it
				} else {
					//cout << "piece there, checking if it's on opposite team" << endl;

					//if piece is red, check if there's a black there
					if(p->getTeam() == 1){
						if(checkerBoard[m.toX][m.toY]->getTeam() == 2){

							//make sure there's space in the next diagonal
							int xDirection = m.toX - m.fromX;

							//if moving to left
							if(xDirection == -1){

								//make sure next diagonal is in the board
								if(m.toX - 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY + 1 < CHECKERBOARDCOLS && m.toY + 1 >= 0){

									//see if spot is free
									if(checkerBoard[m.toX - 1][m.toY + 1]->getTeam() == 0){
										answer = true;
									}
								}
								//if moving to right
							} else if(xDirection == 1){
								//make sure next diagonal is in the board
								if(m.toX + 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY + 1 < CHECKERBOARDCOLS && m.toY + 1 >= 0){
									//see if spot is free
									if(checkerBoard[m.toX + 1][m.toY + 1]->getTeam() == 0){
										answer = true;
									}
								}
							}
						}
						//if piece is black, check if there's a red there
					} else if(p->getTeam() == 2){
						if(checkerBoard[m.toX][m.toY]->getTeam() == 1){
							//make sure there's space in the next diagonal
							int xDirection = m.toX - m.fromX;
							//if moving to left
							if(xDirection == -1){
								//make sure next diagonal is in the board
								if(m.toX - 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY - 1 < CHECKERBOARDCOLS && m.toY - 1 >= 0){
									//see if spot is free
									if(checkerBoard[m.toX - 1][m.toY - 1]->getTeam() == 0){
										answer = true;
									}
								}
								//if moving to right
							} else if(xDirection == 1){
								//make sure next diagonal is in the board
								if(m.toX + 1 >= 0 && m.toX - 1 < CHECKERBOARDROWS && m.toY - 1 < CHECKERBOARDCOLS && m.toY - 1 >= 0){
									//see if spot is free
									if(checkerBoard[m.toX + 1][m.toY - 1]->getTeam() == 0){
										answer = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return answer;
}

void Board::movePiece(move2 m){
	Piece* fromPiece = checkerBoard[m.fromX][m.fromY];
	Piece* toPiece = checkerBoard[m.toX][m.toY];
	//move the piece if the spot is open
	if(toPiece->getTeam() == 0){

		//if red, move red
		if(fromPiece->getTeam() == 1){
			checkerBoard[m.toX][m.toY]->setTeam(1);
			//if black, move black
		} else if(fromPiece->getTeam() == 2){
			checkerBoard[m.toX][m.toY]->setTeam(2);
		}
		checkerBoard[m.toX][m.toY]->setType(fromPiece->getType());
		checkerBoard[m.fromX][m.fromY]->setType(0);
		checkerBoard[m.fromX][m.fromY]->setTeam(0);
		//otherwise, its a jump
	} else {
		int xDirection = m.toX - m.fromX;
		//if red, move red
		if(fromPiece->getTeam() == 1){
			checkerBoard[m.toX + xDirection][m.toY + 1]->setType(fromPiece->getType());
			checkerBoard[m.toX + xDirection][m.toY + 1]->setTeam(1);
			//if black, move black
		} else if(fromPiece->getTeam() == 2){
			checkerBoard[m.toX + xDirection][m.toY - 1]->setType(fromPiece->getType());
			checkerBoard[m.toX + xDirection][m.toY - 1]->setTeam(2);
		}
		//set the original position, and the piece you jump over, cleared
		checkerBoard[m.fromX][m.fromY]->setType(0);
		checkerBoard[m.fromX][m.fromY]->setTeam(0);
		checkerBoard[m.toX][m.toY]->setType(0);
		checkerBoard[m.toX][m.toY]->setTeam(0);
	}
}

move2 Board::pickMove(int turn){
	bool done = false;
	moveSet mSet = getPossibleMoves();
	move2* moves = mSet.moves;
	int numMoves = mSet.size;

	int bufferRandom = rand() % 14;
	int randomMoveNum;

	//pick a random move as long as its for the correct team and print it
	while(!done){
		randomMoveNum = (rand() % numMoves);
		move2 randomMove = moves[randomMoveNum];
		if(checkerBoard[randomMove.fromX][randomMove.fromY]->getTeam() == turn){
			done = true;
		}
	}

	return moves[randomMoveNum];
}

void Board::updateKings(){
	for(int i = 0; i < CHECKERBOARDCOLS; i++){
		for(int j = 0; j < CHECKERBOARDROWS; j++){
			Piece* p = checkerBoard[j][i];
			if(p->getTeam() == 1 && p->getY() == CHECKERBOARDROWS - 1){
				checkerBoard[j][i]->setType(2);
			} else if(p->getTeam() == 2 && p->getY() == 0){
				checkerBoard[j][i]->setType(2);
			}
		}
	}
}

