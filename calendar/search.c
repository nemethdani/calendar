#include "search.h"
#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include "searchui.h"




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

    while((iter!=eventlist->first) && ((condition.name==NULL && iter->year>=condition.year) || (condition.name!=NULL))){

        if(condition.name!=NULL && strstr(iter->name,condition.name)!=NULL)
                inserttofindlist(&findlist,iter);
        else if(condition.name==NULL && condition.week!=0){
                   //printf("%d\n",eventtoweek(iter));
                   if(iter->year==condition.year){
                       Tm* tm=eventtotm(iter);
                       int week=tmtoweek(tm);

                       if(week==condition.week)
                            inserttofindlist(&findlist,iter);
                   }
        }
        else if(condition.month!=0 && condition.day==0 &&
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
        cond.week=0;
        cond.month=timeinfo->tm_mon+1;
        cond.day=0;
        break;
    case byday:
        cond.week=0;
        cond.month=timeinfo->tm_mon+1;
        cond.day=timeinfo->tm_mday;
        break;
  };
  int choice=searchiter(eventlist,cond);
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


