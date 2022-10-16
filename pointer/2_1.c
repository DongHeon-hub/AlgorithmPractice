#include<stdio.h>
#include<stdlib.h>

void swap(int*x, int*y);
void sort(int*a, int m);
void print_array(int*a, int m);
void all_sort(int a[][100], int n, int m);
void print_all_array(int a[][100], int n, int m);

int main(){
    int n, m;
    int i, j;
    int array[100][100];

    scanf("%d %d", &n, &m);

    //array=(int**)malloc(sizeof(int*)*n);

    //for(i=0; i<n; i++) array[i] = (int*)malloc(sizeof(int)*m);

    for(i=0; i<n; i++){
        for(j=0; j<m; j++) scanf("%d", &array[i][j]);
    }

    all_sort(array, n, m);
    print_all_array(array, n, m);

    return 0;

}

void swap(int*x, int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sort(int*a, int m){
    int i, j;
    int temp;

    for(i=0; i<m-1; i++){
        temp=i;

        for(j=i+1; j<m; j++) if(a[j] < a[temp]) temp=j;

        swap(a+i, a+temp);
    }

    return;
}

void print_array(int *a, int m){
    for(int i=0; i<m; i++) printf("%d ", a[i]);

    printf("\n");
}

void all_sort(int a[][100], int n, int m){
    int i, j;

    for(i=0; i<n; i++) sort(a[i], m);
}

void print_all_array(int a[][100], int n, int m){
    for(int i=0; i<n; i++) print_array(a[i], m);
}

