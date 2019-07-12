#include "header.h"
#include <stdio.h>

extern Room rooms[4][10];

void run()
{
    login();
    initial_rooms();
    welcome();
}

void main(){
    FILE *config;
    if((config = fopen("config.dat","rb"))==NULL)
    {
        hotel();
    }
    fclose(config);
    run();
}
