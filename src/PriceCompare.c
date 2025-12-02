#include "PriceCompare.h"   // compare_the_rates() declaration
#include "airplane.h"       // struct AIRPLANE
#include "history.h"        // add_history()

#include <stdio.h>
#include <stdlib.h>         // rand()
#include <string.h>         // strcpy(), sprintf()

void compare_the_rates(struct AIRPLANE f) {

    // Randomized price generation
    int agoda      = 4300 + (rand() % 600);
    int makemytrip = 5000 + (rand() % 600);
    int yatra      = 4800 + (rand() % 600);

    // Logging action
    char log[200];
    sprintf(log, "Compared Prices for Flight %d", f.flight_number);
    add_history(log);

    // Display prices
    printf("\nRates for Flight %d (%s -> %s)\n",
           f.flight_number, f.from, f.to);

    printf("\nAgoda      : Rs %d", agoda);
    printf("\nMakeMyTrip : Rs %d", makemytrip);
    printf("\nYatra      : Rs %d\n", yatra);

    // Identify cheapest
    int cheapest = agoda;
    char site[20] = "Agoda";

    if (makemytrip < cheapest) {
        cheapest = makemytrip;
        strcpy(site, "MakeMyTrip");
    }

    if (yatra < cheapest) {
        cheapest = yatra;
        strcpy(site, "Yatra");
    }

    // Final output
    printf("\nBest price on : %s", site);
    printf("\nAmount        : Rs %d\n", cheapest);
}
