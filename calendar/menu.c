#include "menu.h"
#include "structures.h"
#include <stdlib.h>
#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "search.h"
#include "eventrecord.h"
#include "debugmalloc.h"

char scaninput(){
    int input;
    scanf("%d",&input);
    getchar();

    return input;
}

void filesave(EventList* eventlist){
    if(calendarsave(eventlist)) printf("saved\n");
    else printf("nem sikerult menteni\n");

    //mainmenu(eventlist);
}
int newevent(EventList* eventlist){
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
    printf("Mi az esemeny befejezo ideje? (oo:pp)\n");
    int bora,bperc;
    while(scanf("%d:%d",&bora,&bperc)!=2 || bora>24 || bora<0 || bperc>60 || bperc<0){
        getchar();
        printf("probald ujra\n");
    };
    printf("Mi az esemeny neve? (max 127 karakter)\n");
    getchar();
    char* nev=hosszu_sort_olvas(128);
    printf("Mi az esemeny helye? (max 127 karakter)\n");
    char* hely=hosszu_sort_olvas(128);
    printf("Van megjegyzesed? (max 255 karakter)\n");
    char* megjegyzes=hosszu_sort_olvas(256);





    Event* event=createevent(ev,honap,nap,ora,perc,bora,bperc,nev,hely,megjegyzes);
    if(event==NULL) printf("null event\n");
    //printf("%d",(event->year));
    //printevent_short(event);
    insertevent(eventlist,event);
    SearchConditions cond;
    cond.name=NULL; cond.month=0; cond.week=0;
    int choice=printeventrecord(event,cond,eventlist);
    return choice;
}


char *hosszu_sort_olvas(int bufferhossz) {
    //int db = 0;
    char *sor = (char*) malloc(sizeof(char) * (bufferhossz+1));

    for (int i=0;i<bufferhossz+1;i++)
        sor[i]='\0';
    bool first=true;
    while(first || strlen(sor)>=bufferhossz && sor[bufferhossz-1]!='\n'){
         first=false;
         fgets(sor,bufferhossz+1,stdin);
         if(strlen(sor)>=bufferhossz && sor[bufferhossz-1]!='\n'){
            printf("tul hosszu: max %d karaktert irjal\n",bufferhossz-1);
            while ((getchar()) != '\n');
        }
    }
    //sor[bufferhossz+1]='\0';
    int ujhossz;
    if(strlen(sor)==10 && sor[bufferhossz-1]!='\n') ujhossz=bufferhossz;
    else ujhossz=strlen(sor);
    char *uj=(char*) malloc(sizeof(char)*ujhossz);
    int i;
    for (i=0;sor[i]!='\n';i++)
        uj[i]=sor[i];
    uj[i]='\0';
    free(sor);


    return uj;
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
            while(newevent(eventlist)==1);
            //scaneventrecord();
            break;
        case 2:
            searchmenu(eventlist);
            //scansearchmenu();
            break;
        case 3:
            savemenu(eventlist);
            //scansavemenu();
            break;
        case 4:
            exitmenu(eventlist);
           // scanexitmenu();
            break;
        case 5: break;
        default:
            printf("nincs ilyen menupont\n\n");
            //scanmainmenu(eventlist);
            //getchar();
            break;




    }
}

void searchmenu(EventList* eventlist){
    int choice=0;
    while(choice!=5){
        if(!(choice>=1 && choice<=4)){
            printf("\nHogyan szeretnel keresni?\n");
            printf("(1) Esemeny neve szerint\n");
            printf("(2) Nap szerint\n");
            printf("(3) Het szerint\n");
            printf("(4) Honap szerint\n\n");
            printf("(5) Vissza a fomenube\n");
            choice=scaninput();
        }
        switch(choice){
        case 1:

            choice=searchbyname(eventlist);
            break;
        case 2:

            //choice=searchbyday(eventlist);
            choice=searchactual(eventlist,byday);
            while(choice==2) choice=searchbyday(eventlist);
            break;
        case 3:

            //choice=searchbyweek(eventlist);
            choice=searchactual(eventlist,byweek);
            while(choice==3) choice=searchbyweek(eventlist);
            break;
        case 4:

            //choice=searchbymonth(eventlist);
            choice=searchactual(eventlist,bymonth);
            while(choice==4) choice=searchbymonth(eventlist);
            break;
        case 5:

            //mainmenu(eventlist);
            break;
        default:
            printf("nincs ilyen menupont, probald ujra!\n");
            break;
        }
    }
}
void savemenu(EventList* eventlist){
//    MenuPont menupontok[] = {
//       { "Mentes", filesave },
//       { "Megse", mainmenu },
//       { NULL, NULL }   /* végjel */
//    };
    int choice=1;
    while(choice){
        printf("(1) Mentes\n(2) Megse\n");
        //int meret=printmenu(menupontok);
        //callmenu(meret,menupontok);
        choice=scansavemenu(eventlist);
    }

}

int scansavemenu(EventList* eventlist){
    int valasztas=0;
    scanf("%d",&valasztas);
    getchar;
    switch(valasztas){
        case 1:
            filesave(eventlist);

            return 0;
            //mainmenu(eventlist);
            //scanmainmenu(eventlist);
            break;
        case 2:
            //mainmenu(eventlist);
            //scanmainmenu(eventlist);
            return 0;
            break;
        default:
            printf("nincs ilyen menupont\n");
            //scansavemenu(eventlist);
            break;
    }
}

void exitmenu(EventList* eventlist){
    int choice=1;
    while(choice){

    printf("(1) Kilepes mentessel\n(2) Kilepes mentes nelkul\n(3) Vissza\n");
    choice=scanexitmenu(eventlist);
}



}

int scanexitmenu(EventList* eventlist){
    int command;
    while(scanf("%d",&command)!=1 || command<1 || command>3){
        getchar();
        printf("nincs ilyen parancs\n");
    }
    switch(command){
        case 1:
            filesave(eventlist);
            freeEventList(eventlist);
            exit(0);
            break;
        case 2:
            freeEventList(eventlist);
            exit(0);

            break;
        case 3:
            return 0;
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

