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

Move get_move()
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

    return (Move){ .r = get_digit(r), .c = get_digit(c)};
}
