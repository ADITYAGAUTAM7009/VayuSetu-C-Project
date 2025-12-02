#include "history.h"
#include <stdio.h>
#include <string.h>

char history[200][200];
int history_count = 0;

void add_history(const char *event) {
    strcpy(history[history_count], event);
    history_count++;
}

void show_history() {

    if (history_count == 0) {
        printf("\nNo activity done yet.\n");
        return;
    }

    printf("\n******** USER ACTIVITY HISTORY ********\n\n");

    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }

    printf("\n****************************************\n");
}
