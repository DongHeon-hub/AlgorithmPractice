#include<stdio.h>

void mat_mul(int a[100][100], int b[100][100], int c[100][100], int N);

int main(){
    int a[100][100], b[100][100], c[100][100];

    int n,i,j;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++) scanf("%d", &a[i][j]);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++) scanf("%d", &b[i][j]);
    }

/*
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) printf("%3d ", b[i][j]);
        printf("\n");
    }
*/

    mat_mul(a,b,c, n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++) printf("%d ", c[i][j]);
        printf("\n");
    }

    
    return 0;


}

void mat_mul(int a[100][100], int b[100][100], int c[100][100], int N){
    int i, j, k;

    int sum=0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            for(k=0; k<N; k++) sum+=a[i][k]*b[k][j];

            c[i][j] = sum;
            sum=0;
        }

    }
}