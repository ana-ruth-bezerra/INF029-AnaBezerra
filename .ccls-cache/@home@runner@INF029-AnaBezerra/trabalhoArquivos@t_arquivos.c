#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct dados{
  char Nome[50];
  char Sexo;
  int Idade;
  int Matricula;
  int CPF;
}Aluno;

void leDadosAluno();
void imprimeListaAluno();

int main(){
  leDadosAluno();
  imprimeListaAluno();
}

void leDadosAluno(){
  Aluno Registro[MAX];
  int i;
  for(i = 0; i < MAX; i++){
    printf("\tAluno %d\n", i + 1);
    printf("Nome: ");
    fgets(Registro[i].Nome, 50, stdin);
    printf("Sexo: ");
    scanf(" %c", &Registro[i].Sexo);
    printf("Idade: ");
    scanf("%d", &Registro[i].Idade);
    printf("Matricula: ");
    scanf("%d", &Registro[i].Matricula);
    printf("CPF: ");
    scanf("%d", &Registro[i].CPF);
    getchar();
  }
}

void imprimeListaAluno(){
  Aluno Registro[MAX];
  int i;
  printf("\tLISTA DE ALUNOS: \n");
  for(i = 0; i < MAX; i++){
    printf("\tAluno %d", i + 1);
    printf("\nNome: %s", Registro[i].Nome);
    printf("Sexo: %c\n", Registro[i].Sexo);
    printf("Idade: %d\n", Registro[i].Idade);
    printf("Matricula: %d\n", Registro[i].Matricula);
    printf("CPF: %d\n", Registro[i].CPF);
  }
}