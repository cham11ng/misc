#include<stdio.h>
#include<conio.h>

typedef struct
{
    int hh;
    int mm;
    int ss;
} time;

void evaluate(time *, time *, time, time);

int main()
{
    time a, b, sum, diff;
    printf("HH MM SS : ");
    scanf("%d %d %d", &a.hh, &a.mm, &a.ss);
    printf("HH MM SS : ");
    scanf("%d %d %d", &b.hh, &b.mm, &b.ss);
    evaluate(&sum, &diff, a, b);
    printf("Added time : %d hour %d minute %d second\n", sum.hh, sum.mm, sum.ss);
    printf("Subtracted time : %d hour %d minute %d second\n", diff.hh, diff.mm, diff.ss);
    return 0;
}

void evaluate(time * sum, time * diff, time a, time b)
{
    sum->hh = a.hh + b.hh;
    sum->mm = a.mm + b.mm;
    sum->ss = a.ss + b.ss;
    sum->mm += sum->ss / 60;
    sum->ss %= 60;
    sum->hh += sum->mm / 60;
    sum->mm %= 60;

    diff->hh = a.hh - b.hh;
    diff->mm = a.mm - b.mm;
    diff->ss = a.ss - b.ss;
    if(diff->ss<0)
    {
        diff->ss+=60;
        diff->mm-=1;
    }
    if(diff->mm<0)
    {
        diff->mm+=60;
        diff->hh-=1;
    }
}
