#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int **criaMatriz(int m, int n);
void leiaMatriz(int **mat,int m , int n);
int somaMatriz(int **mat,int m, int n);
int *colunaMatriz(int **mat,int m, int n, int nColuna);
void liberaMatriz(int **mat, int nColuna);
void imprimeMatriz(int **mat,int m, int n);
void imprimeVetor(int *vet, int n);
void esvaziar(int **vet,int linhas);


int main (){
    int **M = NULL;
    int linhas,colunas,i,n=0;    
    
    while(n!= 6){
        printf("\nMenu:\n1-Criar ou Refatorar\n2-Inserir dados\n3-Soma\n4-Imprime Vetor\n5-Imprimir Matriz\n6-Sair\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            esvaziar(M,linhas);
            printf("Digite as dimencoes da matriz: \n");
            scanf("%d%d",&linhas,&colunas);
            M = criaMatriz(linhas,colunas);
            break;
        case 2:
            leiaMatriz(M,linhas,colunas);
            break;
        case 3:
            printf("A soma da matriz é: %d",somaMatriz(M,linhas,colunas));
            break;
        case 4:
            printf("Digite a coluna que deseja imprimir: ");
            scanf("%d",&i);
            imprimeVetor(colunaMatriz(M,linhas,colunas,i-1),linhas);
            break;
        case 5:
            imprimeMatriz(M,linhas,colunas);
            break;
        case 6:
            esvaziar(M,linhas);
            printf("Bye!");
            break;       
        default:
            printf("Opcao invalida, tente novamente");
            break;
        }
    } 
    return 0;
}

int **criaMatriz(int m, int n){
    int **M;
    int i;  
    M = (int **) malloc( sizeof(int*) * m);
    for (i = 0; i < m; i++){
        M[i] = (int *) malloc( sizeof(int*) * n);
    }

    return M;
}

void leiaMatriz(int **mat,int m , int n){

    for (int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            printf("\nValor da posicao [%d,%d]",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }  
    }
    
}

int somaMatriz(int **mat,int m, int n){
    int soma = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            soma += mat[i][j];
    }
    return soma; 
}

int *colunaMatriz(int **mat,int m, int n, int nColuna){
    int *vetor;
    int j = 0;
    vetor = (int *) malloc(sizeof(int)* m);
    if(vetor != NULL){
    for (int i=0; i< m; i++){
        vetor[j] = mat[i][nColuna];
        j++;
        }
    }else
        printf("Erro de alocacao");
    return vetor;
}

void imprimeMatriz(int **mat,int m, int n){

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("| %d |",mat[i][j]);
        }
        printf("\n-----------------------\n");
    }
    
}

void imprimeVetor(int *vet, int n){
    printf("\n");
    for (int i = 0; i<n; i++)
        printf("|%d|\n",vet[i]);
    free(vet);
}

void esvaziar(int **mat,int linhas){
    if(mat != NULL){
        for (int i = 0; i < linhas; i++)
            free(mat[i]);
        free(mat);
    }
}

