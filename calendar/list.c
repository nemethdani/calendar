#include "list.h"
#include <stdlib.h>
#include "structures.h"
#include <time.h>
#include "debugmalloc.h"

EventList* initeventlist(){
    EventList* eventlist=(EventList*) malloc(sizeof(EventList));
    Event* sentinel1=(Event*) malloc(sizeof(Event));
    sentinel1->prev=NULL;
    sentinel1->name=NULL;
    sentinel1->location=NULL;
    sentinel1->comment=NULL;
    Event* sentinel2=(Event*) malloc(sizeof(Event));
    sentinel2->next=NULL;
    sentinel2->name=NULL;
    sentinel2->location=NULL;
    sentinel2->comment=NULL;
    eventlist->first=sentinel1;
    eventlist->last=sentinel2;
    eventlist->first->next=eventlist->last;
    eventlist->last->prev=eventlist->first;
    return eventlist;
}

void freeEventList(EventList* eventlist){
    Event* list=eventlist->first;
    while(list){
        Event* list_temp=list->next;
        free_event(list);
        list=list_temp;
    }
    free(eventlist);
    return;
}

Event* createevent(int ev, int honap, int nap, int ora, int perc, int bora, int bperc, char* nev,char* hely,char* comment){
    Event *event=(Event*) malloc(sizeof(Event));
    if(event==NULL) return NULL;
    //event.date=date;
    event->year=ev;
    event->month=honap;
    event->day=nap;
    event->starthour=ora;
    event->startmin=perc;

    event->endhour=bora;
    event->endmin=bperc;

    event->name=nev;
    event->location=hely;
    event->comment=comment;
    event->prev=NULL;
    event->next=NULL;

    return event;
}
void insertevent(EventList const* eventlist,Event* event){
    if(eventlist==NULL) return NULL;
    if(event==NULL) return NULL;

    Event* moving;
    moving=eventlist->last->prev;
    while(moving!=eventlist->first &&  (starttime(moving) > starttime(event))){
        moving=moving->prev;
    }
    event->prev=moving;
    event->next=moving->next;

    moving->next->prev=event;
    moving->next=event;


    return event;
}

int starttime(Event* event){
    Tm start;
    start.tm_year=event->year;
    start.tm_mon=event->month;
    start.tm_mday=event->day;
    start.tm_hour=event->starthour;
    start.tm_min=event->startmin;
    start.tm_sec=0;



    return mktime(&start);
}

void free_event(Event* event){

    if(event->name!=NULL) free(event->name);
    if(event->location!=NULL) free(event->location);
    if(event->comment!=NULL) free(event->comment);
    free(event);
}
