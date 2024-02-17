#include <stdio.h>
#include <conio.h>

short take_input()
{
    char x;

    x = getch();

    return x;
}

int main()
{
    printf("Press any key...\n");
    printf("You pressed key no.: %d\n", take_input());
    return 0;
}
