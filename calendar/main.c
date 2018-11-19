#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "file.h"
#include "list.h"
#include "menu.h"
#include <stdlib.h>
#include <stdbool.h>



int main(){

    EventList* eventlist=initeventlist();
    //load data
    if(calendarload(eventlist)==false) printf("nem sikerult betolteni a fajlt\n");
    while(1){
        mainmenu();
        scanmainmenu(eventlist);
    };

//    Event* event=createevent(1990,3,26,14,45,15,56,"dani","bp","nincs");
//    printevent_short(event);
    freeEventList(eventlist); //csaka biztonság kedvéért


    return 0;
}
