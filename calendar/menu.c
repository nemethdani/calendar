#include "menu.h"
#include "structures.h"
#include <stdlib.h>
#include "file.h"


void filesave(EventList* eventlist){
    printf("saved\n");
    mainmenu(eventlist);
}
void newevent(EventList* eventlist){
    printf("newevent\n");
}

void mainmenu(EventList* eventlist){
    MenuPont menupontok[] = {
       { "Uj esemeny", newevent },
       { "Kereses", searchmenu },
       { "Mentes", savemenu },
       { "Kilepes", exitmenu },
       { NULL, NULL }   /* végjel */
    };

    int meret=printmenu(menupontok);
    callmenu(meret,menupontok);
}

void searchmenu(EventList* eventlist){
    printf("search\n");
}
void savemenu(EventList* eventlist){
    MenuPont menupontok[] = {
       { "Mentes", filesave },
       { "Megse", mainmenu },
       { NULL, NULL }   /* végjel */
    };

    int meret=printmenu(menupontok);
    callmenu(meret,menupontok);

}
void exitmenu(EventList* eventlist){

    printf("(1) Kilepes mentessel\n(2) Kilepes mentes nelkul\n(3) Vissza\n");
    int command;
    while(scanf("%d",&command)!=1 || command<1 || command>3)
        printf("nincs ilyen parancs\n");
    switch(command){
    case 1:{
        //mentofuggveny
        exit(0);}
        break;
    case 2:
        exit(0);
        break;
    case 3:
        mainmenu(eventlist);
        break;

    };

}


int printmenu(MenuPont* menupontok){
    int i;
    for (i = 1; menupontok[i-1].nev != NULL; ++i)
        printf("(%d) %s\n", i, menupontok[i-1].nev);
    int meret = i;
    return meret;
}

void callmenu(int meret, MenuPont* menupontok, EventList* eventlist){
    int valasztas;
    while(!(scanf("%d",&valasztas)==1 && 0 < valasztas && valasztas < meret)){
        printf("Nincs ilyen menüpont\n");
    }
    menupontok[valasztas-1].pfv(eventlist);
}
