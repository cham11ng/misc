#include<stdio.h>
#define PI 3.1415
#include<math.h>

int main()
{
    float sum=0, x, term=1, n=1;
    printf("Enter angle in radian ");
    scanf("%f", &x);
    x = x * PI / 180;
    term = sum = x;
    printf("term= %f", term);
    while (fabs(term) >= 0.0001)
    {
        n++;
        term = term * (-1) * x * x / ((2 * n - 1) * (2 * n - 2));
        sum+=term;
    }

    printf("value of sin(%f) = %f\n", x, sum);
    return 0;
}
