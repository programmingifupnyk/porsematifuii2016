#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long B,H,J;
    long biayasatuan, biayatotal;
    scanf("%ld %ld %ld",&H,&J,&B);

    biayasatuan = B * 1000;
    biayatotal  = J * H * biayasatuan;

//    printf("Bu Yasmin ingin membuat nasi bungkus untuk para pengungsi merapi selama %ld hari.\n",H);
//    printf("Jumlah nasi bungkus yang ingin dibuat Bu Yasmin sebanyak %ld bungkus perhari.\n",J);
//    printf("Biaya satuan nasi bungkus adalah %ld.\n",biayasatuan);
//    printf("Dengan demikian Bu Yasmin harus mengeluarkan biaya sebanyak Rp.%ld.",biayatotal);

    cout << "Bu Yasmin ingin membuat nasi bungkus untuk para pengungsi merapi selama "<<H<<" hari.\n";
    cout << "Jumlah nasi bungkus yang ingin dibuat Bu Yasmin sebanyak "<<J<<" bungkus perhari.\n";
    cout << "Biaya satuan nasi bungkus adalah "<<biayasatuan<<".\n";
    cout << "Dengan demikian Bu Yasmin harus mengeluarkan biaya sebanyak Rp."<<biayatotal<<".\n";
}
