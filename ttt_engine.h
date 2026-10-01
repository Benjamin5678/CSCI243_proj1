/**
 * @file ttt_engine.h
 * @brief helper functions for tic tac toe games
 *
 * @author Benjamin Hewitt
 * @course CSCI-243 Project 1 (Tic-Tac-Toe)
 */
#ifndef TTT_ENGINE
#define TTT_ENGINE

/** Type to represent a move as a combination of a row and col */
typedef struct {
    char r;
    char c;
} Move;

/** Return value for get_move if any error occurs */
#define INVALID (Move){ .r = -1, .c = -1 }

/**
 * Read std_in for a move in format rc and return the move or -1,-1 if any error
 * @return {r: row, c: col} or INVALID if any error
 */
Move get_move();

/**
 * Check if a move is valid given a board
 * @g a tic tac toe board char[3][3]
 * @m a move
 */
// int valid_move(char[][] g, m); 



#endif
