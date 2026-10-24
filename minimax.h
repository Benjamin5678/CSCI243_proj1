#ifndef MINIMAX
#define MINIMAX

typedef struct {
    char arr[9];
} Array;

/**
 * Copy an array into a new wrapper struct
 * @b an array char[9]
 * @return the copied array
 */
Array wrap_array(char b[]);

/**
 * The main minimax function
 * @board a tic tac toe board
 * @maximizingPlayer 1 for true, 0 for false, X is maximizing, O is minimizing
 * @return The expected value of a board state. 1 for X wins -1 for O wins
 */
int minimax(Array board, int maximizingPlayer);

/**
 * Use minimax to find optimal move given a board
 * @b a tic tac toe board char[9]
 * @p the current player
 * @return the optimal move
 */
int optimal_move(char b[], char p);

#endif
