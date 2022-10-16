#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef NODE *nptr;

void Insert(nptr *head, int data, int index);
void printAll(nptr head);
int size = 0;

int main()
{
    nptr head = NULL;
    int A[10] = {3, 9, 8, 2, 5, 10, 7, 1, 4, 6};

    Insert(&head, A[0], 0);
    Insert(&head, A[1], 0);
    Insert(&head, A[2], 1);
    Insert(&head, A[3], 2);
    Insert(&head, A[4], 0);
    Insert(&head, A[5], 1);
    Insert(&head, A[6], 10);
    Insert(&head, A[7], 4);
    Insert(&head, A[8], -1);
    Insert(&head, A[9], 3);

    return 0;
}

void Insert(nptr *head, int data, int index)
{
    nptr new = (nptr)malloc(sizeof(NODE));
    nptr ptr = *head;
    new->data = data;

    // Insert element in empty list or front of list
    if (*head == NULL || index == 0)
    {
        new->link = *head;
        *head = new;
        size++;
        printAll(*head);
        return;
    }

    // Insert element at back
    if (index > size || index == -1)
    {
        new->link = NULL;
        while (ptr->link)
            ptr = ptr->link;

        ptr->link = new;
        size++;
        printAll(*head);
        return;
    }

    // Insert element at right place

    for (int i = 0; i < index - 1; i++)
        ptr = ptr->link;

    new->link = ptr->link;
    ptr->link = new;
    size++;

    printAll(*head);
}

void printAll(nptr head)
{
    nptr temp = head;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}