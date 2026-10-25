/**
 * @file ttt_analyzer.c
 * @brief enter a board and get an analysis of who will win
 *
 * @author Benjamin Hewitt <bxh2408@rit.edu>
 * @course CSCI-243 Project 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ttt_engine.h"
#include "minimax.h"

/**
 * Read 3 lines of input and save into a board
 * Empty lines skipped
 * @b the tic tac toe board to write to char[9]
 * @return 1 if finished normally, 0 if quit, -1 if error
 */
int read_board(char b[]) {
    int count = 0;
    char bf[6];
    int error = 0;
    while (count < 3) {
        char *s = fgets(bf, sizeof(bf), stdin);
        // exit
        if (s == NULL || strcmp(bf, "q\n") == 0 || strcmp(bf, "quit\n") == 0)
            return 0;
        // skip empty lines
        if (bf[0] == '\n')
            continue;
        // check for wrong size lines
        if (strchr(bf, '\n') == NULL) { // more input than buffer
            error = 1;
            while (getchar() != '\n'); // consume buffer
            count++;
            continue; // prevent getting overriden but still consume 3 lines
        }
        if (strlen(bf) != 4) { // len 0, 1, 2, 4, 5 inputs
            error = 1;
            count++;
            continue;
        }
        // write to b
        for (int i = 0; i < 3; i++)
            b[3*count + i] = bf[i];
        count++;
    }
    if (error) return -1;
    return 1;
}

/**
 * Check that all characters in a board are valid
 * The board might still be invalid
 * @b a tic tac toe board char[9]
 * @return 1 valid characters, 0 invalid character found
 */
int valid_chars(char b[]) {
    char c;
    for (int i = 0; i < 9; i++) {
        c = b[i];
        if (c != 'x' && c != 'o' && c != 'e') return 0;
    }
    return 1;
}


/**
 * Check that board is in a valid state and get current turn
 * @pre board has valid chars
 * @b tic tac toe board
 * @return 'X', 'O', '-' finished, 'i' invalid
 */
char get_turn(char b[]) {
    // check for simultaneous win
    State s = check_board(b);
    if (s == IMPOSSIBLE) return 'i';
    if (s != INCOMPLETE) return '-';
    // count x's and o's
    int xs = 0;
    int os = 0;
    for (int i = 0; i < 9; i++) {
        if (b[i] == 'x') xs++;
        if (b[i] == 'o') os++;
    }
    if (xs != os && xs != os + 1) return 'i';
    return xs == os ? 'X' : 'O';
}

/**
 * Get the projected result of a board
 * @pre board is in a valid state (see get_turn())
 * @b a tic tac toe board
 * @char turn 'X' 'O' anything else defaults to o's turn (like '-' since it doesn't matter)
 * @return "X" "O" "DRAW"
 */
char *get_result(char b[], char turn) {
    int t = turn == 'X' ? 1 : 0;
    int r = minimax(wrap_array(b), t);
    char *result;
    if (r == 1) result = "X";
    if (r == -1) result = "O";
    if (r == 0) result = "DRAW";
    return result;
}


/**
 * The main program for ttt_analyzer
 * @return 0 when quit
 */
int main() {
    char b[9];
    int f;
    char t;
    char *r;
    while (f = read_board(b)) {
        // check read_board, valid_chars, get_turn are all happy
        if (f == -1 || valid_chars(b) == 0 || (t = get_turn(b)) == 'i') {
            printf("INVALID\n");
            continue;
        }
        r = get_result(b, t);
        printf("TURN %c RESULT %s\n", t, r);
    }
}
