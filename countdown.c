#include <stdio.h>

int countdown(int num)
{
    if(num <= 0)
        return 0;
    else {
        printf("%d\n", num);
        countdown(num - 1);
    }
}

int main()
{
    countdown(5);
    return 0;
}

