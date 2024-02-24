#include<stdio.h>
void main()
{
   int a,b,r,hcf,div;
   printf("Enter number ");
   scanf("%d",&a);
   printf("Enter number ");
   scanf("%d",&b);
   hcf=a;
   div=b;
   do
   {
      r=hcf%div;
      hcf=div;
      div=r;
   }while(r!=0);
   printf("H.C.F. is %d\n",hcf);
   printf("L.C.M. is %d",(a*b)/hcf);
   getch();
}
