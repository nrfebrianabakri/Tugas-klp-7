#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int pil_kom()
{
    return rand() % 3 + 1;
}

void tam_pil(int pilihan)
{
    if (pilihan == 1)
        printf("Komputer gunting\n");
    else if (pilihan == 2)
        printf("Komputer batu\n");
    else if (pilihan == 3)
        printf("Komputer kertas\n");
}

int hasil[3] = {0}; // hasil[0] untuk menyimpan jumlah kemenangan, hasil[1] untuk menyimpan jumlah kekalahan, hasil[2] untuk menyimpan jumlah seri

void whowin(int pil_pem, int pilKom)
{
    if (pil_pem == pilKom)
    {
        printf("Hasil seri\n");
        hasil[2]++; // Tambahkan jumlah seri
    }
    else if ((pil_pem == 1 && pilKom == 3) ||
             (pil_pem == 2 && pilKom == 1) ||
             (pil_pem == 3 && pilKom == 2))
    {
        printf("Anda menang\n");
        hasil[0]++; // Tambahkan jumlah kemenangan
    }
    else
    {
        printf("Anda kalah\n");
        hasil[1]++; // Tambahkan jumlah kekalahan
    }
}

int valid()
{
    int input;
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%d", &input) == 1)
        {
            if (input >= 1 && input <= 3)
            {
                return input;
            }
        }
    }
    printf("Salah input, mohon untuk diulangi: ");
    return valid();
}

int main()
{
    int pil_pem, komPil;
    srand(time(NULL));
    char lanjut;

    do
    {
        printf("Welkom, selamat bermain!\n");
        printf("\n");
        printf("1. Gunting\n2. Batu\n3. Kertas\n");

        printf("\nSilahkan pilih: ");
        pil_pem = valid();
        komPil = pil_kom();
        printf("\n");
        tam_pil(komPil);
        whowin(pil_pem, komPil);

        printf("\nAnda ingin bermain lagi?(y/t): ");
        scanf(" %c", &lanjut); 
        while (getchar() != '\n') 
            ;
    } while (tolower(lanjut) == 'y');

    printf("\nMenang: %d\n", hasil[0]);
    printf("Kalah: %d\n", hasil[1]);
    printf("Seri: %d\n", hasil[2]);
    printf("\nTerima kasih telah bermain. Sampai jumpa lagi!\n");

    return 0;
}
