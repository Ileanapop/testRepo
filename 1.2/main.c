#include<string.h>
#include "sll.h"

#define FILE_PATH_OUT "../output.dat"
#define FILE_PATH_IN "../input.dat"

int identifyAction(char s[]);


int main() {

    char string[25];
    int key,ok;

    fin=fopen(FILE_PATH_IN,"r");
    if(fin==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }
    fout=fopen(FILE_PATH_OUT,"a");
    if(fout==NULL)
    {
        perror("File could not be opened");
        exit(EXIT_FAILURE);
    }

    enum Action {
        On_road, Enter_garage, Exit_garage, Show_trucks
    };

    int action=0;
    initialize();

    while(!feof(fin))
    {
        fscanf(fin,"%s",string);
        action=identifyAction(string);
        switch(action){
            case On_road:{
                fscanf(fin,"%d",&key);
                addCar(key);
                break;
            }
            case Enter_garage:{
                fscanf(fin,"%d",&key);
                deleteCar(key,&ok);
                if(ok==1)
                    enterGarage(key);
                break;
            }
            case Exit_garage:{
                fscanf(fin,"%d",&key);
                exitGarage(key,&ok);
                if(ok==1)
                    addCarAtTop(key);
                break;
            }
            case Show_trucks:{
                char  str[30];
                fscanf(fin,"%s",str);
                if(strcmp(str,"road")==0)
                    showTrucks(firstR,lastR);
                else
                if(strcmp(str,"garage")==0)
                    showTrucks(firstG,lastG);
                break;
            }

            default: fprintf(fout,"There is no such operation\n");
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

int identifyAction(char s[])
{
    if(strcmp(s,"On_road")==0)
        return 0;
    if(strcmp(s,"Enter_garage")==0)
        return 1;
    if(strcmp(s,"Exit_garage")==0)
        return 2;
    if(strcmp(s,"Show_trucks")==0)
        return 3;
    return -1;
}