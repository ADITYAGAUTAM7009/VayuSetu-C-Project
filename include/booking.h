#ifndef BOOKING_H
#define BOOKING_H

#include "airplane.h"
#include "history.h"

void book_one_seat_now(struct AIRPLANE *a, int index);
void cancel_the_seat(struct AIRPLANE planes[], int index);

#endif
