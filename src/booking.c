#include "booking.h"
#include <stdio.h>

void book_one_seat_now(struct AIRPLANE *a, int index) {

    if (a->booked_no_of_seats < a->total_no_of_seats) {

        a->booked_no_of_seats++;

        myFlightIndex = index;
        mySeat = a->booked_no_of_seats;
        myPNR = create_pnr();

        printf("\nSeat booked successfully.\n");
        printf("Use Option 4 to view PNR + Seat details.\n");

        char log[200];
        sprintf(log, "Booked Flight %d | Seat %d | PNR %d",
                a->flight_number, mySeat, myPNR);
        add_history(log);

    } else {
        printf("\nNo seats available.\n");
    }
}


void cancel_the_seat(struct AIRPLANE planes[], int index) {

    if (myFlightIndex == -1) {
        printf("\nYou have no booked flight to cancel.\n");
        return;
    }

    if (index != myFlightIndex) {
        printf("\nYou did NOT book this flight.\n");
        printf("Your active booking is for Flight %d only.\n",
               planes[myFlightIndex].flight_number);
        return;
    }

    char log[200];
    sprintf(log, "Cancelled Flight %d | Seat %d",
            planes[index].flight_number, mySeat);
    add_history(log);

    planes[index].booked_no_of_seats--;

    printf("\nSeat cancelled successfully.\n");

    myFlightIndex = -1;
    myPNR = 0;
    mySeat = 0;
}
