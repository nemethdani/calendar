#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "structures.h"

/**
* @defgroup menu Menü kezelő
* @brief menük kiírása, parancsok, adatok bekérése
* A menüknél a függvények egyik része kiírja a menüben végrehajtható parancsokat a hozzájuk tartozó, azt meghívó számmal
* A függvények másik része beolvassa a felhasználó által megadott parancsot, és végrehajtja azt.
* A menük integereket adnak vissza, ezzel vezérelhetők a visszalépések.
* @{
*/

/** Meghívja a mentéssel kapcsolatos menüt, és kiírja, hogy sikeres volt-e a mentés
* @param eventlist: Ennek az EventList típusú listának az eseményeit menti. címmel megadva.
*/
void filesave(EventList const* eventlist);

/** Bekéri a létrehozandó esemény adatait, meghívja a létrehozó függvényeket,
* meghívja az esemény részleteit kiíró és módosításra szolgáló menüt
* @param eventlist: Ebbe az EventList típusú listába szúrjuk be az eseményt. címmel megadva
* @return továbbítja a printeventrecord-ban előállított kimenetet
*/
int newevent(EventList* eventlist);

/** Bekér egy max hosszúságú karaktersort. Szól, ha a megadott sor túl, hosszú, és újra bekéri a szöveget
* @param bufferhossz: max ekkora lehet a hossza a megadott stringnek, lezáró 0-val együtt
* @return a létrehozott dinamikusan foglalt karaktertömbre mutató pointer
*/
char *hosszu_sort_olvas(int bufferhossz);


/** Kiírja a főmenüt és meghívja a kapcsolódó parancsokat bekérő függvényt
*/
void mainmenu();


/** Beolvassa a főmenünél megadott parancsot, és végrehajtja az utasítást
*/
void scanmainmenu(EventList* eventlist);

/** Kiírja a keresési módot választó menüt, beolvassa a felhasználó
* által megadott parancsot, és meghívja a fonatkozó függvényt
*/
void searchmenu(EventList* eventlist);

/** Megkérdezi, hogy tényleg mentse-e a fájlt. (Le lehet mégsézni)
* Meghívja a választ beolvasó függvényt
* @param eventlist: Ennek az EventList típusú listának az eseményeit menti. címmel megadva.
*/
void savemenu(EventList const* eventlist);

/** Beolvassa a savemenu-ben felkínált opciókhoz kapcsolódó parancsot és végrehajta az utasítást
* @param eventlist: Ennek az EventList típusú listának az eseményeit menti. címmel megadva.
* @return mindig 0;
*/
int scansavemenu(EventList const* eventlist);

/** Kiírja a kilépéssel kapcsolatos opciókat és meghívja a parancsbeolvasó függvényt
* @param eventlist: Ezt az EventList típusú eseménylistát menthetjük, ha úgy választunk. címmel megadva
*/
void exitmenu(EventList* eventlist);

/** beolvassa az exitmenu-ben felkínált lehetőségekhez kapcsolódó parancsot
* @param eventlist: Ezt az EventList típusú eseménylistát menthetjük, ha úgy választunk. címmel megadva
* @return mindig 0.
*/
int scanexitmenu(EventList* eventlist);

/** MenuPont típusú tömbben megadott menüpontok nevének kiírása
* @param menupontok: MenuPont típusú tömb, mely tartalmazza a menüpontok nevét és a kapcsolódó parancs függvénypointerét
*/
void printmenu(MenuPont const* menupontok);

/** @} */

#endif // MENU_H_INCLUDED
