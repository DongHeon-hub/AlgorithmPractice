#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} NODE;

typedef NODE *nptr;

void insert(nptr *head, int data);
void Sort(nptr *head);
void printAll(nptr head);

int main(){
    int a[10] = {3, 9, 8, 2, 5, 10, 7, 1, 4, 6};
    nptr head = NULL;

    for (int i = 0; i < 10; i++)
        insert(&head, a[i]);

    Sort(&head);
    printAll(head);

    return 0;
}

void insert(nptr*head, int data){
    nptr new = (nptr)malloc(sizeof(NODE));
    nptr ptr = *head;
    new->data = data;
    new->link = NULL;

    if(*head==NULL){
        *head = new;
    }

    else{
        while(ptr->link)
            ptr = ptr->link;

        ptr->link = new;
        new->link = NULL;
    }

}

void Sort(nptr*head){
    nptr ptr = *head;
    nptr pMin = *head;
    nptr pWalk;
    int temp;
    //selection sort
    while(ptr->link){
        pMin = ptr;

        for (pWalk = ptr->link; pWalk != NULL; pWalk=pWalk->link){
            if(pMin->data > pWalk->data)
                pMin = pWalk;
        }

        temp = pMin->data;
        pMin->data = ptr->data;
        ptr->data = temp;

        ptr = ptr->link;
    }


}

void printAll(nptr head){
    nptr ptr = head;

    while(ptr){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    return;
}