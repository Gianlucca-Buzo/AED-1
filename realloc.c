#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc(void *pont, size_t newSize){
    void *pont2 = malloc(newSize);
    int n = sizeof(pont);
    return memcpy(pont2,pont,n);
}

int main(){
    int *pont;
    int i=0;
    pont =(int *) malloc(sizeof(int));
    printf("%p  %p",&pont,pont);
    pont = realloc(pont, sizeof(int)*2);
    pont[0] = 10;
    pont[1] = 20;
    printf("%d  %d",pont[0],pont[1]);
    return 0;
}