//88. GRUP : 130202036 Bedirhan Sisman 120202022 Kubilay Gorkemli
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<locale.h>
#include<process.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include <math.h>
#include<windows.h>
#define OTUZIKI -32
#define TRUE 1
#define FALSE 0
#define ESC 27
#define TAB 0x9
#define ENTER 13
#define DEL 127
#define BACKSPACE 8
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define YARDIM 63 //soru işareti
#define BUYUKX 88 // X-Y insert tuşu
#define BUYUKY 89
#define KUCUKX 120 // x-y insert tuşu
#define KUCUKY 121
#define ARTI 43
#define EKSI 45
#define TIRNAK 34 // tırnak ve nokta çıkış
#define NOKTA 46
#define ESITTIR 61
#define SPACE 32


char dosyaadi[25],txtdosyaadi[25];
int total=0;
int tl=0;
int k=0;
int u=0;
int i,j,ec,fg,ec2;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;

void git(int x, int y);/*Ekranda imleci istediğimiz yere göndermeyi sağlar.*/
int Y_A_OkCiz(short ,short ,short ,short ,short );/*Menulerde Yukarı-Aşağı Ok çizimi yapmaktadır.*/
void Y_A_OkSil(short ,short ,short,short );/*Menude Yukarı-Aşağı Ok çizimi yapılırken bir önceki Oku silmektedir.*/
void EkraniTemizle();/*Kalın siyah cerceve kalacak sekilde ekranı temizler*/
void MenuTemizle();/*Menunun yazılı olduğu ince cizgilerle cevrili olan dikdörtgenin icini temizler*/
void Menu_Bas();/*Ekran temizlendikten sonra Menunun dısındaki kullanma klavuzunu cerceveleri falan yazdırır*/
void Cerceve();/*Menu ilk açılırken animasyonlu cerceve çizer*/
void AnaMenu();/*Ana Menu*/
void islem();
void Hakkimizda();
void yeniDosya();
void ekleDosya();
void silDosya();
void gosterDosya();
void kaydet();
void farklikaydet();
void dolasma();

volatile int EscGirince=0;

int main(){
    system("color b9");//Renk icin
    Cerceve();
    do
     {
            AnaMenu();


     }
    while(TRUE);
    getch();
}


void Cerceve()
{
     for(int x=0;x<79;x++)
     {
       git(x,0);
       Sleep(2);
       putchar(219);
     }
     for(int y=0;y<24;y++)
     {
       git(78,y);
       Sleep(2);
       putchar(219);
     }
     for(int x=78;x>0;x--)
     {
       git(x,23);
       Sleep(2);
       putchar(219);
     }
     for(int y=23;y>0;y--)
     {
       git(0,y);
       Sleep(2);
       putchar(219);
     }

}

void AnaMenu()
{
                fflush(stdin);
                EscGirince=0;
                system("cls");
                Menu_Bas();

                int y=8,x=29;
                int cevap;
                MenuTemizle();
                git(x+3,y-2);
                puts("**  Ana Menu  **");
                git(x+4,y+1);
                puts(" Yeni Metin Belgesi ");
                git(x+4,y+3);
                puts(" Belge Goruntule ");
                git(x+4,y+5);
                puts(" Belge Duzenle ");
                git(x+4,y+7);
                puts(" Belge Sil ");
                cevap=Y_A_OkCiz(x+3,y+1,4,2,1);
                EscGirince=0;

                 switch (cevap)
                {
                    case 1:{
                         islem();

                        break;
                        }
                    case 2:
                        gosterDosya();
                        break;
                    case 3:{

                        ekleDosya();
                        break;
                        }
                    case 4:
                        silDosya();
                        break;
                }

}

