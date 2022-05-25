#include <stdio.h>
#include <conio.h>

char kare[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int kazanan_kontrolu();
void oyun_tahtasi();
struct skor {
    int Oyuncu1Skoru;
    int Oyuncu2Skoru;
};

int main()
{
    int Oyuncu = 1, i, secim,sk1=0,sk2=0,devam=0;

    char isaret;
    while(1){
    do
    {
        oyun_tahtasi();
        Oyuncu = (Oyuncu % 2) ? 1 : 2;

        printf("Oyuncu_%d kare seciniz:  ", Oyuncu);
        scanf("%d", &secim);

        isaret = (Oyuncu == 1) ? 'X' : 'O';

        if (secim == 1 && kare[1] == '1')
            kare[1] = isaret;

        else if (secim == 2 && kare[2] == '2')
            kare[2] = isaret;

        else if (secim == 3 && kare[3] == '3')
            kare[3] = isaret;

        else if (secim == 4 && kare[4] == '4')
            kare[4] = isaret;

        else if (secim == 5 && kare[5] == '5')
            kare[5] = isaret;

        else if (secim == 6 && kare[6] == '6')
            kare[6] = isaret;

        else if (secim == 7 && kare[7] == '7')
            kare[7] = isaret;

        else if (secim == 8 && kare[8] == '8')
            kare[8] = isaret;

        else if (secim == 9 && kare[9] == '9')
            kare[9] = isaret;

        else
        {
            printf("Gecersiz karakter girdiniz... ");

            Oyuncu--;
            getch();
        }
        i = kazanan_kontrolu();

        Oyuncu++;
    }while (i ==  - 1);

    oyun_tahtasi();

    if (i == 1){
        printf("==>\a%d. Oyuncu kazandi.\n ", --Oyuncu);
        if (Oyuncu==1){
            sk1++;

        }
        else{
                sk2++;
        };

    }
    else
        printf("==>\aOyun Berabere.\n");

    struct skor oyun={sk1,sk2};
    printf("\n1. Oyuncunun Skoru: %d\n2. Oyuncunun Skoru:%d\n",oyun.Oyuncu1Skoru,oyun.Oyuncu2Skoru);

    printf("Devam etmek istiyor musunuz? (Devam etmek icin 1'e basin):");
    scanf("%d",&devam);
    if(devam==1){
        kare[1] = '1';
        kare[2] = '2';
        kare[3] = '3';
        kare[4] = '4';
        kare[5] = '5';
        kare[6] = '6';
        kare[7] = '7';
        kare[8] = '8';
        kare[9] = '9';
        continue;
    }
    else
        { break;
    };
}



    return 0;
}



int kazanan_kontrolu()
{
    if (kare[1] == kare[2] && kare[2] == kare[3])
        return 1;

    else if (kare[4] == kare[5] && kare[5] == kare[6])
        return 1;

    else if (kare[7] == kare[8] && kare[8] == kare[9])
        return 1;

    else if (kare[1] == kare[4] && kare[4] == kare[7])
        return 1;

    else if (kare[2] == kare[5] && kare[5] == kare[8])
        return 1;

    else if (kare[3] == kare[6] && kare[6] == kare[9])
        return 1;

    else if (kare[1] == kare[5] && kare[5] == kare[9])
        return 1;

    else if (kare[3] == kare[5] && kare[5] == kare[7])
        return 1;

    else if (kare[1] != '1' && kare[2] != '2' && kare[3] != '3' &&
        kare[4] != '4' && kare[5] != '5' && kare[6] != '6' && kare[7]
        != '7' && kare[8] != '8' && kare[9] != '9')

        return 0;
    else
        return  - 1;
}





void oyun_tahtasi()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Oyuncu 1 (X)  -  Oyuncu 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", kare[1], kare[2], kare[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", kare[4], kare[5], kare[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", kare[7], kare[8], kare[9]);

    printf("     |     |     \n\n");
}

