#ifndef EVENTRECORD_H_INCLUDED
#define EVENTRECORD_H_INCLUDED

#include "structures.h"
#include <stdbool.h>


typedef enum ModBy{bydate,bystart,byend}ModBy;
void moveevent(Event* event,EventList* eventlist,ModBy modby);
void deleteevent(Event* event);
int scanrecordcommand(bool isnewevent, int i,Event* event,EventList* eventlist);
int printeventrecord(Event* event,SearchConditions condition,EventList* eventlist);


#endif // EVENTRECORD_H_INCLUDED
