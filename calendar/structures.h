#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <time.h>

/**
* @defgroup structures Szükséges struktúrák
* @{
*/


/** Az eseményt leíró adatok*/
typedef struct Event{
    int year,month,day;
    int starthour, startmin, endhour, endmin;
    char* name;
    char* location;
    char* comment;
    /** a duplán láncolt listában az időben következő esemény */
    struct Event* next;
     /** a duplán láncolt listában az időben megelőző esemény */
    struct Event* prev;
}Event;


/** Az események listájának eleje és vége*/
typedef struct EventList{
    /**első őrszem, üres adatokkal */
    Event* first;
    /** utolsó őrszem, üres adatokkal */
    Event* last;
}EventList;


/**Keresés által megtalált esemény*/
typedef struct FoundEvent{
    /** a talált eseményre mutató pointer */
    Event* foundevent;
    /** a találati listában a találatot megelőző elem */
    struct FoundEvent* prevfound;
    /** a találati listában a találatot követő elem */
    struct FoundEvent* nextfound;
}FoundEvent;


/**A keresés által talált események listája*/
typedef struct FindList{
    /** a találati lista első őrszeme, üres */
    FoundEvent* first;
    /** a találati lista utolsó őrszeme, üres */
    FoundEvent* last;
}FindList;


/**A keresést leírő paraméterek*/
typedef struct SearchConditions{
    /**a keresendő nevet tartalmazó karaktertömb vagy NULL */
    char* name;
    /** melyik évben keresünk */
    int year;
    /**melyik hétben keresünk vagy 0 */
    int week;
    /** melyik hónapban keresünk vagy 0 */
    int month;
    /** amelyik napon keresünk vagy 0 */
    int day;
}SearchConditions;

//typedef void (*MenuFv)(EventList*);

/**Menupontok neveinek listája*/
typedef struct MenuPont{
    /** menüpont nevére mutató karaktertömb */
   char const *nev;
   //MenuFv pfv;
} MenuPont;

/** struktúra idő tárolására*/
typedef struct tm Tm;

/** @} */

#endif // STRUCTURES_H_INCLUDED
