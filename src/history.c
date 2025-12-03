#include "history.h"
#include <stdio.h>
#include <string.h>

// Just keeping a simple list to store whatever the user does.
// Nothing complicated — each action gets stored as plain text.
char history[200][200];
int history_count = 0;


// This function basically notes down whatever event happens.
// Think of it like writing a quick diary line for the user’s action.
void add_history(const char *event) {

    // Copying the event text into our history list.
    // Using strcpy since it's quick and enough for our use case here.
    strcpy(history[history_count], event);

    // Moving to the next empty slot for future events.
    history_count++;
}


// Shows all the activity done so far.
// Just prints everything nicely so the user can scroll through it.
void show_history() {

    // If nothing has happened yet, no point showing an empty list.
    if (history_count == 0) {
        printf("\nNo activity done yet.\n");
        return;
    }

    // A small heading, just to make it look cleaner.
    printf("\n******** USER ACTIVITY HISTORY ********\n\n");

    // Looping through whatever we stored and printing it one by one.
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }

    // A neat ending line — just for presentation.
    printf("\n****************************************\n");
}
