#include<stdio.h>
#include<stdlib.h>


int main(){
    int H,W,N;
    int i,j;
    int x, y;
    int module=0;
    int**hotel;
    scanf("%d %d %d", &H, &W, &N);

    module = N-H*(N/H);

    if(module==0) x=H;
    else x=module;

    if(N/H==0) y=1;
    else{
        if(module==0) y=N/H;
        else y=N/H+1;
    }

/*
    hotel = (int**)malloc(sizeof(int*)*H);

    for(i=0; i<W; i++) *(hotel+i) = (int*)malloc(sizeof(int)*W);

    for(j=0; j<W; j++){
        for(i=H-1; i>=0; i--) hotel[i][j] = (H-i)*100+(j+1);
    }

    for(i=0; i<H; i++){
        for(j=0; j<W; j++) printf("%d ", hotel[i][j]);
        printf("\n");
    }
*/
    printf("%d\n", x*100+y);
    return 0;

   

}