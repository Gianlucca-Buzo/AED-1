#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contato{
    char nome[50];
    char telefone[15];
}contato;

typedef struct variaveis{
    int i;
    int j;
    int tam;
    int numContatos;
    int posRemove;
    char nomeRemove[50];
} variaveis;

void *pBuffer;
variaveis *var;
contato *contatos;
contato *auxRemove;


void insere(){
    var->numContatos = var->numContatos + 1;
    var->tam = sizeof(variaveis) + sizeof(contato)* var->numContatos;
    pBuffer = realloc(pBuffer, var->tam);
    var = pBuffer;
    contatos = pBuffer + var->tam - sizeof(contato);
    printf("Digite o nome: ");
    scanf("%s",contatos->nome);
    printf("Digite o telefone: ");
    scanf("%s",contatos->telefone);
}

void imprime(){
    printf("\nAgenda:");
    contatos = pBuffer + sizeof(variaveis);
    for(var->i = 0; var->i < var->numContatos; var->i++){
        printf("\nNome: %s",contatos->nome);
        printf("\nTelefone: %s",contatos->telefone);
        contatos++;
    }
}

void remover(){
    printf("\nDigite o nome que deseja remover: ");
    scanf("%s",var->nomeRemove);
    var->posRemove = -1;
    contatos = pBuffer + sizeof(variaveis);
    for (var->i = 0; var->i < var->numContatos; var->i++){
        if(strcmp(contatos->nome, var->nomeRemove)== 0)
            var->posRemove = var->i;
        if(var->i+1 == var->numContatos)
            auxRemove = contatos;
        contatos++;
    }

    if(var->posRemove != -1){
        contatos = pBuffer + sizeof(variaveis) + sizeof(contato)*var->posRemove;
        strcpy(contatos->nome,auxRemove->nome);
        strcpy(contatos->telefone,auxRemove->telefone);
        var->numContatos--;
        pBuffer = realloc(pBuffer, sizeof(variaveis) + sizeof(contato)* var->numContatos);
        var = pBuffer;
        printf("Nome removido cm sucesso");
    }else{
        printf("A agenda nao contem esse nome");
    } 
}



int main (){ 
    
    pBuffer = malloc(sizeof(variaveis));
    var = pBuffer;
    var->numContatos = 0;
    var->tam = sizeof(variaveis);
    insere();
    insere();
    insere();
    imprime();
    remover();
    imprime();


    return 0;
}