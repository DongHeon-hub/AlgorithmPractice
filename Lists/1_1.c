#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* nptr;
typedef struct node{
    int data;
    nptr link;
} NODE;

void Insert(nptr*, int);
void printAll(nptr);

int main(){
    nptr head=NULL;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i=0; i<10; i++) Insert(&head, a[i]);

    printAll(head);
    return 0;
}

void Insert(nptr*head, int data){
    nptr new = (nptr)malloc(sizeof(NODE));
    new->data = data;

    if(*head == NULL){
        new->link = NULL;
        *head = new;
        return;
    }

    new->link = *head;
    *head = new;

}

void printAll(nptr head){
    while(head){
        printf("%d ", head->data);
        head=head->link;
    }

    printf("\n");
    return;
}