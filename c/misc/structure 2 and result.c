#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char sn[10];
    float MO;
} marks;

typedef struct
{
    char name[20];
    marks * sm;
    float per;
} student;

void sort(student *, int);
void read(student *, int, int);
void disp(student *, int, int);

int main()
{
    int i, n, ns;
    student * rec;
    printf("Numb. of Student and Subject: ");
    scanf("%d %d", &n, &ns);
    rec = (student *) malloc (n * sizeof(student));
    for(i=0; i<n; i++)
        rec[i].sm = (marks *) malloc (ns * sizeof(marks));
    read(rec, n, ns);
    sort(rec, n);
    printf("Record's sorted according to Percentage are : \n");
    disp(rec, n, ns);
    return 0;
}

void read(student * rec, int n, int ns)
{
    int i, j;
    float sum;
    printf("Enter Record of %d Student's\n", n);
    for(i=0; i<n; i++)
    {
        sum = 0;
        printf("Name : ");
        fflush(stdin); gets(rec[i].name);
        for(j=0; j<ns; j++)
        {
            printf("Subject Name : ");
            fflush(stdin); gets(rec[i].sm[j].sn);
            printf("Marks Obtain : ");
            fflush(stdin); scanf("%f", &rec[i].sm[j].MO);
            sum += rec[i].sm[j].MO;
        }
        rec[i].per = sum / ns;
        printf("\n");
    }
}

void disp(student * rec, int n, int ns)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        printf("\nName : %s", rec[i].name);
        for(j=0; j<ns; j++)
        {
            printf("\n\tSubject Name : %s", rec[i].sm[j].sn);
            printf("\n\tMarks Obtain : %f", rec[i].sm[j].MO);
        }
        printf("\nPerc : %f", rec[i].per);
    }

}

void sort(student * rec, int n)
{
    int i, j;
    student temp;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(rec[i].per < rec[j].per)
            {
                temp = rec[i];
                rec[i] = rec[j];
                rec[j] = temp;
            }
}
