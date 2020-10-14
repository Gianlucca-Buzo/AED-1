#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contato{
    char nome[50];
    char telefone[15];
    struct contato *next;
}contato;

typedef struct variaveis{
    int i;
    int j;
    int tam;
    contato *first;
} variaveis;


void *insere(void *pBuffer){
    if (((variaveis *)pBuffer)->first == NULL){
        contato *novoContato;
        novoContato = (contato *) malloc(sizeof(contato *));
        printf("Digite o nome: ");
        scanf("%s",novoContato->nome);
        printf("Digite o telefone: ");
        scanf("%s",novoContato->telefone);
        novoContato->next = NULL;
        //pBuffer = realloc(pBuffer,sizeof(variaveis*)+ sizeof(contato*));
        ((variaveis *)pBuffer)->first = novoContato;
        // printf("Digite o nome: ");
        // scanf("%s",((variaveis *)pBuffer)->first->nome);
        // printf("\nDigite o telefone: ");
        // scanf("%s",((variaveis *)pBuffer)->first->nome);
    }
    return pBuffer;
}

int main (){ 
    variaveis *var;
    var = (variaveis *) malloc(sizeof(variaveis));
    void* pBuffer = NULL;
    var->i = 1;
    var->j = 10;
    var->tam = 0;
    var->first = NULL;
    pBuffer = var;
    pBuffer = insere(pBuffer);
    ((variaveis *)pBuffer)->tam = 20;

    printf("%d",((variaveis *)pBuffer)->i);
    printf("%s",((variaveis *)pBuffer)->first->nome);
    printf("%s",((variaveis *)pBuffer)->first->telefone);

    return 0;
}