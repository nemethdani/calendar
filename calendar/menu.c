#include "menu.h"
#include "structures.h"
#include <stdlib.h>

void newevent(){
    printf("newevent\n");
}
void searchmenu(){
    printf("search\n");
}
void savemenu(){
    printf("save\n");
}
void exitmenu(){
    printf("exit\n");
}

int printmenu(MenuPont* menupontok){
    int i;
    for (i = 1; menupontok[i-1].nev != NULL; ++i)
        printf("(%d) %s\n", i, menupontok[i-1].nev);
    int meret = i;
    return meret;
}

void callmenu(int meret, MenuPont* menupontok){
    int valasztas;
    while(!(scanf("%d",&valasztas)==1 && 0 < valasztas && valasztas < meret)){
        printf("Nincs ilyen menüpont\n");
    }
    menupontok[valasztas-1].pfv();
}
