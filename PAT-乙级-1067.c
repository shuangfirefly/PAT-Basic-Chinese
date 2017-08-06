/*** 原创***/
/*** 原题网址： https://www.patest.cn/contests/pat-b-practise/1067 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char Key[21]= {'\0'}, Try[21]= {'\0'}, Tmp='\0';
    int i=0, N=0, Cnt=0;

    scanf("%s%d", Key, &N);
    getchar();

    for(i=0; i<N; i++)
    {
        while('\n'!=(Tmp=getchar()))
            Try[Cnt++] = Tmp;
        if((1==strlen(Try))&&('#'==Try[0]))
            break;
        else
        {
            if(i>0&&i<N)
                printf("\n");
            if(!strcmp(Key, Try))
            {
                printf("Welcome in");
                break;
            }
            else
            {
                printf("Wrong password: %s", Try);
                if(i==N-1)
                    printf("\nAccount locked");
            }
        }
        Cnt=0;
        memset(Try, '\0', strlen(Try));
    }

    return 0;
}
