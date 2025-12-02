#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== STRUCT ==========
struct AIRPLANE {
    int flight_number;
    char from[30];
    char to[30];
    int total_no_of_seats;
    int booked_no_of_seats;
};

// ========== GLOBAL BOOKING ==========
int myFlightIndex = -1;
int myPNR = 0;
int mySeat = 0;

// ========== BROWSER HISTORY OF THE SITE ==========
char history[200][200];
int history_count = 0;

void add_history(const char *event) {
    strcpy(history[history_count], event);
    history_count++;
}

// ========== DISPLAY FUNCTIONS ==========
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

// ========== TO BOOK A SEAT ==========
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

// ========== TO CANCEL A SEAT ==========
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

    if (planes[index].booked_no_of_seats > 0) {

        char log[200];
        sprintf(log, "Cancelled Flight %d | Seat %d",
                planes[index].flight_number, mySeat);
        add_history(log);

        planes[index].booked_no_of_seats--;

        printf("\nSeat cancelled successfully.\n");

        myFlightIndex = -1;
        myPNR = 0;
        mySeat = 0;

    } else {
        printf("\nNo booked seats to cancel.\n");
    }
}

// ========== TO VIEW THE BOOKINGS ==========
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

// ========== TO COMPARE THE RATES ==========
void compare_the_rates(struct AIRPLANE f) {

    int agoda = 4300 + (rand() % 600);
    int makemytrip = 5000 + (rand() % 600);
    int yatra = 4800 + (rand() % 600);

    char log[200];
    sprintf(log, "Compared Prices for Flight %d", f.flight_number);
    add_history(log);

    printf("\nRates for Flight %d (%s -> %s)\n",
           f.flight_number, f.from, f.to);

    printf("\nAgoda      : Rs %d", agoda);
    printf("\nMakeMyTrip : Rs %d", makemytrip);
    printf("\nYatra      : Rs %d\n", yatra);

    int cheap = agoda;
    char site[20] = "Agoda";

    if (makemytrip < cheap) { cheap = makemytrip; strcpy(site, "MakeMyTrip"); }
    if (yatra < cheap)      { cheap = yatra; strcpy(site, "Yatra"); }

    printf("\nBest price on : %s", site);
    printf("\nAmount        : Rs %d\n", cheap);
}

// ========== SHOW FULL HISTORY ==========
void show_history() {
    if (history_count == 0) {
        printf("\nNo activity done yet.\n");
        return;
    }

    printf("\n******** USER ACTIVITY HISTORY ********\n\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }
    printf("\n****************************************\n");
}

// ========== MAIN GIFT OF THIS CODE  ==========
int main() {

    add_history("Started VAYUSETU Application");

    struct AIRPLANE planes[5] = {
        {101, "DELHI", "MUMBAI", 180, 75},
        {102, "CHANDIGARH", "GUJARAT", 160, 48},
        {103, "DELHI", "BENGALURU", 200, 120},
        {104, "MUMBAI", "KOLKATA", 150, 90},
        {105, "GUWAHATI", "DELHI", 140, 60}
    };

    int n = 5;
    int ch;

    while (1) {

        printf("\n============== VAYUSETU MENU ==============\n");
        printf("1. View All Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Seat\n");
        printf("4. View My Booked Flight (PNR + Seat)\n");
        printf("5. Compare Flight Prices\n");
        printf("6. Visit VAYUSETU Website\n");
        printf("7. Open VAYUSETU Video Link\n");
        printf("8. View My Activity History\n");
        printf("9. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
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

        else if (ch == 6) {
            add_history("Visited VAYUSETU Website");
#ifdef _WIN32
            system("start https://digital-air-bridge.qwikbuild.com/#video");
#else
            system("open https://digital-air-bridge.qwikbuild.com/#video");
#endif
        }

        else if (ch == 7) {
            add_history("Opened VAYUSETU Video Link");
#ifdef _WIN32
            system("start https://youtu.be/aPQHWWSpe-A");
#else
            system("xdg-open https://youtu.be/aPQHWWSpe-A");
#endif
        }

        else if (ch == 8) show_history();

        else if (ch == 9) {
            add_history("Exited VAYUSETU Application");
            break;
        }

        else printf("\nInvalid input.\n");
    }

    return 0;
}
