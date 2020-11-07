#include <stdio.h>
int leapyear(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    
    int days;
    int year=1980;
    scanf("%d",&days);
    while (days>365)
    {
        if(leapyear(year))
        {
        
           days-=366;
           if(days==0)
           {
               year=year;
           }
           else
           {
               year+=1;
           }
           
           
            
        }
        else
        {
            
            days-=365;
            year+=1;
               
        }
        

    }
    printf("the year is %d",year);
    return 0;

}
