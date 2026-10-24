#ifndef MINIMAX
#define MINIMAX

typedef struct {
    char arr[9];
} Array;

/**
 * Use minimax to find optimal move given a board
 * @b a tic tac toe board char[9]
 * @p the current player
 * @return the optimal move
 */
int optimal_move(char b[], char p);

#endif
