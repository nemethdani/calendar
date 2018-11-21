#ifndef EVENTRECORD_H_INCLUDED
#define EVENTRECORD_H_INCLUDED

#include "structures.h"
#include <stdbool.h>
/**
* @defgroup eventrecord Események részletei
* Események részleteinek kiírásával és módosításával kapcsolatos függvények
* @{
*/

/**Hogyan szeretnénk módosítani az eseményt:
* bydate: dátum szerint
* bystart: kezdőidő (óra, perc) szerint
* byend: befejezőidő (óra, perc) szerint
*/
typedef enum ModBy{bydate,bystart,byend}ModBy;
/** Az esemény időhöz kapcsolódó változóinak módosítása
* Bekéri az új értéket, és erre módosítja
* Áthelyezi az eseményt a láncolt listában,
*   ha dátum vagy kezdőidő szerint módosítjuk
* @param event: Event típusra mutató pointer: a módosítandó esemény
* @param eventlist: EventList-re mutató pointer: a lista amelyikben a módosítandó esemény található
*/
void moveevent(Event* event,EventList const* eventlist,ModBy modby);
/**Esemény törlése
* Megkérdezi, hogy töröljük-e
* @param event: törlendő Event típusó eseményre mutató pointer
*/
void deleteevent(Event* event);
/**Bekéri az eseményrekord menüből az utasítást
* és meghívja a kívánt parancshoz tartozó függvényt
* @param isnewevent: true, ha újonnan létrehozott esemény rekordját nézzük
* @param i: hány db menüpont van+1
* @param event: Event típusú vizsgált eseményre mutató pointer
* @param eventlist: EventList-re mutató pointer: a lista amelyikben a módosítandó esemény található
* @return 5, ha a főmenube akarunk menni;
            2, ha maradni akarunk az eseménynél
            0: kereses mashogy
            1: kereses ugyanigy vagy új esemény
            -1:talalati lista
*/
int scanrecordcommand(bool isnewevent, int i,Event* event,EventList* eventlist);
/** Kiírja az esemény részleteit és a szerkesztéshez, navigációhoz kapcsolatos menüpontokat
* majd meghívja a parancsbeolvasó fv-t.
* @param event: Event típusra mutató pointer: a módosítandó esemény
* @param condition: a keresés feltételeit tartalmazó változó
* @param eventlist: EventList-re mutató pointer: a lista amelyikben a módosítandó esemény található
* @return   5, ha a főmenube akarunk menni;
            0: kereses mashogy
            1: kereses ugyanigy, vagy új esemény
            -1:talalati lista
*/
int printeventrecord(Event* event,SearchConditions condition,EventList* eventlist);

/** @} */

#endif // EVENTRECORD_H_INCLUDED
