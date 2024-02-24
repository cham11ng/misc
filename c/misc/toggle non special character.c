#include<stdio.h>

void main()
{
    char character;

    printf("Enter a Non Special Character ");
    scanf("%c",&character);

    if(character>='a' && character<='z')
        character-=32;
    else if(character>='A' && character<='Z')
        character+=32;

    printf("Toggled Character is %c \n",character);

}
