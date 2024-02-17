#include<stdio.h>
int main()
{
    long int _rem, _rev=0, _num;

    printf("Enter an integer: ");
    scanf("%ld", &_num);

    while(_num!=0)
    {
        _rem=_num%10;
        _rev=_rev*10+_rem;
        _num/=10;
    }

    printf("Reverse of the given integer: %ld", _rev);
    return 0;
}
