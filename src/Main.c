#include "airplane.h"
#include "history.h"
#include "display.h"
#include "booking.h"
#include "pricecompare.h"

int myFlightIndex = -1;
int myPNR = 0;
int mySeat = 0;

char history[200][200];
int history_count = 0;

int main() {

    add_history("Started VAYUSETU Application");

    struct AIRPLANE planes[5] = {
        {101, "DELHI", "MUMBAI", 180, 75},
        {102, "CHANDIGARH", "GUJARAT", 160, 48},
        {103, "DELHI", "BENGALURU", 200, 120},
        {104, "MUMBAI", "KOLKATA", 150, 90},
        {105, "GUWAHATI", "DELHI", 140, 60}
    };

    int n = 5, ch;

    while (1) {
        printf("\n============== VAYUSETU MENU ==============\n");
        printf("1. View All Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Seat\n");
        printf("4. View My Booking Details\n");
        printf("5. Compare Prices\n");
        printf("6. View History\n");
        printf("7. Exit\n");
        printf("============================================\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) ALL_FLIGHTS(planes, n);

        else if (ch == 2) {
            int id = select_flight(planes, n);
            if (id != -1) book_one_seat_now(&planes[id], id);
        }

        else if (ch == 3) {
            int id = select_flight(planes, n);
            if (id != -1) cancel_the_seat(planes, id);
        }

        else if (ch == 4) my_personal_booking(planes);

        else if (ch == 5) {
            int id = select_flight(planes, n);
            if (id != -1) compare_the_rates(planes[id]);
        }

        else if (ch == 6) show_history();

        else if (ch == 7) {
            add_history("Exited Application");
            break;
        }

        else printf("Invalid choice.\n");
    }

    return 0;
}
