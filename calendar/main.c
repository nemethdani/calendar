#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "file.h"
#include "list.h"
#include "menu.h"
#include <stdlib.h>



int main(){

    EventList eventlist=initeventlist();
    //load data

    MenuPont menupontok[] = {
       { "Uj esemeny", newevent },
       { "Kereses", searchmenu },
       { "Mentes", savemenu },
       { "Kilepes", exitmenu },
       { NULL, NULL }   /* végjel */
    };

    int meret=printmenu(menupontok);
    callmenu(meret,menupontok);

    printf("Hello world!\n");
    return 0;
}
