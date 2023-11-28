#ifndef wpisywanie.c
int pozycja()
{
int pozycja = 0;
int kolumna;
char wiersz;
printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
scanf("%c%d", &wiersz, &kolumna );
getchar();
while(wiersz < 'A'|| wiersz  > 'M' || kolumna < 0 || kolumna > 13)
{
    printf("podano niewlasciwa wartosc kolumny/wiersza\n");
    printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
    scanf("%c%d", &wiersz , &kolumna);
    getchar();
}
pozycja = (wiersz - 'A')*13 + kolumna - 1;
return pozycja;
}
#endif
