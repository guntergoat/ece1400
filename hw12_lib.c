#include "hw12_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person *findHead(struct Person *n) {
	while(n->prev!=NULL) {
		n=n->prev;
	}
	return n;
}

struct Person *findTail(struct Person *n) {
	while(n->next!=NULL) {
		n=n->next;
	}
	return n;
}

struct Person *findByName(struct Person *n, const char *name) {
	n=findHead(n);
	while(strcmp(n->Name, name)!=0) {
		n=n->next;
		if(n==NULL) {
			return NULL;
		
		}
	}
	return n;
}
struct Person *addToTail(struct Person *n, const char *name, const char *Father, const char *Mother) {
	n=findTail(n);
	struct Person *newNode=malloc(sizeof(struct Person));
	strncpy(newNode->Name, name, sizeof(newNode->Name));
    strncpy(newNode->Mother, Mother, sizeof(newNode->Mother));
    strncpy(newNode->Father, Father, sizeof(newNode->Father));
	newNode->prev=n;
	newNode->next=NULL;
	n->next=newNode;
    return newNode;
}

struct Person *findNode(struct Person *n, const char *name) {
    n=findHead(n);
    while(n->next != NULL) {
        n=n->next;
        if(strcmp(n->Name, name)==0) {
            return n;
        }
    }
    return NULL;
}
	
const char *GetFather (struct Person *n, const char *name){
    n=findNode(n,name);
    if (n==NULL) {
        return NULL;
    }
    return n->Father;
}

const char *GetMother (struct Person *n, const char *name){
    n=findNode(n,name);
    if (n==NULL) {
        printf("%s is not in the list\n",name);
        return 0;
    }
    return n->Mother;
}


bool printPerson(struct Person *n) {
    printf("name=%s\tFather=%s\tMother=%s\t",n->Name,n->Father,n->Mother);
    return true;
}

bool load (struct Person *n, const char *filename) {
    FILE *in_file = fopen(filename, "r");
    if (in_file == NULL) {
        printf("No file found");
        return false;
    }
    char name[50];
    char Mother[50];
    char Father[50];
    while (fscanf(in_file, "%s%s%s", name, Father, Mother)== 3) {
        addToTail(n,name,Father,Mother);
    }
    fclose(in_file);
    return true;
}

int numInList(struct Person *n) {
	n=findHead(n);
	int num=0;
		while(n->next!=NULL) {
			num++;
			n=n->next;
	}
	return num;
}
void printList(struct Person *n) {
	n=findHead(n);
	while (n->next !=NULL) {
	    n=n->next;
        printf("%s\t%s\t%s\n", n->Name, n->Father, n->Mother);

	}
}


void findAnc(struct Person *n, const char *name, int gen) {
    n=findByName(n,name);
    char bad[50] = "NULL";
      if (strcmp(n->Father,bad)==0) {
         
            return;    
      }else{
        if (gen>2) {
            printf("great ");
        }

        if (gen>1) {
        printf("great ");
        }
        if (gen>=1) {
            printf("grand");
        }
        printf("father ");
        printf("%s\n",n->Father);
        findAnc(n,n->Father,gen+1);
        if (gen>2) {
             printf("great ");
        }
        if (gen>1) {
            printf("great ");
        }

        if (gen>=1) {
            printf("grand");
        }
        printf("mother ");
        printf("%s\n",n->Mother);
        findAnc(n,n->Mother,gen+1);

    }
    return;
}


void findDec(struct Person *n, const char *name, int gen) {
    n=findHead(n);
    while(n->next != NULL) {
        n=n->next;
        if(strcmp(n->Father, name)==0) {
            if (gen>2) {
                printf("great ");
            }
            if (gen>1) {
                    printf("great ");
             }

             if (gen>=1) {
                printf("grand");
             }
            printf("child ");

            printf("%s\n",n->Name);

            findDec(n,n->Name, gen + 1);
        }
        if(strcmp(n->Mother, name)==0) {
            if (gen>2) {
                printf("great ");
            }
            if (gen>1) {
                printf("great ");
            }

             if (gen>=1) {
                printf("grand");
             }
            printf("child ");

            printf("%s\n",n->Name);
            findDec(n,n->Name, gen + 1);
        }

    }
    return;
}




