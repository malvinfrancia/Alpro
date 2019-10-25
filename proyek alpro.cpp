#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define pass "2017"

unsigned long saldo=1000000, setor, tarik;
int pilihan, k, x;
char transaksi ='y';
char pin [5], ch;
char h[5]= pass;
int i, j;
int c=0;

int ceksaldo();
int tariktunai();
int setortunai();
void tunggu(int detik);

int main()
{
 system("COLOR 16");
 FILE *ftulis;
 ftulis=fopen("memori_saldo.txt","at");
 ftulis=fopen("memori_saldo.txt","r+");
 while (!feof(ftulis))
 {
  fscanf(ftulis,"%lu",&saldo);
 }
 printf("------------------------------------------------------------------------\n");
 printf("                  PROYEK AKHIR DASAR KOMPUTER                    \n");
 printf("                         SISTEM ATM                              \n");
 printf("Oleh: KELOMPOK 16\n");
 printf("      Ignatius Malvin Francia   - 1706037112\n");
 printf("      Rangga Dwi Putra          - 1706022142\n");
 printf("------------------------------------------------------------------------\n\n");
 printf("\nProgram ini berfungsi sebagai sistem ATM, di mana layanan yang\ntersedia adalah cek saldo, menarik uang tunai, dan menyetor\nuang tunai.\nPIN Rahasia Anda adalah 2017 dengan saldo awal Rp1000000.\nSelamat menggunakan!\n\n");
 printf("------------------------------------------------------------------------\n\n");
 while (c != 4)
 {
  printf("MASUKKAN PIN RAHASIA ANDA: ");
    for(i=0;i<4;i++)
    {
      ch=getch();
        pin[i]=ch;
        ch='*';
        printf("%c", ch);
    }
   for(int j=0;j<4;j++)
   {
       if(pin[j]==h[j])
        c=c+1;
   }
   if (c != 4)
   {
  printf("\nPIN ANDA SALAH, SILAKAN COBA LAGI\n\n");
  continue;
 }
 }
 do
 {
    printf("\n\n************SELAMAT DATANG DI ATM SETOR-TARIK TUNAI*********************\n");
    printf("(1) Cek Saldo						Setor Tunai (3)\n\n\n");
    printf("(2) Tarik Tunai						Keluar      (4)\n");
    
   printf("************************************************************************\n\n");
    printf("MASUKKAN PILIHAN ANDA: ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
     case 1:
       ceksaldo();
       break;
     case 2:
       tariktunai();
       break;
     case 3:
       setortunai();
       break;
      case 4:
       printf("\n\nTERIMA KASIH TELAH MENGGUNAKAN ATM KAMI");
       return 0;
     default:
       printf("\nPILIHAN TIDAK TERDAFTAR");
    }
    do
        {
  z:printf("\n\n\nAPAKAH ANDA INGIN MELAKUKAN TRANSAKSI LAIN?(y/n)\n");
    fflush(stdin);
  scanf("%c", &transaksi);
  x = 0;
    if (transaksi == 'n'|| transaksi == 'N')
        {
         k = 1;
         x=0;
  }
  else if (transaksi == 'y'|| transaksi == 'Y')
  {
   k != 1;
   x=0;
  }
  else
  {
   printf("\nPILIHAN TIDAK TERDAFTAR");
   x=1;
  }
  }
  while (x==1);
 }
 while (!k);
 printf("\n\nTERIMA KASIH TELAH MENGGUNAKAN ATM KAMI");
 fprintf(ftulis,"%lu\n",saldo);
 fclose(ftulis);
 system("pause");
}

int ceksaldo()
{
 printf("\nSALDO REKENING ANDA: Rp%lu ", saldo);
}

int tariktunai()
{
 printf("\nMASUKKAN JUMLAH PENARIKAN TUNAI: Rp");
    scanf("%lu", &tarik);
    if (tarik % 100 != 0)
    {
     printf("\nMASUKKAN ANGKA DENGAN KELIPATAN 100");
    }
    else if (tarik >(saldo - 500))
    {
     printf("\nSALDO REKENING TIDAK CUKUP");
    }
    else
    {
     saldo = saldo - tarik;
     printf("\n\nSILAKAN TUNGGU, TRANSAKSI SEDANG DIPROSES\n\n");
     tunggu(3);
     printf("\n\nSILAKAN AMBIL UANG");
     printf("\nSALDO REKENING ANDA: Rp%lu", saldo);
    }
}

int setortunai()
{
 printf("\nMASUKKAN JUMLAH PENYETORAN TUNAI: Rp");
    scanf("%lu", &setor);
    saldo = saldo + setor;
    printf("\n\nSILAKAN TUNGGU, TRANSAKSI SEDANG DIPROSES\n\n");
    tunggu(3);
    printf("SALDO REKENING ANDA: Rp%lu", saldo);
}

void tunggu(int detik)
{
    clock_t end_wait=(clock() + (detik * CLOCKS_PER_SEC));
    while(clock()<end_wait)
    {}
}

