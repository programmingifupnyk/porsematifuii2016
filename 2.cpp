#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int hh,mm;
    int shha,smma;
    double fshha, fsmma;
    double cek, fmm;

    scanf("%2d:%2d",&hh,&mm);

    if(hh > 12)
    {
        shha = hh - 12;
    }else
    {
        shha = hh;
    }
    //printf("%d %d\n",shha,smma);
    shha = shha * 30;

    smma = mm;

    fmm = mm;
    fshha = shha;

    fmm  = (fmm / 60) * 30;

    smma = smma * 6;

    //printf("%d %d\n",shha,smma);
    fshha = fshha + fmm;
    cek = fabs(fshha - smma);

    //printf("%.1f\n",cek);
    if(cek > 180)
    {
        cek = 360 -  cek;
    }
    printf("%.1f",cek);
    printf("\n");
}
