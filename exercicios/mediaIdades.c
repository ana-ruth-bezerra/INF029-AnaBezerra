#include <stdio.h>

int main(){
    printf("Quantas idades vc quer comparar? \n");
    int TAM;
    scanf("%d", &TAM);
    int numeros[TAM];
    int soma = 0;
    int maior = 0;
    int maiorMedia = 0;
    int i;
    printf("Digite os valores: \n");
    for(i = 0; i < TAM; i++){
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    printf("\nIDADES ESCOLHIDAS: \n\n");
    for(int j = 0; j < TAM; j ++){
        printf("[%d] ", numeros[j]);
        }
    int media = soma / (float) TAM;
    printf("\n\nMEDIA DAS IDADES: \n\n[%d]\n\n", media);
    for(i = 0; i < TAM; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
    }
    printf("MAIOR:\n\n[%d]\n", maior);
    printf("\nIDADES MAIORES DO QUE A MEDIA DE IDADES: \n\n");
    for(i = 0; i < TAM; i ++){
        if(numeros[i] >= media){
            maiorMedia = numeros[i];
            printf("[%d] ", maiorMedia);
        }
    }
    printf("\n\n");
}