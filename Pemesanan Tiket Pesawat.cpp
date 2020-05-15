#include <conio.h>
#include <stdio.h>
#include <string.h>


struct
{
  char kode[15][50],nama[15][50],tgl[10][50],nama_psw[15][50],tujuan[10][50];
  int berat[50],kode_2[50];
  long int biaya[50],biaya_brg[50];

}pen;

 int jd;
 int x,br;


entry()
{
  char adl;
  adl='y';jd=1;
  while (adl=='y'||adl=='Y' && jd<=50)
  {
    clrscr();fflush(stdin);
    gotoxy(20, 3);printf("Entry Data Booking ");// printf("ke:%i\n",jd);
    gotoxy(20, 4);printf("==============================");
    gotoxy(20, 5);printf("Data Ke.                     :%i",jd);
    gotoxy(20, 6);printf("Pilih Kode Pesawat  [1,2,3]  :");
    gotoxy(20, 7);printf("Nama Penumpang               :");
    gotoxy(20, 8);printf("Tanggal Berangkat            :");
    gotoxy(20, 9);printf("Berat Barang                 :");
    gotoxy(20,11);printf("Ada Data Lagi [y/t]          :");
    gotoxy(20,14);printf("|-------------------------------------------|");
    gotoxy(20,15);printf("|                 Informasi                 |");
    gotoxy(20,16);printf("|            Entry Data Airlines            |");
    gotoxy(20,17);printf("|-------------------------------------------|");
    gotoxy(20,18);printf("|No |Kode|Nama Pesawat|Tujuan |Biaya Pesawat|");
    gotoxy(20,19);printf("|-------------------------------------------|");
    gotoxy(20,20);printf("|[1]|K001|Lion        |Jakarta|Rp.  878.000 |");
    gotoxy(20,21);printf("|[2]|K002|City Link   |Jakarta|Rp.  915.000 |");
    gotoxy(20,22);printf("|[3]|K003|Garuda      |Jakarta|Rp.1.000.000 |");
    gotoxy(20,23);printf("|-------------------------------------------|");

    gotoxy(50, 6);scanf("%i",&pen.kode_2[jd]);fflush(stdin);
    gotoxy(50, 7);gets(pen.nama[jd]);fflush(stdin);
    gotoxy(50, 8);gets(pen.tgl[jd]);fflush(stdin);
    gotoxy(50, 9);scanf("%i",&pen.berat[jd]);fflush(stdin);
    jd=jd+1;
    gotoxy(50,11);scanf("%c",&adl);fflush(stdin);

  }
}


checkout()
{

float jml_bayar,grand_total;

    clrscr();
    gotoxy(33, 1);printf("Chekout Bills");
    gotoxy(1 , 2);printf("--------------------------------------------------------------------------------");
    gotoxy(1 , 3);printf("|No|Nama      |Tanggal   |Kode|Nama     |Tujuan |Biaya   |Berat|Biaya  |Jumlah |");
    gotoxy(1 , 4);printf("|  |Penumpang |Berangkat |Psw.|Pesawat  |       |(Rp.)   |Brg. |Barang |Bayar  |");
    gotoxy(1 , 5);printf("|  |          |          |    |         |       |        |(Kg.)|(Rp.)  |(Rp.)  |");
    gotoxy(1 , 6);printf("--------------------------------------------------------------------------------");
/*                        12345678901234567890123456789012345678901234567890123456789012345678901234567890*/
/*                                 1         2         3         4         5         6         7         8*/
br=7;
//for (x=1;x<=jd-1;x++)
x=1;
while(x<=jd-1)
{

    if(pen.kode_2[x]==1)
    {
    strcpy(pen.kode[x],"K001");
    strcpy(pen.nama_psw[x],"Lion");
    strcpy(pen.tujuan[x],"Jakarta");
    pen.biaya[x]=878000;
    }
     else
      if(pen.kode_2[x]==2)
      {
      strcpy(pen.kode[x],"K002");
      strcpy(pen.nama_psw[x],"City Link");
      strcpy(pen.tujuan[x],"Jakarta");
      pen.biaya[x]=915000;
      }
       else
        if(pen.kode_2[x]==3)
        {
        strcpy(pen.kode[x],"K003");
        strcpy(pen.nama_psw[x],"Garuda");
        strcpy(pen.tujuan[x],"Jakarta");
        pen.biaya[x]=1000000;
        }
           else
           {
           strcpy(pen.nama_psw[x],"--");
           strcpy(pen.tujuan[x],"--");
           pen.biaya[x]=0;
           }

    if (pen.berat[x]<=10)
    pen.biaya_brg[x]=0;
     else
      if (pen.berat[x]>=10)
      pen.biaya_brg[x]=15000*pen.berat[x];
    



    gotoxy(1 ,br);printf("|%i",x);
    gotoxy(4 ,br);printf("|%s",pen.nama[x]);
    gotoxy(15,br);printf("|%s",pen.tgl[x]);
    gotoxy(26,br);printf("|%s",pen.kode[x]);
    gotoxy(31,br);printf("|%s",pen.nama_psw[x]);
    gotoxy(41,br);printf("|%s",pen.tujuan[x]);
    gotoxy(49,br);printf("|%li",pen.biaya[x]);
    gotoxy(58,br);printf("|%i",pen.berat[x]);
    gotoxy(64,br);printf("|%li",pen.biaya_brg[x]);
    jml_bayar=pen.biaya[x]+pen.biaya_brg[x];
    gotoxy(72,br);printf("|%8.0f",jml_bayar);
    grand_total=grand_total+jml_bayar;

gotoxy(80,br);printf("|");
br=br+1;
x++;
}
gotoxy(1 ,br  );printf("--------------------------------------------------------------------------------");
gotoxy(1 ,br+1);printf("                                                 Grand Total      Rp.  |%8.0f     ",grand_total);
gotoxy(1 ,br+2);printf("--------------------------------------------------------------------------------");
gotoxy(80,br+1);printf("|");
gotoxy(48,br+1);printf("|");
gotoxy(1 ,br+5);printf("Press Enter to Main Menu...");
gotoxy(29 ,br+5);


getche();
}


main()
{
int pilih=0;
while(pilih<3)
 {
  clrscr();
  gotoxy(25, 3);printf("|---------------------------------|");
  gotoxy(25, 4);printf("|        Selamat Datang di        |");
  gotoxy(25, 5);printf("|    Menu Utama Data Penumpang    |");
  gotoxy(25, 6);printf("|---------------------------------|");
  gotoxy(25, 7);printf("|[1]. Booking                     |");
  gotoxy(25, 8);printf("|[2]. Checkout                    |");
  gotoxy(25, 9);printf("|[3]. Exit                        |");
  gotoxy(25,10);printf("|---------------------------------|");
  gotoxy(25,11);printf("|Please, Your Choice 1,2,3    [ ] |");
  gotoxy(25,12);printf("|---------------------------------|");
  gotoxy(56,11);scanf("%i",&pilih);

  switch(pilih)
  {
  case 1: entry();
          break;
  case 2: checkout();
          break;
  case 3: 3;
  }
 }
}



















