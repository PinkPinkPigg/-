#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Room rooms[4][10];

void hotel(){
    Room r[4][10];
    int i,j;
    char blank[5] = "";
    FILE *fr;
    for(i=0;i<4;i++)
        for(j=0;j<10;j++)
    {
            r[i][j].num = (i+1)*100 + j+1;
            r[i][j].level = i+1;
            r[i][j].price1 = 100 + 35*(i+1);
            r[i][j].price2 = 40 + 15*(i+1);
            r[i][j].condition = 0;
            strcpy(r[i][j].name,blank);
            strcpy(r[i][j].sex,blank);
            strcpy(r[i][j].ID,blank);
            r[i][j].age=0;
            r[i][j].WoU = 1;
            r[i][j].time = 0;
            r[i][j].addcount1=0;
            r[i][j].addcount2=0;
            r[i][j].addcount3=0;

    }
    fr = fopen("config.dat","wb");
    for(i=0;i<4;i++)
    {
        for(j=0;j<10;j++)
        {
            fwrite(&r[i][j],sizeof(Room),1,fr);
        }

    }
    fclose(fr);
}
