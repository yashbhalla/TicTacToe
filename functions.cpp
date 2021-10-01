#include <iostream>
#include <limits>
using namespace std;

void getUserNames(string &userX, string &userO){ 
	cout<<"\nPlayer X, enter your name:\t";
	cin>>userX; //input player X name
	cout<<"\nPlayer O, enter your name:\t";
	cin>>userO; //input player Y name
	cout<<endl;
	return;
}

void printBlankBoard(){ //print blank board with numbered squares
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<" ("<<i+1<<","<<j+1<<") ";
			if(j==0 || j==1)
				cout<<"|";
		}
		cout<<endl;
	}
	return;
}

void printBoard(Board &boardIn){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<" "<<boardIn.getPosition(i,j)<<" ";
			if(j==0 || j==1)
				cout<<"|";
		}
		cout<<endl;
	}
	return;
}

void printUserPrompt(string nameIn, char letter){
	cout<<nameIn<<", where would you like to place your "<<letter<<"?\t";
	return;
}

void printWinner(Board &boardIn, string nameX, string nameO){
	char winner = boardIn.determineWinner();
	if(winner=='x')
		cout<<"Congrats "<<nameX<<"! You won!\n";
	if(winner=='o')
		cout<<"Congrats "<<nameO<<"! You won!\n";
	return;
}

int getRow(){
	int row;
	cout<<"\nEnter a row: 1, 2 or 3:\t";
	cin>>row;
	return row;
}

int getColumn(){
	int col;
	cout<<"\nEnter a column: 1, 2 or 3:\t";
	cin>>col;
	return col;
}

void checkResponse(Board &boardIn, char input) {
	int row, col, userInput=0;
	do {
		row=getRow()-1;
		col=getColumn()-1;
		userInput=boardIn.setPosition(row, col, input);
		if (userInput==-1)
			cout<<"This position is already taken! Try again!\n";
	} while (userInput==-1);
}
