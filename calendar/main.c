#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "file.h"
#include "list.h"
#include "menu.h"
#include <stdlib.h>
#include <stdbool.h>

/*! \mainpage Határidőnapló
 *
 * A határidőnapló program képes események létrehozására, keresésére, módosítására és törlésére.
 * Az események duplán láncolt listában vannak tárolva, két üres strázsával, időben növekvő sorrendben rendezbe (lásd:struktúrák).
 * A keresésnél időben visszafelé haladunk, így kevesebb iterációt kell végezni feltételezve, hogy a felhasználó "közeli eseményekre keres".
 * Módosításkor ha az esemény kezdő  idejét módosítjuk,  a program áthelyezi a láncolt listában az eseményt. Szöveges infó módosításánál csak kicseréljük a stringet
 * A háttérműködést vezérlő modulok: file-, lista-, keresés-kezelő, és a struktúrák
 * A felhasználói felülethez kapcsolódó modulok: események részletei (itt lehet az eseményt módosítani is), menü kezelő, keresés-menü kezelő.
 */


/** Inicializál egy üres eseméynlistát és feltölti adatokkal a fájlból, ha létezik a naptar.txt
*/
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
