#include<stdio.h>
#include<conio.h>

typedef struct
{
    int feet;
    int inch;
    int cm;
} distance;

distance sumDistance(distance, distance);
distance diffDistance(distance, distance);

int main()
{
    distance a, b, c;
    printf("feet inch cm : ");
    scanf("%d %d %d", &a.feet, &a.inch, &a.cm);
    printf("feet inch cm : ");
    scanf("%d %d %d", &b.feet, &b.inch, &b.cm);
    c=sumDistance(a, b);
    printf("Added Distance : %d feet %d inch %d cm\n", c.feet, c.inch, c.cm);
    c=diffDistance(a, b);
    printf("Subtracted Distance : %d feet %d inch %d cm\n", c.feet, c.inch, c.cm);
    return 0;
}

distance sumDistance(distance a, distance b)
{
    distance r;
    r.feet = a.feet + b.feet;
    r.inch = a.inch + b.inch;
    r.cm = a.cm + b.cm;
    r.inch += r.cm / (int)2.54;
    r.cm %= (int) 2.54;
    r.feet += r.inch / 12;
    r.inch %= 12;
    return r;
}

distance diffDistance(distance a, distance b)
{
    distance r;
    r.feet = a.feet - b.feet;
    r.inch = a.inch - b.inch;
    r.cm = a.cm - b.cm;
    if(r.cm<0)
    {
        r.cm+=2.54;
        r.inch-=1;
    }
    if(r.inch<0)
    {
        r.inch+=12;
        r.feet-=1;
    }
    return r;
}
