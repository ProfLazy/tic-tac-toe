/**
 * @file tic_tac_toe.c
 * @author Haashir Masroor
 * TODO - DESCRIPTION
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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