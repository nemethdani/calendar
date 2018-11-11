#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct Event{
    int year,month,day;
    int starthour, startmin, endhour, endmin;
    char* name;
    char* location;
    char* comment;
    struct Event* next;
    struct Event* prev;
}Event;

typedef struct EventList{
    Event* first;
    Event* last;
}EventList;

typedef struct FoundEvent{
    Event* foundevent;
    struct FoundEvent* prevfound;
    struct FoundEvent* nextfound;
}FoundEvent;

typedef struct FindList{
    FoundEvent* first;
    FoundEvent* last;
}FindList;

typedef struct SearchConditions{
    char* name;
    int week,month,day;
}SearchConditions;

typedef void (*MenuFv)(void);

typedef struct {
   char const *nev;
   MenuFv pfv;
} MenuPont;

#endif // STRUCTURES_H_INCLUDED
