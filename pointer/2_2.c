#include<stdio.h>
#include<stdlib.h>

void swap(int*a, int*b);
void sort(int*a, int m);
void all_sort(int a[][100], int n, int m);
int binary_search(int*a, int*endPtr, int key, int**findPtr);
int all_binary_search(int a[][100], int n, int m, int key, int**findPtr);

int main(){
    int a[100][100];
    int i, j;
    int n, m;
    int*findPtr;
    int key;

    scanf("%d %d %d", &n, &m, &key);

    for(i=0; i<n; i++){
        for(j=0; j<m; j++) scanf("%d", &a[i][j]);

    }
    

    all_sort(a, n, m);
    if(all_binary_search(a, n, m, key, &findPtr)){
        printf("%d\n%p\n", 1, findPtr);
    }
    else{
        printf("%d\n", 0);
    }

    return 0;
}

void swap(int*a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int*a, int m){
    int i, j;

    for(i=0; i<m-1; i++){
        for(j=1; j<m-i; j++){
            if(a[j] < a[j-1]) swap(&a[j], &a[j-1]);
        }
    }
}

void all_sort(int a[][100], int n, int m){
    for(int i=0; i<n; i++) sort(a[i], m);
}

int binary_search(int*a, int*endPtr, int key, int**findPtr){
    int*firstPtr = a;
    int*middle;

    while(firstPtr <= endPtr){
        middle = firstPtr + (endPtr-firstPtr)/2;

        if(*middle == key){
            *findPtr = middle;
            return 1;
        }

        else if(*middle < key){
            firstPtr = middle+1;
        }

        else{
            endPtr = middle-1;
        }
    }

    return 0;
}

int all_binary_search(int a[][100], int n, int m, int key, int**findPtr){
    int flag=0;
    int *endPtr;
    for(int i=0; i<n; i++){
        endPtr = a[i]+m-1;
        if(binary_search(a[i], endPtr, key, findPtr)) return 1;
    }

    return 0;
}