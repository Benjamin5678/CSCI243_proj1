#include <stdio.h>
#include "ttt_engine.h"

/**
 * Is an ASCII character a digit?
 * @param i an ASCII character from getchar()
 * @return 1 if it is a digit else 0
 */
int is_digit(int i)
{
    return i >= '0' && i <= '9';
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
    while ((c = getchar()) != '\n' && c != EOF);
}

Move get_move()
{
    char valid = 1;
    char bf[4];
    fgets(bf, sizeof(bf), stdin);

    int r = bf[0];
    int c = bf[1];

    // is first char a number? is second char a number?
    if (!is_digit(r)) valid = 0;
    if (!is_digit(c)) valid = 0;
    // was more than 2 characters entered?
    if (valid && bf[2] != '\n' && bf[2] != EOF) {
        valid = 0;
        clear_buffer();
    }

    if (valid) {
        return (Move){ .r = get_digit(r), .c = get_digit(c)};
    } else {
        return INVALID;
    }
}
