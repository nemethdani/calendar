#include "eventrecord.h"
#include "structures.h"
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
//#include "list.c"

void free_event(Event* event){
    free(event->comment);
    free(event->name);
    free(event->location);
    free(event);
}

void deleteevent(Event* event){
    printf("tenyleg törölni szeretned? (i)/(n)");
    char valasz;
    getchar();
    scanf("%c",&valasz);
    if(valasz=='i'){
        event->prev->next=event->next;
        event->next->prev=event->prev;
        free_event(event);
    }
    else return;

}

int scanrecordcommand(bool isnewevent, int i,Event* event,EventList* eventlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar;
    if(valasztas==i-1) return 5; //fomenu
    if(valasztas==1){
            free(event->name);
            printf("Mi az esemeny neve? (max 127 karakter)\n");
            getchar();
            char* newname=hosszu_sort_olvas(128);
            event->name=newname;
            return 2;
    }
    else if(valasztas==5){
        free(event->location);
        getchar();
        printf("Mi az esemeny helye? (max 127 karakter)\n");
        event->location=hosszu_sort_olvas(128);
        return 2;
    }
    else if(valasztas==6){
        free(event->comment);
        getchar();
        printf("Van megjegyzesed? (max 255 karakter)\n");
        event->comment=hosszu_sort_olvas(256);
        return 2;
    }
    if(!isnewevent){
        if (valasztas==i-2) return 0; //kereses mashogy
        else if (valasztas==i-3) return 1; //kereses ugyanigy
        else if (valasztas==i-4) return -1; //talalati lista
        else if (valasztas==i-5) {deleteevent(event); return 5;} //fomenu
        else if (valasztas==i-6) {savemenu(eventlist); return 2;}//mentes

    }
    else{
        if (valasztas==i-3) {deleteevent(event); return 5;} //fomenu
        else if (valasztas==i-4) {savemenu(eventlist); return 2;}//mentes
        else if (valasztas==i-2) return 1;//uj esemeny

    }

}

int printeventrecord(Event* event,SearchConditions condition,EventList* eventlist){
    int choice=2;
    bool isnewevent=false;
    while(choice>1 && choice!=5){
        int i=1;
        printf("(%d) Nev:        %s\n",i++,event->name);
        printf("(%d) Datum:      %d.%.2d.%.2d\n",i++,event->year,event->month,event->day);
        printf("(%d) Kezdes:     %.2d:%.2d\n",i++,event->starthour,event->startmin);
        printf("(%d) Befejezes:  %.2d:%.2d\n",i++,event->endhour,event->endmin);
        printf("(%d) Hely:       %s\n",i++,event->location);
        printf("(%d) Megjegyzes: %s\n",i++,event->comment);
        printf("(%d) Mentes\n",i++);
        printf("(%d) Torles\n",i++);
        if(condition.name==NULL && condition.week==0 && condition.month==0){
            printf("(%d) Uj esemeny\n",i++);
            isnewevent=true;

        }
        else {
            printf("(%d) Vissza a talalati listahoz\n",i++);
            printf("(%d) Uj kereses ugyanigy\n",i++);
            printf("(%d) Kereses mashogy\n",i++);
        }


        printf("(%d) Fomenu\n",i++);

        choice=scanrecordcommand(isnewevent,i,event,eventlist);

    }
    return choice;
}


