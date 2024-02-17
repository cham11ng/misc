#include<stdio.h>
#include<math.h>

int main()
{
    float _mean, _sd, _sum=0, _sum2=0, _num;
    int n, _t;

    printf("Enter number of numbers \n\tN=");
    scanf("%d", &n);

    for(_t=1; _t<=n; _t++)
    {
        printf("Enter number %d:\t", _t);
        scanf("%f", &_num);
        _sum+=_num;
        _sum2+=_num*_num;
    }

    _mean=_sum/n;
    _sd=sqrt(_sum2/n-pow((_sum/n),2));

    printf("Mean=%.3f\n S.D.=%.3f", _mean, _sd);
    return 0;
}
