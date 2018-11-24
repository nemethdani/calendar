#ifndef SEARCHUI_H_INCLUDED
#define SEARCHUI_H_INCLUDED

/**
* @defgroup search Keresés-menü kezelő
* @brief a kereséshez szükséges adatok bekérése, találatok kiírása
* a keresés típusától függően bekérjük a felhasználótól a szükséges adatokat, ezt típusonként egy-egy fv kezeli.7
* Ezek a függvények átadják az infót a külön modulban található searchiter fv-nek, ami meghívja a printfindlist fv-t a találati lista kiírásához
* a tlálati listában az eseményekhez tartózó szám bevitelével (amit a scanfindlist olvas be) az eseményrekordra jutunk, ahol módosítani és törölni tudjuk az eseményt.
* @{
*/

/**Bekér egy számot, és ezt adja vissza*/
int scaninput();

/** Név szerinti kereséshez bekéri a nevet, majd meghívja a searchiter-t kereséshez
* @param eventlist: ebben a listában keresünk
* @return a searchiter visszatérési értékét továbbítja
*/
int searchbyname(EventList* eventlist);

/** Hét szerinti kereséshez bekéri az évet és a hetet, majd meghívja a searchiter-t kereséshez
* @param eventlist: ebben a listában keresünk
* @return a searchiter visszatérési értékét továbbítja
*/
int searchbyweek(EventList* eventlist);

/** Hó szerinti kereséshez bekéri az évet és a hónapot, majd meghívja a searchiter-t kereséshez
* @param eventlist: ebben a listában keresünk
* @return a searchiter visszatérési értékét továbbítja
*/
int searchbymonth(EventList* eventlist);

/** Nap szerinti kereséshez bekéri az évet, hónapot és napot, majd meghívja a searchiter-t kereséshez
* @param eventlist: ebben a listában keresünk
* @return a searchiter visszatérési értékét továbbítja
*/
int searchbyday(EventList* eventlist);

/** kiírja a keresés által talált események listáját és az elérhető menüpontokat.
* Meghívja a parancsbeolvasó függvényt a menüpontokhoz
* @param findlist: ebben vannak tárolva a keresés által talált elemek
* @param condition: itt tároljuk a keresési feltétleket. lásd: searchiter
* @param eventlist: ebben a listában keresünk
*/
int printfindlist(FindList* findlist, SearchConditions condition,EventList* eventlist);

/** Beolvassa a találati listán érvényes parancsokat a felhasználótól és meghívja a vonatkozó függvényt
* @param i: a printfindlist-ben kiírt menüpontok száma+1
* @param findlist: a keresés által visszaadott események listája
* @param condition: keresési feltételek
* @param eventlist: az események listája, amiben keresünk
* @return 1: keresés ugyanígy, 0: keresés máshogy, 5: főmenü
*/
int scanfindlist(int i, FindList* findlist,SearchConditions condition,EventList* eventlist);

/** Kiírja az esemény nevét, dátumát, kezdőidejét*/
void printevent_short(Event* event);

/** @} */

#endif // SEARCHUI_H_INCLUDED
