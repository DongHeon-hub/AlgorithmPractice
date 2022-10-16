#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node *nptr;
typedef struct node{
    int data;
    struct node *link;
} NODE;

void insert(nptr *, int);
void delete(nptr *);
void printAll(nptr);

int main(){
    nptr head = NULL;
    int a[10] = {3, 9, 8, 2, 5, 10, 7, 1, 4, 6};

    for (int i = 0; i < 10; i++)
        insert(&head, a[i]);

    printAll(head);

    for (int i = 0; i < 10; i++)
        delete (&head);

    return 0;
}

void insert(nptr*head, int data){
    nptr temp = *head;
    nptr new = (nptr)malloc(sizeof(NODE));
    new->data = data;

    if(*head == NULL){
        new->link = NULL;
        *head = new;
    }

    else{
        while(temp->link)
            temp = temp->link;

        new->link = NULL;
        temp->link = new;
    }

    return;
}

void delete(nptr*head){
    nptr temp = *head;
    
    if(*head ==NULL){
        printAll(*head);
        return;
    }
       

    *head = (*head)->link;
    free(temp);
    printAll(*head);
    return;
}

void printAll(nptr head){
    nptr temp = head;

    if(head==NULL){
        printf("Empty\n");
        return;
    }
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");

    return;
}
