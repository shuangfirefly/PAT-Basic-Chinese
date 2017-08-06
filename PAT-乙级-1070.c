/*** 原创***/
/*** 原题网址： https://www.patest.cn/contests/pat-b-practise/1070 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int M=0, N=0, A=0, B=0, Change=0;
    int i=0, Tmp=0;

    scanf("%d%d%d%d%d", &M, &N, &A, &B, &Change);

    for(i=0; i<M*N; i++)
    {
        scanf("%d", &Tmp);
        if(Tmp>=A&&Tmp<=B)
            printf("%03d", Change);
        else
            printf("%03d", Tmp);
        if((i+1)%N)
            printf(" ");
        else
        {
            if(i<M*N-1)
                printf("\n");
        }
    }
    return 0;
}
