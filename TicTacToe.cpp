#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);
	
	

	while (true) {

	// The first player makes a move
	 	makeAMove(board, 'X');
	 	displayBoard(board);

	 	if (isWon('X', board)) {
	 		cout << "X player won" << endl;
	 		exit(0);
	 	}
	 	else if (isDraw(board)) {
	 		cout << "No winner" << endl;
	 		exit(0);
	 	}

	 	// The second player makes a move
	 	makeAMove(board, 'O');
	 	displayBoard(board);

	 	if (isWon('O', board)) {
	 		cout << "O player won" << endl;
	 		exit(0);
	 	}
	 	else if (isDraw(board)) {
	 		cout << "No winner" << endl;
	 		exit(0);
	 	}
	 }

	return 0;
} 

void displayBoard(char board[][3]){
	cout<<"-------------\n";
	cout<<"| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |\n";
	cout<<"-------------\n";
	cout<<"| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |\n";
	cout<<"-------------\n";
	cout<<"| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |\n";
	cout<<"-------------\n";
}
void makeAMove(char board[][3], char player)
{
	int column,row,occupied=0;
	do
	{
		cout<<"Enter a row (0, 1, 2) for player "<<player<<": ";
		cin>>row;
		cout<<"Enter a column (0, 1, 2) for player "<<player<<": ";
		cin>>column;
		for(int i = 0; i < 3; i++)
		{
		for(int j = 0; j < 3; j++)
		{
			if(i == row && j == column)
			{
				if(board[i][j] == ' ')
				{
					board[i][j] = player;
					occupied = 0;
				}
				else
				{
					cout<<"\nThis cell is already occupied. Try a different cell";
					occupied = 1;
					break;
				}
			}
		}
		}
	} while (occupied == 1);
	
}

bool isWon(char player, char board[][3])
{
	    //vertical win
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j){
				if(board[j][i] != player)
					break;
				if(j == 2)
					return true;
			}
		}

		//horisontal win 
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(board[i][j] != player)
					break;
				if(j == 2)
					return true;
			}
		}

		//Top Left to bottom Right Diagonal Win
		for(int i = 0; i < 3; ++i){
			if(board[i][i] != player)
				break;
			if(i == 2)
				return true;
		}
 
		//Top Right to Bottom Left Diagonal Win
		for(int i = 0; i < 3; ++i){
			if(board[2-i][i] != player)
				break;
			if(i == 2)
				return true;
		}
	

	return false;
	
}
bool isDraw(char board [][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(board[i][j] == ' ')
			return false;
		}
		
	}
	return true;
	
}