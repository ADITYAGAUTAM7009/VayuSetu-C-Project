#include "display.h"
#include <stdio.h>

void show_flight_info(struct AIRPLANE p) {

    printf("\n---------------------------------------");
    printf("\nFlight No : %d", p.flight_number);
    printf("\nRoute     : %s -> %s", p.from, p.to);
    printf("\nSeats     : Total %d | Booked %d | Available %d",
           p.total_no_of_seats, p.booked_no_of_seats,
           p.total_no_of_seats - p.booked_no_of_seats);
    printf("\n---------------------------------------\n");
}

void ALL_FLIGHTS(struct AIRPLANE a[], int n) {
    add_history("Viewed All Flights");

    printf("\n******** VIEW ALL FLIGHTS ********\n");
    for (int i = 0; i < n; i++) {
        show_flight_info(a[i]);
    }
}

void my_personal_booking(struct AIRPLANE arr[]) {

    add_history("Viewed My Booking Details");

    if (myFlightIndex == -1) {
        printf("\nYou have not booked any flight yet.\n");
    } else {

        printf("\n******** YOUR BOOKING DETAILS ********\n");

        show_flight_info(arr[myFlightIndex]);

        printf("Your PNR Number : %d\n", myPNR);
        printf("Your Seat Number: %d\n", mySeat);
        printf("---------------------------------------\n");
    }
}
