#ifndef Plansza.c
//kolorki na Linuxa
#define KOLKO   ' '//"\x1b[32m"
#define KRZYZYK ' '//"\x1b[34m"
#define RESET   ' '//"\x1b[0m"
#define TLO ' '//"\x1b[0m"
//#define TLO   "\x1b[48;2;139;69;19m"
typedef struct plansza
{
    int rozmiar;
    char* wartosci[169];    //reprezentacja stanu gry
}plansza;
plansza* utworz_plansze(plansza* nowa,int rozmiar){
    plansza* nowa_plansza = (plansza*)malloc(sizeof(plansza));

    nowa_plansza->rozmiar = rozmiar;
    for(int i = 0;i < rozmiar * rozmiar;i++)
        nowa_plansza->wartosci[i] = " ";

    return nowa_plansza;
}
void wypisz(plansza* wejscie,int rozmiar){
    for(int i = 0;i < rozmiar;i++)
        {
                printf("   %c  ",65 + i);
        }
    printf("\n");
    for(int i = 0;i < rozmiar;i++)
        {
            printf(" _____");
        }
    for(int k = 0;k < rozmiar;k++)
    {
        printf("\n|");
        for(int i = 0;i < rozmiar;i++)
        {
            printf("     |");
        }
        printf("\n|");
        for(int i = 0;i < rozmiar;i++)
        {
            if(wejscie->wartosci[k * rozmiar + i] == "O")
                printf("  %s  |",wejscie->wartosci[k * rozmiar + i]);
            else
                printf("  %s  |",wejscie->wartosci[k * rozmiar + i]);
        }
        printf(" %d \n|",1 + k);
        for(int i = 0;i < rozmiar;i++)
        {
            printf("_____|");
        }
    }
    printf("\n\n");
}
#endif
