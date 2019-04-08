#include <stdio.h>
#include <stdlib.h>

struct urun{
    int urunId;
    int urunStok;
    int urunFiyat;
    char urunAd;

};

char bilgi[] = "20,20,10,1,su,30,0.5,cay,20,1.0,3,kahve,15,1.5,4,cikolata,50,1.75,5,biskuvi,100,2.0";
char tablo[23][20];
char c;
int temp, yirmibes, elli, bir, i=0, j=0, n=0, t=0, virgulSayac=0, sayac =0;
float sayi;


void bilgiAl2(){
    for(i=0; i<23; i++){
        for(j=0;j<20;j++){
            if(virgulSayac == 0){

            }

            if(tablo[i][j] == '-'){
                printf("\nsatir sonu");
                printf("TEST");
                break;
            }

        }
    }
    printf("sayi: %d\n", sayi);
}


void bilgiAl(){
    //Virgülleri böl.
    for(i=0;i<n;i++){
        c = bilgi[i];
        if(c == ','){
            tablo[t][j] = '-';
            t++;
            j=0;
        }else{
            tablo[t][j] = c;
            j++;

        }

    }
  //Tabloyu yazdır.
  for(i=0;i<23;i++){
    for(j=0;j<20;j++){
        if(tablo[i][j] == '-'){
            printf("\n");
            break;
        }else{
            printf("%c", tablo[i][j]);
        }
    }
  }

}

void karakterSay(){
  c = bilgi[i];
  while(c != '\0'){
  n++;
  i++;
  c = bilgi[i];
  }
    printf("Karakter sayisi : %d \n", n);
}

int main()
{
    karakterSay();
    bilgiAl();
    bilgiAl2();
    return 0;
}
