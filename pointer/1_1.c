#include<stdio.h>
#include<stdlib.h>

void shift_right(int*a);
void shift_n_right(int*a, int n);
void print_array(int*a);

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int n;

    scanf("%d", &n);
    shift_n_right(a, n);
    print_array(a);

    return 0;
}

void shift_right(int*a){
    int b[10];
    for(int i=0; i<10; i++) b[i]=a[i];

    for(int i=1; i<10; i++) a[i] = b[i-1];
    a[0] = b[9];
    return;
}

void shift_n_right(int*a, int n){
    int i;
    for(i=0; i<n; i++) shift_right(a);
    return;
}

void print_array(int*a){
    int i;

    for(i=0; i<10; i++) printf("%d ", a[i]);

    printf("\n");
}