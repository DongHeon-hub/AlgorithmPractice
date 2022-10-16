#include<stdio.h>
#include<stdlib.h>

void insertNodeAtFront(char a);
void insertNodeAtBack(char b);
void DeleteNodeAtFront();
void DeleteNodeAtBack();
void printList();

typedef struct _NODE{
    char data;
    struct _NODE *link;
} NODE;

NODE *head=NULL;


int main(){
    insertNodeAtFront('n');
    insertNodeAtFront('e');
    insertNodeAtFront('p');
    insertNodeAtBack('l');
    insertNodeAtFront('o');
    insertNodeAtBack('a');
    insertNodeAtBack('b');
    printList();
    DeleteNodeAtFront();
    DeleteNodeAtBack();
    DeleteNodeAtBack();
    DeleteNodeAtBack();
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

    if(head == NULL){
        new->link = NULL;
        head = new;
    }

    else{
        NODE *ptr = head;
        while(ptr->link)
            ptr = ptr->link;

        new->link = NULL;
        ptr->link = new;
    }
}

void DeleteNodeAtFront(){
    if(head==NULL)
        return;

    NODE *ptr = head;
    head = head->link;
    free(ptr);
}

void DeleteNodeAtBack(){
    if(head==NULL)
        return;

    NODE *ptr = head;
    
    if(head->link == NULL){
        ptr = head;
        head = NULL;
        free(ptr);
        return;
    }

    while(ptr->link->link){
            ptr = ptr->link;
    }

    NODE *temp = ptr->link;
    ptr->link = NULL;
    free(temp);
}

void printList(){
    NODE *ptr = head;
    while(ptr){
        printf("%c", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    

    return;
}

/* 알수 있던 점
NODE*에 free()를 사용하면 NODE*가 가리키고 있는 메모리 영역이 해제되어 그 영역을 자유롭게 사용할 수 있다. 이 때 그 영역에는 임의의 쓰레기 값이 들어간다.
또한 NODE*는 NULL이 되는것이 아니다.
앞으로 문제풀 때 더 나은 코드 / 알게된 점 / 참고 자료 및 추가 자료 적고 링크 달아놓기
*/