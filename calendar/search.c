#include "search.h"
#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include "debugmalloc.h"

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
    int choice=printfindlist(&findlist,condition,eventlist);

    FoundEvent* fiter=findlist.first->nextfound;
    FoundEvent* ftemp;
    while(fiter!=findlist.last){
        ftemp=fiter->nextfound;
        free(fiter);
        fiter=ftemp;
    }

    return choice;


}

int searchactual(EventList* eventlist,SearchBy searchmode){
  time_t rawtime;
  struct tm * timeinfo;
  SearchConditions cond;
  cond.name=NULL;


  time (&rawtime);
  timeinfo = localtime (&rawtime);
  cond.year=timeinfo->tm_year+1900;
  switch(searchmode){
    case byweek:
        cond.week=tmtoweek(timeinfo);
        break;
    case bymonth:
        cond.week=NULL;
        cond.month=timeinfo->tm_mon+1;
        cond.day=NULL;
        break;
    case byday:
        cond.week=NULL;
        cond.month=timeinfo->tm_mon+1;
        cond.day=timeinfo->tm_mday;
        break;
  };
  int choice=searchiter(eventlist,cond);
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
int printfindlist(FindList* findlist, SearchConditions condition,EventList* eventlist){

    int choice=1;
    int newchoice=0;
    while(choice!=5 && choice!=0){
        FoundEvent* fe=findlist->first->nextfound;
        int i=1;
        while(fe->nextfound!=NULL){
            printf("(%d) ",i);
            printevent_short(fe->foundevent);
            fe=fe->nextfound;
            i++;
        }
        if(condition.name!=NULL){
            printf("(%d) Uj kereses nev szerint\n",i++);
            newchoice=1;
        }
        else if(condition.name==NULL && condition.week!=NULL){
            printf("(%d) Uj kereses het szerint\n",i++);
            newchoice=3;
        }
        else if(condition.month!=NULL && condition.day==NULL){
            printf("(%d) Uj kereses ho szerint\n",i++);
            newchoice=4;
        }
        else{printf("(%d) Uj kereses nap szerint\n",i++);
            newchoice=2;
        }
        printf("(%d) Kereses mashogy\n",i++);
        printf("(%d) Fomenu\n",i++);
        printf("\nHova szeretnel menni?\n");
        choice=scanfindlist(i,findlist,condition,eventlist);
        if(choice==1 && newchoice!=0)
            return newchoice;
    }
    return choice;
}

int scanfindlist(int i, FindList* findlist,SearchConditions condition,EventList* eventlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar;
    if(valasztas<=i-4 && valasztas>=1){
        FoundEvent* fe=findlist->first->nextfound;
        int szamlalo=1;
        while(szamlalo!=valasztas){
            fe=fe->nextfound;
            szamlalo++;
        };
        //eventrecord(fe->foundevent);
        int recordchoice=printeventrecord(fe->foundevent,condition,eventlist);
        return recordchoice;
    }
    else if(valasztas==i-3) return 1; //kereses ugyanigy
    else if(valasztas==i-2) return 0; //kereses mashogy
    else if(valasztas==i-1) return 5; //fomenu
}
