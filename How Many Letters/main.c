#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

typedef struct
{
    int harf;
    int adet;
} struct_harf ;

void Alfabe(struct_harf* dizi);
void Siralama(struct_harf* dizi);
int kontrol(int degisken);              //toupper fonksiyonunda ı ve i elle kontrol edilmiş ç ğ ş ve ü harfleri ascii kodlariyla yazilmiştir. (settings->editor->encoding = windows 1254)

int main()
{
    setlocale(LC_ALL, "Turkish");
    struct_harf dizi[29];
    Alfabe(dizi);
    FILE *fp;
    fp=fopen("okunacak.txt","r");
    int i , j;
    int alinan,tp;
    while(alinan !=EOF)
    {
        alinan=fgetc(fp);
        tp=kontrol(alinan);
        for(i=0;i<29;i++)
            if(tp==dizi[i].harf)
                dizi[i].adet++;

    }

        Siralama(dizi);

    return 0;
}

int kontrol(int degisken)
{
        if(degisken==105 || degisken==221)
            return 221;
        else if(degisken==73 || degisken==253)
            return 73;
        else
            return (toupper(degisken));
}

void Siralama(struct_harf* dizi)
{
    int temp,temp2,i,j,toplam=0;
    for(i=0;i<29;i++)
    {
        for(j=1;j<29;j++)
        {
            if(dizi[j-1].adet<dizi[j].adet)
            {
                temp=dizi[j-1].adet;
                dizi[j-1].adet=dizi[j].adet;
                dizi[j].adet=temp;

                temp2=dizi[j-1].harf;
                dizi[j-1].harf=dizi[j].harf;
                dizi[j].harf=temp2;

            }
        }
    }
        for(i=0;i<29;i++)
        toplam+=dizi[i].adet;
        printf("Dosyada bulunan toplam harf say%cs%c : %d \n", 253, 253, toplam);
        for(i=0;i<29;i++)
            printf("%c --> %d\n",dizi[i].harf, dizi[i].adet);
}

void Alfabe(struct_harf* dizi)
{
    dizi[0].harf = 'A';
    dizi[0].adet = 0;
    dizi[1].harf = 'B';
    dizi[1].adet = 0;
    dizi[2].harf = 'C';
    dizi[2].adet = 0;
    dizi[3].harf = 199;
    dizi[3].adet = 0;
    dizi[4].harf = 'D';
    dizi[4].adet = 0;
    dizi[5].harf = 'E';
    dizi[5].adet = 0;
    dizi[6].harf = 'F';
    dizi[6].adet = 0;
    dizi[7].harf = 'G';
    dizi[7].adet = 0;
    dizi[8].harf = 208;
    dizi[8].adet = 0;
    dizi[9].harf = 'H';
    dizi[9].adet = 0;
    dizi[10].harf = 'I';
    dizi[10].adet = 0;
    dizi[11].harf = 221;
    dizi[11].adet = 0;
    dizi[12].harf = 'J';
    dizi[12].adet = 0;
    dizi[13].harf = 'K';
    dizi[13].adet = 0;
    dizi[14].harf = 'L';
    dizi[14].adet = 0;
    dizi[15].harf = 'M';
    dizi[15].adet = 0;
    dizi[16].harf = 'N';
    dizi[16].adet = 0;
    dizi[17].harf = 'O';
    dizi[17].adet = 0;
    dizi[18].harf = 214;
    dizi[18].adet = 0;
    dizi[19].harf = 'P';
    dizi[19].adet = 0;
    dizi[20].harf = 'R';
    dizi[20].adet = 0;
    dizi[21].harf = 'S';
    dizi[21].adet = 0;
    dizi[22].harf = 222;
    dizi[22].adet = 0;
    dizi[23].harf = 'T';
    dizi[23].adet = 0;
    dizi[24].harf = 'U';
    dizi[24].adet = 0;
    dizi[25].harf = 220;
    dizi[25].adet = 0;
    dizi[26].harf = 'V';
    dizi[26].adet = 0;
    dizi[27].harf = 'Y';
    dizi[27].adet = 0;
    dizi[28].harf = 'Z';
    dizi[28].adet = 0;
}
