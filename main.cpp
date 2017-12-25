#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>

using namespace std;

// return false for invalid move, true for valid move
bool validDiagonal (int board[][8], int inputRow, int inputCol, int outputRow,
int outputCol, int piece)
{
	// diagonol check
	if (abs(inputRow - inputCol) != abs(outputRow-outputCol))
	{
		return false; 
	}

	int blackWhite = 0;
	int rowDist = outputRow - inputRow;
	int colDist = outputCol - inputCol;
	
	if (piece >= 7 && piece <= 12) // check if piece is white
	{
		blackWhite++; // 1 is white
	}
	else // check if piece is black
	{
		// 0 is false
	}
	
	while (inputRow != outputRow && inputCol != outputCol)
	{
		// if desired move is down and right from current position
		if (rowDist > 0 && colDist > 0) 
		{
			inputRow++;
			inputCol++;
		}
		// if desired move is down and left from current position
		else if (rowDist > 0 && colDist < 0)
		{
			inputRow++;
			inputCol--;
		}
		// if desired move is up and left from current position
		else if (rowDist < 0 && colDist < 0)
		{
			inputRow--;
			inputCol--;
		}
		// if desired move is up and right from current position 
		else if (rowDist < 0 && colDist > 0)
		{
			inputRow--;
			inputCol++;
		}
		int inputRC = board[inputRow][inputCol]; // current position
		if (blackWhite == 1) // white piece
		{
			if (inputRC >= 7 && inputRC <=12) //blocked by same color piece
			{
				return false;
			}
			else if (inputRC != 0) // check if opposite piece
			{
				if(inputRow == outputRow && inputCol == outputCol) // take opposite piece
				{
					return true;
				}
				else // if moved past opposite color piece return false
				{
					return false;
				}
			}
		}
		else
		{
			if (inputRC >= 1 && inputRC <= 6) //blocked by same color piece
			{
				return false;
			}
			else if (inputRC != 0) // check if opposite piece
			{
				if(inputRow == outputRow && inputCol == outputCol) // take opposite piece
				{
					return true;
				}
				else // if moved past opposite color piece return false
				{
					return false;
				}
			}
		}	
	}
	return true;
}

bool validUD(int board[][8], int inputRow, int inputCol, int outputRow,
int outputCol, int piece)
{
	// up down check
	if (inputRow != outputRow && inputCol != outputCol)
	{
		return false;
	}

	int blackWhite = 0;
	int rowDist = outputRow - inputRow;
	int colDist = outputCol - inputCol;

	if (piece >= 7 && piece <= 12) // check if piece is white
	{
		blackWhite++; // 1 is white
	}
	else // check if piece is black
	{
		// 0 is false
	}

	while (inputRow != outputRow && inputCol != outputCol) 
	{
		if (rowDist > 0) // go down
		{
			inputRow++;

		}
		else if (rowDist < 0) // go up
		{
			inputRow--;
		}
		else if (colDist > 0) // go right
		{
			inputCol++;
		}
		else if (colDist < 0) // go left
		{
			inputCol--;
		}
		int inputRC = board[inputRow][inputCol];
		if (blackWhite == 1) // white piece
		{
			if (inputRC >= 7 && inputRC <=12) //blocked by same color piece
			{
				return false;
			}
			else if (inputRC != 0) // check if opposite piece
			{
				if(inputRow == outputRow && inputCol == outputCol) // take opposite piece
				{
					return true;
				}
				else // if moved past opposite color piece return false
				{
					return false;
				}
			}
		}
		else
		{
			if (inputRC >= 1 && inputRC <= 6) //blocked by same color piece
			{
				return false;
			}
			else if (inputRC != 0) // check if opposite piece
			{
				if(inputRow == outputRow && inputCol == outputCol) // take opposite piece
				{
					return true;
				}
				else // if moved past opposite color piece return false
				{
					return false;
				}
			}
		}	
	}
}

