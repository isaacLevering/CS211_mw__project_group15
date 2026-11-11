# Part A: 2048 - movement and game control
  ## Starting point
    Use the supplied main.cpp and 2048_helper.h as a starting point. The movement functions are unfinished. You must also
    correct the main loop, random insertion behavior, and file organization. This handout governs the requirements where older
    handouts or starter behavior differ.
    The board is a 5x5 integer array. Each cell contains zero for empty, or a power of two starting at 2. A new game clears the
    board, resets score and successful-move count to zero, and places two tiles of value 2 in different randomly chosen empty
    cells.
    Complete the four directional functions
    Implement move_left, move_right, move_up, and move_down. You may add helpers and adjust function signatures to
    report whether the board changed and how many points the move earned.
      1. Slide nonzero tiles as far as possible in the chosen direction.
      2. Merge equal adjacent tiles in the direction of travel. Each tile may participate in only one merge during a move. A newly
      merged tile cannot merge again in that move.
      3. Close gaps after merging. Add the value of every newly merged tile to the score.
      4. If the board changed, count one successful move and insert exactly one new 2 in a randomly selected empty cell. This
      includes a slide with no merge.
      5. If the board did not change, do not insert a tile or change the score or move count.
    Keep random insertion outside movement functions so movement can be tested deterministically.
    Movement examples: before random insertion
    Original row Result of a left move Score gained
    0 2 0 2 0 4 0 0 0 0 4
    2 2 2 0 0 4 2 0 0 0 4
    2 2 2 2 2 4 4 2 0 0 8
    2 2 4 0 0 4 4 0 0 0 4
    4 4 8 8 0 8 16 0 0 0 24
    2 4 8 0 0 2 4 8 0 0 0
    A right move on 2 2 2 0 0 gives 0 0 0 2 4. Apply the same ordering rules to columns for up/down moves.
    Required controls and display
    Display commands for u/d/l/r (movement), s (save), o (open/load), n (new game after confirmation), h (help), and e (exit).
    Explain them in the program and README. Reject invalid commands and handle end of input cleanly.
    Display the board, score, successful-move count, and highest tile at startup and after movement, a new game, or a
    successful load. Help, save, invalid input, and exit must not change the game state. Random insertion earns no score.
    Announce success when a tile reaches 2048 or higher and allow continued play. Game over means there are no empty
    cells and no equal horizontal or vertical neighbors. A full board may still have a valid move. At game over, allow save, load, new game, help, and exit, but prevent further movement.

# Part A: 2048 - save, load, and tests
  ## Save and load requirements
    Use C++ text-file streams and one slot named savegame.txt in the working directory. Saving again may replace this slot;
    explain that behavior in help and the README. Report file-open or write failures accurately.
    Use this layout: the marker CS211_2048_V1; then the score and successful-move count; then five rows of five integers.
    For example:
    CS211_2048_V1
    8 3
    4 4 0 0 0
    0 0 0 0 0
    2 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    Save all 25 cells and both counters. Loading must:
      - Check the version marker, two nonnegative integer counters, and exactly 25 integer cell values.
      - Accept a cell only if it is zero or a power of two of at least 2. Reject missing data, extra non-whitespace content, and
      values outside the range of the chosen types.
      - Read into temporary variables and a temporary board. Replace the active state only after the complete file passes
      validation.
      - Leave the game unchanged if the file is missing or invalid, and display a useful error message.
      - Restore the exact saved board and counters without inserting a tile or counting a move. The future random sequence
      does not need to be restored.
    Required 2048 test evidence
    Record starting state/input, expected result, actual result, and pass/fail in tests.md. Include board values. Separate the
    deterministic movement result from the later random insertion.
      1. Sliding and merging in each of the four directions, including movement through gaps.
      2. Three equal tiles and four equal tiles: no tile merges twice in one move.
      3. A successful slide with no merge: one new 2, one counted move, no score gain.
      4. An unchanged move: no inserted tile and no changed counters.
      5. A full board with a possible merge, and a full board with no possible moves.
      6. Several merges in one move, correct score updates, and reaching the 2048 target.
      7. Save, change the game, and load: exact restoration of all cells and counters.
      8. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.
      9. Help, invalid commands, new-game confirmation, and exit behavior.
    Manual dry run
    Include one 2048 movement dry run in report.pdf. Show the starting board, intermediate slide/merge steps, final board
    before random insertion, score gained, and whether a new tile should appear. Explain why the merge-once rule is satisfied.
