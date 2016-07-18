#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char S[200];
    gets(S);
    printf("%c",S[0]);
    for(int i=1; i<strlen(S); i++)
    {
        if(S[i] == 32)
        {
            printf("%c",S[i+1]);
        }
    }
    printf("\n");
}
