
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "2048_helper.h"
using namespace std;

int main(int argc, char* argv[])
{
    //initializing   
    int score=0;                       
    bool win = false;
    bool game=false;
    bool save=false;
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
    cout<<"                       WELCOME TO 2048!                             "<<endl;
    cout<<endl<<"           [y] to play                 [n] to stop             "<<endl;
    cin>>choice;
    if(choice=='y') //begin game
    {
        game=true;
        choice='u';
    }
    else if(choice=='n') //do not begin game
    {
        game=false;
        cout<<endl<<"GAME NOT STARTED...";
        return 0;
    }
    else
    {
        cout<<endl<<"GAME NOT STARTED...";
        return 0;
    }

    //begin game
    while(game==true)
    {
        cout << "Initial Board : [5x5] :" << endl;
        print_board(board);

        while (choice != 'e')		//while it is not e continue game process
        {
            cout<<"Moves: "<<moves<<endl;
            cout<<"Score: "<<score<<endl;
            cout<<"Highest Tile: "<<highest_tile(board, high_tile, size)<<endl;
            cout << "Please enter choice:{u,d,l,r,h,s,o,e} for UP, DOWN, LEFT, RIGHT, HELP, SAVE, OPEN, Exit: " << endl;
            cout << "Choice: ";
            cin >> choice;

            if (choice == 'u')		//move up and track moves
            {
                move_up(board, score, win, size);
                moves++;
                insert_random(board, size);
                print_board(board);
            }
            else if (choice == 'd')		//move down and track moves
            {
                move_down(board, score, win, size);
                moves++;
                insert_random(board, size);
                print_board(board);
            }
            else if (choice == 'l')		//move left and track moves
            {
                move_left(board, score, win, size);
                moves++;
                insert_random(board, size);
                print_board(board);
            }
            else if (choice == 'r')		//move right and track moves
            {
                move_right(board, score, win, size);
                moves++;
                insert_random(board, size);
                print_board(board);
            }
            else if (choice == 'h')		//explain when choice is h
            {
                cout<<endl<<"The Goal of 2048 is to match numbered tiles to 2048, using the UP, DOWN, LEFT, or RIGHT functions,";
                cout<<endl<<"try not to let the board fill up with numbers that cannot be matched to a neighboring tile!"<<endl;
                cout<<endl<<"GOOD LUCK!"<<endl;
                print_board(board);
            }
            else if (choice == 's')		//save game as "CS211_2048_V1"
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
                save=true;
                cout<<"SAVE COMPLETE!"<<endl;
            }   
            else if (choice == 'o')			//when a game has saved, validate all saved aspects then load all to game
            {
                if(save==true)
                {
                    cout<<endl<<"Load?";
                    cout<<endl<<"[y] to confirm         [n] to deny"<<endl;
                    cin>>choice;
                    if(choice=='y')		//confirm choice
                    {
                        try
                        {
                            ifstream input("CS211_2048_V1");

                            if (!input)
                                throw runtime_error("Could not open save file.");

                            int loadedScore;
                            int loadedMoves;
                            int tempBoard[5][5];

                            input >> loadedScore;
                            input >> loadedMoves;

                            if (!input)
                                throw runtime_error("Invalid save data.");

                            if (loadedScore < 0 || loadedMoves < 0)
                                throw runtime_error("Invalid score or move count.");

                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5; j++)
                                {
                                    if (!(input >> tempBoard[i][j]))
                                        throw runtime_error("Invalid board data.");

                                    if (!valid_tile(tempBoard[i][j]))
                                        throw runtime_error("Invalid tile value!");
                                }
                            }

                            char extra;
                            if (input >> extra)
                                throw runtime_error("Unexpected extra data in save file.");

                            score = loadedScore;
                            moves = loadedMoves;

                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5; j++)
                                {
                                    board[i][j] = tempBoard[i][j];
                                }
                            }

                            print_board(board);
                            cout<<"SAVE LOADED!"<<endl;
                        }
                        catch (const runtime_error& e)
                        {
                            cout << "ERROR: " << e.what() << endl;
                            cout << "Save Not Loaded!" << endl;
                        }
                    }
                    else if(choice=='n')	//deny confirmation
                    {
                        print_board(board);
                        cout<<"Save Not Loaded!"<<endl;
                    }
                    else
                    {
                        print_board(board);
                        cout<<"Save Not Loaded!"<<endl;
                    }
                }
                if(save==false)		//no saved data
                {
                    print_board(board);
                    cout<<"No Save Available!"<<endl;
                }
            }
            else if(choice=='e')		//if e is chosen game becomes false
            {
                game=false;
            }
            else			//handles invalid input
            {
                cout<<endl<<"INVALID INPUT..."<<endl;
                print_board(board);
            }
        
		     if(game==false) 			//confirm game exit
            {
                cout<<"Exit Game?"<<endl;
                cout<<"[y] to confirm       [n] to keep playing"<<endl;
                cin>>choice;
                
                if(choice=='y')
                {
                    return 0;
                }
                else if(choice=='n')
                {
                    game=true;
                    print_board(board);
                }
                else
                {
                    game=true;
                    print_board(board);
                }
            }

            if(win==true)		//display this if win happens
            {
                cout<<endl<<"You Win!";
            }
            else if(check_loss(board, size)==true)		//if loss happens, show loss and end
            {
                cout<<endl<<"You Lost!";
                return 0;
            }
        }
    }

    return 0;
}
