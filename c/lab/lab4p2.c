#include<stdio.h>

int main()
{
    int _n, _c=1, _c2, _count=0;

    printf("Enter the upper limit: ");
    scanf("%d", &_n);
    printf("The prime numbers up to %d are:\n", _n);
    while(_c<=_n)
    {
        for(_c2=1; _c2<=_c; _c2++)
        {
            if(_c%_c2==0)
                ++_count;
            if(_count>2)
                break;
        }
        if(_count==2)
            printf("%d ", _c);
        _count=0;
        ++_c;
    }
    return 0;
}
