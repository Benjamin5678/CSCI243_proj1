/**
 * @file ttt_random.c
 * @brief play against a bot that picks random moves
 *
 * @author Benjamin Hewitt <bxh2408@rit.edu>
 * @course CSCI-243 Project 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ttt_engine.h"

/**
 * @return a random valid move 0-8
 */
int random_move(char board[]) {
    int open[9];
    int count = 0;

    for (int i = 0; i < 9; i++) {
        if (board[i] == 'e') {
            open[count++] = i;
        }
    }

    return open[rand() % count];
}

/**
 * The main program for ttt_random
 * run the program with an argument X or O to determine who will be the bot
 * @return 0 when program finishes
 */
int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc != 2) {
        printf("USAGE: ttt_random {bot (X | O)}\n");
        return -1;
    }

    char bot;
    if (strcmp(argv[1], "X") == 0) bot = 'x';
    else bot = 'o';

    char b[9];
    init_board(b);
    State game_state = INCOMPLETE;
    char p = 'x';

    while (game_state == INCOMPLETE) {
        int m;
        if (p == bot) {
            m = random_move(b);
        } else {
            m = get_move();
            if (m == QUIT) break;
            if (m == INVALID || !valid_move(b, m)) {
                printf("INVALID\n");
                continue;
            }
        }
        play_move(b, m, p);
        display_board(b);
        game_state = check_board(b);
        // switch player
        p = p == 'x' ? 'o' : 'x';
    }

    // print result
    printf("RESULT %s\n", get_state_name(game_state));
}