void Menu_Bas()
{
     git(2,13);
     printf("Menude hareket icin;");
     git(6,15);
     putchar(24);
     git(6,17);
     putchar(25);
     git(7,16);
     putchar(26);
     git(5,16);
     putchar(27);
     git(10,15);
     printf("Yon Tuslarini");
     git(11,17);
     printf("kullaniniz.");
     git(2,19);
     printf("Ana menuye donus icin;");
     git(4,21);
     printf("\"ESC\" kullaniniz.");

     git(58,6);
     printf("Kisayol tuslarini\n");
     git(58,7);
     printf("goruntulemek\n");
     git(58,8);
     printf("ister misiniz?");


     git(58,10);
     printf("CTRL+S   Kaydet");
     git(58,12);
     printf("ESC      Ana Menu");
     git(58,14);
     printf("CTRL+D   Gezinme");
     git(58,16);
     printf("X        Cikis");

     git(42,21);
     printf("Bedirhan SISMAN - Kubilay GORKEMLI");
     for(int x=27;x<55;x++)
     {
      git(x,4);
      putchar(196);
     }
     for(int x=27;x<55;x++)
     {
      git(x,20);
      putchar(196);
     }
     for(int y=5;y<20;y++)
     {
      git(26,y);
      putchar(179);
     }
     for(int y=5;y<20;y++)
     {
      git(55,y);
      putchar(179);
     }
     git(26,4);
     putchar(218);
     git(55,4);
     putchar(191);
     git(26,20);
     putchar(192);
     git(55,20);
     putchar(217);
      for(int x=0;x<79;x++)
     {
       git(x,0);
       putchar(219);
     }
     for(int y=0;y<24;y++)
     {
       git(78,y);
       putchar(219);
     }
     for(int x=78;x>0;x--)
     {
       git(x,23);
       putchar(219);
     }
     for(int y=23;y>0;y--)
     {
       git(0,y);
       putchar(219);
     }



}

void dolasma()
{
        int xas=5,yas=5;

        git(50,8);
        printf("Gezinme menusu;");
        git(50,10);
        printf("GEZINMEK ICIN");
        git(50,12);
        printf("YON TUSLARINI");
        git(50,14);
        printf("KULLANINIZ.");
        git(50,16);
        printf("(Cikis->ESC)");

        git(5,5);


    int basilan_tus;
    for(;;)
    {
     if(kbhit()){
     basilan_tus=getch();
     if(basilan_tus==72)
     {
      yas--;
      git(xas,yas);
     }
     if(basilan_tus==DOWN)
     {
      yas++;
      git(xas,yas);
     }
     if(basilan_tus==RIGHT)
     {
      xas++;
      git(xas,yas);
     }
     if(basilan_tus==LEFT)
     {
      xas--;
      git(xas,yas);
     }
     if(basilan_tus==ESC)
     {
         break;
     }
    }
    }
}

void MenuTemizle()
{
     for(int x=27;x<55;x++)
    {
             for(int y=5;y<19;y++)
             {
              git(x,y);
              putchar(' ');
             }
    }
}

int Y_A_OkCiz(short x1,short y1,short adet,short uzaklik,const short donusDegeri)
{
    int tus;

    if (EscGirince==1)
    return 99;

        git(x1,y1);
        putchar(16);


    git(79,24);
    do
    {
        tus=getch();
    }
    while(tus!=UP&&tus!=DOWN&&tus!=ENTER&&tus!=ESC&&tus!=TAB);

    if(tus==UP)
    {
        if(donusDegeri==1)
        {
            y1=y1+(uzaklik*(adet-1));

          Y_A_OkSil(x1,y1,adet,uzaklik);
          return Y_A_OkCiz(x1,y1,adet,uzaklik,adet);
        }

        else
        {
            y1=y1-uzaklik;


          Y_A_OkSil(x1,y1,adet,uzaklik);
            return Y_A_OkCiz(x1,y1,adet,uzaklik,donusDegeri-1);
        }
    }

    if (tus==DOWN||tus==TAB)
    {
        if(donusDegeri==adet)
        {
            y1=y1-(uzaklik*(adet-1));

           Y_A_OkSil(x1,y1,adet,uzaklik);
            return Y_A_OkCiz(x1,y1,adet,uzaklik,1);
        }

        else
        {
            y1=y1+uzaklik;
           Y_A_OkSil(x1,y1,adet,uzaklik);
            return Y_A_OkCiz(x1,y1,adet,uzaklik,donusDegeri+1);
        }

    }

    if (tus==ENTER) return donusDegeri;

    if (tus==ESC)
    {
        EscGirince=1;
        return 99;
    }

    if (tus==BUYUKX||tus==KUCUKX)
    {
        exit(0);
        //getch();
    }

    return 0;
}

