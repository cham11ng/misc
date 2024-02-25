#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    int n = 50;
    int *p = &n; // declaring variable to hold address

    printf("Getting address: %p\n", p);
    printf("Getting value: %i\n\n", *p); // go to the given location

    char *s = "HI!";

    printf("String value: %s\n", s);
    printf("String address: %p\n", s);
    printf("String value first character: %c\n", s[0]);
    printf("String value NULL character: %c\n", s[3]);
    printf("String address first: %p\n", &s[0]);
    printf("String address second: %p\n", &s[1]);
    printf("String address third: %p\n", &s[2]);

    // pointer arithmetic
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2));

    // string comparision
    char *t = "HI!";
    printf("%d\n", strcmp(s, t));
    printf("%d\n", strcmp("Test", t));

    // string assignment
    char i[20]; // prevent having a garbage value
    char *c;

    printf("Enter the value of I: ");
    scanf("%s", i);
    c = i;

    c[0] = toupper(c[0]);
    printf("Value of I: %s\n", i);
    printf("Value of C: %s\n", c);

    // malloc
    char *m = malloc(sizeof(int));

    for (int j = 0, n = strlen(i); j <= n; j++)
    {
        m[j] = i[j];
    }

    if (strlen(i) > 0)
    {
        m[0] = tolower(m[0]);
    }

    printf("Value of I: %s\n", i);
    printf("Value of M: %s\n", m);

    free(m);

    return 0;
}
