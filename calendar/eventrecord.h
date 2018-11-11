#ifndef EVENTRECORD_H_INCLUDED
#define EVENTRECORD_H_INCLUDED

#include "structures.h"

void printrecordmenu(Event* event,SearchConditions conditions);
void printevent(Event* event);
void modifyevent(int tomod, Event* event);
void savetofile(Event* event,SearchConditions conditions); /*parameterek ugyanaz mint rekordmenu*/
void deleteevent(Event* event,SearchConditions conditions);
void scanrecordcommand(int maxmod, Event* event,SearchConditions conditions) /*osszes parameter a fentiekből*/


#endif // EVENTRECORD_H_INCLUDED
