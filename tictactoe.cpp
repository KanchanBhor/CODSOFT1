#include <iostream>
using namespace std;
//function to draw the Tic-Toe board
void drawBoard(char board[3][3])
{
	cout<<"-------------\n";
	for(int i=0;i<3;i++){
		cout<<"|";
		for(int j=0;j<3;j++){
			cout<<board[i][j]<<"|";
		}
		cout<<"\n-------------\n";
	}
}
//function to check for win
bool checkWin(char board[3][3],char player)
{
	//check rows,columns and diagonals
	for(int i=0;i<3;i++){
		if(board[i][0]==player&&board[i][1]==player&&board[i][2]==player)
		return true;
			if(board[0][i]==player&&board[1][i]==player&&board[2][i]==player)
			return true;
	}
	if(board[0][0]==player && board[1][1]==player && board[2][2] == player)
	return true;
		if(board[0][2]==player && board[1][1]==player && board[2][0] == player)
		return true;
	return false;
}
int main()
{
	system("cls");
	system("color E0");
	//initialize the board and players
	char board[3][3]={{' ',' ',' '},
	                   {' ',' ',' '},
	                   {' ',' ',' '}
					   };
   char	player='X';
   int row,col;
   int turn;//declare turn here
   cout<<"welcome to Tic- Tae-Toe!!!\n";
   //game loop
   for(turn=0;turn<9;turn++){
   	//draw the board
   	drawBoard(board);
   	//prompt for valid input
   	while(true){
   		cout<<"player"<<player
   		<<", enter row(0-2) and column(0-2):";
   		cin>>row>>col;
   		if(board[row][col]!= ' '|| row<0||row>2||col<0||col>>2){
   			cout<<"Invalid move...try again.\n";
		   }
		   else{
		   	break;//valid input,exit the loop
		   }
	   }
	   //make the move
	   board[row][col]=player;
	   //check for win after making a move
	   if(checkWin (board,player)){
	   	drawBoard(board);
	   	cout<<"player"<<player<<"win!\n";
	   	break;
	   }
	   //switch to the other player
	   player=(player=='X'?'O':'X');
   }	
   //END THE GAME
   drawBoard(board);
   //check foe a draw
   if(turn==9&& !checkWin(board,'X')&& !checkWin(board,'O')){
   	cout<<"its a draw!!\n";
   }			   
	return 0;				   
					   
	
	
}
