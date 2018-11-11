#include "file.h"
#include <stdio.h>
#include <stdbool.h>
#include "structures.h"


//bool calendarload(EventList* eventlist){
//    if(eventlist==NULL) return false;
//
//    FILE *fp; /* fájl mutató (file pointer/handle) */
//
//    fp = fopen("naptar.txt", "rt"); /* megnyitás */
//    if (fp == NULL) {
//       perror("Fájl megnyitása sikertelen");
//       return false;    /* nem folytathatjuk! */
//    }
//    int year,month,day;
//    int starthour, startmin, endhour, endmin;
//    char name[128];
//    char location[128];
//    char comment[256];
//
//    while(
//          fscanf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%[^\t]\t%[^\t]\t%[^\n]",
//                &year,&month,&day,
//                &starthour,&startmin,
//                &endhour,&endmin,
//                name,location,comment)==10){
//        Event* event= createevent(date, start, ends, name, loc, comm);
//        if(event==NULL) return false;
//        if(insertEventToListBackwards(eventlist, event)==false) return false;
//
//    }
//
//
//    fclose(fp);
//    return true;
//}
//
//bool calendarsave(EventList* eventlist){
//    FILE *fp; /* fájl mutató (file pointer/handle) */
//
//    fp = fopen("naptar.txt", "wt"); /* megnyitás */
//    if (fp == NULL) {
//       perror("Fájl megnyitása sikertelen");
//       return false;    /* nem folytathatjuk! */
//    }
//    EventListElement* moving=eventlist->first->next;
//    if(moving==NULL
//       || moving==eventlist->last)
//        return false;
//    Event* me;
//    while(moving!=eventlist->last){
//        me=moving->event;
//        fprintf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\n",
//                me->start.tm_year,
//                me->start.tm_mon,
//                me->start.tm_mday,
//                me->start.tm_hour,
//                me->start.tm_min,
//                me->ends.tm_hour,
//                me->ends.tm_min,
//                me->name,
//                me->location,
//                me->comment);
//
//        moving=moving->next;
//    }
//
//    fclose(fp);
//    return true;
//}

