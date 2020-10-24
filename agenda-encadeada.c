#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[30];
    int idade;
    int altura;
    struct pessoa *next;
}pessoa;



void *insere(pessoa *pessoas){
    if(pessoas != NULL){
        pessoa *novo, *aux;
        aux = pessoas;
        novo = (pessoa *) malloc(sizeof(pessoa));
        if(novo != NULL){
            printf("Digite o nome da pessoa: ");
            scanf("%s", &novo->nome);
            printf("Digite a idade: ");
            scanf("%d", &novo->idade);
            printf("Digite a altura em cm: ");
            scanf("%d", &novo->altura);
            novo->next = NULL;

            while(aux->next != NULL)
                aux = aux->next;
            aux->next = novo;
        }else{
            printf("Erro de alocacao! ");
        }
    }else{
        printf("Erro de alocacao");
    }
    
}

void imprime(pessoa *pessoas){
    pessoa *aux;
    aux = pessoas;

    if(aux->next != NULL){
        aux = aux->next;
        printf("==== Agenda ====\n");
        while (aux != NULL){
            printf("Nome: %s Idade : %d Altura: %d\n",aux->nome,aux->idade,aux->altura);
            aux = aux->next;
        }
        
    }else{
        printf("Não tem nenhuma pessoa na agenda");
    }
    
}

int main (){ 
    pessoa *head;
    pessoa *aux;
    head = (pessoa *) malloc(sizeof(pessoa));
    head->next = NULL;
    int n = 0;
    while(n != 2){
    printf("\nMenu: \n1-Inserir\n2-Sair\n");
    scanf("%d",&n);
        switch (n){
        case 1:
            insere(head);
            break;
        case 2:
            imprime(head);
            while(head->next != NULL){
                aux = head->next;
                free(head);
                head = aux;
            }
            free(head);
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }

    return 0;
}