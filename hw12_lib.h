#ifndef HW12_LIB_H
#define HW12_LIB_H
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

struct Person {
        char Father[80];
        char Mother[80];
        char Name[80];
        struct Person *next;
        struct Person *prev;
};
struct Person *findHead(struct Person *n);
struct Person *findTail(struct Person *n);
bool load (struct Person *n, const char *filename);
struct Person *findByName(struct Person *n, const char *name);
struct Person *addToTail(struct Person *n, const char *name, const char *Father, const char *Mother);
const char *GetFather (struct Person *n, const char *name);
const char *GetMother (struct Person *n, const char *Name);
void printList(struct Person *n);
void findAnc(struct Person *n, const char *name, int gen);
struct Person *findKid(struct Person *n, const char *name);
void findDec(struct Person *n, const char *name, int gen); 

#endif
