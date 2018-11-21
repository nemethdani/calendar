#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <stdbool.h>
#include "structures.h"

//typedef enum IterMode{insertion,lookup}IterMode;
typedef enum SearchBy{byweek,byday,bymonth}SearchBy;

int searchiter(EventList* eventlist, SearchConditions condition);
int searchactual(EventList* eventlist,SearchBy searchmode);
void inserttofindlist(FindList* findlist,Event* event);
int tmtoweek(Tm* tm);
Tm* eventtotm(Event* event);


#endif // SEARCH_H_INCLUDED
