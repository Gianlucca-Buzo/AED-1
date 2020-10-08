#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu (){
    printf("\nMenu:\n");
    printf("1.Adicionar:\n");
    printf("2.Listar:\n");
    printf("3.Remover:\n");
    printf("4.Sair:\n");
}

char *insere (char* list, char nome[50]){
    int tam = strlen(nome);
    if (list == NULL){
        list = (char*) malloc((strlen(nome) + 2) * (sizeof(char)));
        strcpy(list, nome);
        list[tam] = ';';
        list[tam + 1] = '\0';
    }else
    {
        int tam2 = strlen(list);
        list =(char *) realloc(list,(strlen(nome) + tam2 +  2) * (sizeof(char)));
        strcat(list,nome);
        tam2 = strlen(list);
        list[tam2] = ';';
        list[tam2 + 1] = '\0';
        printf("%d",tam2);
    }
    return list;
    
}

char* options(int n, char* list){
    char nome[50];
    char teste;
    switch (n)
    {
    case 1:
        printf("Digite o nome que deseja adicionar: ");
        scanf("%s",&nome);
        nome[strlen(nome)] = '\0';
        list = insere(list,nome);
        break;
    case 2:
        printf("/n");
        break;
    case 3:
        printf("Digite o nome que deseja remover: ");
        break;
    case 4:
        printf("Bye");
        break;
    default:
        printf("Opção inválida, tente novamente");
        break;
    }
    return list;
}

int main (){
    char* list = NULL;
    int n = 0;
    while(n != 4){
        printMenu();
        scanf("%d",&n);
       list = options(n, list);
    }
    return 0;
}