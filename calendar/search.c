#include "search.h"
#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

int searchiter(EventList* eventlist, SearchConditions condition){
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
        else if(condition.year==iter->year &&
                condition.month==iter->month &&
                condition.day==iter->day)
                    inserttofindlist(&findlist,iter);


        iter=iter->prev;
    }
    int choice=printfindlist(&findlist,condition);
    return choice;


}

int searchbyname(EventList* eventlist){
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
    int choice=searchiter(eventlist,byname);
    return choice;
    //searchbyname_iter(eventlist,&search);
}

int searchbyweek(EventList* eventlist){
    printf("Hanyadik ev, hanyadik het? (eeee.hh)\n");
    int week,year;
    scanf("%d.%d",&year,&week);
    SearchConditions byweek;
    byweek.name=NULL;
    byweek.week=week;
    byweek.year=year;
    int choice=searchiter(eventlist,byweek);
    return choice;

}

int searchbymonth(EventList* eventlist){
    printf("Hanyadik ev, hanyadik ho?(eeee.hh)\n");
    int month,year;
    scanf("%d.%d",&year,&month);
    SearchConditions bymonth;
    bymonth.name=NULL;
    bymonth.week=NULL;
    bymonth.year=year;
    bymonth.month=month;
    bymonth.day=NULL;
    int choice=searchiter(eventlist,bymonth);
    return choice;
}

int searchbyday(EventList* eventlist){
    printf("Hanyadik ev, hanyadik ho,hanyadik nap?(eeee.hh.nn)\n");
    int month,year,day;
    scanf("%d.%d.%d",&year,&month,&day);
    SearchConditions byday;
    byday.name=NULL;
    byday.week=NULL;
    byday.year=year;
    byday.month=month;
    byday.day=day;
    int choice=searchiter(eventlist,byday);
    return choice;
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
int printfindlist(FindList* findlist, SearchConditions condition){

    int choice=1;
    while(choice!=5){
        FoundEvent* fe=findlist->first->nextfound;
        int i=1;
        while(fe->nextfound!=NULL){
            printf("(%d) ",i);
            printevent_short(fe->foundevent);
            fe=fe->nextfound;
            i++;
        }
        if(condition.name!=NULL)
            printf("(%d) Uj kereses nev szerint\n",i++);
        else if(condition.name==NULL && condition.week!=NULL)
            printf("(%d) Uj kereses het szerint\n",i++);
        else if(condition.month!=NULL && condition.day==NULL)
            printf("(%d) Uj kereses het szerint\n",i++);
        else printf("(%d) Uj kereses nap szerint\n",i++);
        printf("(%d) Kereses mashogy\n",i++);
        printf("(%d) Fomenu\n",i++);
        printf("\nHova szeretnel menni?\n");
        choice=scanfindlist(i,findlist);
    }
    return choice;
}

int scanfindlist(int i, FindList* findlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar;
    if(valasztas<=i-4 && valasztas>=1){
        FoundEvent* fe=findlist->first->nextfound;
        int szamlalo=1;
        while(szamlalo!=valasztas){
            fe=fe->nextfound;
            i++;
        };
        //eventrecord(fe->foundevent);
        printeventrecord(fe->foundevent);
    }
    else if(valasztas==i-2) return 0;
    else if(valasztas==i-1) return 5;
}
