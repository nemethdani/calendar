#include "menu.h"
#include "structures.h"
#include <stdlib.h>
#include "file.h"


void filesave(EventList* eventlist){
    printf("saved\n");
    //mainmenu(eventlist);
}
void newevent(EventList* eventlist){
    printf("Mi az esemeny datuma? (eeee.hh.nn)\n");
    int ev, honap, nap;
    while(scanf("%d.%d.%d",&ev,&honap,&nap)!=3 || honap>12 || honap<1 || nap>31 || nap<1){
        getchar();
        printf("probald ujra\n");
    };
    printf("Mi az esemeny kezdo ideje? (oo:pp)\n");
    int ora,perc;
    while(scanf("%d:%d",&ora,&perc)!=2 || ora>24 || ora<0 || perc>60 || perc<0){
        getchar();
        printf("probald ujra\n");
    };
    printf("Mi az esemeny neve? (max 127 karakter)\n");




    insertevent(eventlist);
}


char *hosszu_sort_olvas(int hossz) {
    int db = 0;
    char *sor = (char*) malloc(sizeof(char) * 1);
    sor[0] = '\0';
    char ujkar;
    while (scanf("%c", &ujkar) == 1 && ujkar != '\n') {
        /* itt a tömb nyújtása */
        char *ujtomb = (char*) malloc(sizeof(char) * (db+1+1));
        for (int i = 0; i < db; ++i)
            ujtomb[i] = sor[i];
        free(sor);
        sor = ujtomb;
        ujtomb[db] = ujkar;
        ujtomb[db+1] = '\0';
        ++db;
    }

    return sor;
}

void mainmenu(){
    MenuPont menupontok[] = {
       { "Uj esemeny", newevent },
       { "Kereses", searchmenu },
       { "Mentes", savemenu },
       { "Kilepes", exitmenu },
       { NULL, NULL }   /* végjel */
    };

    int meret=printmenu(menupontok);
    //callmenu(meret,menupontok);
}

void scanmainmenu(EventList* eventlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar();
    switch(valasztas){
        case 1:
            newevent(eventlist);
            //scaneventrecord();
            break;
        case 2:
            searchmenu(eventlist);
            //scansearchmenu();
            break;
        case 3:
            savemenu(eventlist);
            scansavemenu();
            break;
        case 4:
            exitmenu(eventlist);
            scanexitmenu();
            break;
        default:
            printf("nincs ilyen menupont");
            scanmainmenu(eventlist);
            getchar();
            break;




    }
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
    //callmenu(meret,menupontok);

}

void scansavemenu(EventList* eventlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar;
    switch(valasztas){
        case 1:
            filesave(eventlist);
            mainmenu(eventlist);
            scanmainmenu(eventlist);
            break;
        case 2:
            mainmenu(eventlist);
            scanmainmenu(eventlist);
        default:
            printf("nincs ilyen menupont");
            scansavemenu(eventlist);
            break;
    }
}

void exitmenu(EventList* eventlist){

    printf("(1) Kilepes mentessel\n(2) Kilepes mentes nelkul\n(3) Vissza\n");
//    int command;
//    while(scanf("%d",&command)!=1 || command<1 || command>3)
//        printf("nincs ilyen parancs\n");
//    switch(command){
//    case 1:{
//        //mentofuggveny
//        exit(0);}
//        break;
//    case 2:
//        exit(0);
//        break;
//    case 3:
//        mainmenu(eventlist);
//        break;



}

void scanexitmenu(EventList* eventlist){
    int command;
    while(scanf("%d",&command)!=1 || command<1 || command>3){
        getchar();
        printf("nincs ilyen parancs\n");
    }
    switch(command){
        case 1:
            filesave(eventlist);
            exit(0);
            break;
        case 2:
            exit(0);
            break;
        case 3:
            mainmenu(eventlist);
            scanmainmenu(eventlist);
            break;
    }
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
