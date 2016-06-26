#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int hh, mm, M;
    int minute;

    char A[10];

    scanf("%2d:%2d %s %d",&hh,&mm, &A, &M);
    minute = hh * 60 + mm;

    if(strcmp(A,"maju") == 0)
    {
      minute = minute + M;

    }else
    {
      minute = minute - M;
    }

    hh = minute / 60;
    mm = minute % 60;

    while(mm<0)
    {
        mm = 60 + mm;
        hh = hh - 1;
    }
    while(mm > 60)
    {
        mm = mm - 60;
        hh = hh + 1;
    }
    while(hh > 23)
    {
        hh = hh - 24;
    }

    while(hh<0)
    {
        hh = 24 + hh;
    }


    printf("%02d:%02d",hh,mm);
    printf("\n");
}
