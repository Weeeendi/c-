
#include <stdio.h>
#include<stdlib.h>
#define SIZE 9

//Function prototypes
void display(char (*board)[SIZE]);

int main(int argc, char **argv)
{
	char board[SIZE][SIZE];
	int row=0;
	int col=0;
	char again=0;

	printf("\nREVERSI\n\n");
	printf("You can go first on the first game,then we will take turns.\n");
	printf(" You will be white-(O)\n Iwill be black-(x).\n");
	printf("Select a square for your move by typing a digit for the row\n "
			"and a letter for the column with no space between.\n");
	printf("\nGood luck! Press Enter to start.\n");
	scanf("%c",&again);

	//Blank all the board squares
	for(row=0;row<SIZE;row++)
		for(col=0;col<SIZE;col++)
			board[row][col]=' ';

	//Place the initial four counters in the center
	board[SIZE/2-1][SIZE/2-1]=board[SIZE/2][SIZE/2]='O';
	board[SIZE/2-1][SIZE/2]=board[SIZE/2][SIZE/2-1]='X';

	display(board);
	system("pause");//ÔÝÍ£
	return 0;
	
}

//The function to display the board
void display(char (*board)[SIZE])
{
	int row=0;
	int col=0;
	char col_label='a';

	printf("\n");
	for(col=0;col<SIZE;col++)
		printf("   %c",col_label+col);
	for(row=0;row<SIZE;row++)
	{
		printf("\n");
		printf(" +");
		for(col=0;col<SIZE;col++)
			printf("---+");
		printf("\n%d|",row+1);
		for(col=0;col<SIZE;col++)
			printf(" %c |",board[row][col]);
	}
	printf("\n +");
	for(col=0;col<SIZE;col++)
		printf("---+");
	printf("\n");
}
