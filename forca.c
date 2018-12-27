#include "forca.h"
#include <stdlib.h>
#include <stdio.h>
int Tamanho(){
    int tamanho;
    for(tamanho=0;palavra[tamanho]!='\0';tamanho++);
    return tamanho;
}
void zerap(){
    int i,tamanho=Tamanho();
    for(i=0;i<tamanho;i++){
        if(palavra[i]==32)
            impalavra[i]=' ';
        else if(palavra[i]==45)
            impalavra[i]='-';
        else
            impalavra[i]='_';
    }
    for(i=0;i<tamanho+7;i++){

        if(i=tamanho+6)
        {
            letras_usadas[i]='\0';

        }

        else
            letras_usadas[i]=' ';
    }
}
void imprime_nomes(){
    printf("\t\t\t_________________________________\n");
    printf("\t\t\t|Marco Antonio de Oliveira Costa|\n");
    printf("\t\t\t|_______________________________|\n");
}

void iniciajogo(){//faz as leituras e inicia
    int i;
    printf("Certifique-se que o outro jogador nao esteja olhando e: \n");
    system("pause");
    system("cls");
    printf("Informe uma palavra: ");
    scanf("%[^\n]s",&palavra);
    fflush(stdin);
    for(i=0;palavra[i]!='\0';i++){//colocar todas as letras sendo maiusculas
        palavra[i]=toupper(palavra[i]);
    }
    printf("Informe uma dica: ");
    scanf("%[^\n]s",&dica);
    system("cls");
}
void cenario(int erros){
    if(erros==0){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |      |\n\t\t\t\t  |\n\t\t\t\t  |\n\t\t\t\t  |\n\t\t\t\t  |\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |\n");
    }
    else if(erros==1){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |      |\n\t\t\t\t  |      O\n\t\t\t\t  |\n\t\t\t\t  |\n\t\t\t\t  |\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");
    }
    else if(erros==2){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |\t |\n\t\t\t\t  |\t O\n\t\t\t\t  |\t |\n\t\t\t\t  |\t |\n\t\t\t\t  |\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");
    }
    else if(erros==3){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |\t |\n\t\t\t\t  |\t O\n\t\t\t\t  |\t/|\n\t\t\t\t  |\t |\n\t\t\t\t  |\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");
    }
    else if(erros==4){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |\t |\n\t\t\t\t  |\t O\n\t\t\t\t  |\t/|\\ \n\t\t\t\t  |\t |\n\t\t\t\t  |\t\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");
    }
    else if(erros==5){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |\t |\n\t\t\t\t  |\t O\n\t\t\t\t  |\t/|\\ \n\t\t\t\t  |\t |\n\t\t\t\t  |\t/\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");
    }
    else if(erros==6){
        imprime_nomes();
        printf("\t\t\t\t  +------+\n\t\t\t\t  |\t |\n\t\t\t\t  |\t O\n\t\t\t\t  |\t/|\\ \n\t\t\t\t  |\t |\n\t\t\t\t  |\t/ \\\n\t\t\t\t  |");
        printf("\n\t\t\t\t+----+-------+\n\t\t\t\t|            |");

    }

}
int varre_palavra(char letra){
    int i,tamanho=Tamanho(),count=0;
    for(i=0;i<tamanho;i++){
        if(letra==palavra[i]){
            impalavra[i]=letra;
            count++;
        }
    }
    if(count!=0)
        return 1;
    else
        return 0;
}
void imprime_palavra(){
    int i,tamanho=Tamanho();
    for(i=0;i<tamanho;i++){
        printf("%c  ",impalavra[i]);
    }
}
void imprime_Lusadas(){
    int i;
    for(i=0;i<strlen(letras_usadas);i++){
        if(letras_usadas[i]!=' ')
            printf("%c,",letras_usadas[i]);
        else
            printf(" ");
    }

}
int verifica_Lusadas(char letra){
    int i;
    if(letra==2)
        return 1;
    for(i=0;letras_usadas[i]!='\0';i++){
        if(letras_usadas[i]==letra)
            return 1;
    }
    return 0;
}
void imprimeinfo(int erros,char letra){
    int tamanho=Tamanho();
    printf("\n\nPalavra(%d letras):\n",tamanho);
    imprime_palavra();
    printf("\n\nDica: %s\n",dica);
    printf("Letras ja usadas: ");
    printf("{");
    imprime_Lusadas(letra);
    printf("}");
}
int verifica_fim(){
    int i,tamanho=Tamanho();
    for(i=0;i<tamanho;i++){
        if(impalavra[i]=='_')
            return 0;
    }
    return 1;
}
