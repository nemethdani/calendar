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

    mainmenu();

    printf("Hello world!\n");
    return 0;
}
