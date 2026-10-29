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
