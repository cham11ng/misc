#include<stdio.h>
#include<conio.h>

typedef struct
{
    int feet;
    int inch;
    int cm;
} distance;

void evaluate(distance *, distance *, distance, distance);

int main()
{
    distance a, b, sum, diff;
    printf("feet inch cm : ");
    scanf("%d %d %d", &a.feet, &a.inch, &a.cm);
    printf("feet inch cm : ");
    scanf("%d %d %d", &b.feet, &b.inch, &b.cm);
    evaluate(&sum, &diff, a, b);
    printf("Added Distance : %d feet %d inch %d cm\n", sum.feet, sum.inch, sum.cm);
    printf("Subtracted Distance : %d feet %d inch %d cm\n", diff.feet, diff.inch, diff.cm);
    return 0;
}

void evaluate(distance * sum, distance * diff, distance a, distance b)
{
    sum->feet = a.feet + b.feet;
    sum->inch = a.inch + b.inch;
    sum->cm = a.cm + b.cm;
    sum->inch += sum->cm / (int)2.54;
    sum->cm %= (int)2.54;
    sum->feet += sum->inch / 12;
    sum->inch %= 12;

    diff->feet = a.feet - b.feet;
    diff->inch = a.inch - b.inch;
    diff->cm = a.cm - b.cm;
    if(diff->cm<0)
    {
        diff->cm+=2.54;
        diff->inch-=1;
    }
    if(diff->inch<0)
    {
        diff->inch+=12;
        diff->feet-=1;
    }
}

