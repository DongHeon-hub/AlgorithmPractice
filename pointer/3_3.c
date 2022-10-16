#include<stdio.h>
#include<stdlib.h>

int*get_next_process(int*prev_pointer, int size);
void swap(int*a, int*b);
void sort(int*a, int size);

int main(void){
    int n;
    int*prev_pointer;
    int*next_pointer;
    scanf("%d", &n);
    prev_pointer = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n;i++){
        scanf("%d", &prev_pointer[i]);
    }

    sort(prev_pointer, n);

    while(next_pointer=get_next_process(prev_pointer, n)){
        if(n%2!=0)
            n = n/2+1;
        else 
            n = n/2;

        for(int i=0; i<n; i++) printf("%d ", next_pointer[i]);
        printf("\n");
        sort(next_pointer, n);
        free(prev_pointer);
        prev_pointer = next_pointer;
    }

    return 0;
}

int *get_next_process(int*prev_pointer, int size){
    int i, j;

    int next_size;
    int*next_pointer;

    if(size == 1) return NULL;
    
    if(size%2==0){
        next_size==size/2;
        if(size==2) next_size=1;

        next_pointer = (int*)malloc(sizeof(int)*next_size);

        for(i=0; i<next_size; i++) next_pointer[i] = prev_pointer[size-2*i-1]+prev_pointer[size-2*i-2];
        


    } 
    else{
        next_size = size/2+1;
        next_pointer = (int*)malloc(sizeof(int)*next_size);

        for(i=0; i<next_size && size-2*i-2>0; i++) next_pointer[i] = prev_pointer[size-2*i-1]+prev_pointer[size-2*i-2];

        next_pointer[next_size-1] = prev_pointer[0];
    }

    return next_pointer;

}

void swap(int*a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int*a, int size){
    int i, j;
    int temp;

    for(i=0; i<size-1; i++){
        temp=i;

        for(j=i+1; j<size; j++){
            if(a[temp] > a[j]) temp=j;
        }

        if(i!=temp) swap(&a[i], &a[temp]);
    }
}