// does not include en passant
bool validPawn(int board[][8], int inputRow, int inputCol, int outputRow,
int outputCol, int piece)
{
	int blackWhite = 0;
	int rowDist = outputRow - inputRow;
	int colDist = outputCol - inputCol;
	
	// logic is wrong, bugged, illegal instruction core dumped
	if ((inputRow != 6 || inputRow != 1) && (abs(rowDist) > 1 || abs(colDist) > 1))
	{
		return false; 
	}
	if ((inputRow == 6 || inputRow == 1) && ((abs(rowDist) > 2) || (abs(colDist) > 1) || (abs(rowDist) == 2 && colDist != 0)))
	{
		return false;
	}

	if (piece >= 7 && piece <= 12) // check if piece is white
	{
		blackWhite++; // 1 is white
	}
	else // check if piece is black
	{
		// 0 is false
	}

	if (blackWhite ==1) // white piece
	{
		if (inputRow -1 == outputRow || inputRow -2 == outputRow) // go forward 1 or 2 squares
		{
			if (board[inputRow -1][inputCol] != 0) // square directly in "front" has to be empty
			{
				return false;
			}
		} 
		else // move diagnolly 
		{
			if (board[outputRow][outputCol] < 1 || board[outputRow][outputCol] > 6) // has to be opposite color piece
			{
				return false;
			}
		}
	}
	else // black piece
	{
		if (inputRow +1 == outputRow || inputRow +2 == outputRow) // go forward 1 or 2 squares
		{
			if (board[inputRow +1][inputCol] != 0) // square directly in "front" has to be empty
			{
				return false;
			}
		} 
		else // move diagnolly 
		{
			if (board[outputRow][outputCol] < 7 || board[outputRow][outputCol] > 12) 
			{
				return false;
			}
		}
	}
	return true;
}


void printBoard(int board[][8])
{
	int cCounter = 1;
    cout << "  a  b  c  d  e  f  g  h" << endl;
	for (int i = 0; i < 8; i++)
	{
	    for (int j = 0; j <8; j++)
	    {
	    	if (j == 0)
	    	{
	    		cout << cCounter << " ";
	    	}
	    	if (board[i][j] == 1) // print black pieces
	    	{
	    		cout << "BP" <<  " ";
	    	}
	    	else if (board[i][j] == 3 )
	    	{
	    		cout << "BB" << " ";
	    	}
	    	else if (board[i][j] == 2)
	    	{
	    		cout << "BH" << " ";
	    	}
	    	else if (board[i][j] == 4)
	    	{
	    		cout << "BR" << " ";
	    	}
	    	else if (board[i][j] == 5)
	    	{
	    		cout << "BQ" << " ";
	    	}
	    	else if (board[i][j] == 6 )
	    	{
	    		cout << "BK" << " ";
	    	}
	    	else if (board[i][j] == 7 ) // print white pieces
	    	{
	    		cout << "WP" <<  " ";
	    	}
	    	else if (board[i][j] == 9 )
	    	{
	    		cout << "WB" << " ";
	    	}
	    	else if (board[i][j] == 8)
	    	{
	    		cout << "WH" << " ";
	    	}
	    	else if (board[i][j] == 10)
	    	{
	    		cout << "WR" << " ";
	    	}
	    	else if (board[i][j] == 11)
	    	{
	    		cout << "WQ" << " ";
	    	}
	    	else if (board[i][j] == 12)
	    	{
	    		cout << "WK" << " ";
	    	}
	    	else 
	    	{
	    		cout << "00" << " ";
	    	}

	        
	    }
	    cCounter++;
	    cout << endl;
	}
}

void initialize(int board[][8])
{

   for (int i =0; i < 8; i++)
   {
       for (int j = 0; j < 8; j++)
       {
           if (i == 1)
           {
                board[i][j] = 01; // fill black pawns
           }
           else if (i == 6)
           {
                board[i][j] = 7; // fill white pawns
           }
           else if (i== 0)
           {
               board[i][0] = 4; // fill black
               board[i][7] = 4;
               board[i][1] = 2;
               board[i][6] = 2;
               board[i][2] = 3;
               board[i][5] = 3;
               board[i][3] = 5;
               board[i][4] = 6;
           }
           else if (i == 7)
           {
               board[i][0] = 10;
               board[i][7] = 10;
               board[i][1] = 8;
               board[i][6] = 8;
               board[i][2] = 9;
               board[i][5] = 9;
               board[i][3] = 11;
               board[i][4] = 12;
           }
           else
           {
               board[i][j] = 0;
           }
       }
   }
}
// return -1 if invalid
// return 1 if valid

