#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
    int yy;
    int mm;
    int dd;
} date;

typedef struct
{
    char name[50];
    long int num;
    int sal;
    date dob;
} staff;

int main()
{
    int i, n;
    staff * rec;
    printf("No. of Staff : ");
    scanf("%d", &n);
    rec = (staff *) malloc(n * sizeof(staff));
    printf("\nStaff Record Input :\n");
    for(i=0; i<n; i++)
    {
        printf("\nStaff Name : ");
        fflush(stdin);
        gets(rec[i].name);
        printf("Phone Number : ");
        scanf("%ld", &rec[i].num);
        printf("Salary : ");
        scanf("%d", &rec[i].sal);
        printf("Date Of Birth (YY MM DD): ");
        scanf("%d %d %d", &rec[i].dob.yy, &rec[i].dob.mm, &rec[i].dob.dd);
    }
    printf("\nStaff Records Output : \n");
    for(i=0; i<n; i++)
    {
        printf("Staff Name : %s \n", rec[i].name);
        printf("Phone Number : %ld \n", rec[i].num);
        printf("Salary : %d \n", rec[i].sal);
        printf("Date Of Birth : %d %d %d\n\n", rec[i].dob.yy, rec[i].dob.mm, rec[i].dob.dd);
    }
    return 0;
}
