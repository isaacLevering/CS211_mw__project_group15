#include <iostream>
#include <fstream>
#include "2048_helper.h"
using namespace std;

int main(int argc, char* argv[])
{
    //initializing   
    int score=0;                       
    bool win = false;
    bool game=false;
	int size = 5;
	int moves=0;
	int high_tile = 4;
	int board[5][5] = {
		{0, 4, 2, 4, 0},
		{0, 0, 0, 0, 0},
		{2, 0, 2, 0, 2},
		{0, 0, 2, 0, 0},
		{2, 2, 2, 2, 2},
	};
	//while getch == x loop for up down left right
	char choice = 'u'; //initialized
	
	//begin the start menu
    cout<<"                       WELCOME TO 2048!                             "<<endl;         //Creates the basic menu for starting the game
    cout<<endl<<"           [y] to play                 [n] to stop             "<<endl;
    cin>>choice;
    if(choice=='y')     //if y is pressed, start the game
    {
        game=true;
        choice='u';
    }
    else if(choice=='n')     //if n is pressed, do not start game
    {
        game=false;
        cout<<endl<<"GAME NOT STARTED...";
        return 0;
    }
    else                    //if any other input is pressed do not start game
    {
        cout<<endl<<"GAME NOT STARTED...";
        return 0;
    }

    //begin game
    while(game==true)
    {
	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	while (choice != 'e')
	{
	    cout<<"Moves: "<<moves<<endl;       //displays moves
        cout<<"Score: "<<score<<endl;       //displays score
        cout<<"Highest Tile: "<<highest_tile(board, high_tile, size)<<endl;     //displays the highest title
		cout << "Please enter choice:{u,d,l,r,h,s,o,e} for UP, DOWN, LEFT, RIGHT, HELP, SAVE, OPEN, Exit: " << endl;        //displays options
		cout << "Choice: ";     //asks for choice
		cin >> choice;          //get the choice

		if (choice == 'u')              //completes the function while adding to the number of moves, as well as generating the next random number
		{
			move_up(board, score, win, size);
			moves++;
			insert_random(board, size);
			print_board(board);
		}
		else if (choice == 'd')         //completes the function while adding to the number of moves, as well as generating the next random number
		{
			move_down(board, score, win, size);
			moves++;
			insert_random(board, size);
			print_board(board);
		}
		else if (choice == 'l')         //completes the function while adding to the number of moves, as well as generating the next random number
		{
			move_left(board, score, win, size);
			moves++;
			insert_random(board, size);
			print_board(board);
		}
		else if (choice == 'r')         //completes the function while adding to the number of moves, as well as generating the next random number
		{
			move_right(board, score, win, size);
			moves++;
			insert_random(board, size);
			print_board(board);
		}
		else if (choice == 'h')     //creates the HELP menu with directions for the game
		{
            cout<<endl<<"The Goal of 2048 is to match numbered tiles to 2048, using the UP, DOWN, LEFT, or RIGHT functions,";
            cout<<endl<<"try not to let the board fill up with numbers that cannot be matched to a neighboring tile!"<<endl;
            cout<<endl<<"GOOD LUCK!"<<endl;
            print_board(board);
		}
        else if (choice == 's')     //saves the game as "CS211_2048_V1" and confirms that it was saved
        {
            ofstream output("CS211_2048_V1");
            output << score << endl;
            output << moves << endl;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    output << board[i][j] << " ";
                }
                output << endl;
            }
            print_board(board);
            cout<<"SAVE COMPLETE!"<<endl;
        }   
        else if (choice == 'o')     //opens the previously saved game "CS211_2048_V1" and confirms that it was opened
        {
            ifstream input("CS211_2048_V1");
            input >> score;
            input >> moves;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    input >> board[i][j];
                }
            }
            print_board(board);
            cout<<"SAVE LOADED!"<<endl;
        }
        else if(choice=='e')        //if 'e' is selected during the span of the game, display this and exit
        {
            cout<<"EXITING...";
            return 0;
        }
        else                    //do not accept any additional inputs from the ones allowed
        {
            cout<<endl<<"INVALID INPUT..."<<endl;
            print_board(board);
        }
		
		//print_board(board);

		
		if(win==true)           //If you get to 2048, display this while allowing further play
		{
            cout<<endl<<"You Win!";
		}
		else if(check_loss(board, size)==true)      //if you lose, display this and end game
		{
            cout<<endl<<"You Lost!";
            return 0;
		}

	}
}

	return 0;
}
