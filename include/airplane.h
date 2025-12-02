#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct AIRPLANE {
    int flight_number;
    char from[30];
    char to[30];
    int total_no_of_seats;
    int booked_no_of_seats;
};

// CURRENT ACTIVE BOOKING
extern int myFlightIndex;
extern int myPNR;
extern int mySeat;

// FUNCTIONS
int select_flight(struct AIRPLANE planes[], int n);
int create_pnr();

#endif
