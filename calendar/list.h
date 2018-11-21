#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "structures.h"
#include <time.h>

typedef struct tm Tm;

EventList* initeventlist();
void freeEventList(EventList* eventlist);
Event* createevent(int ev, int honap, int nap, int ora, int perc, int bora, int bperc, char* nev,char* hely,char* comment);
void insertevent(EventList* eventlist,Event* event);
int starttime(Event* event);
void free_event(Event* event);

#endif // LIST_H_INCLUDED
