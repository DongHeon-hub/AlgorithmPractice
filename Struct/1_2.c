#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14
#define EPSILON 0.0000001
#define ABS(X) ((X) < 0 ? -(X) : (X))
typedef struct{
    double x;
    double y;
    double z;
    double r;
} SPHERE;

double Distance(SPHERE s1, SPHERE s2); // 중심 사이 거리
double CrossSectionArea(SPHERE s1, SPHERE s2); // 단면적 합
double SurfaceArea(SPHERE s1, SPHERE s2); // 겉넓이 합
double Volume(SPHERE s1, SPHERE s2); // 부피 합
int stateOftwoSphere(SPHERE*s1, SPHERE*s2);

int main(){
    SPHERE s1, s2;
    printf("Type First Sphere Coordinate : ");
    scanf("%lf %lf %lf", &(s1.x), &(s1.y), &(s1.z));
    getchar();
    printf("Type First Sphere Radius : ");
    scanf("%lf", &(s1.r));
    getchar();

    printf("Type Second Sphere Coordinate : ");
    scanf("%lf %lf %lf", &(s2.x), &(s2.y), &(s2.z));
    getchar();
    printf("Type Second Sphere Coordinate : ");
    scanf("%lf", &(s2.r));
    getchar();

    
 
    switch(stateOftwoSphere(&s1, &s2)){
        case 0 : printf("Sum of Cross Section Area : %.2lf\n", CrossSectionArea(s1, s2)); 
                 break;
        case 1 : printf("Sum of Surface Area : %.2lf\n", SurfaceArea(s1, s2)); 
                 break;
        case 2 : printf("Sum of Volum : %.2lf\n", Volume(s1, s2));
    }

    return 0;


}

double Distance(SPHERE s1, SPHERE s2){
    double distance = sqrt(pow(s1.x-s2.x,2)+pow(s1.y-s2.y,2)+pow(s1.z-s2.z,2));
    return distance;

}

double CrossSectionArea(SPHERE s1, SPHERE s2){
    double cross;
    cross = PI*s1.r*s1.r + PI*s2.r*s2.r;
    return cross;
}

double SurfaceArea(SPHERE s1, SPHERE s2){
    double area;
    area = 4*PI*s1.r*s1.r + 4*PI*s2.r*s2.r;
    return area;
}


double Volume(SPHERE s1, SPHERE s2){
    double area;
    double cons = (double)4/(double)3;

    area = cons*PI*(s1.r*s1.r*s1.r + s2.r*s2.r*s2.r);

    return area;
}

int stateOftwoSphere(SPHERE*s1, SPHERE*s2){
    int flag;

    double distance = Distance(*s1, *s2);
    double rdis = s1->r+s2->r;

    if(distance > rdis) return 0;
    else if(ABS(distance-rdis) < EPSILON) return 1;
    else return 2; 
}