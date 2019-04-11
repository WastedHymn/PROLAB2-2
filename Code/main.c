#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

float bakiyeyukle(int yirmibes, int ellikurus, int birtl)
{
    float toplam=0;
    toplam+=yirmibes*0.25;
    toplam+=ellikurus*0.50;
    toplam+=birtl*1.0;
    banka.para[0]+=yirmibes;
    banka.para[1]+=ellikurus;
    banka.para[2]+=birtl;

    printf("\nKullanıcı Su Kadar Para Yukledi: %0.2f TL\n",toplam);

    return toplam;

}

void kasayigoster(){
    printf("\nKasadaki Guncel Bakiye Degerleri:\n");
    printf("25 Kurus Sayisi: %d \n50 Kurus Sayisi: %d \n1 TL Sayisi: %d\n",banka.para[0],banka.para[1],banka.para[2]);
}
void urunlerigoster(){
    printf("\nUrun Bilgileri \nUrun Adi\t Urun Stogu\t Urun Fiyati\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s, \t\t %d, \t\t%0.2f \n",urunler[i].urunAd,urunler[i].urunStok,urunler[i].urunFiyat);
    }
}


void urunsec(int a,b,c,d,f,float kullanicibakiye,float guncelbakiye){
    float harcamatutari=0;
    float paraustu=0;
    int ust=0;
    for (int i = 0; i <5 ; ++i) {
        if(i==0)
            harcamatutari+=a*urunler[i].urunFiyat;
        if(i==1)
            harcamatutari+=b*urunler[i].urunFiyat;
        if(i==2)
            harcamatutari+=c*urunler[i].urunFiyat;
        if(i==3)
            harcamatutari+=d*urunler[i].urunFiyat;
        if(i==4)
            harcamatutari+=f*urunler[i].urunFiyat;
    }

    printf("\nSecilen Urunler icin Harcanacak Tutar: %0.2f\n",harcamatutari);

    if(harcamatutari>kullanicibakiye)// Kullanıcının Parasının Yetmemesi Durumu
        printf("\nAlisveris icin Bakiyeniz Yetersiz. ");
    else if (harcamatutari==kullanicibakiye) // Paranın Tam Yetmesi Durumu
        printf("\nAlisveris Gerceklesir... Para ustu yok.\n");
    else if(harcamatutari<kullanicibakiye)//Verilen Paranın Harcamadan Fazla Olması Paraustu Verilecek
    {
        printf("\nKullanici bakiyesi: %0.2f, Harcama Tutarı: %0.2f",kullanicibakiye,harcamatutari);
        paraustu=kullanicibakiye-harcamatutari;
        printf("\nVerilecek Para Ustumuz: %0.2f \nPara Ustu Hesaplaniyor...\n",paraustu);

        sleep(2);
        while(paraustu!=0.0)
        {
            paraustu-=0.25;
            ust++;
        }
        int birtl=ust/4;
        ust%=4;
        int ellikurus=ust/2;
        ust%=2;

        printf("\nVerilecekler Bozuk Paralar \n 1 TL Sayisi: %d, 50 Kurus Sayisi: %d, 25 Kurus Sayisi: %d\n",birtl,ellikurus,ust);
        banka.para[0]-=ust;
        banka.para[1]-=ellikurus;
        banka.para[2]-=birtl;
        sleep(2);
    }
}

void bilgigonder()
{
    int yirmibeskurus=5,ellikurus=10,birtl=15; //Kullanıcı Girdisi
    int a=2,b=2,c=2,d=2,f=2; // Alınacak Ürünler
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

    kasayigoster();
    urunlerigoster();
    float guncelbakiye=banka.para[0]+banka.para[1]+banka.para[2]; //Kasadaki Toplam Para
    float kullanicibakiye;
    kullanicibakiye=bakiyeyukle(yirmibeskurus,ellikurus,birtl); // Kullanici Bakiyesi

    urunsec(a,b,c,d,f,kullanicibakiye,guncelbakiye);

    kasayigoster();

}

int main()
{
    bilgigonder();

    return 0;
}