#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// yeh AIRPLANE structure hai, purane wale struct naam ko replace kiya
struct AIRPLANE {
    int flight_number;     
    char from[30];
    char to[30];
    int total_no_of_seats;  
    int booked_no_of_seats; 
};

// tumhari kundali yaha save hoti hai (PNR + seat + jo bhi tum book karoge)
int myFlightIndex = -1;
int myPNR = 0;
int mySeat = 0;

// yaha flight ki saari info dikhate hain, human touch me
void show_flight_info(struct AIRPLANE p) {
    printf("\n---------------------------------------");
    printf("\nFlight Number : %d", p.flight_number);
    printf("\nRoute         : %s -> %s", p.from, p.to);
    printf("\nSeats         : Total %d | Booked %d | Available %d",
           p.total_no_of_seats, p.booked_no_of_seats,
           p.total_no_of_seats - p.booked_no_of_seats);
    printf("\n---------------------------------------\n");
}

// yaha user ko puch rahe hain — kahan jana chahoge ?
void ALL_FLIGHTS(struct AIRPLANE a[], int n) {

    printf("\n******** SHOW ALL FLIGHTS ********\n");

    for (int i = 0; i < n; i++) {
        show_flight_info(a[i]);
    }
}

// user ko puch rahe — kaunsi flight lena chahoge ?
int select_flight(struct AIRPLANE planes[], int n) {

    printf("\nSelect flight ");

    for (int i = 0; i < n; i++) {
        printf("\n%d. Flight %d (%s -> %s)",
               i + 1, planes[i].flight_number, planes[i].from, planes[i].to);
    }

    printf("\n\nMention option you want to go with : ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > n) {
        printf("\nInvalid choice.\n");
        return -1;
    }
    return choice - 1;
}

// yaha tumhari kundali generate hoti hai (PNR create hota hai)
int create_pnr() {   
    return 10000000 + (rand() % 90000000);
}

// seat book krne ka pura scene yaha hota hai
void book_one_seat_now(struct AIRPLANE *a, int index) {

    if (a->booked_no_of_seats < a->total_no_of_seats) {

        a->booked_no_of_seats++;

        // tumhari kundali set kar di
        myFlightIndex = index;
        mySeat = a->booked_no_of_seats;
        myPNR = create_pnr();

        printf("\nSeat booked successfully.\n");
        printf("Check option 4 for PNR + Seat.\n");

    } else {
        printf("\nNo seats available.\n");
    }
}

// yaha cancellation hota hai — agar mann badal jaye
void cancel_the_seat(struct AIRPLANE *a, int index) {

    if (a->booked_no_of_seats > 0) {
        a->booked_no_of_seats--;

        printf("\nSeat cancelled.\n");

        if (myFlightIndex == index) {
            myFlightIndex = -1;
            myPNR = 0;
            mySeat = 0;
        }
    }
    else {
        printf("\nNo booked seats.\n");
    }
}

// yaha tumhari booking open hoti hai — tumhari kundali reveal hoti hai
void my_personal_booking(struct AIRPLANE arr[]) {

    if (myFlightIndex == -1) {
        printf("\nYou have not booked anything yet.\n");
    } else {
        printf("\n******** YOUR BOOKING DETAILS ********\n");

        show_flight_info(arr[myFlightIndex]);

        printf("Your PNR Number : %d\n", myPNR);  // tumhari kundali
        printf("Your Seat Number: %d\n", mySeat);

        printf("---------------------------------------\n");
    }
}

// rate comparison section — aao tumhe kuch dikhaye (for rate comparison)
void compare_the_rates(struct AIRPLANE f) {

    printf("\nAao tumhe kuch dikhaye (for rate comparison)\n");

    int agoda = 4300 + (rand() % 600);   // surprise no. 1 for site
    int makemytrip = 5000 + (rand() % 600);
    int yatra      = 4800 + (rand() % 600);

    printf("\nRates for Flight %d (%s -> %s)\n",
           f.flight_number, f.from, f.to);

    printf("\nAgoda       : Rs %d   (surprise no. 1 for site)", agoda);
    printf("\nMakeMyTrip  : Rs %d", makemytrip);
    printf("\nYatra       : Rs %d\n", yatra);

    int cheap = agoda;
    char site[20] = "Agoda";

    if (makemytrip < cheap) { cheap = makemytrip; strcpy(site, "MakeMyTrip"); }
    if (yatra < cheap)      { cheap = yatra; strcpy(site, "Yatra"); }

    printf("\nBest price on : %s", site);
    printf("\nAmount        : Rs %d", cheap);

    printf("\n---------------------------------------\n");
}

int main() {

    // flight ki list ready hai — choose karo bhai!
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
        printf("1. ALL FLIGHTS\n");
        printf("2. Book seat\n");
        printf("3. Cancel seat\n");
        printf("4. View my booking\n");
        printf("5. Compare the rates\n");
        printf("6. Surprise no. 2 for video\n");   // surprise no. 2 for video
        printf("7. Exit\n");
        printf("============================================\n");

        printf("Your choice : ");
        scanf("%d", &ch);

        if (ch == 1) ALL_FLIGHTS(planes, n);

        else if (ch == 2) {
            int id = select_flight(planes, n);
            if (id != -1) book_one_seat_now(&planes[id], id);
        }

        else if (ch == 3) {
            int id = select_flight(planes, n);
            if (id != -1) cancel_the_seat(&planes[id], id);
        }

        else if (ch == 4) my_personal_booking(planes);

        else if (ch == 5) {
            int id = select_flight(planes, n);
            if (id != -1) compare_the_rates(planes[id]);
        }

        else if (ch == 6) {
#ifdef _WIN32
            system("start https://www.youtube.com/watch?v=aPQHWWSpe-A"); 
#else
            system("xdg-open https://www.youtube.com/watch?v=aPQHWWSpe-A");
#endif
        }

        else if (ch == 7) break;

        else printf("\nInvalid input.\n");
    }

    return 0;
}
