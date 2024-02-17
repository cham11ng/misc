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
    marks sm[10];
    float per;
} student;

void sort(student *, int);
void read(FILE *, student *, int);
void disp(student *, int);

int main()
{
    int i=0, n, choice;
    FILE * fp;
    student rec[10];
    fp = fopen("record.dat","rb+");
    printf(" 1. Add \n 2. Display \n 3. Sort\n\n Choice?");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            fclose(fp);
            fp=fopen("record.dat", "ab+");
            printf("Number of Student : ");
            scanf("%d", &n);
            read(fp, rec, n);
            break;
        case 2:
            while(fread(&rec[i++], sizeof(student), 1, fp));
            disp(rec, i-1);
            break;
        case 3:
            while(fread(&rec[i++], sizeof(student), 1, fp));
            sort(rec, i-1);
            disp(rec, i-1);
            break;
        default:
            exit(0);
    }
    fclose(fp);
    return 0;
}

void read(FILE * fp, student * rec, int n)
{
    int i, j;
    float sum;
    printf("Enter Record of %d Student's\n", n);
    for(i=0; i<n; i++)
    {
        sum = 0;
        printf("Name : ");
        fflush(stdin); gets(rec[i].name);
        for(j=0; j<4; j++)
        {
            printf("Subject Name : ");
            fflush(stdin); gets(rec[i].sm[j].sn);
            printf("Marks Obtain : ");
            fflush(stdin); scanf("%f", &rec[i].sm[j].MO);
            sum += rec[i].sm[j].MO;
        }
        rec[i].per = sum / 4.0;
        fwrite(&rec[i], sizeof(student), 1, fp);
    }
}

void disp(student * rec, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        printf("\nName : %s", rec[i].name);
        for(j=0; j<4; j++)
        {
            printf("\n\tSubject Name : %s", rec[i].sm[j].sn);
            printf("\n\tMarks Obtain : %f", rec[i].sm[j].MO);
        }
        printf("\nPerc : %f", rec[i].per);
        printf("\n");
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

