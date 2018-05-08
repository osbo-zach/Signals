#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int sizeofary = 0;
    int ary[4][2];
    char str[12];
    char tmp[5];
    int temp;
    
    while(i < 400 && sizeofary < 5)
    {
        fgets(str, 12, stdin);
        if (strlen(str) > 9)
        {
            tmp[0] = str[0];
            tmp[1] = str[1];
            tmp[2] = str[2];
            tmp[3] = str[3];
            tmp[4] = str[4];
            temp = atoi(tmp);
            ary[sizeofary][0] = temp;
            ary[sizeofary][1] = i;
            sizeofary++;
        }
        i++;
    }
    
    int second, third, last;
    second = ary[1][1] - ary[0][1];
    third = ary[2][1] - ary[0][1];
    last = ary[3][1] - ary[0][1];
    printf("%d is the winner!\n%d is 2nd, %d lines behind\n%d is 3rd, %d lines behind\n%d is last, %d lines behind\n", ary[0][0], ary[1][0], second, ary[2][0], third, ary[3][0], last);
    
    return 0;
}