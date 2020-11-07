#include<string.h>
#include <stdio.h>
int read_req(char *req) {
    char buf[100];     
    strcpy(buf, req);
    printf("%s\n",buf);
    return 0;
}
int main()
{
    char req[200];
    gets(req);
    read_req(req);
    return 0;
}