#include "airplane.h"
#include <stdio.h>
#include <stdlib.h>   // for rand()

// shows all flights and lets the user pick one
int select_flight(struct AIRPLANE planes[], int n) {

    printf("\nSelect a flight:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. Flight %d (%s -> %s)\n",
               i + 1,
               planes[i].flight_number,
               planes[i].from,
               planes[i].to);
    }

    printf("\nEnter option number: ");
    int choice;
    scanf("%d", &choice);

    // simple check so user doesn’t pick something random
    if (choice < 1 || choice > n) {
        printf("\nInvalid choice.\n");
        return -1;
    }

    return choice - 1; // converting user choice to array index
}

// makes a simple 8-digit PNR using random numbers
int create_pnr() {
    return 10000000 + (rand() % 90000000);
}
