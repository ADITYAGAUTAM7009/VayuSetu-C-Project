#include "airplane.h"
#include <stdio.h>
#include <stdlib.h>   // using rand for PNR

// shows all flights and lets the user choose one
int select_flight(struct AIRPLANE planes[], int n) {

    printf("\nSelect a flight:\n");

    for (int i = 0; i < n; i++) {
        // printing flights in a simple numbered list
        printf("%d. Flight %d (%s -> %s)\n",
               i + 1,
               planes[i].flight_number,
               planes[i].from,
               planes[i].to);
    }

    printf("\nEnter option number: ");
    int choice;
    scanf("%d", &choice);

    // basic check so the user doesn’t pick something outside the list
    if (choice < 1 || choice > n) {
        printf("\nInvalid choice.\n");
        return -1;
    }

    return choice - 1;  // returning index form of the selection
}

// creates an 8-digit random PNR for bookings
int create_pnr() {
    return 10000000 + (rand() % 90000000);
}
