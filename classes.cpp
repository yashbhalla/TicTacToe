#include<iostream>
using namespace std;

class Board {
	char positions[3][3];
	char winner;
public:
	Board() {
		winner = 'z'; //not determined or tie
		for (int i=0; i<3; i++){
			for( int j=0; j<3; j++)
				positions[i][j]= '-'; //set all positions to - initially
		}
	}
	
	char getPosition(int row, int column) {
		return positions[row][column]; //return the position on the board
	}
	
	int setPosition (int i, int j, char user) {
		if (positions[i][j] == '-'){
			positions[i][j] = user; //set the position to user char
			return 0;
		}
		else 
			return -1; //position already taken
	}
	
	char checkRows() { //check rows for winner
		int threeX = 0;
		int threeO = 0;
		for(int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				if (positions[i][j]=='x')
					threeX++;
				if (positions[i][j]=='o')
					threeO++;
				if(threeX==3){
					winner='x';
					return 'x'; //x has 3 in a row
				}
				if(threeO==3){
					winner='o';
					return 'o'; //o has 3 in a row
				}
			}
			threeX=0;
			threeO=0;
		}
		return 'z'; //no winner yet
	}
	
	char checkColumns() {
		int threeX=0;
		int threeO=0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(positions[j][i]=='x')
					threeX++;
				if(positions[j][i]=='o')
					threeO++;
				if(threeX==3){
					winner='x';
					return 'x'; //x has 3 in a column
				}
				if(threeO==3){
					winner='o';
					return 'o'; //o has 3 in a column
				}
			}
			threeX=0;
			threeO=0;
		}
		return 'z'; //no winner yet
	}
	
	char checkDiagonals() {
		int threeX=0;
		int threeO=0;
		//first we'll check the left diagonal
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(i==j){
					if(positions[i][j]=='x')
						threeX++;
					if(positions[i][j]=='o')
						threeO++;
					if(threeX==3){
						winner='x';
						return 'x'; // x has 3 in a diagonal
					}
					if(threeO==3){
						winner='o';
						return 'o'; // o has 3 in a diagonal
					}
				}
			}
		}
		threeX=0;
		threeO=0;
		//now we'll check the right diagonal
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(i+j==2){
					if(positions[i][j]=='x')
						threeX++;
					if(positions[i][j]=='o')
						threeO++;
					if(threeX==3){
						winner='x';
						return 'x'; // x has 3 in a diagonal
					}
					if(threeO==3){
						winner='o';
						return 'o'; // o has 3 in a diagonal
					}
				}
			}
		}
		return 'z'; //no winner yet
	}
	
	char determineWinner(){
		char winner = 'z';
		winner =checkRows(); //check rows
		if (winner=='z')
			winner=checkColumns(); //check columns
		if(winner=='z')
			winner=checkDiagonals(); //check diagonals
		return winner;
	}
};
