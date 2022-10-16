#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _Node{
    int st_id;
    char *st_name;
    struct _Node *link;
} Node;

Node *head = NULL;
void create_Node(int id, char *name);



int main(){
    int numberOfstudent;
    char line[100];
    char name[30];
    char c;
    int id;
    FILE *fp;
    Node *ptr;

    if((fp = fopen("input.txt", "r")) == NULL){
        printf("Error!\n");
        exit(1);
    }

    fscanf(fp, "%d", &numberOfstudent);
    c=fgetc(fp);
    for (int i = 0; i < numberOfstudent; i++){
        fgets(line, 100, fp);
        //printf("%s", line);
        sscanf(line, "%d %[^\n]", &id, name);
        create_Node(id, name);
    }

    ptr = head;

    while(ptr){
        printf("%d / %s\n",  ptr->st_id, ptr->st_name);
        ptr = ptr->link;
    }

    fclose(fp);
    return 0;
}

void create_Node(int id, char*name){
    Node *new = (Node *)malloc(sizeof(Node));
    new->st_id = id;
    new->st_name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new->st_name, name);

    if(head==NULL){
        new->link = NULL;
        head = new;
    }

    else{
        Node *temp = head;

        while(temp->link)
            temp = temp->link;

        new->link = NULL;
        temp->link = new;
    }

}

