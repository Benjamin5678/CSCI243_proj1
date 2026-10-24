/**
 * @file ttt_engine.h
 * @brief helper functions for tic tac toe games
 *
 * @author Benjamin Hewitt
 * @course CSCI-243 Project 1 (Tic-Tac-Toe)
 */
#ifndef TTT_ENGINE
#define TTT_ENGINE

/** Return value for get_move if any error occurs */
#define INVALID -1
/** Return value for get_move if quit */
#define QUIT -2

/** Enum for board state */
typedef enum {
    INCOMPLETE,
    X,
    O,
    DRAW
} State;

/**
 * @return string corresponding to state value
 */
char* get_state_name(State s);

/**
 * set all spaces in board to 'e'
 * @b a tic tac toe board char[9]
 */
void init_board(char b[9]);

/**
 * Print out the board
 * @b a tic tac toe board char[9]
 */
void display_board(char b[9]);

/**
 * Read std_in for a move in format rc and return the move or a special value
 * @return move 0-8 or QUIT or INVALID if any error
 */
int get_move();

/**
 * Check if a move is valid given a board
 * @b a tic tac toe board char[9]
 * @m a move
 */
int valid_move(char b[9], int m); 

/**
 * Play a move on the board
 * @b a tic tac toe board char[9]
 * @i index of board 0-8
 * @p which player 'X' or 'O'
 * @pre check that the move is valid
 */
int play_move(char b[9], int i, char p);

/**
 * Check for end of game
 * @b a tic tac toe board char[9]
 * @return the board state
 */
State check_board(char b[9]);

#endif
