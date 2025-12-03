#include "booking.h"
#include <stdio.h>

// books one seat if anything is left
void book_one_seat_now(struct AIRPLANE *a, int index) {

    if (a->booked_no_of_seats < a->total_no_of_seats) {

        a->booked_no_of_seats++;   // marking one more seat as booked

        myFlightIndex = index;     // storing which flight user picked
        mySeat = a->booked_no_of_seats;   // assigning next available seat
        myPNR = create_pnr();      // generating a fresh PNR

        printf("\nSeat booked successfully.\n");
        printf("Use Option 4 to view PNR + Seat details.\n");

        char log[200];
        // logging what exactly happened
        sprintf(log, "Booked Flight %d | Seat %d | PNR %d",
                a->flight_number, mySeat, myPNR);
        add_history(log);

    } else {
        printf("\nNo seats available.\n");   // when flight is fully packed
    }
}


// cancels the currently booked seat if it's the same flight
void cancel_the_seat(struct AIRPLANE planes[], int index) {

    if (myFlightIndex == -1) {
        printf("\nYou have no booked flight to cancel.\n");   // nothing to undo
        return;
    }

    if (index != myFlightIndex) {
        printf("\nYou did NOT book this flight.\n");   // user selected wrong flight
        printf("Your active booking is for Flight %d only.\n",
               planes[myFlightIndex].flight_number);
        return;
    }

    char log[200];
    // noting the cancellation in history
    sprintf(log, "Cancelled Flight %d | Seat %d",
            planes[index].flight_number, mySeat);
    add_history(log);

    planes[index].booked_no_of_seats--;   // freeing one booked seat

    printf("\nSeat cancelled successfully.\n");

    myFlightIndex = -1;   // clearing active booking details
    myPNR = 0;
    mySeat = 0;
}
