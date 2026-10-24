#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ttt_engine.h"
#include "minimax.h"

void read_board(char b[]) {
    int count = 0;
    char bf[5];
    while (count < 3) {
        char *s = fgets(bf, sizeof(bf), stdin);
        if (s == NULL || strcmp(bf, "q\n") == 0 || strcmp(bf, "quit\n") == 0)
            exit(0);
        if (bf[0] == '\n')
            continue;
        for (int i = 0; i < 3; i++)
            b[3*count + i] = bf[i];
        count++;
    }
}

int legal_board(char b[]) {

int main() {
    char b[9];
    read_board(b);
    display_board(b);
}
