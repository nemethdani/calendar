#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

//#include <stdio.h>
#include "structures.h"
#include <stdbool.h>
/**
* @defgroup file File kezelő
* @brief adatok fájlba mentése és ebből betöltése
* mivel az adatok betöltésénél először fix méretű tömbbe tesszük az adatokat, fontos, hogy amikor a felhasználó új adatot ad meg, korlátozzuk annak hosszát, hogy megfeleljen a betöltéskor beolvasható max hosszal.
* @{
*/

/** String másolása dinamikusan foglalt tömbbe
* @param karakterstringre mutató pointer
* @return dinamikusan foglalt karaktertömb lezáró nullával
*/
char* dstrcpy(char const* str);
/** Betölti az adatokat a naptar.txt fajlbol
* @param eventlist: EventList-re mutató pointer: ebbe a már inicializált listába töltjük be az adatokat
* @return false, ha nem sikerült végrehajtani, egyébként true
*/
bool calendarload(EventList const* eventlist);
/** Elmenti az adatokat a naptar.txt fajlba
* @param eventlist: EventList-re mutató pointer: ebből a listából mentjük ki az adatokat
* @return false, ha nem sikerült végrehajtani, egyébként true
*/
bool calendarsave(EventList const* eventlist);
/** @} */


#endif // FILE_H_INCLUDED
