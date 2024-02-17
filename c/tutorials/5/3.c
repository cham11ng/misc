#include<stdio.h>
#include<conio.h>

typedef struct
{
    int hh;
    int mm;
    int ss;
} time;

time sumTime(time, time);
time diffTime(time, time);

int main()
{
    time a, b, c;
    printf("HH MM SS : ");
    scanf("%d %d %d", &a.hh, &a.mm, &a.ss);
    printf("HH MM SS : ");
    scanf("%d %d %d", &b.hh, &b.mm, &b.ss);
    c=sumTime(a, b);
    printf("Added time : %d hour %d minute %d second\n", c.hh, c.mm, c.ss);
    c=diffTime(a, b);
    printf("Subtracted time : %d hour %d minute %d second\n", c.hh, c.mm, c.ss);
    return 0;
}

time sumTime(time a, time b)
{
    time r;
    r.hh = a.hh + b.hh;
    r.mm = a.mm + b.mm;
    r.ss = a.ss + b.ss;
    r.mm += r.ss / 60;
    r.ss %= 60;
    r.hh += r.mm / 60;
    r.mm %= 60;
    return r;
}

time diffTime(time a, time b)
{
    time r;
    r.hh = a.hh - b.hh;
    r.mm = a.mm - b.mm;
    r.ss = a.ss - b.ss;
    if(r.ss<0)
    {
        r.ss+=60;
        r.mm-=1;
    }
    if(r.mm<0)
    {
        r.mm+=60;
        r.hh-=1;
    }
    return r;
}
