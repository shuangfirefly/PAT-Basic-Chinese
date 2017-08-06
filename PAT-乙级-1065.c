/*** 原创***/
/*** 题目网站： https://www.patest.cn/contests/pat-b-practise/1065 ***/

#include <stdio.h>
#include <stdlib.h>

const int iLen=1e5;

typedef struct
{
    int Id; ///Id means if there is a man who has this Id;
    int Cpl; ///Cpl = Couple
    int St; ///St = Status   if Status=1, "Got one"; else if Status=0, "None"
} MARRY;

int main(void)
{
    MARRY *Man=NULL, *Women=NULL;
    int *Id=NULL; ///Sgl = Single Person;
    int N=0, M=0, i=0, TmpMan=0, TmpWomen=0, Flag=0, Cnt=0;  ///Flag=1, means = Single

    Man = (MARRY *) calloc(sizeof(MARRY), iLen);
    Women = (MARRY *) calloc(sizeof(MARRY), iLen);
    Id = (int *) calloc(sizeof(int), iLen);

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d%d", &TmpMan, &TmpWomen);
        (Man+TmpMan)->Id = 1;  /// Which means yes, he is alive.
        (Man+TmpMan)->Cpl = TmpWomen;

        (Women+TmpWomen)->Id = 1;
        (Women+TmpWomen)->Cpl = TmpMan;
    }

    scanf("%d", &M);

    for(i=0; i<M; i++)
    {
        scanf("%d", &TmpMan); /// Just a person, I do not know the sex.
        if((Man+TmpMan)->Id||(Women+TmpMan)->Id)
        {
            (Man+TmpMan)->St = ((Man+TmpMan)->Id)?1:0;
            (Women+TmpMan)->St = ((Women+TmpMan)->Id)?1:0;
            *(Id+TmpMan) = 2; /// If have the Other One , Set 2; Else Set 1;
        }
        else
            *(Id+TmpMan) = 1;
    }

    /// Now Count the person;
    for(i=0, Flag=0; i<iLen; Flag=0, i++)
    {
        if(*(Id+i))
        {
            if((Man+i)->Id)
            {
                Flag = (Man+i)->Cpl;
                if(2!=((Man+i)->St+(Women+Flag)->St))
                    *(Id+i) = 1, Cnt++;
            }
            else if((Women+i)->Id)
            {
                Flag = (Women+i)->Cpl;
                if(2!=((Women+i)->St+(Man+Flag)->St))
                    *(Id+i) = 1, Cnt++;
            }
            else
                Cnt++;
        }
    }

    printf("%d\n", Cnt);
    for(i=0; Cnt; i++)
        if(1==*(Id+i))
    {
        printf("%05d", i);
        if(Cnt>1)
            printf(" ");
        Cnt--;
    }

    free(Man);
    free(Women);
    free(Id);

    return 0;
}
