#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *input[] = {"20,20,10","1,su,30,0.5","2,cay,20,1.0","3,kahve,15,1.5","4,cikolata,50,1.75","5,biskuvi,100,2.0"};
struct urun{
    int urunId;
    char urunAd[30];
    int urunStok;
    float urunFiyat;
}urunler[5];

struct hesap{
    int para[3];
}banka;

void kasabilgilerinial(char gelensatir[30])
{
    int x=0;
    char *line ;
    char const virgul[2] = "," ;
    line = strtok(gelensatir,virgul);
    while(line != NULL)
    {
        // 20 -> int 20
        banka.para[x] = atoi(line);
        line = strtok(NULL,virgul);
        x++;
    }
}

void urunbilgilerinial(char satir[] , int sayi)
{
    int x = 0 ;
    char *line ;
    char const virgul[2] = "," ;
    line = strtok(satir,virgul);
    while(line != NULL)
    {
        // x = 0 iken ürünün id
        if(x == 0)
        {
            urunler[sayi].urunId = sayi+1 ;
        }
            // x = 1 ne alıyorum nereye göndercem
            // x = 1 -> ürünün ismi var
        else if(x == 1 )
        {
            strcpy(urunler[sayi].urunAd,line);
        }

        else if(x==2)
            urunler[sayi].urunStok=atoi(line);
        else if(x==3)
            urunler[sayi].urunFiyat=atof(line);
        // yazacağın yer  = atoi(string) ;


        line = strtok(NULL,virgul);
        x++ ;
    }
}

void bilgigonder()
{
    char temp[30];
    strcpy(temp,input[0]);//20 20 10 -> temp
    kasabilgilerinial(temp);
    int i ;
    int sayi = 0  ;
    for(int i = 1 ; i < 6 ; i++)
    {
        strcpy(temp,input[i]);
        urunbilgilerinial(temp,sayi);
        sayi++ ;
    }
}

int main()
{

    bilgigonder();

    printf("Bakiye Degerleri:\n");
    printf("25 Kurus Sayisi: %d \n50 Kurus Sayisi: %d \n1 TL Sayisi: %d",banka.para[0],banka.para[1],banka.para[2]);
    printf("\n\nUrun Bilgileri:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s , %d , %0.2f \n",urunler[i].urunAd,urunler[i].urunStok,urunler[i].urunFiyat);
    }


    return 0;
}