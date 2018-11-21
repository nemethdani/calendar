#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

//#include <stdio.h>
#include "structures.h"
#include <stdbool.h>

char* dstrcpy(char* str);
bool calendarload(EventList* eventlist);
bool calendarsave(EventList* eventlist);



#endif // FILE_H_INCLUDED
