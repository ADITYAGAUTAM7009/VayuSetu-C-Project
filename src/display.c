#include <stdio.h>
#include "display.h"
#include "airplane.h"

// This function is basically the “home screen” of the program.
// Just prints the main options in a simple, clean way.
void show_main_menu() {

    printf("\n========================================\n");
    printf("          WELCOME TO VAYUSETU\n");
    printf("========================================\n");

    // Keeping the menu short and sweet so the user doesn’t get confused.
    printf("1. View All Flights\n");
    printf("2. Search Flight\n");
    printf("3. Book a Seat\n");
    printf("4. Cancel a Seat\n");
    printf("5. View Booking History\n");
    printf("6. Compare Ticket Rates\n");
    printf("7. Exit\n");

    printf("========================================\n");
    printf("Enter your choice: ");
}



// Shows a single flight’s details in a clean “card-like” format.
// Used internally by the main flight listi
