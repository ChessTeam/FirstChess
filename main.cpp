#include <iostream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

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

	//valid player check
	int inputRC = board[inputRow][inputCol];
	int outputRC = board[outputRow][outputCol];
	if (inputRC == 0)
	{
		return -1;
	}
	if(turnCounter%2 == 0) // white move
	{
		if (inputRC > 12 || inputRC < 7)
		{
			return -1;
		}
		if (inputRC == 7)
		{
				if(inputRow == 6)
				{
					if (outputRow )
				}
		}
	}
	else // black move
	{
		if (inputRC < 1 || inputRC > 6)
		{
			return -1;
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