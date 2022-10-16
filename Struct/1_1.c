#include<stdio.h>
#include<stdlib.h>

enum Gender{Male=0, Female=1};
typedef struct{
    char dept_name[256];
    int dept_no;
} dept;

typedef struct{
    int employee_id;
    char name[40];
    enum Gender gender;
    dept department;
    double salary;
} employee_data;

int search(employee_data *e, int num, int keyword);
employee_data update(employee_data e, int n);
