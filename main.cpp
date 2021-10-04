//TicTacToe Main

#include "Classes.cpp"
#include "Functions.cpp"

int main(){
	Board game;
	string nameX, nameO; //player names
	char winner = 'z'; //stores winner
	int turns = 0; //counts number of turns
	
	cout<<"Welcome to tic-tac-toe!\n";
	cout<<"\n---GAMEBOARD---\n";
	printBlankBoard(); //prints board with numbered squares
	
	getUserNames(nameX, nameO);
	while (turns <8) {
		printBoard(game); // prints board
		printUserPrompt(nameX, 'X'); //player X's turn
		checkResponse(game, 'X'); //check if position is valid
		winner = game.determineWinner(); //check for winner
		
		if (winner != 'z'){ //if player X has won, end the game
			printBoard(game);
			printWinner(game, nameX, nameO);
			break;
		}
		
		printBoard(game); //print board
		printUserPrompt(nameO, 'O'); //player O's turn
		checkResponse(game, 'O'); //check if position is valid
		winner = game.determineWinner(); //check for winner
		
		if (winner != 'z'){ //if player O has won, end the game
			printBoard(game);
			printWinner(game, nameX, nameO);
			break;
		}
		turns+=2; //updates for each round
	}
	if(turns >= 8)
		cout<<"Game is tied!\n";
	return 0;
}
