#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct name_phone{

    char name[20];
    char ph_number[10];

}NODE, *LIST;

LIST info = NULL;
int n = 0;

int cmp(const void *a, const void *b)
{
    NODE aTemp = *(LIST)a;
    NODE bTemp = *(LIST)b;

    if(strcmp(aTemp.name, bTemp.name) < 0)
        return -1;
    else
        return 1;
}

int findName(char *tName)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while(low <= high)
    {
        if(strcmp(info[low].name, tName) == 0)
            return low;
        if(strcmp(info[high].name, tName) == 0)
            return high;
        mid = low + (high - low) / 2;
        if(strcmp(info[mid].name, tName) == 0)
            return mid;
        if(strcmp(info[mid].name, tName) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int i;
    char tName[20], tPhoneNumber[10];

    scanf("%d", &n);
    getchar();

    info = (LIST)malloc(sizeof(NODE) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%s%s", tName, tPhoneNumber);
        strcpy(info[i].name, tName);
        strcpy(info[i].ph_number, tPhoneNumber);
    }
    qsort(info, n, sizeof(NODE), cmp);

    while(scanf("%s", tName) != EOF)
    {
        i = findName(tName);
        if(i == -1)
            printf("Not found\n");
        else
            printf("%s=%s\n", info[i].name, info[i].ph_number);
    }

    free(info);
    return 0;
}