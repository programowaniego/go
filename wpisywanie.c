#ifndef wpisywanie.c
int pozycja(char kolumna , char wiersz)
{
int pozycja = 0;
printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
scanf("%c%d", &kolumna , &wiersz);
getchar();
 while(kolumna < 'A'|| kolumna  > 'M' || wiersz < 0 || wiersz > 13)
    {
        printf("podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
        scanf("%c%d", &kolumna , &wiersz);
        getchar();
    }
    pozycja = (wiersz - 1)*13 + kolumna - 'A';
    return pozycja;
}
#endif
