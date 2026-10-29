#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	  for (int i = 0; i < 5; ++i) 
		{
        int targetlocation = 0;
		//goal location for all numbers to start
        bool merged[5] = {false,false,false,false,false};
//this array tracks merges on each row to insure no double merge

        for (int j = 0; j < 5; ++j) 
		{
            if (board[i][j] != 0)
			 {
				//this starts the move and weeds out zeroes
                int val = board[i][j];
                board[i][j] = 0;

                // can this be merged?
                if (targetlocation > 0 and board[i][targetlocation - 1] == val and !merged[targetlocation - 1]) {
                    board[i][targetlocation - 1] *= 2;
					//the actual merge happens here
                    merged[targetlocation - 1] = true;
                } 
				else 
				{
                    board[i][targetlocation] = val;
					//sets the furthest left 0 value to the number
                    targetlocation++;
                }
			}
            
        }
    }
}

void move_right(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
