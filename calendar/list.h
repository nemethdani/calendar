#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "structures.h"
#include <time.h>

/**
* @defgroup list Lista kezelő
* listák, események létrehozás, törlése
* @{
*/

/** időponthoz tartozó struktúra
*/
typedef struct tm Tm;

/** Létrehoz egy új eseméynlistát
* duplán láncolt listaként, 2 db üres, nem használt őrszemmel
* @return a létrehozott EventList típusú listára mutató pointer
*/
EventList* initeventlist();

/** Felszabadítja az eseménylistát eseményekkel együtt
* A felszabadítandó EventList típusú litsára mutató pointer
*/
void freeEventList(EventList* eventlist);

/** Létrehoz egy eseményt dianmiusan, és feltölti a megadott adatokkal
* @param ev: Esemény éve
* @param honap: Esemény hava
* @param nap: Esemény napja
* @param ora: Esemény kezdő órája
* @param perc: Esemény kezdő perce
* @param bora: Esemény befejező órája
* @param bperc: Esemény befejező perce
* @param nev: Esemény nevét tartalmazó char típusú stringre mutató pointer. A megadott string már legyen lefoglalva. Max 128 karakter lezáró nullával együtt.
* @param nev: Esemény helyét tartalmazó char típusú stringre mutató pointer. A megadott string már legyen lefoglalva. Max 128 karakter lezáró nullával együtt.
* @param nev: Eseményre vonatkozó megjegyzést tartalmazó char típusú stringre mutató pointer. A megadott string már legyen lefoglalva. Max 256 karakter lezáró nullával együtt.
* @return event: Event típusú létrehozott eseményre mutató pointer
*/
Event* createevent(int ev, int honap, int nap, int ora, int perc, int bora, int bperc, char* nev,char* hely,char* comment);

/** Beilleszt egy már létrehozott eseményt az eseménylistába
* Az eseményeket kezdő dátum és kezdő idő szerint növekvően rendezve szúrja be
* A keresést visszafelé (hátulról előre) végzi
* @param eventlist: Ebbe az EventList típusó listába szúrjuk az eseményt. címmel adjuk meg
* @param event: Ezt az Event típusú eseményt szúrjuk be. Címmel adjuk meg
*/
void insertevent(EventList const* eventlist,Event* event);

/** Létrehozza az események kezdőidejét jelző számot másodperc nagyságrendben a kezdőidő összehasonlításához
* @param event: ennek az Event típusú eseménynek keressük a kezdőidejét. Az esemény kezdőmásodpercét nullának vettük
* @return másodperc nagyságrendben adja vissza, hogy hol helyezkedik el az esemény az időben.
*/
int starttime(Event* event);

/** Felszabadítja az eseményt és a tartalmazott karaktertömböket
* @param: a felszabadítani kívánt Event típusú eseményre mutató pointer
*/
void free_event(Event* event);


/** @} */

#endif // LIST_H_INCLUDED
