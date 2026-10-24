/**
 * @file minimax.c
 * @brief implementation of minimax.h
 *
 * @author Benjamin Hewitt <bxh2408@rit.edu>
 * @course CSCI-243 Project 1
 */ 
#include "minimax.h"
#include "ttt_engine.h"

Array wrap_array(char b[]) {
    Array new;
    for (int i = 0; i < 9; i++)
        new.arr[i] = b[i];
    return new;
}

/**
 * Find all valid moves (empty spaces) from current board
 * @b a current tic tac toe board
 * @return an array where the first spaces are filled with valid moves and any unused indexes are -1
 */
Array valid_moves(char b[]) {
    char open[9];
    for (int i = 0; i < 9; i++) open[i] = -1;
    int count = 0;
    
    for (int i = 0; i < 9; i++) {
        if (b[i] == 'e') {
            open[count++] = i;
        }
    }

    return wrap_array(open);
}

int minimax(Array board, int maximizingPlayer) {
    // base case
    State s = check_board(board.arr);
    if (s != INCOMPLETE) {
        if (s == X) return 1;
        if (s == O) return -1;
        return 0;
    }
     
    Array children = valid_moves(board.arr);
    int value;
     
    if (maximizingPlayer) {
        value = -1;
        int i = 0;
        while (i < 9 && children.arr[i] != -1) {
            Array child = wrap_array(board.arr);
            play_move(child.arr, children.arr[i], 'x');
            int child_value = minimax(child, 0);
            if (child_value > value) value = child_value;
            i++;
        }
    } else {
        value = 1;
        int i = 0;
        while (i < 9 && children.arr[i] != -1) {
            Array child = wrap_array(board.arr);
            play_move(child.arr, children.arr[i], 'o');
            int child_value = minimax(child, 1);
            if (child_value < value) value = child_value;
            i++;
        }
    }
    return value;
}

int optimal_move(char b[], char p) {
    Array moves = valid_moves(b);
    int maximizing = (p == 'x');
    int best_move = -1;
    int best_value = maximizing ? -2 : 2;

    int i = 0;
    while (i < 9 && moves.arr[i] != -1) {
        Array child = wrap_array(b);
        play_move(child.arr, moves.arr[i], p);
        int child_value = minimax(child, !maximizing);

        if (maximizing ? (child_value > best_value) : (child_value < best_value)) {
            best_value = child_value;
            best_move = moves.arr[i];
        }
        i++;
    }
    return best_move;
}
