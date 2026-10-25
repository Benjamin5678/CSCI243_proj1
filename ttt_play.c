/**
 * @file ttt_play.c
 * @brief play ttt with two players from the terminal
 *
 * @author Benjamin Hewitt <bxh2408@rit.edu>
 * @course CSCI-243 Project 1
 */
#include <stdio.h>
#include "ttt_engine.h"

/**
 * The main program for ttt_play
 * Enter a move as "rc" where r & c are from 0-2
 * @return should be 0
 */
int main()
{
    char b[9];
    init_board(b);
    State game_state = INCOMPLETE;
    char p = 'x';

    while (game_state == INCOMPLETE) {
        int m = get_move();
        if (m == QUIT) break;
        if (m == INVALID || !valid_move(b, m)) {
            printf("INVALID\n");
            continue;
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
