#include "PriceCompare.h"   // using the rate compare function
#include "airplane.h"       // airplane data structure
#include "history.h"        // logging what the user does

#include <stdio.h>
#include <stdlib.h>         // for random prices
#include <string.h>         // for strcpy and sprintf

void compare_the_rates(struct AIRPLANE f) {

    // randomly making some prices just to keep things fun
    int agoda      = 4300 + (rand() % 600);
    int makemytrip = 5000 + (rand() % 600);
    int yatra      = 4800 + (rand() % 600);

    // noting down that we checked the rates
    char log[200];
    sprintf(log, "Compared Prices for Flight %d", f.flight_number);
    add_history(log);

    // showing the prices to the user
    printf("\nRates for Flight %d (%s -> %s)\n",
           f.flight_number, f.from, f.to);

    printf("\nAgoda      : Rs %d", agoda);
    printf("\nMakeMyTrip : Rs %d", makemytrip);
    printf("\nYatra      : Rs %d\n", yatra);

    // checking which one is the cheapest
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

    // final cheapest option for the user
    printf("\nBest price on : %s", site);
    printf("\nAmount        : Rs %d\n", cheapest);
}
