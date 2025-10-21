#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "safeinput.h"

// typedef enum{
//     WITHDRAWAL_OK,
//     WITHDRAWAL_TOO_LARGE_AMOUNT,
//     WITHDRAWAL_NOT_ENOUGH_MONEY
// } WITHDRAWAL_STATUS;

// WITHDRAWAL_STATUS withdrawal(int amount){
//     if(amount > 3000){
//         return WITHDRAWAL_TOO_LARGE_AMOUNT;
//     }
//     if(amount > saldo){
//         return WITHDRAWAL_NOT_ENOUGH_MONEY;
//     }
//     return WITHDRAWAL_OK;
// }

typedef struct {
    int jersey;
    char name[20];
}Player;



void printMenu(){
    // int error = withdrawal(5000);
    // if(error == WITHDRAWAL_TOO_LARGE_AMOUNT){
    //     printf("För stort belopp per gånmg");
    // }else if(error == WITHDRAWAL_NOT_ENOUGH_MONEY){

    // }
    printf("1. Skapa ny\n");
    printf("2. Lista alla\n");
    printf("3. Exit\n");
}


void createNew(Player *newPlayer){
    // Felhantering - loopa till alla är "ok"
    printf("Skapa ny\n************************\n");
    // Loop

    GetInput("Name:", newPlayer->name,20);
    //if(result == INPUT_RESULT_OK)

    //INPUT_RESULT result = GetInput("Name:", newPlayer->name,20);
    //if(result == INPUT_RESULT_OK)
    // printf("Name:");
    // scanf(" %s", newPlayer->name); // 1. buffer overflow, 2. mellanslag
    
     GetInputInt("Ange jersey:",&newPlayer->jersey);
//     printf("Jersey:");
//     scanf(" %d",&newPlayer->jersey); // om error = ingen clear
 }


 typedef struct{
    Player *allPlayers;
    int count;
 } PLAYERSLIST;

int main(){
    //int age;
    //Player allPlayers[10]; // 240 bytes
 
    //int bla;
    // TA BORT ALLA SCANF
    // BYT UT MOT GetInput...
    // int num;
    // scanf(" %d", &num);
    // Player player[num];

    PLAYERSLIST playersList;
    playersList.count = 0;
    playersList.allPlayers = NULL;
    while(true){
        printMenu();
        int selection;
        // printf("Ange val:");
        // scanf(" %d",&selection);
        while(true){
            bool ok = GetInputInt("Ange val:", &selection);
            if(ok){
                break;
            }
            printf("Men din dummer skriv in ett tal");
        }

        switch(selection){
            case 1:
                //allPlayers = realloc(allPlayers, (count + 1) * sizeof(Player));
                if(playersList.count == 0){
                    playersList.allPlayers = malloc(sizeof(Player));
                }else{
                    int newSize = (playersList.count + 1) * sizeof(Player);
                    playersList.allPlayers = realloc(playersList.allPlayers,newSize);
                }
                createNew(&playersList.allPlayers[playersList.count]);
                printf("Ny spelare som heter:%s\n", playersList.allPlayers[playersList.count].name);
                playersList.count++;
                //Put player into a "list"  (dvs array!) (konsektivt minne)
                break;
            case 2:
                printf("Lista alla\n");
                for(int i = 0; i < playersList.count;i++){
                    printf("%s\n", playersList.allPlayers[i].name);
                }

                break;
            case 3:
                return 0;
        }
    }
    return 0;
}


