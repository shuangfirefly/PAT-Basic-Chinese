/*** 原创***/
/*** 题目网址： https://www.patest.cn/contests/pat-b-practise/1068 ***/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void Uniq(int *Num, int M, int N, int *Pos, int *PixCnt, int TOL);
int Check_Pix(int X, int Y, int M, int N, int *Num, int TOL);

int main(void)
{
    int *PixCnt=NULL, *Num=NULL;
    int Pos[4]= {0}; ///像素点位置,0,1:X,Y坐标[-1代表不存在]。2:像素值。3:像素点计数器。
    int i=0, M=0, N=0, TOL=0, Max=0; ///M:行，N:列

    scanf("%d%d%d", &N, &M, &TOL);
    Max = M*N;
    Num = calloc(Max, sizeof(int));
    PixCnt = calloc((int )pow(2, 24), sizeof(int));

    for(i=0; i<Max; i++)
    {
        scanf("%d", (Num+i));
        *(PixCnt+*(Num+i))+=1;
        ///printf(" ***MAIN :%d = %d\n", *(Num+i), *(PixCnt+*(Num+i)));
    }

    Uniq(Num, M, N, Pos, PixCnt, TOL);

    if(0==*(Pos+3))
        printf("Not Exist");
    else if(1==*(Pos+3))
        printf("(%d, %d): %d", *(Pos+1)+1, *(Pos+0)+1, *(Pos+2));
    else
        printf("Not Unique");

    free(Num);
    free(PixCnt);

    return 0;
}

void Uniq(int *Num, int M, int N, int *Pos, int *PixCnt, int TOL)
{
    int i=0, j=0;

    if((1==M&&1==N)&&(*(Num)>TOL))
        *(Pos+0)=i, *(Pos+1)=j, *(Pos+2)=*(Num+i*N+j), *(Pos+3)+=1;

    else
        for(i=0; i<M; i++)
        {
            for(j=0; j<N; j++)
            {
                if((Check_Pix(i, j, M, N,Num, TOL))&&(1==*(PixCnt+*(Num+i*N+j))))
                {
                    ///printf("Num = %d  Cnt = %d\n", *(Num+i*N+j), *(PixCnt+*(Num+i*N+j)));
                    *(Pos+0)=i, *(Pos+1)=j, *(Pos+2)=*(Num+i*N+j), *(Pos+3)+=1;
                }
            }
        }
}

int Check_Pix(int X, int Y, int M, int N, int *Num, int TOL)
{
    int i=0, j=0, Flag=1, Real_TOL=0, NumMid=0, NumThr=0; ///NumThr: Number The Other

    NumMid = *(Num+X*N+Y);

    for(i=X-1; i<X+2; i++)
    {
        for(j=Y-1; j<Y+2; j++)
        {
            if(i<0||i>M-1||j<0||j>N-1)
                continue;
            if(i!=X||j!=Y)
            {
                NumThr = *(Num+i*N+j);
                Real_TOL=NumMid-NumThr;

                if(abs(Real_TOL)<=TOL)
                    Flag=0;
            }
        }
        if(!Flag)
            break;
    }

    return Flag;
}
