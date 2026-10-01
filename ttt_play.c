#include <stdio.h>
#include "ttt_engine.h"

int main()
{
    Move m = get_move();
    printf("%d%d\n", m.r, m.c);
    m = get_move();
    printf("%d%d\n", m.r, m.c);
}
