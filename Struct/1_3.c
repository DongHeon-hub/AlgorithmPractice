#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _SUBJECT_{
    char number[8];
    int credit;
    double grade;
} subject;

typedef struct _STUDENT_{
    int id;
    int number_of_course;
    subject*courses;
} student;

double calcCGPA(student s);

int main(){
    student*best;
    double*cgpa;
    int n;
    int i;
    int save;
    int cnt=0;
    scanf("%d", &n);
    save=n;
    best = (student*)malloc(sizeof(student)*n);
    cgpa = (double*)malloc(sizeof(double)*n);

    while(n--){
        scanf("%d %d", &((best+cnt)->id), &(best[cnt].number_of_course));
        getchar();
        best[cnt].courses = (subject*)malloc(sizeof(subject)*best[cnt].number_of_course);

        for(i=0; i<best[cnt].number_of_course; i++) {
            scanf("%s %d %lf", &(best[cnt].courses[i].number), &(best[cnt].courses[i].credit), &(best[cnt].courses[i].grade));
            getchar();
        }
            
        cgpa[cnt] = calcCGPA(best[cnt]);
        cnt++;
    }

    printf("========\n");

    for(i=0; i<save; i++){
        printf("%d / %lf\n", best[i].id, cgpa[i]);
    }

    printf("\n");

    return 0;

}

double calcCGPA(student s){
    int i;
    int sumOfcredit=0;
    double beforeDivision=0.0;
    double result;
    for(i=0; i<s.number_of_course; i++){
        sumOfcredit += s.courses[i].credit;
        beforeDivision += (double)s.courses[i].credit * s.courses[i].grade;
    }

    result = beforeDivision / sumOfcredit;
    
    return result;
}