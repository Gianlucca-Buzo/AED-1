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

void listar (char* list){
    for (int i = 0; i < strlen(list); i++){

        if(list[i] != ';')
            printf("%c",list[i]);
        else
            printf("\n");  
    }
}

char* remover (char* list, char nome[50]){
    char *list2 = NULL;
    char teste[50];
    int i=0,j=0;
    while(list[i]!= '\0'){
        if (list[i] != ';'){
            teste[j] = list[i];
            i++;
            j++;
        }else{
            teste[strlen(teste)] = '\0';
            if(strcmp(nome,teste)!= 0){
               list2 = insere(list2,teste);
            }
            
            for (int k=0; k<j ;k++)
                teste[k] = '\0';
            j = 0;
            i++;
        }
    
    }
    free(list);
    return list2;
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
        printf("\n");
        listar(list);
        break;
    case 3:
        printf("Digite o nome que deseja remover: ");
        scanf("%s",&nome);
        nome[strlen(nome)] = '\0';
        list = remover(list,nome);
        break;
    case 4:
        printf("Bye");
        free(list);
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