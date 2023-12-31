#include<stdio.h>
#include<stdlib.h>
#include "Plansza.c"
#include "wpisywanie.c"
int oddechy(plansza* stol,int pole,int rozmiar){    //oddechy pojedynczego pionka
    int oddechy = 4;
    if(pole % rozmiar != rozmiar - 1){  //Sprawdzanie czy nie jest przy prawej krawędzi
        
        if(stol->wartosci[pole + 1] != " ")
            oddechy -= 1;
        }
        
    else
        oddechy -= 1;
    
    if(pole % rozmiar != 0){    //Sprawdzanie czy nie jest przy lewej krawędzi
        
        if(stol->wartosci[pole - 1] != " ")
            oddechy -= 1;
    }
    
    else
        oddechy -= 1;
        
    if(pole >= rozmiar){    //Sprawdzanie czy nie jest przy górnej krawędzi
        
        if(stol->wartosci[pole - rozmiar] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;
    
    if(pole < rozmiar * (rozmiar - 1)){ //Sprawdzanie czy nie jest przy dolnej krawędzi
            
            if(stol->wartosci[pole + rozmiar] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;

    return oddechy;
}
int liczenie_oddechow_grupy(plansza* stol,int rozmiar,int pole,int* sprawdzone,int oddechy_grupy)
{
    int dodatki[] = {1,-1,13,-13};
    if(stol->wartosci[pole] != " " && sprawdzone[pole] == 0){
        oddechy_grupy += oddechy(stol,pole,rozmiar);
        sprawdzone[pole] = 1;
        for(int i = 0;i < 4;i++){
            if(stol->wartosci[pole] == stol->wartosci[pole + dodatki[i]] && sprawdzone[pole + dodatki[i]] == 0){    //znalazl brachola
                oddechy_grupy += liczenie_oddechow_grupy(stol,rozmiar,pole + dodatki[i],sprawdzone,oddechy_grupy);
            }
        } 
        return oddechy_grupy;
    }
}

int postaw_pionek(plansza* stol,int rozmiar,int pole,char* gracz[2])
{
    if(stol->wartosci[pole] == " "){
        stol->wartosci[pole] = gracz;  
        for(int i = 0;i < rozmiar * rozmiar + 1;i++){
            int sprawdzone [169] = {};     //wskażnik musi być bo wywala błąd, sprawdzone to lista po to zeby nie chodził w kółko w grupie, zerowanie listy co fora
            if(i == rozmair * rozmiar ? stol->wartosci[pole] != " " && liczenie_oddechow_grupy(stol,rozmiar,pole,sprawdzone,0) == 0 : stol->wartosci[i] != " " && liczenie_oddechow_grupy(stol,rozmiar,i,sprawdzone,0) == 0 && i != pole){  //grupa nie ma oddechow
                for(int j = 0;j < rozmiar * rozmiar;j++){
                    if(sprawdzone[j] == 1){
                        printf("zniszczono %s %d",stol->wartosci[j],j);
                        stol->wartosci[j] = " ";
                        sprawdzone[j] = 0;
                    }
                }
            }
        }
        wypisz(stol,13);
    }
}
void losowo(plansza* stol,char gracz[1]){   //stawianie pionka w losowym miejscu
    int pole = rand() % 169;
    if(stol->wartosci[pole] == " ")
        
        postaw_pionek(stol,13,pole,gracz);
    
    else
    
        losowo(stol,gracz);
    
    
}
int dostepne_ruchy(plansza* stol)//tablica ruchow trzeba zrobic
{
    int ruchy[169] = {};
    int k = 0;
    for(int i = 0;i < 169;i++){
        if(stol->wartosci[i] = " ");
            ruchy[k] = i;
            k++;
    }
}
char* tura(i){
    if(i % 2 == 0)
        return "X";
    else
        return "O";
    
}
void main()
{
    srand(time(NULL));
    plansza* stol = utworz_plansze(stol,13);
    for(int i = 1;i <= 169;i++)
        postaw_pionek(stol,13,pozycja(),tura(i));//warunek na puste pole
        
    
}
    
