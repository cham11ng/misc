#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[20];
    int roll;
    int age;
} student;

void sort(student *, int);
void read(student *, int);
void disp(student *, int);

int main()
{
    int n;
    student * rec;
    printf("Numb. of Student : ");
    scanf("%d", &n);
    rec = (student *) malloc (n * sizeof(student));
    read(rec, n);
    sort(rec, n);
    printf("Record's sorted according to name are : \n");
    disp(rec, n);
    return 0;
}

void read(student * rec, int n)
{
    int i;
    printf("Enter Record of %d student's\n", n);
    for(i=0; i<n; i++)
    {
        printf("Name : ");
        fflush(stdin); gets(rec[i].name);
        printf("Roll no : ");
        fflush(stdin); scanf("%d", &rec[i].roll);
        printf("Age : ");
        fflush(stdin); scanf("%d", &rec[i].age);
        printf("\n");
    }
}

void disp(student * rec, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nName : %s", rec[i].name);
        printf("\nRoll no : %d", rec[i].roll);
        printf("\nAge : %d\n", rec[i].age);
    }

}

void sort(student * rec, int n)
{
    int i, j;
    student temp;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(strcmp(rec[i].name, rec[j].name) > 0)
            {
                temp = rec[i];
                rec[i] = rec[j];
                rec[j] = temp;
            }
}
