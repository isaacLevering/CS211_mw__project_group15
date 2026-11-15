**2048**  
Starting where the problem tells us to start, moving left takes two loops nested and a target location set to 0\. The first loop initializes an array with the size of five filled with  all falses to start. The program moves all numbers of a row first, then moves down to the next one.  When a number merges, it sets the leftmost number to itself\*2 and it sets the space in the array to true. A number cannot merge with another number when one has its space set to true. If there are no numbers in front of one as it moves, it moves until it hits the target number. The target number then increases. This ensures that no numbers will try to share a space without merging if they can. When a number merges, the score increases. If the merged number is 2048, a variable called win becomes true. This tells the program you won.  
	Similar principles are taken for the other directions, only adjusting whether the row or column gets moved. To check all spaces in case all are full, a function is run to see if all spaces are zero or not. If they are not zero, it tells a variable to become true. That variable tells the program that you lost. When “S” is input, The game saves to a file called “CS211\_2048\_V1”. This file takes the score, the moves input, and the board and saves them to the file.  If that file already exists, it overwrites it. It also tells the game that you saved. When you try to load, the program checks if the file is valid. If it is, it loads.

**Dry Run**  
The input will be L to go left.

| Board | i | j | merged | Target location | Val | Points | Winner |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |
| {0, 4, 2, 4, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2},  |  |  |  |  |  |  |  |
|  | 0 |  |  |  |  |  |  |
|  |  |  |  | 0 |  |  |  |
|  |  |  | {false,false,false,false,false} |  |  |  |  |
|  |  | 0 |  |  |  |  |  |
| {4, 0, 2, 4, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 1 |  | 1 | 4 |  |  |
| {4, 2, 0, 4, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 2 |  | 2 | 2 |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 3 |  | 3 | 4 |  |  |
|  |  | 4 |  |  |  |  |  |
|  |  | 5 |  |  |  |  |  |
|  | 1 |  |  |  |  |  |  |
|  |  |  | {false,false,false,false,false} |  |  |  |  |
|  |  |  |  | 0 |  |  |  |
|  |  | 0 |  |  |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  |  |  |  |  |  |  |
|  |  | 1 |  |  | 0 |  |  |
|  |  | 2 |  |  | 0 |  |  |
|  |  | 3 |  |  | 0 |  |  |
|  |  | 4 |  |  | 0 |  |  |
|  |  | 5 |  |  | 0 |  |  |
|  | 2 |  |  |  |  |  |  |
|  |  |  | {false,false,false,false,false} |  |  |  |  |
|  |  |  |  | 0 |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {2, 0, 2, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 0 |  |  | 2 |  |  |
|  |  |  |  | 1 |  |  |  |
|  |  | 1 |  |  |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 0, 0, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 2 | {true,false,false,false,false} | 1 |  | 4 |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 0, 0, 0, 2},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 3 |  |  | 0 |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 4 |  | 2 | 2 |  |  |
|  | 3 |  |  |  |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {0, 0, 2, 0, 0},         {2, 2, 2, 2, 2}, |  | 0 | {false,false,false,false,false} | 0 |  |  |  |
|  |  | 1 |  |  |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {2, 2, 2, 2, 2}, |  | 2 |  | 1 | 2 |  |  |
|  |  | 3 |  |  |  |  |  |
|  |  | 4 |  |  |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {2, 2, 2, 2, 2}, | 4 | 0 | {false,false,false,false,false} | 0 |  |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {4, 0, 2, 2, 2}, |  | 1 | {true,false,false,false,false} | 1 | 2 | 8 |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {4, 2, 0, 2, 2}, |  | 2 | {true,false,false,false,false} | 2 | 2 |  |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {4, 4,0 , 0, 2}, |  | 3 | {true,false,false,false,false} |  | 2 | 12 |  |
| {4, 2, 4, 0, 0},         {0, 0, 0, 0, 0},         {4, 2, 0, 0, 0},         {2, 0, 0, 0, 0},         {4, 4, 2, 0, 0}, |  | 4 | {true,true,false,false,false} |  | 2 |  |  |

