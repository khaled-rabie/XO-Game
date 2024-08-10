#include <iostream>
using namespace std;

 
 /*
 draw the board
	 ---------------
     |    |    |    |
     ---------------
     |    |    |    |
     ---------------
     |    |    |    |
     ---------------

	 we observe that there is -- on even rows and | on odd
   */
void DrawBoard(char board[3][3])
{
	for (int rows = 0; rows < 7; rows++)
	{
		if (!(rows % 2))//if(i % 2 == 0) because there is -- on even rows 0 2 4 6
		{
			for (int j = 0; j < 15; j++)
			{
				cout << "-";
			}
		}

		else  // odd rows we print |     
		{
			for (int j = 0; j < 4; j++)
			{
				/* 
				to put the x or o 
				 0 0 0 1 0 2   
                 1 0 1 1 1 2
                 2 0 2 1 2 2
				  |    |     |      |        on rows 1 ,3 5
				  board[rows / 2][j] && j < 3 this formul to get the position to pit the x or o 
				 */
				if (board[rows / 2][j] && j < 3) 
				{
					cout << "|  " << board[rows / 2][j] << " ";
				}
				else
				{
					cout << "|    ";
				}
			}
		}
		cout << endl;
	}
}


char CheckWinner(char board[3][3])
{
	//Check horizontally 
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1]
			&& board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}


	//Check vertically 
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i]
			&& board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	// check diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ')
	{
		return board[0][0];
	}


	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] &&
		board[2][0] != ' ')
	{
		return board[2][0];
	}


	return ' ';
}

void StartGame(char Board[3][3])
{
char gameOver = ' '; // if ' ' then draw x x win o  o win
bool isX = true; 
DrawBoard(Board);
int placed = 0; // every turn placed++ when placed ==9 and no one win so draw 
do
{
	cout << "Please choose which block: ";
	int x, y;
	cin >> x >> y;

	// check if the position filled or the postion out of the range
	while (Board[x][y] != ' ' || x > 2 || x < 0 || y > 2 || y < 0)
	{

		cout << "Already filled location! Please choose again! " << endl;
		cin >> x >> y;
	}


	if (isX)
	{
		Board[x][y] = 'X';
	}
	else
	{
		Board[x][y] = 'O';
	}


	placed++;
	DrawBoard(Board);
	gameOver = CheckWinner(Board); // check winner rtunn character who win x or o or if ' ' then draw
	if (gameOver == ' ' && placed == 9)
	{
		cout << "Game over! No one won!" << endl;
		break;
	}


	isX = !isX; // turn to o next turn
} while (gameOver == ' ');


if (gameOver == 'X')
{
	cout << "X won!" << endl;
}
else if (gameOver == 'Y')
{
	cout << "Y won!" << endl;
}
}
void main()
{
	
	char Board[3][3];
	// fill the 2d array with ' ' (default)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Board[i][j] = ' ';
		}
	}

	StartGame(Board);

	
	cin.get();
}