void Y_A_OkSil(short x1,short y1,short adet,short uzaklik)
{
     if((y1+uzaklik)>1 && (y1+uzaklik)<23)
    {
    git(x1,y1+uzaklik);
    putchar(' ');
    }
    if((y1-uzaklik)>1 && (y1-uzaklik)<23)
    {
    git(x1,y1-uzaklik);
    putchar(' ');
    }
    if((y1+uzaklik*(adet-1))>1 && (y1+uzaklik*(adet-1))<23)
    {
      git(x1,y1+uzaklik*(adet-1));
      putchar(' ');
    }
    if((y1-uzaklik*(adet-1))>1 && (y1-uzaklik*(adet-1))<23)
    {
      git(x1,y1-uzaklik*(adet-1));
      putchar(' ');
    }
    git(79,24);
    return;
}

void islem(){

int satirsayaci=0,sayfasayaci=1,sayfaNo=1;
	 system("cls");

 fp1=fopen("temp.txt","w");
 printf("\n\tMetni girin, kaydetmek icin 'CTRL+S' basin.\n\n");
 printf("Sayfa %d;\n------------------------------\n",sayfaNo);

  while(1)
  {

    c=getch();

    if(c==4)
    {
    dolasma();
    }
    else if(c==19)
    {
    goto end5;
    }
    else if(c==13)
    {
    c='\n';
    printf("\n");
    fputc(c,fp1);
    sayfasayaci++;
    satirsayaci=0;
      if(sayfasayaci>24)
      {
      printf("\n------------------------------\n\n");
      sayfaNo++;
      printf("Sayfa %d;\n------------------------------\n",sayfaNo);
      sayfasayaci=1;
      }
   }
   else
   {
   printf("%c",c);
   fputc(c,fp1);
   satirsayaci++;
   }

   if(satirsayaci>29)
   {
   printf("\n");
   fputc(c,fp1);
   satirsayaci=0;
   sayfasayaci++;
   }

   if(sayfasayaci>24)
   {
   printf("\n------------------------------\n\n");
   sayfaNo++;
   printf("Sayfa %d;\n------------------------------\n",sayfaNo);
   sayfasayaci=1;
   }
   }


   end5: fclose(fp1);
   printf("\n\n\tDosya adi girin : ");
   scanf("%s",fn);
   fp1=fopen("temp.txt","r");
   strcpy(txtdosyaadi,"");
   strcpy(txtdosyaadi,fn);
   strcat(txtdosyaadi,".txt");
   fp2=fopen(txtdosyaadi,"w");
   while(!feof(fp1))
   {
    c=getc(fp1);
    putc(c,fp2);
   }
   fclose(fp2);
   printf("\n\tDosya basarili bir sekilde kaydedildi : %s",txtdosyaadi);
   getch();

}


