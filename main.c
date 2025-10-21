#include <stdio.h>
#include <stdbool.h>
#include "safeinput.h"

typedef struct {
    int jersey;
    char name[20];
}Player;

void printMenu(){
    printf("1. Skapa ny\n");
    printf("2. Lista alla\n");
    printf("3. Exit\n");
}

// input, print
// API - färdiga funktioner - 
// avr_gcc Embedded - färdiga funktioner 

void createNew(Player *newPlayer){
    // Felhantering - loopa till alla är "ok"
    printf("Skapa ny\n************************\n");
    printf("Name:");
    scanf(" %s", newPlayer->name);
    
    // bool successfulInput = GetInputInt("Jersey:",&newPlayer->jersey);
    printf("Jersey:");
    scanf(" %d",&newPlayer->jersey); // om error = ingen clear
}


int main(){
    while(true){
        printMenu();
        int selection;
        printf("Ange val:");
        scanf(" %d",&selection);
        switch(selection){
            case 1:
                Player player;
                createNew(&player);
                printf("Ny spelare som heter:%s\n", player.name);
                //Put player into a "list"  (dvs array!) (konsektivt minne)
                break;
            case 2:
                printf("Lista alla\n");
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}


