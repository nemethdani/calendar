#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "structures.h"
#include <time.h>

typedef struct tm Tm;

EventList* initeventlist();
void printevent_short(Event* event);
void insertevent(EventList* eventlist,Event* event);
Event* createevent(int ev, int honap, int nap, int ora, int perc, int bora, int bperc, char* nev,char* hely,char* comment);

#endif // LIST_H_INCLUDED
