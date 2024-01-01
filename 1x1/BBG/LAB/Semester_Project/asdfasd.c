#include <stdio.h> /// KUSURSUZ CODE
#include <stdlib.h>
#include <time.h>
void printboard(int x, int y, int matris[][y])
{
    printf("Tahta : \n");
    int i;
    int j;
    for (i = 1; i < y + 1; i++)
    {
        printf("| %d ", i);
    }
    printf("|");
    printf("\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("| %d ", matris[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int i = 0;
    int j = 0;
    int k = 0;
    // MENÜ
    char secim[2]; // Char dizisi en az 2 elemanlı olmalı
    char nickname[20] = "Misafir Oyuncu";
    int basla = 0;
    int highscore[2];
    int quit = 0;
    do
    {
        while (basla == 0)
        {
            printf(" Oyna\n");
            printf(" Nickname girin: \n");
            printf(" Bilgi\n");
            printf(" Cikis\nTercihinizi yapiniz :");
            scanf("%s", secim);

            if (secim[0] == 'C' || secim[0] == 'c')
            {
                return 0;
            }
            else if (secim[0] == 'O' || secim[0] == 'o')
            {
                printf("Oyun Basliyor\n");
                basla = 1;
            }
            else if (secim[0] == 'B' || secim[0] == 'b')
            {
                printf("Oyunun amaci bloklari en alt satira kadar indirmek ve ayni satirdaki elemanlarin hepsini 1 yapmaktir\n");
                printf("Her satir 1 ile doldugunda satir patlar ve patladiginda satir uzunlugu kadar puan kazanirsiniz\n");
                printf("Oyun bittiginde en yuksek puani alan oyuncu kazanmis olur\n");
                printf("Blokunuzu yerlestirirken blokun en sol ust kosesinin X kordinatini yerlestirin\n");
                printf("Menuye donuldu\n");
            }
            else if (secim[0] == 'N' || secim[0] == 'n')
            {
                printf("Nickname : \n");
                scanf("%s", nickname);
                printf("Nickname tercihiniz kaydedildi. Menuye donuldu\n");
            }
        }
        // tahta boyutunu alma
        int bsizex;
        int bsizey;
        printf("HOSGELDINIZ %s\nEglenceye hazir miyiz? ", nickname);
        printf("Minimum 5x5 Maximum 10x10 olacak sekilde tahtanin boyutlarini giriniz\nX: ");
        do
        {
            scanf("%d", &bsizey);
        } while (bsizey < 5 || bsizey > 10);
        do
        {
            printf("Y: ");
            scanf("%d", &bsizex);
        } while (bsizex < 5 || bsizex > 10);
        // tahtada fazladan 1 satir olusturduk
        int board[bsizex + 1][bsizey];
        // tahtanin her elemanini 0 yapma
        for (i = 0; i < bsizex + 1; i++)
        {
            for (j = 0; j < bsizey + 2; j++)
            {
                board[i][j] = 0;
            }
        }
        // tahtanin en alttan bir alt satırını bir yapma
        for (i = 0; i < bsizey + 1; i++)
        {
            board[bsizex][i] = 1;
        }
        printboard(bsizex, bsizey, board);
        // OYUN BASLIYOR
        int gameover = 0;
        int dead = 0;
        int score = 0;
        do
        {
            // rastgele blok boyutunun sayisini uretme
            int bloksize = rand() % (4) + 1;
            int blok[4][4];
            for (int i = 0; i < bloksize; i++)
            {
                for (int j = 0; j < bloksize; j++)
                {
                    blok[i][j] = 0;
                }
            }

            // rastgele blok uretme
            int a = 0;
            int x = 0;
            int y = 0;
            blok[x][y] = 1;
            while (a < bloksize - 1)
            {
                int grow = rand() % 4;

                if (grow == 0)
                {
                    x++;
                    blok[x][y] = 1;
                    a++;
                }
                else if (grow == 1)
                {
                    y++;
                    blok[x][y] = 1;
                    a++;
                }

                else if (grow == 2 && y != 0 && blok[x][y - 1] == 0)
                {
                    y--;
                    blok[x][y] = 1;
                    a++;
                }
                else if (grow == 3 && x != 0 && blok[x - 1][y] == 0)
                {
                    x--;
                    blok[x][y] = 1;
                    a++;
                }
            }

            // kullaniciya bloku gosterme
            printf("blok : \n");
            for (i = 0; i < bloksize; i++)
            {
                for (j = 0; j < bloksize; j++)
                {
                    if (blok[i][j] == 1)
                        printf("%d ", blok[i][j]);
                    else
                        printf("  ");
                }
                printf("\n");
            }
            // bloktaki 1 lerin sayisini bulma
            int ones = 0;
            for (i = 0; i < bloksize; i++)
            {
                for (j = 0; j < bloksize; j++)
                {
                    if (blok[i][j] == 1)
                    {
                        ones++;
                    }
                }
            }
            int rotate = 0;

            // blokun yönünü değiştirme   once transpoze sonra reverse
            if (ones > 1)
            {
                printf("kac kere 90 derece dondurmek istiyorsunuz?");
                scanf("%d", &rotate);
            }
            if (rotate > 0)
            {
                for (k = 0; k < rotate; k++)
                {
                    // transpoze
                    int newblok[4][4];
                    for (i = 0; i < bloksize; i++)
                    {
                        for (j = 0; j < bloksize; j++)
                        {
                            newblok[j][i] = blok[i][j];
                        }
                    }
                    // reverse
                    for (i = 0; i < bloksize; i++)
                    {
                        int a = 0;
                        for (j = bloksize - 1; -1 < j; j--)
                        {
                            blok[i][j] = newblok[i][a];
                            a++;
                        }
                    }
                }
            }
            // bloku sol üste alma
            int silrow = 0;
            int silcol = 0;
            int toplamrow = 0;
            int toplamcol = 0;
            i = 0;
            if (rotate > 0 && blok[0][0] == 0)
            {
                while (i < bloksize && toplamcol == 0)
                {
                    j = 0;
                    while (j < bloksize && toplamcol == 0)
                    {
                        toplamcol = toplamcol + blok[j][i];
                        j++;
                    }
                    if (toplamcol == 0)
                    {
                        silcol++;
                    }
                    i++;
                }
                i = 0;
                while (i < bloksize && toplamrow == 0)
                {
                    j = 0;
                    while (j < bloksize && toplamrow == 0)
                    {
                        toplamrow = toplamrow + blok[i][j];
                        j++;
                    }
                    if (toplamrow == 0)
                    {
                        silrow++;
                    }
                    i++;
                }
                // bloku sola alma ve geri kalanı 0 yapma
                for (i = 0; i < bloksize; i++)
                {
                    for (j = 0; j < bloksize; j++)
                    {
                        if (i + silrow < bloksize && j + silcol < bloksize)
                        {
                            if (blok[i + silrow][j + silcol] == 1)
                            {
                                blok[i][j] = blok[i + silrow][j + silcol];
                            }
                            blok[i + silrow][j + silcol] = 0;
                        }
                    }
                }
            }
            // blokun boyutunu en küçük olarak hesaplama
            int bloklastx = 0;
            int bloklasty = 0;
            for (i = 0; i < bloksize; i++)
            {
                for (j = 0; j < bloksize; j++)
                {
                    if (blok[i][j] == 1)
                    {
                        if (bloklasty < j)
                        {
                            bloklasty = j;
                        }
                    }
                    if (blok[i][j] == 1)
                    {
                        if (bloklastx < i)
                        {
                            bloklastx = i;
                        }
                    }
                }
            }
            if (rotate > 0)
            {
                printf("DONDURULMUS BLOK : \n");
                for (i = 0; i < bloklastx + 1; i++)
                {
                    for (j = 0; j < bloklasty + 1; j++)
                    {
                        if (blok[i][j] == 1)
                            printf("%d ", blok[i][j]);
                        else
                            printf("  ");
                    }
                    printf("\n");
                }
            }
            // tahtayı yazdırma
            printboard(bsizex, bsizey, board);
            // bloku tahtada nereye koyacaksin
            int by;
            do
            {
                printf("bloku nereye koymak istersiniz? X kordinatini giriniz :");
                scanf("%d", &by);
                if (by <= 0 || by + bloklasty > bsizey)
                {
                    printf("Tahtanin disina cikamazsiniz\n");
                }
            } while (by <= 0 || by + bloklasty > bsizey);
            by--;
            // en üstten indirmeye başla aynı zamanda yerleşiyor mu kontrol et
            int full = 0;
            int dead = 0;
            int indirrow = 1;
            while (dead == 0 && indirrow <= bsizex + 1)
            {
                for (i = 0; i < bloklastx + 1; i++)
                {
                    for (j = 0; j < bloklasty + 1; j++)
                    {
                        if (board[i + indirrow][j + by] != 0 && blok[i][j] == 1)
                        {
                            dead = 1;
                        }
                    }
                }
                indirrow++;
            }
            indirrow -= 2;
            // bloku tahtaya yerleştirme
            for (i = 0; i < bloklastx + 1; i++)
            {
                for (j = 0; j < bloklasty + 1; j++)
                {
                    if (blok[i][j] == 1)
                    {
                        board[i + indirrow][j + by] = blok[i][j];
                    }
                }
            }
            // tahtayı yazdırma
            printboard(bsizex, bsizey, board);
            // satır tamamlandıysa o satırı sil
            for (i = 0; i < bsizex; i++)
            {
                int tmp = 0;
                for (j = 0; j < bsizey; j++)
                {
                    tmp = tmp + board[i][j];
                }
                if (tmp == bsizey)
                {
                    printf("Satir tamamlandi!! %d.Satir BOOM!!\n", i + 1);
                    for (k = i; k > 0; k--)
                    {
                        for (j = 0; j < bsizey; j++)
                        {
                            board[k][j] = board[k - 1][j];
                        }
                    }
                    for (j = 0; j < bsizey; j++)
                    {
                        board[0][j] = 0;
                    }
                    score = score + bsizey;
                    printboard(bsizex, bsizey, board);
                }
            }
            // OYUN SONLANDİ Mİ
            for (i = 0; i < bsizey; i++)
            {
                if (board[0][i] == 1)
                {
                    full++;
                }
            }
            if (full != 0)
            {
                gameover = 1;
                printf("Oyun bitti\n");
            }
            if (gameover != 1)
            {
                printf("Devam etmek icin 0'a basin. Cikmak icin 1'e basin. ");
                scanf("%d", &gameover);
                highscore[1] = score;
            }
        } while (gameover < 1);
        if (highscore[0] == 0)
        {
            highscore[0] = highscore[1];
        }
        if (highscore[1] >= highscore[0])
        {
            printf("Tebrikler rekoru kirdiniz\n");
            highscore[0] = highscore[1];
        }
        printf("Highscore : %d\n", highscore[0]);
        printf("Your score : %d\n", highscore[1]);
        printf("Yeni oyuna gecmek icin 0'e basin. Cikmak icin 1'e basin.\n");
        scanf("%d", &quit);
    } while (quit < 1);
    return 0;
}