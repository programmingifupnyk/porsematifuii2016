/// UNI TAKSI

#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
using namespace std;

struct pelanggan
{
    int T;
    int Xa;
    int Ya;
    int Xb;
    int Yb;
    string status;
};

struct uni
{
    pair<int,int> posisi[5];
    int t[5];
    string status;

};

string pesan[] = {"Menunggu","Menjemput Pelanggan","Di lokasi asal pelanggan","Mengantar Pelanggan","Di lokasi tujuan pelanggan"};
int TT[100];
pelanggan p[101];
queue <int> qkondisi;
queue <int> qpelanggan;
pair<int,int> koordinat[300];
uni K[100];

int main()
{
    int i=0;
    int j=0;
    int jum_p=0;
    int test;
    int ti,pi;
    int dx,dy;
    int tempx,tempy,temps,temppi,acuan;
    int no_pelanggan_sekarang;
    int no_pelanggan_berikutnya;
    bool masih = true;

    do{
        scanf("%d",&test);
        if(test == -99)
            masih = false;
        else
        {   p[i].T = test;
            scanf("%d %d %d %d",&p[i].Xa, &p[i].Xb, &p[i].Ya, &p[i].Yb);
            jum_p++;
            i++;
        }

    }while(masih);

    masih = true;
    i=0;
    do
    {
        scanf("%d",&test);
        if(test == -99)
            masih = false;
        else
        {   TT[i] = test;
            i++;
        }
    }while(masih);

    no_pelanggan_sekarang = 0;
    qpelanggan.push(no_pelanggan_sekarang);
    K[no_pelanggan_sekarang].status = pesan[1];
    K[no_pelanggan_sekarang].t[0] = 0; /// start jemput
    K[no_pelanggan_sekarang].t[1] = K[no_pelanggan_sekarang].t[0] + p[no_pelanggan_sekarang].Xa; /// t belok jemput
    K[no_pelanggan_sekarang].t[2] = K[no_pelanggan_sekarang].t[1] + p[no_pelanggan_sekarang].Ya; /// t sampai jemput, start antar
    K[no_pelanggan_sekarang].t[3] = K[no_pelanggan_sekarang].t[2] + abs(p[no_pelanggan_sekarang].Xb - p[no_pelanggan_sekarang].Xa); /// t belok antar
    K[no_pelanggan_sekarang].t[4] = K[no_pelanggan_sekarang].t[3] + abs(p[no_pelanggan_sekarang].Yb - p[no_pelanggan_sekarang].Ya); /// t sampai antar, start jemput berikutnya

    K[no_pelanggan_sekarang].posisi[0].first = 0;                           K[no_pelanggan_sekarang].posisi[0].second = 0;
    K[no_pelanggan_sekarang].posisi[1].first = p[no_pelanggan_sekarang].Xa; K[no_pelanggan_sekarang].posisi[1].second = 0;


    p[no_pelanggan_sekarang].status = pesan[4];
    K[no_pelanggan_sekarang].status = pesan[4];

    for(ti = 0; ti < 5; ti++) /// masukkan histori waktu ke queue.
        qkondisi.push(K[no_pelanggan_sekarang].t[ti]);

        do{
            acuan=no_pelanggan_sekarang;
            i = 0;
            temppi = -1;
            while(K[acuan].t[4] > p[i].T)
            {
                if(p[i].status != pesan[4] && p[i].status != "")
                {
                    tempx = abs(p[i].Xa - p[acuan].Xb);
                    tempy = abs(p[i].Ya - p[acuan].Yb);
                    temps = tempx + tempy;
                    temppi = i;
                    dx = abs(p[i].Xa - p[acuan].Xb);
                    dy = abs(p[i].Ya - p[acuan].Yb);

                    if((dx + dy) < temps)
                    {
                        tempx = dx; /// menyimpan jarak  x terdekat antara titik terakhir dengan titik jemputan
                        tempy = dy; /// idem y
                        temppi = i; /// menyimpan no pelanggan yang terdekat
                    }
                }
                i++;
            }
            i = 1;
            while(K[acuan].t[4] > p[acuan+i].T)
            {
                if(p[acuan+i].status != pesan[4] && p[acuan+i].status != "")
                {
                    tempx = abs(p[acuan+i].Xa - p[acuan].Xb);
                    tempy = abs(p[acuan+i].Ya - p[acuan].Yb);
                    temps = tempx + tempy;
                    temppi = i;
                    dx = abs(p[acuan+i].Xa - p[acuan].Xb);
                    dy = abs(p[acuan+i].Ya - p[acuan].Yb);

                    if((dx + dy) < temps)
                    {
                        tempx = dx; /// menyimpan jarak  x terdekat antara titik terakhir dengan titik jemputan
                        tempy = dy; /// idem y
                        temppi = i; /// menyimpan no pelanggan yang terdekat
                    }
                }
                i++;
            }
             if(temppi == -1 && (p[acuan+1].T > K[acuan].t[4] && (p[acuan+1].status != pesan[4] || p[acuan+1].status != "")))
             {
                 temppi = no_pelanggan_sekarang + 1;
             }else
             {
                 break;
             }
             no_pelanggan_berikutnya = temppi;
             qpelanggan.push(no_pelanggan_berikutnya);
             koordinat[0] = make_pair(p[acuan].Xa,p[acuan].Yb);
             koordinat[1] = make_pair(p[acuan].Xb,p[acuan].Yb);
             koordinat[2] = make_pair(p[no_pelanggan_berikutnya].Xa,p[no_pelanggan_berikutnya].Ya);
             koordinat[3] = make_pair(p[no_pelanggan_berikutnya].Xb,p[no_pelanggan_berikutnya].Yb);

            no_pelanggan_sekarang = no_pelanggan_berikutnya;
            K[no_pelanggan_sekarang].t[0] = K[acuan].t[4]; /// start jemput pelanggan berikutnya
            K[no_pelanggan_sekarang].t[1] = K[no_pelanggan_sekarang].t[0] + abs(koordinat[2].first  - koordinat[1].first); /// t belok jemput
            K[no_pelanggan_sekarang].t[2] = K[no_pelanggan_sekarang].t[1] + abs(koordinat[2].second - koordinat[2].second); /// t sampai jemput, start antar
            K[no_pelanggan_sekarang].t[3] = K[no_pelanggan_sekarang].t[2] + abs(koordinat[3].first  - koordinat[2].first); /// t belok antar
            K[no_pelanggan_sekarang].t[4] = K[no_pelanggan_sekarang].t[3] + abs(koordinat[3].second - koordinat[2].second); /// t sampai antar, start jemput berikutnya

            p[no_pelanggan_sekarang].status = pesan[4];
            K[no_pelanggan_sekarang].status = pesan[4];

            for(ti = 0; ti < 5; ti++)
                qkondisi.push(K[no_pelanggan_sekarang].t[ti]);
        }while(1);

        printf("Urutan pengambilan pelanggan : \n\n");

        while(!qpelanggan.empty())
        {
            pi = qpelanggan.pop();
            printf("No. pelanggan          : %d\n",pi);
            printf("Waktu datang pelanggan : %d\n",p[pi].T);
            printf("Waktu jemput pelanggan : %d\n",K[pi].t[0]);
            printf("Waktu belok jemput     : %d\n",K[pi].t[1]);
            printf("Waktu sampai jemput    : %d\n",K[pi].t[2]);
        }
}
