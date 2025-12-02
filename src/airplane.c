#include "airplane.h"
#include <stdio.h>

int select_flight(struct AIRPLANE planes[], int n) {

    printf("\nSelect a flight:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Flight %d (%s -> %s)\n",
               i + 1, planes[i].flight_number, planes[i].from, planes[i].to);
    }

    printf("\nEnter option number: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > n) {
        printf("\nInvalid choice.\n");
        return -1;
    }

    return choice - 1;
}

int create_pnr() {
    return 10000000 + (rand() % 90000000);
}
