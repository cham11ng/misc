#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,age,child=0,teen=0,adult=0,mature=0,old=0;
    printf("Total No of Person : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Age of person %d : ", i);
        scanf("%d",&age);
        if(age>0&&age<=12)
            child++;
        else if(age<=19)
            teen++;
        else if(age<=30)
            adult++;
        else if(age<=50)
            mature++;
        else if(age>50)
            old++;
        else
            printf("Invalid Age\n");
    }
    printf("\nChild of age 0-12           : %d",child);
    printf("\nTeenage of age 13-19        : %d",teen);
    printf("\nAdult of age 20-30          : %d",adult);
    printf("\nMature of age 31-50         : %d",mature);
    printf("\nOld age of age more than 50 : %d",old);
    getch();
}
