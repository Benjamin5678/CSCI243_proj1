#include <stdio.h>
#include "ttt_engine.h"

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
