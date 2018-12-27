#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "forca.h"
int main()
{
    iniciajogo();
    zerap();
    int erros=0,aux,count=0;
    char letra;
    while(erros<6){
        system("cls");
        cenario(erros);
        imprimeinfo(erros,letra);
        fflush(stdin);
        do{
            printf("\nInforme uma letra: ");
            scanf("%c",&letra);
            fflush(stdin);
            letra=toupper(letra);
        }
        while(verifica_Lusadas(letra)!=0);
        letras_usadas[count]=letra;
        system("cls");
        cenario(erros);
        imprimeinfo(erros,letra);
        aux=varre_palavra(letra);
        if(aux==0)
            erros++;
        if(verifica_fim()==1){
            system("cls");
            cenario(erros);
            printf("\n____________________");
            printf("\nVOCE ADIVINHOU !!|\n");
            printf("____________________\n");
            system("pause");
            return 0;
        }
        count++;
    }
    if(erros==6){
        system("cls");
        cenario(erros);
        printf("\nVOCE PERDEU !!!!");
        system("pause");
        return 0;
    }

}
