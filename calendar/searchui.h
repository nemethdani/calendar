#ifndef SEARCHUI_H_INCLUDED
#define SEARCHUI_H_INCLUDED

char scaninput();
int searchbyname(EventList* eventlist);
int searchbyweek(EventList* eventlist);
int searchbymonth(EventList* eventlist);
int searchbyday(EventList* eventlist);
int printfindlist(FindList* findlist, SearchConditions condition,EventList* eventlist);
int scanfindlist(int i, FindList* findlist,SearchConditions condition,EventList* eventlist);
void printevent_short(Event* event);

#endif // SEARCHUI_H_INCLUDED
