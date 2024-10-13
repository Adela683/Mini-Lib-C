#include <unistd.h>
#include <stdio.h>

int puts(const char *string)
{
    int i = 0;
    while (string[i]) // standard c idiom for looping through a null-terminated string
    {
        if (write(1, &string[i], 1) == -1) // if we got the EOF value from writing the char
        {
            return -1;
        }
        i++;
    }

    char nw = '\n';
    if (write(1, &nw, 1) == -1) // this will occur right after we quit due to the null terminated character.
    {
        return -1;
    }
    return 1; // to meet spec.
}
