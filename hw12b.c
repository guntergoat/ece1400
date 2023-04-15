#include "hw12_lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char*argv[]) {
    if(argc!=3) {
        printf("incorrect usage\n");
        return 1;
    }
    const char *filein=argv[1];
    const char *name = argv [2];
    struct Person head;
    head.prev=NULL;
    head.next=NULL;


    FILE *in_file =fopen(filein, "r");
    if (in_file ==NULL) {
        printf("No input file found");
        return 1;
    }
    char kid[80];
    char father[80];
    char mother[80];
    while (fscanf(in_file, "%s%s%s",kid, father, mother) ==3) {
          //printf("%s %s %s\n", kid, father, mother);
          addToTail (&head,kid, father, mother);
    }
    int gen=0;
    printf("ancestors of %s:\n",name);
    findAnc(&head,name, gen);
    printf("descendants of %s:\n",name);
    findDec(&head,name, gen);
    
}
    
