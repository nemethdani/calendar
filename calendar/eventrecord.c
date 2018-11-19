#include "eventrecord.h"
#include "structures.h"
#include <stdio.h>
//#include "list.c"

int printeventrecord(Event* event,SearchConditions condition){
    int choice=2;
    while(choice>=1 && choice!=5){
        int i=1;
        printf("(%d) Datum:     %d.%.2d.%.2d\n",i++,event->year,event->month,event->day);
        printf("(%d) Kezdes:    %.2d:%.2d\n",i++,event->starthour,event->startmin);
        printf("(%d) Befejezes: %.2d:%.2d\n",i++,event->endhour,event->endmin);
        printf("(%d) Mentes\n",i++);
        printf("(%d) Torles\n",i++);
        if(condition.name==NULL && condition.week==0 && condition.month==0){
            printf("(%d) Uj esemeny\n",i++);

        }
        else {
            printf("(%d) Vissza a talalati listahoz\n",i++);
            printf("(%d) Uj kereses ugyanigy\n",i++);
            printf("(%d) Kereses mashogy\n",i++);
        }


        printf("(%d) Fomenu\n",i++);

        choice=scanrecordcommand();
    };
}

int scanrecordcommand(){

}
