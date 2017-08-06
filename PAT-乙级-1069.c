/*** 原创***/
/*** 题目网址： https://www.patest.cn/contests/pat-b-practise/1069 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char Name[1001][21]= {{'\0'}}, Money[1001][21]= {{'\0'}};
    int M=0, N=0, S=0, i=0, j=0, Cnt=0;

    scanf("%d%d%d", &M, &N, &S);

    for(i=0; i<M; i++)
    {
        scanf("%s", *(Name+i));
        getchar();
    }

    if(S>M)
        printf("Keep going...");
    else
    {
        for(i=S-1; i<M; i+=N)
        {
            for(j=0; j<Cnt; j++)
            {
                if(!strcmp(*(Name+i), *(Money+j)))
                {
                    if(i+1<M)
                        i++, j=0;
                    else
                        break;
                }
            }
            printf("%s", *(Name+i));
            memcpy(*(Money+(Cnt++)), *(Name+i), strlen(*(Name+i)));
            printf("\n");
        }
    }

    return 0;
}
