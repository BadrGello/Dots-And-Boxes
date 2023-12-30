#ifndef READLINE_H
#define READLINE_H


#include <ctype.h>

void readLine(char str[], int n)
{
    int ch, i = 0;
    int prevIsWhitespace = 0; //Flag to track the previous character

    //Skip leading whitespaces
    while (((ch=getchar()) != '\n') && isspace(ch))
    {
        //Do nothing, just skip whitespaces
    }

    //Read the rest of the line
    while (ch != '\n')
    {
        if (i<n)
        {
            //If the previous character was a whitespace and the current character is also a whitespace,
            //skip storing it in the array
            if (!(prevIsWhitespace && isspace(ch)))
            {
                ch=tolower(ch);
                str[i++] = ch;
            }

            //Update the flag based on the current character
            prevIsWhitespace = isspace(ch);
        }
        ch = getchar();
    }
    str[i] = '\0'; //sets the last element to be null (to make it a string)
}

#endif
