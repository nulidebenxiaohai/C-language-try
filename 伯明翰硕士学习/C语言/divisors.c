#include <stdio.h>
#include <stdbool.h>//输入一个数来判断这个数是否为一个质数并且显示约数

int main()
{
    unsigned long num;
    unsigned long div;
    bool isPrime;

    printf("Please enter an integer for analysis: ");
    printf("Enter q to quit.\n");

    while(scanf("%lu", &num)==1)
    {
        for (div=2, isPrime=true; (div*div)<=num; div++)
        {
            if(num%div == 0)
            {
                if((div*div) != num)
                {
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num/div);
                }
                else
                {
                    printf("%lu is divisible by %lu.\n", num,div);
                }
                isPrime=false;
            }
        }

        if (isPrime)
        {
            printf("%lu is prime.\n", num);
        }
        printf("Please enter another integer for analysis;");
        printf("Enter q to quit.\n");
                
    }
    printf("Bye.\n");
    return 0;
}
