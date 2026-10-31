# Unit Tests
//TODO: the required tests for both parts with expected/actual results and pass/fail. Also record the final clean-extraction
build test.

## 2048
Record starting state/input, expected result, actual result, and pass/fail in tests.md. Include board values. Separate the
deterministic movement result from the later random insertion.
  1. Sliding and merging in each of the four directions, including movement through gaps.
    Input: LEFT
Starting board (adjusted to match examples in part A):
{0,2, 0, 2, 0},
		{2, 2, 2, 0, 0},
		{2, 2, 2, 2, 2},
		{2, 2, 4, 0, 0},
		{2, 4, 8, 0, 0},
Result
{4,0, 0, 0, 0},
		{4, 2, 0, 0, 0},
		{4, 4, 2, 0, 0},
		{4, 4, 0, 0, 0},
		{2, 4, 8, 0, 0},


  3. Three equal tiles and four equal tiles: no tile merges twice in one move.
  4. A successful slide with no merge: one new 2, one counted move, no score gain.
  5. An unchanged move: no inserted tile and no changed counters.
  6. A full board with a possible merge, and a full board with no possible moves.
  7. Several merges in one move, correct score updates, and reaching the 2048 target.
  8. Save, change the game, and load: exact restoration of all cells and counters.
  9. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
  10. Help, invalid commands, new-game confirmation, and exit behavior.

## Luhn Algorithm
Test input or action               | Expected result
-----------------------------------|------------------------------------------------
4532015112830366                   | Correct format; checksum passes
4532015112830367                   | Correct format; checksum fails
0000000000000018                   | Correct format; leading zeros preserved; passes
453201511283036                    | Reject: 15 digits
45320151128303666                  | Reject: 17 digits
453201511283036X                   | Reject: non-digit
Input containing an internal space | Reject: malformed input
Several checks followed by exit    | Results correct; loop exits cleanly

# TEST RESULT
## 2048
	6. a) Full Board with a possible merge.
			Starting input: {2, 4, 8, 16, 32}, 
					   		{4, 8, 16, 64, 2}, 
					   		{2, 4, 8, 16, 32}, 
					   		{4, 8, 16, 2, 2}, 
					   		{8, 2, 32, 16, 4}
			Expected: Game allows continued play.
			Actual: Game allows continued play.
			Pass/Fail? PASS
		b) Full board with no possible merge. 
			Starting input: {2, 4, 8, 16, 32}, 
					   		{4, 8, 16, 64, 2}, 
					   		{2, 4, 8, 16, 32}, 
					   		{4, 8, 16, 2, 8}, 
					   		{8, 2, 32, 16, 4}
			Expected: Game exits with message.
			Actual: Game exits with message.
			Pass/Fail? PASS
	7.  a) Several merges in one move
			Starting point: {0, 0, 0, 0, 0}, 
							{0, 0, 0, 0, 4}. 
							{0, 0, 4, 0, 4}, 
							{0, 0, 0, 2, 2}, 
							{0, 0, 0, 8, 32} 
			Expected: Both merges complete successfully.
			Actual: Both merges complete successfully.
			Pass/Fail? PASS
		b) Correct Score updates: Score 144, Move: 12(board same as above)
			Expected: Score increases by 12 ((2+2)+(4+4)); Move increases by 1
			actual: Score increases by 12. Move increases by 1
			Pass/Fail? PASS	
		c) Reach 2048 target.
			Starting input: Score 1024
							{2, 4, 8, 16, 32} 
							{8, 8, 16, 1024, 2}, 
							{0, 2, 4, 1024, 64}, 
							{0, 4, 8, 64, 8}, 
							{0, 8, 2, 4, 0} 
		Expected: Game displays a win message and allows play to continue.
		Actual: Game displays a win message and allows play to continue.
		Pass/Fail? PASS
	8. Starting input: Score: 428, Moves: 29,
					   {2,8,0,0,0},
					   {16,0,0,0,0},
					   {64,0,0,0,0},
					   {32,2,0,0,0},
					   {0,0,0,0,0}

		Expected behavior: Save game -> change board -> exit -> load save to above state.
		Actual result: game loads to original state.
		Pass/Fail? PASS
	9. Starting input: Score: 20, Moves: 2,
						{4,2,4,0,2},
						{2,0,0,0,0},
						{4,2,0,0,0},
						{2,0,0,0,0},
						{8,2,0,0,0}
		Expected Result: Game is saved to working directory. Save is changed to include invalid number (e.g. -1). When save is loaded, terminal throws exception and helpful error message and does not load game.
		Actual Result: Loading save with illegal input removes tile and continues load.
		Pass/Fail? FAIL
	10. Starting input: DEFAULT
		Expected behavior: Help prints help message
		Actual: Help prints help message
		Pass/Fail? PASS

		Starting input: DEFAULT.
		Expected result: invalid commands print error and loop back to board.
		Actual: invalid commands print error and loop back to board.
		Pass/Fail? PASS

		Starting input: DEFAULT.
		Expected behavior: confirm user input before new game is loaded
		Actual: load immediately
		Pass/Fail? FAIL

		Starting input: DEFAULT.
		Expected result: Confirm exit and close game exit behavior.
		Actual: exit immeditly
		Pass/Fail? FAIL

