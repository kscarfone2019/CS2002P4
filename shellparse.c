#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//use strtok?
//

#define BUFF_SIZE 1024

//void split(char *args);
//void split(char *name, char *args);
void split(char *name, char *args);
int main() {
    char *command;
    size_t bufsize = 1024;
    size_t characters;
    command = (char *)malloc(bufsize * sizeof(char));

    characters = getline(&command, &bufsize, stdin);
    //printf("characters: %zu\n", characters);
    //printf("command: %s\n", command);
    free(command);


    //command string holds the raw input form file
    //split command string into two new strings ./prog1 and args strings
    //fclose(file);


    char *token;
    char *token2;
    char *search = " ";
    char progName[16];

    int commandLength = strlen(command);
    //printf("command length: %d\n", commandLength);
    //loop to remove \n from end of line because fgets auto adding

    for (int y = 0; y < commandLength; y++) {
        if(command[y] == '\n') {
            command[y] = '\0';
        }
    }


    //find index of first space to split program name from args

    char find = ' ';
    char *space = strchr(command, find);
    int indexOfSplit = space - command;
    //printf("index of space: %s\n", space);
    char progArgs[16];
    if(space != NULL) {
        for (int i = 0; i < indexOfSplit; i++) {
            progName[i] = command[i];
        }
        int count = 0;
        for (int x = indexOfSplit+1; x < commandLength; x++) {
            progArgs[count] = command[x];
            count++;
        }
        //printf("here\n");
        //get number of arguments to pass to split function
        int numOfArgs = 0;
        for (int c = 0; c < count-1; c++) {
            if(progArgs[c] != ' ' && progArgs[c] != '\"') {
                numOfArgs++;
            }

        }
    }
    else {
        //command string doesnt really need parsing
        int len = strlen(command);
        for (int i = 0; i < len; i++) {
            progName[i] = command[i];
        }
    }



    split(progName, progArgs);
    //progName and progArgs are command split in two now
    return 0;
}

void split(char *name, char *args) {
    //split when you find a space - exception if you see "" then wait until you see closing ""
    //printf("arguments before any manipulation: %s\n", args);
    char *test;
    const char *arr[10];


    //printf("numArgs %d\n", numArgs);
    test = strtok(args, " ");
    int count = 0;
    while(test != NULL) {

        arr[count] = test;
        test = strtok(NULL, " ");
        count++;
    }

    //figure out of number of args from counting array with args in them
    int numArgs = 0;
    for (int u = 0; u < count; u++) {
        if(arr[u]!=NULL) {
            numArgs++;
        }
    }
    if(numArgs == 1) {
        printf("Run program \"%s\" with argument ", name);
    }
    else if(numArgs > 1) {
        printf("Run program \"%s\" with arguments ", name);
    }
    else {
        printf("Run program \"%s\"\n", name);
    }

    for (int g = 0; g < numArgs; g++) {
        if((g+1) == numArgs) { //last argument so no and after needed
            printf("\"%s\"\n", arr[g]);
        }
        else {
            printf("\"%s\" and ", arr[g]);
        }
    }
}

//system function -
