#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[30];
    char telefone[15];
    struct pessoa *next;
    struct pessoa *prev;
}pessoa;

typedef struct TipoFila{
    pessoa contato;
    struct TipoFila *next;
}TipoFila;

typedef struct Sfila{
    TipoFila *pFirst;
    TipoFila *pLast;
}SFila;

typedef struct variaveis{
    int opcao;
    int i;
    int j;
    int contador;
    int numContatos;
    int posRemove;
    char auxNome[30];
    char auxTelefone[15];
    pessoa *auxNext;
} variaveis;

SFila *fila;    
variaveis *var;
void *pBuffer;

void imprimeFila();
void criaFila(pessoa *head);
void Push(pessoa *novo);
void ordenaTelefone(pessoa *head);
void ordenaNome(pessoa *head);
void *inicializa(pessoa *pessoas);
void *insere(pessoa *pessoas);
void imprime(pessoa *pessoas);


int main (){ 
    fila = (SFila *) malloc(sizeof(SFila));
    fila->pFirst =NULL;
    fila->pLast = NULL;
    pessoa *head;
    pessoa *aux;
    TipoFila *auxFila;
    pBuffer = malloc(sizeof(variaveis));
    var = pBuffer;
    var->numContatos = 0;
    var->opcao = 0;
    head = (pessoa *) malloc(sizeof(pessoa));
    head->next = NULL;
    head->prev = NULL;
    while(var->opcao != 4){
    printf("\nMenu: \n1-Inserir\n2-Imprimir\n3-Imprimir Ordenado \n4-Sair\n");
    scanf("%d",&var->opcao);
        switch (var->opcao){
        case 1:
            insere(head);
            break;
        case 2:
            imprime(head);
        break;
        case 3:
            //inicializa(head);
            printf("\nDeseja ordenar por 1-Nome ou 2-Telefone?");
            scanf("%d",&var->i);
            if(var->i == 1 || var->i == 2){
                if(var->i == 1)
                    ordenaNome(head);
                else
                    ordenaTelefone(head);
                criaFila(head);
                imprimeFila();
            }else{
                printf("Opcao Invalida");
            }
            break;
        case 4:
            while(head->next != NULL){
                aux = head;
                head = head->next;
                free(aux);
            }
            free(head);

            while(fila->pFirst != NULL){
                auxFila = fila->pFirst;
                fila->pFirst = fila->pFirst->next;
                free(auxFila);
            }
            free(fila);
            printf("Bye");
        break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    }

    return 0;
}

void imprimeFila(){
    printf("Agenda Ordenada\n");
    for ( TipoFila *i = fila->pFirst; i != NULL; i = i->next){
        printf("Nome: %s Telefone: %s\n",i->contato.nome,i->contato.telefone);
    }
    
}

void criaFila(pessoa *head){
    for (pessoa *i = head->next; i != NULL; i = i->next){
        Push(i);
    }
    
}

void Push(pessoa *novo){

    strcpy(var->auxNome,novo->nome);
    strcpy(var->auxTelefone,novo->telefone);
    TipoFila *novoNodo;
    novoNodo = (TipoFila *) malloc(sizeof(TipoFila));
    strcpy(novoNodo->contato.nome,var->auxNome);
    strcpy(novoNodo->contato.telefone,var->auxTelefone);
    novoNodo->contato = *novo;
    novoNodo->next = NULL;

    if(fila->pFirst != NULL)
        fila->pLast->next = novoNodo;
    else
        fila->pFirst = novoNodo;

    fila->pLast = novoNodo;

}

void ordenaTelefone(pessoa *head){
    if(head->next !=NULL){
    for (pessoa *i = head->next; i->next != NULL; i = i->next){
        pessoa *menor = i;
        for (pessoa *j = i->next; j != NULL; j = j->next){
            if(strcmp(j->telefone,menor->telefone) < 0)
                menor = j;
        }
        
        strcpy(var->auxNome,i->nome);
        strcpy(var->auxTelefone,i->telefone);
        var->auxNext = menor->next;
        strcpy(i->nome,menor->nome);
        strcpy(i->telefone,menor->telefone);
        strcpy(menor->nome,var->auxNome);
        strcpy(menor->telefone,var->auxTelefone);

        }
    }
    else{
        printf("Nao tem contatos para serem ordenados");
    }
}

void ordenaNome(pessoa *head){
    if(head->next!=NULL){
    for (pessoa *i = head->next; i->next != NULL; i = i->next){
        pessoa *menor = i;
        for (pessoa *j = i->next; j != NULL; j = j->next){
            if(strcmp(j->nome,menor->nome) < 0)
                menor = j;
        }
        
        strcpy(var->auxNome,i->nome);
        strcpy(var->auxTelefone,i->telefone);
        var->auxNext = menor->next;
        strcpy(i->nome,menor->nome);
        strcpy(i->telefone,menor->telefone);
        strcpy(menor->nome,var->auxNome);
        strcpy(menor->telefone,var->auxTelefone);

        }
    }
    else{
        printf("Nao tem contatos para serem ordenados");
    }
}

// void *inicializa(pessoa *pessoas){
//     pessoa *contato1;
//     pessoa *contato3;
//     pessoa *contato4;
//     pessoa *contato5;

//     contato1 = (pessoa *) malloc(sizeof(pessoa));
//     contato3 = (pessoa *) malloc(sizeof(pessoa));
//     contato4 = (pessoa *) malloc(sizeof(pessoa));
//     contato5 = (pessoa *) malloc(sizeof(pessoa));

//     pessoas->next = contato1;
//     strcpy(contato1->nome , "Isabela");
//     strcpy(contato1->telefone , "98404272");
//     contato1->prev = pessoas;
//     contato1->next = contato3;
//     strcpy(contato3->nome , "Joaz");
//     strcpy(contato3->telefone, "98123631");
//     contato3->prev = contato1;
//     contato3->next= contato4;
//     strcpy(contato4->nome , "Gianlucca");
//     strcpy(contato4->telefone, "12345");
//     contato4->prev = contato3;
//     contato4->next= contato5;
//     strcpy(contato5->nome , "Enrico");
//     strcpy(contato5->telefone, "678910");
//     contato5->prev = contato4;
//     contato5->next= NULL;
//     var->numContatos = 4;
    
// }

void *insere(pessoa *pessoas){
    if(pessoas != NULL){
        var->numContatos++;
        pessoa *novo, *aux;
        aux = pessoas;
        novo = (pessoa *) malloc(sizeof(pessoa));
        if(novo != NULL){
            printf("Digite o nome da pessoa: ");
            getchar();
            gets(novo->nome);
            printf("Digite o telefone: ");
            gets(novo->telefone);
            novo->next = NULL;

            while(aux->next != NULL)
                aux = aux->next;
            aux->next = novo;
            novo->prev = aux;
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
            printf("Nome: %s Telefone: %s\n",aux->nome,aux->telefone);
            aux = aux->next;
        }   
    }else{
        printf("Não tem nenhuma pessoa na agenda");
    }
    
}