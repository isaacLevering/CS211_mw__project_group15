#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int& points, bool& winner, int numrows = 5)      //function for moving left
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
                if (targetlocation > 0 and board[i][targetlocation - 1] == val and !merged[targetlocation - 1]) 
                {
                    if(board[i][targetlocation - 1]*2==2048) //win condition for when a tile gets to 2048
                   {
                        winner=true;
                   }
                    points=board[i][targetlocation - 1]*2+points;   //adds the new tile number to the score
                    
                    board[i][targetlocation - 1]*= 2;
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

void move_right(int board[][5], int& points, bool& winner, int numrows = 5)     //function for moving right
{
	//CODE HERE
	 for (int i = 4; i >= 0; --i) 
		{
        int targetlocation = 4;
		//goal location for all numbers to start
        bool merged[5] = {false,false,false,false,false};
//this array tracks merges on each row to insure no double merge

        for (int j = 4; j >= 0; --j) 
		{
            if (board[i][j] != 0)
			 {
				//this starts the move and weeds out zeroes
                int val = board[i][j];
                board[i][j] = 0;

                // can this be merged?
                if (targetlocation < 4 and board[i][targetlocation + 1] == val and !merged[targetlocation + 1]) 
                {
                    if(board[i][targetlocation + 1]*2==2048) //win condition for when a tile gets to 2048
                   {
                        winner=true;
                   }
                    points=board[i][targetlocation + 1]*2+points;   //adds the new tile number to the score
                    
                    board[i][targetlocation + 1] *= 2;
					//the actual merge happens here
                    merged[targetlocation + 1] = true;
                } 
				else 
				{
                    board[i][targetlocation] = val;
					//sets the furthest right 0 value to the number
                    targetlocation--;
                }
			}
            
        }
    }
}

void move_up(int board[][5], int& points, bool& winner, int numrows = 5)        //function for moving up
{
	//CODE HERE
		for (int i = 0; i < 5; ++i) 
		{
        int targetlocation = 0;
		//goal location for all numbers to start
        bool merged[5] = {false,false,false,false,false};
//this array tracks merges on each row to insure no double merge

        for (int j = 0; j < 5; ++j) 
		{
            if (board[j][i] != 0)
			 {
				//this starts the move and weeds out zeroes
                int val = board[j][i];
                board[j][i] = 0;

                // can this be merged?
                if (targetlocation > 0 and board[targetlocation - 1][i] == val and !merged[targetlocation - 1]) 
                {
                    if(board[targetlocation - 1][i]*2==2048) //win condition for when a tile gets to 2048
                   {
                        winner=true;
                   }
                    points=board[targetlocation - 1][i]*2+points;   //adds the new tile number to the score
                    
                    board[targetlocation - 1][i] *= 2;
					//the actual merge happens here
                    merged[targetlocation - 1] = true;
                } 
				else 
				{
                    board[targetlocation][i] = val;
					//sets the furthest up 0 value to the number
                    targetlocation++;
                }
			}
        }
    }
}

void move_down(int board[][5], int& points, bool& winner, int numrows = 5)      //function for moving down
{
//CODE HERE
		for (int i = 4; i >= 0; --i) 
		{
        int targetlocation = 4;
		//goal location for all numbers to start
        bool merged[5] = {false,false,false,false,false};
//this array tracks merges on each row to insure no double merge

        for (int j = 4; j >= 0; --j) 
		{
            if (board[j][i] != 0)
			 {
				//this starts the move and weeds out zeroes
                int val = board[j][i];
                board[j][i] = 0;

                // can this be merged?
                if (targetlocation < 4 and board[targetlocation + 1][i] == val and !merged[targetlocation + 1]) 
                {
                    if(board[targetlocation + 1][i]*2==2048) //win condition for when a tile gets to 2048
                   {
                        winner=true;
                   }
                    points=board[targetlocation + 1][i]*2+points;   //adds the new tile number to the score
                    
                    board[targetlocation + 1][i] *= 2;
					//the actual merge happens here
                    merged[targetlocation + 1] = true;
                } 
				else 
				{
                    board[targetlocation][i] = val;
					//sets the furthest down 0 value to the number
                    targetlocation--;
                }
			}
            
        }
    }
}

bool check_loss(int board[][5], int numrows=5)      //Checks board to see if it may be full swithout a possible move
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // Check for an empty cell
            if (board[i][j] == 0)
            {
                return false;
            }

            // Check the cell to the right
            if (j < 4 && board[i][j] == board[i][j + 1])
            {
                return false;
            }
            
            //check the cell to the left
             if (j > 0 && board[i][j] == board[i][j - 1])
            {
                return false;
            }

            // Check the cell below
            if (i < 4 && board[i][j] == board[i + 1][j])
            {
                return false;
            }
            
            //check the cell above
            if (i > 0 && board[i][j] == board[i - 1][j])
            {
                return false;
            }
        }
    }

    // No empty cells or possible merges
    return true;
}


void print_board(int board[][5], int numrows = 5)       //prints board
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


void insert_random(int board[][5], int numrows = 5)     //inserts a random number to the board
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
}

int highest_tile(int board[][5], int& high, int numrows=5) //finds the highest tile within the board
{
    for(int i=0; i<5; i++)      
    {
        for(int k=0; k<5; k++)
        {
            if(board[i][k]>=high)   
            {
                high=board[i][k];
            }
        }
    }
    return high; //returns the largest number found on the board
}
    
    
    
    
    
    

