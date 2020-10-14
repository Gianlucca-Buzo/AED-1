// #include <stdio.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// int main() {
//     int escolhamenu;
//     char adicionarnome[10];
//     char nomeremover[10];
//     char *nomes = NULL;
//     char *nomesaux = NULL;


//     do{
//         printf("1-Adicionar nome\n");
//         printf("2-Remover nome\n");
//         printf("3-Listar\n");
//         printf("4-Sair\n");
//         scanf("%d", &escolhamenu);

//         switch(escolhamenu){
//             case 1: 
//                 printf("Digite o nome: ");
//                 getchar();
//                 gets(adicionarnome);
//                 int tam2 = 0;
//                 if (nomes == NULL)
//                 { 
//                 nomes = (char*) malloc((strlen(adicionarnome)+2)*sizeof(char)); 
//                 strcpy(nomes, adicionarnome);
//                 tam2 = strlen(nomes);
//                 nomes[tam2] = '!';
//                 nomes[tam2 + 1] = '\0';

//                 }
//                 else{
//                     tam2 = strlen(nomes);
//                     nomes =(char *) realloc(nomes,(strlen(adicionarnome) + tam2 +  2) * (sizeof(char)));
//                     //nomes = (char*) realloc(nomes, (strlen(adicionarnome)+strlen(nomes)+1)*sizeof(char));
//                     strcat(nomes, adicionarnome);
//                     tam2 = strlen(nomes);
//                     nomes[tam2] = '!';
//                     nomes[tam2 +1] = '\0';
//                 }
//                 break;
//             case 2:
//                 printf("\n Qual nome deseja remover?\n");
//                 gets(nomeremover);
//                 for(int i = 0; i<strlen(nomes); i++){


//                 }


//             case 3: puts(adicionarnome);

//     }
//     } while(escolhamenu != 4);

//     free(nomes);

 



//    return 0;
// }