#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if(isalpha(ch)) //如果是一个字符
        {
            putchar(ch+1);
        }
        else
        {
            putchar(ch);
        }
    }
    putchar(ch);
    return 0;
    
}