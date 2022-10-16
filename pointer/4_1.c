#include<stdio.h>
#include<stdlib.h>

void sort(int*a, int size);
void swap(int*a, int*b);
void double_double(int**a, int *size);

int main(){
    int n;
    int *array;

    scanf("%d", &n);
    array = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++) scanf("%d", &array[i]);

    double_double(&array, &n);
    double_double(&array, &n);
    double_double(&array, &n);

    free(array);
    return 0;
    
}

void sort(int*a, int size){
    int i, j;

    for(i=0; i<size-1; i++){
        for(j=1; j<size-i; j++){
            if(a[j] < a[j-1]) swap(a+j, a+j-1);
        }
    }

    return;

}

void swap(int*a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void double_double(int**a, int *size){
    int i, j=0;

    int*temp = (int*)malloc(sizeof(int)*(*size));

    for(i=0; i<*size; i++) temp[i] = 2*(*a)[i];

    *a = (int*)realloc(*a, sizeof(int)*(2*(*size)));

    for(i=*size; i<2*(*size); i++) (*a)[i] = temp[j++];

    *size = *size*2;
    sort(*a, *size);

    for(i=0; i<*size; i++) printf("%d ", (*a)[i]);
    printf("\n");

    return;
}