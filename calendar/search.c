#include "search.h"
#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void searchiter(EventList* eventlist, SearchConditions condition){
    Event* iter=eventlist->last->prev;
    FindList findlist;
    FoundEvent sentinel1;
    FoundEvent sentinel2;
    sentinel1.foundevent=NULL;
    sentinel2.foundevent=NULL;
    sentinel1.prevfound=NULL;
    sentinel2.nextfound=NULL;
    sentinel1.nextfound=&sentinel2;
    sentinel2.prevfound=&sentinel1;
    findlist.first=&sentinel1;
    findlist.last=&sentinel2;

    while(iter!=eventlist->first){

        if(condition.name!=NULL && strstr(iter->name,condition.name)!=NULL)
                inserttofindlist(&findlist,iter);
        else if(condition.name==NULL && condition.week!=NULL){
                   //printf("%d\n",eventtoweek(iter));
                   if(iter->year==condition.year){
                       Tm* tm=eventtotm(iter);
                       int week=tmtoweek(tm);

                       if(week==condition.week)
                            inserttofindlist(&findlist,iter);
                   }
        }
        else if(condition.month!=NULL && condition.day==NULL &&
                iter->year==condition.year &&
                iter->month==condition.month)
                    inserttofindlist(&findlist,iter);


        iter=iter->prev;
    }
    printfindlist(findlist);


}

void searchbyname(EventList* eventlist){
    printf("\nIrj be legalabb 3 osszefuggo karaktert az esemeny nevebol!\n");
    char search[128]={0};
    bool first=true;
    while(strlen(&search)<3){
            if(!first) printf("legalabb 3 karaktert irjal\n");
            scanf("%s",search);
            first=false;
    }
    SearchConditions byname;
    byname.name=search;
    searchiter(eventlist,byname);
    //searchbyname_iter(eventlist,&search);
}

void searchbyweek(EventList* eventlist){
    printf("Hanyadik ev, hanyadik het? (eeee.hh)\n");
    int week,year;
    scanf("%d.%d",&year,&week);
    SearchConditions byweek;
    byweek.name=NULL;
    byweek.week=week;
    byweek.year=year;
    searchiter(eventlist,byweek);

}

void searchbymonth(EventList* eventlist){
    printf("Hanyadik ev, hanyadik ho?(eeee.hh)\n");
    int month,year;
    scanf("%d.%d",&year,&month);
    SearchConditions bymonth;
    bymonth.name=NULL;
    bymonth.week=NULL;
    bymonth.year=year;
    bymonth.month=month;
    bymonth.day=NULL;
    searchiter(eventlist,bymonth);
}

void inserttofindlist(FindList* findlist,Event* event){
    FoundEvent* newfound=(FoundEvent*) malloc(sizeof(FoundEvent));
    newfound->foundevent=event;
    newfound->nextfound=findlist->first->nextfound;
    newfound->nextfound->prevfound=newfound;
    findlist->first->nextfound=newfound;
    newfound->prevfound=findlist->first;
}

int tmtoweek(Tm* tm){
    char buffer[3];


    strftime (buffer,3, "%V\n",tm);
    //printf("%s\n",buffer);
    return (buffer[0]-'0')*10 + (buffer[1]-'0');
}

Tm* eventtotm(Event* event){
  time_t timer;
  time(&timer);
  Tm* start=localtime(&timer);

  //start=localtime ( &rawtime );
  start->tm_year=event->year-1900;
  start->tm_mon=event->month-1;
  start->tm_mday=event->day;

  //mktime(start);
//    start->tm_year=1993;
//    start->tm_mon=5;
//    start->tm_mday=9;
//    char buffer[3];
//
//
//    strftime (buffer,80,"%V",start);
//    printf("%s\n",buffer);
//    return (buffer[0]-'0')*10 + (buffer[1]-'0');,
    mktime(start);
    return start;
}
void printfindlist(FindList findlist){
    FoundEvent* fe=findlist.first->nextfound;
    while(fe->nextfound!=NULL){
        printevent_short(fe->foundevent);
        fe=fe->nextfound;
    }
}
