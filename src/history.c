#include "display.h"
#include <stdio.h>

// just prints one flight’s basic details in a clean format
void show_flight_info(struct AIRPLANE p) {

    printf("\n---------------------------------------");
    printf("\nFlight No : %d", p.flight_number);
    printf("\nRoute     : %s -> %s", p.from, p.to);
    printf("\nSeats     : Total %d | Booked %d | Available %d",
           p.total_no_of_seats, p.booked_no_of_seats,
           p.total_no_of_seats - p.booked_no_of_seats);
    printf("\n---------------------------------------\n");
}

// shows every flight in the system one by one
void ALL_FLIGHTS(struct AIRPLANE a[], int n) {
    add_history("Viewed All Flights");   // noting that user checked all flights

    printf("\n******** VIEW ALL FLIGHTS ********\n");
    for (int i = 0; i < n; i++) {
        show_flight_info(a[i]);          // using the same display function
    }
}

// prints the user's currently booked flight (if any)
void my_personal_booking(struct AIRPLANE arr[]) {

    add_history("Viewed My Booking Details");   // logging what user viewed

    if (myFlightIndex == -1) {
        printf("\nYou have not booked any flight yet.\n");   // nothing booked so far
    } else {

        printf("\n******** YOUR BOOKING DETAILS ********\n");

        show_flight_info(arr[myFlightIndex]);   // showing the flight you booked

        printf("Your PNR Number : %d\n", myPNR);
        printf("Your Seat Number: %d\n", mySeat);
        printf("---------------------------------------\n");
    }
}
