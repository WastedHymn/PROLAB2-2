#include <stdio.h>
#include <string.h>
    char input[] = {
    "20,20,10",
    "1,su,30,0.5",
    "2,cay,20,1.0",
    "3,kahve,15,1.5",
    "4,cikolata,50,1.75",
    "5,biskuvi,100,2.0"};

    struct urun{
        int urunId;
        int urunStok;
        int urunFiyat;
        char urunAd;
    }urunler[5];

    struct hesap{
        int para[3];
    }banka;
    void kasabilgilerinial(char gelensatır[30])
    {
        int x=0;
        char *parçalayacağımızsatır ;
        char const virgul[2] = "," ;
        parçalayacağımızsatır = strtok(gelensatır,virgül);
        while(parçalayacağımızsatır != NULL)
        {
            // 20 -> int 20 
            banka.para[x] = atoi(parçalayacağımızsatır);  
            parçalayacağımızsatır = strtok(NULL,virgül);
            x++ ;
        }
    }
    void ürünbilgilerinial(char satır[] , int sayi)
    {
        int x = 0 ;
        // ilk 5 satır aynı 
        while()
        {
            // x = 0 iken ürünün id  
            if(x == 0)
            {
                urunler[sayi].urunId = sayi+1 ;
            }
            // x = 1 ne alıyorum nereye göndercem
            // x = 1 -> ürünün ismi var 
            if(x == 1 )
            {
                strcpy(urunler[sayi].urunAd)
            }


            if(x==2)
            urunler[sayi].urunStok=atoi(parçalayacağımızsatır);
            // yazacağın yer  = atoi(string) ;
    
    
            parçayalayacağımızsatır = strtok(NULL,virgül);
            x++ ;
        }
    }

    void bigligonder()
    {
        char temp[30];
        strcpy(temp,input[0]);//20 20 10 -> temp
        kasabilgilerinial(temp);
        int i ;
        int  sayı = 0  ;
        for(int i = 1 ; i < 6 ; i++)
        {
            strcpy(temp,input[i]);
            ürünbilgilerinial(temp,sayı);
            sayı++ ;
        }
    }

int main() 
{
    bigligonder();
 
    return 0;
}