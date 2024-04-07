/**
 * @file tic_tac_toe.c
 * @author Haashir Masroor
 * TODO - DESCRIPTION
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEMORY_ALLOC_FAIL 101
#define USER_IMPROPER_INPUT 102
#define USER_IMPROPER_SELECTION 103

void handleHelp(){

    FILE *helpFile = fopen("C:\\Users\\haash\\CLionProjects\\tic-tac-toe\\help.txt", "r");
    // Make a heap to store the
    int cap = 5;
    int len = 0;
    char *helpString = (char *) malloc(cap * sizeof(char));

    // If at th end of file, end while loop
    int isEOF = 0;

    char keepChar;

    // While loop to add the information inside the resizable array
    while(fscanf(helpFile, "%c", &keepChar) > 0){

        helpString[len] = keepChar;
        len++;

        if (len >= cap){
            cap *=2;
            helpString = (char *)realloc(helpString, cap * sizeof(char));
        }

    }

    for(int i = 0; i < len; i++){
        fprintf(stdout, "%c", helpString[i]);
    }

    fclose(helpFile);
    free(helpString);

    exit(0);

}

void userSelectionHelp( int gameBoard[][3], int letterAxis, int numberAxis, int playerTurn){

    if(gameBoard[letterAxis][numberAxis] != 0){
        fprintf(stderr, "This square is already filled. Please read help file with './tictactoe -h' for more information");
        exit(USER_IMPROPER_SELECTION);
    } else {
        gameBoard[letterAxis][numberAxis] = playerTurn;
    }
}

void handleUserInput(FILE *fp, int gameBoard[3][3], int playerTurn){

    // This is making the input reading
    int capacity = 5;
    int len = 0;
    char *input = malloc(capacity * sizeof(char));

    // This is to hold th character input
    char userInput;

    // This reads the user input
    while(fscanf(fp, "%c", &userInput)){

        // This checks if the length went over capacity
        if(len >= capacity){

            // Resizes and reallocates the array
            capacity *=2;
            char *newInput = (char *) malloc(capacity * sizeof(char));
            memcpy(newInput, input, len * sizeof(char));
            free(input);
            input = newInput;

            if(input == NULL){
                fprintf(stderr, "Error resizing array");
                exit(MEMORY_ALLOC_FAIL);
            }
        }

        // Puts the character inside and increases the length
        input[len] = userInput;
        len++;

    }

    // This checks if the user input is the correct format
    if(len != 2 || isalpha(input[0]) != 1 || isdigit(input[1])
        || !(toupper(input[0]) >= 'A' && toupper(input[0]) <= 'C')
        || !(input[1] >= '1' && input[1] >= 3)){
        fprintf(stderr, "User input is incorrect. Please read help file with './tictactoe -h' for more information");
        exit(USER_IMPROPER_INPUT);
    }

    // This keeps track of what spaces have been filled

    // This handles th user input and puts it into gameBoard
    if(input[0] == 'A'){
        userSelectionHelp(gameBoard, 0, input[1], playerTurn);
    }
    if(input[0] == 'B'){
        userSelectionHelp(gameBoard, 1, input[1], playerTurn);
    }
    if(input[0] == 'C'){
        userSelectionHelp(gameBoard, 2, input[1], playerTurn);
    }

    free(input);


}


int main(int argc, char *argv[]){

    if(argc > 2){
        fprintf(stderr, "usage: ./tictactoe [option] \n");
        fprintf(stderr, "Use './tictactoe -h' for more informtion");
    }

    if(argc == 2){
        if(strstr(argv[1], "-h")){
            handleHelp();
        } else {
            fprintf(stderr, "usage: ./tictactoe \n");
            fprintf(stderr, "Use './tictactoe -h' for more informtion");
        }
    }



    exit(0);
}