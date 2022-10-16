#include<stdio.h>
#include<stdlib.h>

int*get_new_array(int size);
void get_new_array_call_by_value(int*a, int size);
void get_new_array_call_by_reference(int**a, int size);
void print_state(int*a);

int main(){
    int *a=NULL;
    print_state(a);

    get_new_array_call_by_value(a, 10);
    print_state(a);
    free(a);

    get_new_array_call_by_reference(&a, 10);
    print_state(a);
    free(a);

    a = get_new_array(10);
    print_state(a);
    free(a);
}

int *get_new_array(int size){
    int*array = (int*)malloc(sizeof(int)*size);
    free(array);
    return array;
}

void get_new_array_call_by_value(int*a, int size){
    a = (int*)malloc(sizeof(int)*size);
}

void get_new_array_call_by_reference(int**a, int size){
    *a = (int*)malloc(sizeof(int)*size);
    return;
}

void print_state(int*a){
    if(a) printf("allocated\n");
    else printf("not allocated\n");
}