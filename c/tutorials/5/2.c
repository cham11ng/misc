#include<stdio.h>
#include<conio.h>

typedef struct
{
    float real;
    float img;
} complex;

void evaluate(complex *, complex *, complex, complex);

int main()
{
    complex a, b, sum, diff;
    printf("Real and Imaginary Value : ");
    scanf("%f %f", &a.real, &a.img);

     printf("Real and Imaginary Value : ");
    scanf("%f %f", &b.real, &b.img);

    evaluate(&sum, &diff, a, b);
    printf("Sum of Complex Numbers is : %.2f %.2fi\n", sum.real, sum.img);
    printf("Difference of Complex Numbers is : %.2f %.2fi\n", diff.real, diff.img);
    return 0;
}

void evaluate(complex * sum, complex * diff, complex a, complex b)
{
    sum->real = a.real + b.real;
    sum->img = a.img + b. img;
    diff->real = a.real - b.real;
    diff->img = a.img - b. img;
}
