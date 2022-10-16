#include<stdio.h>
#include<stdlib.h>

void insertNodeAtFront(char a);
void insertNodeAtBack(char b);
void printList();

typedef struct _NODE{
    char data;
    struct _NODE *link;
} NODE;

NODE *head=NULL;

int main(){
    insertNodeAtFront('p');
    insertNodeAtFront('p');
    insertNodeAtFront('a');
    insertNodeAtBack('l');
    insertNodeAtBack('e');

    printList();

    return 0;
}

void insertNodeAtFront(char a){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = a;

    new->link = head;
    head = new;
}

void insertNodeAtBack(char b){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = b;
    new->link = NULL;
    NODE *ptr = head;

    if(!head){
        head = new;
    }
    else{
        while(ptr->link)
            ptr = ptr->link;

        ptr->link = new;
    }

    return;
}

void printList(){
    while(head){
        printf("%c", head->data);
        head = head->link;
    }

    printf("\n");
}
