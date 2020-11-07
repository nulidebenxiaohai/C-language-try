#include <stdio.h>
int main(void)
{
    int year;

    printf("Please enter a character.\n");
    scanf("%d", &year);   
    printf("Please enter a character %d",year);
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    
}