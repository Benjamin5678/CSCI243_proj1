#include <stdio.h>
#include <string.h>
#include "ttt_engine.h"

/**
 * Is an ASCII character a digit from 0-2?
 * @param i an ASCII character from getchar()
 * @return 1 if it is a valid row/col else 0
 */
int is_rc(int i)
{
    return i >= '0' && i <= '2';
}

/**
 * Get numberical value of ASCII digit
 * @param i an ASCII character from getchar()
 * @return numerical value 0-9
 */
int get_digit(int i)
{
    return i - '0';
}

char* get_state_name(State s) {
    switch (s) {
        case INCOMPLETE: return "INCOMPLETE";
        case X: return "X";
        case O: return "O";
        case DRAW: return "DRAW";
    }
}

/**
 * Consume characters from stdin until a newline or EOF is found
 * @pre There should be characters in stdin or else program will pause
 * @post The next character in stdin will be what is immediately following a newline or EOF
 */
void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

void init_board(char b[]) {
    for (int i = 0; i < 9; i++)
        b[i] = 'e';
}

char get_spot(char b[], int r, int c) {
    return b[3*r + c];
}

void display_board(char b[]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col ++) {
            printf("%c", get_spot(b, row, col));
        }
        printf("\n");
    }
    printf("\n");
}

int get_move()
{
    char bf[6];

    // read and check for quit
    if (fgets(bf, sizeof(bf), stdin) == NULL || !strcmp(bf, "quit\n") || !strcmp(bf, "q\n")) return QUIT;

    // check for input larger than buffer
    if (strchr(bf, '\n') == NULL) {
        clear_buffer();
        return INVALID;
    }

    // is length correct?
    if (strlen(bf) != 3) return INVALID;

    // parse move
    int r = bf[0];
    int c = bf[1];

    // is first char a number? is second char a number?
    if (!is_rc(r)) return INVALID;
    if (!is_rc(c)) return INVALID;

    return 3*get_digit(r) + get_digit(c);
}

int valid_move(char b[], int m) {
    if (b[m] == 'e') return 1;
    return 0;
} 

void play_move(char b[], int m, char p) {
    b[m] = p;
}

State check_board(char b[]) {
    char p;
    int x_win = 0;
    int o_win = 0;
    // check cols
    for (int col = 0; col < 3; col++) {
        if ((p = get_spot(b, 0, col)) != 'e' && p == get_spot(b, 1, col) && p == get_spot(b, 2, col)) {
            if (p == 'x') x_win = 1;
            if (p == 'o') o_win = 1;
        }
    }
    // check rows
    for (int row = 0; row < 3; row++) {
        if ((p = get_spot(b, row, 0)) != 'e' && p == get_spot(b, row, 1) && p == get_spot(b, row, 2)) {
            if (p == 'x') x_win = 1;
            if (p == 'o') o_win = 1;
        }
    }
    // check diags
    if ((p = get_spot(b, 0, 0)) != 'e' && get_spot(b, 1, 1) == p && get_spot(b, 2, 2) == p) {
        if (p == 'x') x_win = 1;
        if (p == 'o') o_win = 1;
    }
    if ((p = get_spot(b, 0, 2)) != 'e' && get_spot(b, 1, 1) == p && get_spot(b, 2, 0) == p) {
        if (p == 'x') x_win = 1;
        if (p == 'o') o_win = 1;
    }

    if (x_win && o_win) return IMPOSSIBLE; // simultaneous win
    if (x_win) return X;
    if (o_win) return O;
    
    // check draw
    for (int i = 0; i < 9; i++) {
        if (b[i] == 'e') return INCOMPLETE;
    }

    return DRAW;
}
