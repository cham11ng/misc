#include<stdio.h>
#include<conio.h>

int HCF(int, int);

int main()
{
    int a, b, c;
    printf("Three Numbers : ");
    scanf("%d %d %d", &a, &b, &c);
    printf("HCF of Three Numbers are : %d", HCF(HCF(a, b), c));
    return 0;
}

int HCF(int hcf, int t)
{
    if(!(t % hcf))
        return hcf;
    else
        return HCF(t % hcf, hcf);
}
