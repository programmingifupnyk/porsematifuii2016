#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

char arr[10][10];
char arr2[10][10];
queue<pair <int,int> > q;

bool cek(char c1,int x, int y,int N)
{
    if(x>N || y>N || c1 != arr[x][y]) return false;
    else
    {
        if(c1 == arr[x][y]) return true;
    }
}
int main()
{
    int N;
    int length;
    char K[11];
    int l = 0;
    int m,n;
    int arah = 0;
    bool masih = true;
    scanf("%d %s",&N,&K);


    //bool ketemu = false;
    for(int i=0;i<N;i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%c ",&arr[i][j]);
            arr2[i][j] = arr[i][j];
        }
    }

    length = strlen(K);
    for(int i=0;i<N;i++)
    {
        for(int j=0; j<N; j++)
        {

            if(cek(K[0],i,j,N))
            {

                arah = 0;
                switch(arah)
                {
                    case 0 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i-1,j,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i-k][j] = '_';
                                }
                            }
                        }
                    case 1 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i-1,j+1,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i-k][j+k] = '_';
                                }
                            }
                        }
                    case 2 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i,j+l,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i][j+k] = '_';
                                }
                            }

                        }
                    case 3 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i+l,j+l,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i+k][j+k] = '_';
                                }
                            }
                        }
                    case 4 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i+1,j,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i+k][j] = '_';
                                }
                            }
                        }
                    case 5 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i+1,j-l,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i+k][j-k] = '_';
                                }
                            }
                        }
                    case 6 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i,j-l,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i][j-k] = '_';
                                }
                            }
                        }
                    case 7 :
                        {
                            l = 1;
                            while(l<length)
                            {
                                if(!cek(K[l],i-1,j-l,N))
                                {
                                    break;
                                }
                                l++;
                            }
                            if(l == length)
                            {
                                for(int k = 0; k < length; k++)
                                {
                                    arr2[i-k][j-k] = '_';
                                }
                            }

                        }
                }

            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%c ",arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
