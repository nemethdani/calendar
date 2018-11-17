#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdbool.h>
#include "structures.h"

typedef enum IterMode{insertion,lookup}IterMode;

SearchConditions printsearchmenu();
void searchbyname(EventList* eventlist);
SearchConditions searchbymonth();
void searchbyweek(EventList* eventlist);
Tm* eventtotm(Event* event);
SearchConditions searchbyday();
void scansearchmenucommand();
bool istrueevent(bool condition);
//void iterevents(bool backward, EventList eventlist, Itermode itermode);
void puttofindlist(Event* event);
void inserttofindlist(FindList* findlist,Event* event);


#endif // SEARCH_H_INCLUDED
