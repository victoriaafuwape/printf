#include "main.h"
#include <stdio.h>

int main(void)
{
        char initial = 'V';
        char name[] = "Ifeoma";
        char school[] = "ALX";
        char *nameptr = name;

        _printf("My initial is %c.\tMy partner's name's %s.\n", initial, nameptr);
        _printf("We both attend %s.\tWe will score 100%%.\n", school);
        _printf("Hi, %c!\n", initial);
        return (0);
}
