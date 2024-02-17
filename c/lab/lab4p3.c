#include<stdio.h>

void main()
{
    struct student
    {
        char name[20];
        int roll;
        float marks;
    }s[3], st[3];

    int i;
    FILE *fptr;
    fptr=fopen("test.txt", "wb");

    if(fptr==NULL)
    {
        printf("No FILE CREAted!!");
        exit(1);
    }
    printf("\n Name\t ROll \t Marks \n");

    for(i=0; i<1; i++)
    {
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);
    }
    printf("\n Writting to file");

    fwrite(&student, sizeof(student), 1, fptr);
    rewind(fptr);

    printf("\n Reading fro file: \n");
    printf("\n Name\t ROll \t Marks \n");
    fread(&student, sizeof(student), 1, fptr);
    for(i=0; i<3; i++)
    {
        printf("%s\t %d \t %f", st[i].name, st[i].roll, st[i].marks);
    }
    fclose(fptr);
}