int moveInput(string input, int board[][8], int turnCounter)
{
	string rowCoor = "12345678";
	string colCoor = "abcdefgh";
	bool valid1 = false;
	bool valid2 = false;
	bool valid3 = false;
	bool valid4 = false;
	int inputCol;
	int inputRow;
	int outputCol;
	int outputRow;
	
	for (int i =0; i < 8; i++)
	{
		if(input[0] == colCoor[i])
		{
			valid1 =true;
		}
		if(input[1] == rowCoor[i])
		{
			valid2 = true;
		}
		if(input[3] == colCoor[i])
		{
			valid3 = true;
		}
		if(input[4] == rowCoor[i])
		{
			valid4 = true;
		}
	}

	if (input.size() != 5 || input[2] != '-' || valid1 == false || valid2 ==false || valid3 == false|| valid4 == false)
	{
		return -1;
	}
	
	for (int i =0; i< 8; i++)
	{
		if(input[0] == colCoor[i])
		{
			inputCol = i;
		}
		if (input[1] == rowCoor[i])
		{
			inputRow = i;
		}
		if (input[3] == colCoor[i])
		{
			outputCol = i;
		}
		if (input[4] == rowCoor[i])
		{
			outputRow = i;
		}

	}
	if (inputRow == outputRow && inputCol == outputCol) // cant move in place
	{
		return -1;
	}

	//valid player check
	int inputRC = board[inputRow][inputCol];
	//int outputRC = board[outputRow][outputCol];
	bool diagonol = validDiagonal(board, inputRow, inputCol, outputRow, outputCol, inputRC);
	bool upDown = validUD(board, inputRow, inputCol, outputRow, outputCol, inputRC);
	bool pawnMove = validPawn(board, inputRow, inputCol, outputRow, outputCol, inputRC);
	if (inputRC == 0)
	{
		return -1;
	}
	if(turnCounter%2 == 0) // white move
	{
		// check if white piece
		if (inputRC > 12 || inputRC < 7) 
		{
			return -1;
		}
		if (inputRC == 7) // pawn move
		{
			if (pawnMove == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 9) // bishop
		{
			if (diagonol == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 10) // rook
		{
			if (upDown == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 11) // queen
		{
			if (upDown == 0 && diagonol == 0)
			{
				return -1;
			}
		}
	}
	else // black move
	{
		// check if black piece
		if (inputRC < 1 || inputRC > 6)
		{
			return -1;
		}
		if (inputRC == 1)
		{
			if (pawnMove == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 3)
		{
			if (diagonol == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 4)
		{
			if (upDown == 0)
			{
				return -1;
			}
		}
		else if (inputRC == 5) // queen
		{
			if (upDown == 0 && diagonol == 0)
			{
				return -1;
			}
		}
	}
	//old
	board[outputRow][outputCol] = board[inputRow][inputCol];
	board[inputRow][inputCol] = 0;

	return 1;
}

int main()
{
	bool win = false;
	int turnCounter= 0;
    int board[8][8];
    initialize(board);
    // 0 = empty
    // 1-6 black, 1 = pawn, 2 = knight, 3 = bishop,
    // 4 = rook, 5 = queen, 6 = king
    // 7-12 white, 7 = pawn, 8 = knight, 9 = bishop,
    // 10 = rook, 11 = queen, 12 = king

    while (true)
    {
    	
    	printBoard(board);
    	string move;
    	if (turnCounter%2 == 0)
    	{
    		cout << "White's turn: ";
    	}
    	else
    	{
    		cout << "Black's turn: ";
    	}

    	cin >> move;
    	
    	
    	
    	int moveCheck = moveInput(move,board, turnCounter);

    	

    	if (moveCheck == -1)
    	{
    		cout << "Invalid input" << endl;
    		//cin.clear();
    		//cin.ignore(INT_MAX);
    		continue;
    	}

    	turnCounter++;

    	
    }

  
    
    return 0;
}