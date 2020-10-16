#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contato{
    char nome[50];
    char telefone[15];
}contato;

typedef struct variaveis{
    int opcao;
    int i;
    int contador;
    int tam;
    int numContatos;
    int posRemove;
    char auxNome[50];
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
    printf("\nAgenda:\n");
    contatos = pBuffer + sizeof(variaveis);
    for(var->i = 0; var->i < var->numContatos; var->i++){
        printf("\nNome: %s",contatos->nome);
        printf("\nTelefone: %s",contatos->telefone);
        contatos++;
    }
    printf("\n");
}

void buscarNome(){
    contatos = pBuffer + sizeof(variaveis);
    var->contador = -1;
    printf("Digite o nome que deseja buscar: ");
    scanf("%s", var->auxNome);
    for(var->i = 0; var->i < var->numContatos; var->i++){
        if(strcmp(var->auxNome,contatos->nome)== 0){
            printf("\nNome: %s  Telefone: %s",contatos->nome,contatos->telefone);
            var->contador++;
        }
        contatos++;
    }
    if(var->contador == -1)
        printf("\nNome nao encontrado na lista");
}

void verificaExiste(){
    var->posRemove = -1;
    contatos = pBuffer + sizeof(variaveis);
    for (var->i = 0; var->i < var->numContatos; var->i++){
        if(strcmp(contatos->nome, var->auxNome)== 0)
            var->posRemove = var->i;
        if(var->i+1 == var->numContatos)
            auxRemove = contatos;
        contatos++;
    }
}

void remover(){
    printf("\nDigite o nome que deseja remover: ");
    scanf("%s",var->auxNome);
    verificaExiste();
    if(var->posRemove != -1){
        contatos = pBuffer + sizeof(variaveis) + sizeof(contato)*var->posRemove;
        strcpy(contatos->nome,auxRemove->nome);
        strcpy(contatos->telefone,auxRemove->telefone);
        var->numContatos--;
        pBuffer = realloc(pBuffer, sizeof(variaveis) + sizeof(contato)* var->numContatos);
        var = pBuffer;
        printf("Nome removido com sucesso");
    }else{
        printf("A agenda nao contem esse nome");
    } 
}

void redireciona(){

    
    scanf("%d",&var->opcao);
    getchar();
    switch (var->opcao)
    {
    case 1:
        insere();
        break;
    case 2:
        imprime();
        break;
    case 3:
        remover();
        break;
    case 4:
        buscarNome();
        break;
    case 5:
        printf("\nBye!\n");
        break;    
    
    default:
        break;
    }
}

void menu(){

    printf("\nOpcoes:");
    printf("\n1-Insere");
    printf("\n2-Listar");
    printf("\n3-Remover");
    printf("\n4-Buscar");
    printf("\n5-Sair\n");
}

int main (){ 
    
    pBuffer = malloc(sizeof(variaveis));
    var = pBuffer;
    var->numContatos = 0;
    var->tam = sizeof(variaveis);
    printf("====Agenda====");
    while (var->opcao != 5){
        menu();
        redireciona();
    }
    free(pBuffer);
    return 0;
}