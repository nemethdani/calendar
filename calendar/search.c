#include "search.h"
#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void inserttofindlist(FindList* findlist,Event* event){
    FoundEvent* newfound=(FoundEvent*) malloc(sizeof(FoundEvent));
    newfound->foundevent=event;
    newfound->nextfound=findlist->first->nextfound;
    newfound->nextfound->prevfound=newfound;
    findlist->first->nextfound=newfound;
    newfound->prevfound=findlist->first;
}



void printfindlist(FindList findlist){
    FoundEvent* fe=findlist.first->nextfound;
    while(fe->nextfound!=NULL){
        printevent_short(fe->foundevent);
        fe=fe->nextfound;
    }
}
