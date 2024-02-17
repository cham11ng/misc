#include<stdio.h>
#include<conio.h>

typedef struct
{
    float real;
    float img;
} complex;

complex complexSum(complex, complex);
complex complexDiff(complex, complex);
complex complexMul(complex, complex);
complex complexDiv(complex, complex);

int main()
{
    complex a, b, c;
    printf("Real and Imaginary Value : ");
    scanf("%f %f", &a.real, &a.img);

     printf("Real and Imaginary Value : ");
    scanf("%f %f", &b.real, &b.img);

    c=complexSum(a, b);
    printf("Sum of Complex Numbers is : %.2f %.2fi\n", c.real, c.img);
    c=complexDiff(a,b);
    printf("Difference of Complex Numbers is : %.2f %.2fi\n", c.real, c.img);
    c=complexMul(a,b);
    printf("Multiplication of Complex Numbers is : %.2f %.2fi\n", c.real, c.img);
     c=complexDiv(a,b);
    printf("Division of Complex Numbers is : %.4f %.4fi\n", c.real, c.img);
    return 0;
}

complex complexSum(complex a, complex b)
{
    complex c;
    c.real = a.real + b.real;
    c.img = a.img + b. img;
    return c;
}

complex complexDiff(complex a, complex b)
{
    complex c;
    c.real = a.real - b.real;
    c.img = a.img - b. img;
    return c;
}

complex complexMul(complex a, complex b)
{
    complex c;
    c.real = a.real * b.real - a.img * b.img; /*** - sign is because square of i = -1 **/
    c.img = a.real * b.img + b.real * a.img;
    return c;
}

complex complexDiv(complex a, complex b)
{
    complex c;
    float num;
    num = (b.real * b.real) + (b.img * b.img);
    b.img *= -1; /** conjugate of b **/
    c = complexMul(a, b);
    c.real /= num;
    c.img /= num;
    return c;
}