void ekleDosya()
{
  int satirsayaci=0,sayfasayaci=1,sayfaNo=1;
  system("cls");
  printf("\n\tDosya adi girin : ");
  scanf("%s",fn);
  strcpy(txtdosyaadi,"");
  strcpy(txtdosyaadi,fn);
  strcat(txtdosyaadi,".txt");
  fp1=fopen(txtdosyaadi,"r+");

  if(fp1==NULL)
  {
   printf("\n\t%s dosyasi bulunamadi!",txtdosyaadi);
   goto end6;
  }
  printf("\n\tMetni girin, tekrar kaydetmek icin 'CTRL+S' basin.\n\n");
  printf("Sayfa %d;\n------------------------------\n",sayfaNo);

  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
    if(c=='\n')
    {
        sayfasayaci++;
        satirsayaci=0;
    }
    else
    {
        satirsayaci++;
    }

    if(satirsayaci>30)
    {
        printf("\n");
        sayfasayaci++;
        satirsayaci=0;
    }

   if(sayfasayaci>24)
    {
        printf("\n------------------------------\n\n");
        sayfaNo++;
        printf("Sayfa %d;\n------------------------------\n",sayfaNo);
        sayfasayaci=1;
    }

  }

  while(1)
  {
   c=getch();
   if(c==4)
    {
    dolasma();
    }

   if(c==19)
    goto end3;
   if(c==13)
   {
    c='\n';
    printf("\n");
    fputc(c,fp1);
    sayfasayaci++;
    satirsayaci=0;
    if(sayfasayaci>24)
    {
        printf("\n------------------------------\n\n");
        sayfaNo++;
        printf("Sayfa %d;\n------------------------------\n",sayfaNo);
        sayfasayaci=1;
    }
   }
   else
   {
    printf("%c",c);
    fputc(c,fp1);
    satirsayaci++;
    if(satirsayaci>29)
    {
      printf("\n");
      fputc(c,fp1);
      satirsayaci=0;
      sayfasayaci++;
      c='\n';
      fputc(c,fp1);

    }
   }
   if(sayfasayaci>24)
    {
        printf("\n------------------------------\n\n");
        sayfaNo++;
        printf("Sayfa %d;\n------------------------------\n",sayfaNo);
        sayfasayaci=1;
    }
  }
  end3: fclose(fp1);
  printf("\n\n\n\tDosya basarili bir sekilde kaydedildi : %s",txtdosyaadi);
  end6:
  getch();

}


void gosterDosya()
{
  int satirsayaci=0,sayfasayaci=1,sayfaNo=1;
  system("cls");
  printf("\n\tDosya adi girin : ");
  scanf("%s",fn);
  strcpy(txtdosyaadi,"");
  strcpy(txtdosyaadi,fn);
  strcat(txtdosyaadi,".txt");
  fp1=fopen(txtdosyaadi,"r");
  printf("\n");
  if(fp1==NULL)
  {
   printf("\n\t%s dosyasi bulunamadi!",txtdosyaadi);
   goto end1;
  }
  printf("\t\t\t\t   Sayfa %d;\n\t\t\t-------------------------------\n\t\t\t",sayfaNo);
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
    if(c=='\n')
    {
        sayfasayaci++;
        satirsayaci=0;
        printf("\t\t\t");
    }
    else
    {
        satirsayaci++;
    }

    if(satirsayaci>30)
    {
        printf("\n\t\t\t");
        sayfasayaci++;
        satirsayaci=0;

    }

   if(sayfasayaci>24)
    {
        printf("\n\t\t\t-------------------------------\n\n");
        sayfaNo++;
        printf("\t\t\t\t   Sayfa %d;\n\t\t\t-------------------------------\n\t\t\t",sayfaNo);
        sayfasayaci=1;
    }

  }

end1:
  fclose(fp1);
  printf("\n\n\tDevam etmek icin herhangi bir tusa basin...");
  getch();
}


void silDosya()
{
  system("cls");
  printf("\n\tDosya adi girin : ");
  scanf("%s",fn);
  strcpy(txtdosyaadi,"");
  strcpy(txtdosyaadi,fn);
  strcat(txtdosyaadi,".txt");
  fp1=fopen(txtdosyaadi,"r");
  if(fp1==NULL)
  {
   printf("\n\t%s dosyasi bulunamadi!",txtdosyaadi);
   goto end2;
  }
  fclose(fp1);
  if(remove(txtdosyaadi)==0)
  {
   printf("\n\n\tDosya basarili bir sekilde silindi!");
   goto end2;
  }
  else
   printf("\n\tHata!\n");
end2: printf("\n\n\tDevam etmek icin herhangi bir tusa basin...");
  getch();
}


void git(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

