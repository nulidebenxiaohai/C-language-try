#include<stdio.h>
void bar(int x)  {
  int y = x -1; 
  if (y > 10)
    printf("Yes\n");
  else printf("No\n");
}
int main()
{
    int number;
    scanf("%d",&number);
    bar(number);
}