#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdbool.h>

typedef enum IterMode{insertion,lookup}IterMode;

SearchConditions printsearchmenu();
SearchConditions searchbyname();
SearchConditions searchbymonth();
SearchConditions searchbyweek();
SearchConditions searchbyday();
void scansearchmenucommand();
bool istrueevent(bool condition);
void iterevents(bool backward, EventList eventlist, Itermode itermode);
void puttofindlist(Event* event);


#endif // SEARCH_H_INCLUDED
