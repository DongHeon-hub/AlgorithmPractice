#include<stdio.h>
#include<stdlib.h>

void push_back(int**a, int *size, int value);
void pop_back(int**a, int*size);
double average(int*a, int size);
double variance(int*a, int size);

int main(){
    int n;
    int value;
    int size=0;
    int flag;
    scanf("%d", &n);
    int*a=NULL;

    while(n-->0){
        scanf("%d", &flag);

        if(flag==1){
            scanf("%d", &value);
            push_back(&a, &size, value);
            for(int i=0; i<size; i++) printf("%d ", a[i]);
            printf("\n");
            printf("%f %f\n", average(a, size), variance(a,size));
        }

        else{
            pop_back(&a, &size);
            for(int i=0; i<size; i++) printf("%d ", a[i]);
            printf("\n");
            printf("%f %f\n", average(a, size), variance(a, size));
        }
    }

    return 0;
}

void push_back(int**a, int *size, int value){
    *size+=1;
    *a = (int*)realloc(*a, sizeof(int)*(*size));
    (*a)[*size-1] = value;
}

void pop_back(int**a, int*size){
    *size-=1;
    *a = (int*)realloc(*a, sizeof(int)*(*size));
}

double average(int*a, int size){
    double sum=0.0;

    for(int i=0; i<size; i++) sum+=a[i];

    return sum/size;
}

double variance(int*a, int size){
    double sum=0.0;
    double average;
    for(int i=0; i<size; i++) sum+=a[i];

    average = sum/(double)size;
    sum=0.0;

    for(int i=0; i<size; i++){
        sum += (average-(double)a[i])*(average-(double)a[i]);
    }

    return sum/size;
}