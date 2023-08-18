#include <stdio.h>

int main(){
    printf("Tamanho do vetor: \n");
    int TAM;
    scanf("%d", &TAM);
    int numeros[TAM];
    int soma = 0;
    printf("Digite os valores: \n");
    for(int i = 0; i < TAM; numeros[i++]){
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    printf("VETOR PREENCHIDO: \n\n");
    for(int j = 0; j < TAM; j ++){
        printf("[%d] ", numeros[j]);
        }
        int media = soma / (float) TAM;
        printf("\n\nMEDIA DOS VALORES DO SEU VETOR: \n\n-> %d\n", media);
    return 0;
}