#include "list.h"

EventList initeventlist(){
    EventList eventlist;
    Event* first=(Event*) malloc(sizeof(Event));
    Event* last=(Event*) malloc(sizeof(Event));
    eventlist.first=first;
    eventlist.last=last;
    eventlist.first->next=eventlist.last;
    eventlist.last->prev=eventlist.first;
    return eventlist;
}
