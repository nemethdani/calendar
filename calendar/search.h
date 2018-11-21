#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdbool.h>
#include "structures.h"

/**
* @defgroup search Keresés kezelő
* a keresést támogató háttérfüggvények
* @{
*/

/** Keresés módjának megadására szolgáló enum
*/
typedef enum SearchBy{
    byweek, /**< hét szerint */
    byday, /**< nap szerint */
    bymonth /**< hónap szerint */
}SearchBy;

/** A megadott keresési feltételeknek megfelelően végig megy a listán hátulról előre.
* Ha telál a feltételnek megfelelő eseményt, beteszi a találati listába az insertofindlist függvénnyel
* kiírja a találati listát
* Visszatérés előtt felszabadítja a találati listát
* @param eventlist: ebben az EventList típusú eseménylistában keresünk. cím szerint megadva
* @param condition: ebben a SearchConditions típusú változóban adjuk meg az adott kereséshez szükséges adatokat.
*   ha nem név szerint keresünk akkor condition.name=NULL.
*   ha nem hét szerint keresünk, akkor condition.week=0.
*   ha nem nap szerint keresünk, akkor condition.day=0;
* @return továbbítja a printfindlist visszatérési értékét
*/
int searchiter(EventList* eventlist, SearchConditions condition);

/** Keresést futtat a jelenlegi hétre, hónapra vagy napra
* @param eventlist: ebben a listában keresünk
* @param searchmode: mi szerint keresünk (byweek, byday, bymonth)
* @return továbbítja a searchiter-ből kapott visszatérési értéket
*/
int searchactual(EventList* eventlist,SearchBy searchmode);

/** A talált elemek beillesztése egy találati listába
* @param findlist: ebbe a találati listába illesztünk be (a searchiter létrehozza). cím szerint adjuk meg.
* @param event: ezt az eseményt illesztjük be. cím szerint.
*/
void inserttofindlist(FindList* findlist,Event* event);

/** Kiszámítja, hogy adott dátum az év hányadik hetére esik (ISO 8601 szabvány szerint)
* @param tm: Tm típusú pointer cím szerint. Itt adjuk meg a vizsgált dátumot
* @return a hét száma (1-53)
*/
int tmtoweek(Tm* tm);

/** Esemény kezdőidejét Tm típussá alakítja
* @param event: ennek az eseménynek a kezdőidejét alakítjuk át
* @return Tm típusú pointer (struct tm)
*/
Tm* eventtotm(Event* event);

/** @} */


#endif // SEARCH_H_INCLUDED
