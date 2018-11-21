#include "structures.h"
#include <stdbool.h>
#include <stdio.h>

int scaninput(){
    int input;
    scanf("%d",&input);
    getchar();

    return input;
}

int searchbyname(EventList* eventlist){
    printf("\e[1;1H\e[2J");
    printf("Irj be legalabb 3 osszefuggo karaktert az esemeny nevebol!\n");
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
    printf("\e[1;1H\e[2J");
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
    printf("\e[1;1H\e[2J");
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
    printf("\e[1;1H\e[2J");
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


int printfindlist(FindList* findlist, SearchConditions condition,EventList* eventlist){

    int choice=1;
    int newchoice=0;
    while(choice!=5 && choice!=0){
        FoundEvent* fe=findlist->first->nextfound;
        int i=1;
        printf("\e[1;1H\e[2J");
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
    getchar();
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

void printevent_short(Event* event){
    printf("%d.%d.%d %d:%d %s\n",event->year,event->month,event->day,event->starthour,event->startmin,event->name);
}
