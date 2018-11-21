#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "structures.h"


void filesave(EventList* eventlist);
int newevent(EventList* eventlist);
char *hosszu_sort_olvas(int bufferhossz);
void mainmenu();
void scanmainmenu(EventList* eventlist);
void searchmenu(EventList* eventlist);
void savemenu(EventList* eventlist);
int scansavemenu(EventList* eventlist);
void exitmenu(EventList* eventlist);
int scanexitmenu(EventList* eventlist);
int printmenu(MenuPont* menupontok);

#endif // MENU_H_INCLUDED
