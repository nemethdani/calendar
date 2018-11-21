#include "file.h"
#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "list.h"
#include <string.h>



char* dstrcpy(char const* str){
    int len=strlen(str)+1;
    char* uj=(char*) malloc(sizeof(char)*len);
    strcpy(uj,str);
    return uj;
}

bool calendarload(EventList const* eventlist){
    if(eventlist==NULL) return false;

    FILE *fp; /* fájl mutató (file pointer/handle) */

    fp = fopen("naptar.txt", "rt"); /* megnyitás */
    if (fp == NULL) {
       perror("Fájl megnyitása sikertelen");
       return false;    /* nem folytathatjuk! */
    }
    int year,month,day;
    int starthour, startmin, endhour, endmin;
    char name[128];
    char location[128];
    char comment[256];

    while(
          fscanf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%[^\t]\t%[^\t]\t%[^\n]",
                &year,&month,&day,
                &starthour,&startmin,
                &endhour,&endmin,
                name,location,comment)==10){
        //karaktereket átalakítani dinamikussá!

        Event* event= createevent(year,month,day,starthour,startmin,endhour, endmin, dstrcpy(&name),dstrcpy(&location),dstrcpy(&comment));
        if(event==NULL) return false;
        insertevent(eventlist, event);

    }



    fclose(fp);
    return true;
}

bool calendarsave(EventList const* eventlist){
    FILE *fp; /* fájl mutató (file pointer/handle) */

    fp = fopen("naptar.txt", "wt"); /* megnyitás */
    if (fp == NULL) {
       perror("Fájl megnyitása sikertelen");
       return false;    /* nem folytathatjuk! */
    }
    Event* me=eventlist->first->next;
    if(me==NULL
       || me==eventlist->last)
        return false;
    //Event* me;
    while(me!=eventlist->last){
        //me=moving->event;
        fprintf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\n",
                me->year,
                me->month,
                me->day,
                me->starthour,
                me->startmin,
                me->endhour,
                me->endmin,
                me->name,
                me->location,
                me->comment);

        me=me->next;
    }

    fclose(fp);
    return true;
}



