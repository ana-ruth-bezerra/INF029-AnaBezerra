#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 3
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZA_AL_SUCESS -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUI_ALUNO_SUCESS -6
#define ERRO_CADASTRO_SEXO -7
#define ERRO_DATA_INVALIDA -8

int menuGeral();
int menuAluno();

typedef struct dma {
	char dataCompleta[11];
  int dia;
  int mes;
	int ano; 
} Data;

typedef struct aluno_dados{
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  int ativo;
}Aluno;

int cadastroAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizaAluno(Aluno listaAluno[], int qtdAluno);
int excluiAluno(Aluno listaAluno[], int qtdAluno);
int validar_data(char data[]);
int valida_data_numeros(int dia, int mes, int ano);
int mainAluno(Aluno lista_aluno[], int qtd_alunos);

int main (void){
  Aluno listaAluno[TAM_ALUNO];
  int sair = 0;
  int opcao;
  int qtdAluno = 0;
  while(!sair){
    opcao = menuGeral();
    switch(opcao){
      case 0:{
        sair = 1;
        break;
      }
      case 1:{
        printf("Modulo Aluno\n");
        int sairAluno = 0;
        int opcaoAluno;
        
        while(!sairAluno){
          opcaoAluno = menuAluno();
          switch(opcaoAluno){
            case 0:{
              sairAluno = 1;
              break;
            }
            case 1:{
              int retorno = cadastroAluno(listaAluno, qtdAluno);
              if(retorno == LISTA_CHEIA)
                printf("Lista de alunos cheia.\n");
              else
                if(retorno == MATRICULA_INVALIDA)
                  printf("Matricula Invalida.\n");
              else{
                printf("Cadastro realizado com sucesso.\n");
                qtdAluno++;
              }
              break;
            }
            case 2:{
              listarAluno(listaAluno, qtdAluno);
              break;
            }
            case 3:{
              int retorno = atualizaAluno(listaAluno, qtdAluno);
              switch(retorno){
                case MATRICULA_INVALIDA:{
                  printf("Matricula invalida.\n");
                  break;
                }
                case MATRICULA_INEXISTENTE:{
                  printf("Matricula inexistente.\n");
                  break;
                }
                case ATUALIZA_AL_SUCESS:{
                  printf("Aluno atualizado com sucesso.\n");
                  break;
                }
              }
              break;
            }
            case 4:{
              int retorno = excluiAluno(listaAluno, qtdAluno);
              switch(retorno){
                case MATRICULA_INVALIDA:{
                  printf("Matricula invalida.\n");
                  break;
                }
                case MATRICULA_INEXISTENTE:{
                  printf("Matricula inexistente.\n");
                  break;
                }
                case EXCLUI_ALUNO_SUCESS:{
                  printf("Aluno excluido com sucesso.\n");
                  qtdAluno--;
                  break;
                }
                default:{
                printf("Opcao Invalida\n");
                }
              }
              break;
            }
            default:{
            printf("Opcao Invalida\n");
            }
          }
        }
        break;
      }
      case 2:{
        printf("Modulo Professor\n");
        break;
      }
      case 3:{
        printf("Modulo Disciplinas\n");
        break;
      }
      default:{
        printf("Opcao Invalida\n");
      }
    }
  }
  return 0;
}

int menuGeral(){
  int opcao;
  printf("Projeto Escola\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int menuAluno(){
  int opcaoAluno;
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Aluno\n");
  printf("2 - Listar Aluno\n");
  printf("3 - Atualizar Aluno\n");
  printf("4 - Excluir Aluno\n");
  scanf("%d", &opcaoAluno);
  return opcaoAluno;
}

int cadastroAluno(Aluno listaAluno[TAM_ALUNO], int qtdAluno){
  printf("Cadastrar Aluno\n");
  if(qtdAluno == TAM_ALUNO){
    return LISTA_CHEIA;
  }else{
    printf("Digite a matricula: \n");
    int matricula;
    scanf("%d", &matricula);                
    if(matricula < 0){
      return MATRICULA_INVALIDA;
    }
    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;
    return CAD_ALUNO_SUCESSO;
  }
}

void listarAluno(Aluno listaAluno[], int qtdAluno){
  printf("Listar Aluno\n");
  if(qtdAluno == 0){
    printf("Lista de alunos vazia.\n");
  }else{
    for(int i = 0; i < qtdAluno; i ++){
      if(listaAluno[i].ativo == 1)
        printf("Matricula: %d\n", listaAluno[i].matricula);
    }
  }
}

int atualizaAluno(Aluno listaAluno[], int qtdAluno){
  printf("Atualizar Aluno\n");
  printf("Digite a matricula: \n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if(matricula < 0){
    return MATRICULA_INVALIDA;
  }else{
    for(int i = 0; i < qtdAluno; i ++){
      if(matricula == listaAluno[i].matricula && listaAluno[i].ativo){
        printf("Digite a nova matricula: \n");
        int novaMatricula;
        scanf("%d", &novaMatricula);
        if(novaMatricula < 0){
          return MATRICULA_INVALIDA;
        }  
        listaAluno[i].matricula = novaMatricula;
        achou = 1;
        break;
      }
    }
    if(achou)
      return ATUALIZA_AL_SUCESS;
    else
      return MATRICULA_INEXISTENTE;
  }
}

int excluiAluno(Aluno listaAluno[], int qtdAluno){
  printf("Excluir Aluno\n");
  printf("Digite a matricula: \n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if(matricula < 0){
    return MATRICULA_INVALIDA;
  }else{
    for(int i = 0; i < qtdAluno; i ++){
      if(matricula == listaAluno[i].matricula){
        listaAluno[i].ativo = -1;
        for(int j = i; j < qtdAluno - 1; j++){
          listaAluno[j].matricula = listaAluno[j + 1].matricula;
          listaAluno[j].sexo = listaAluno[j + 1].sexo;
          listaAluno[j].ativo = listaAluno[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if(achou)
      return EXCLUI_ALUNO_SUCESS;
    else
      return MATRICULA_INEXISTENTE;
  }
}

int validar_data(char data[]){ 
  return 1;
  int dia;
  int mes;
  int ano;
  
  char sDia[3];
  char sMes[3];
  char sAno[5];
  
  int i;

  for(i = 0; data[i] != '/' && i < 2; i++){
    sDia[i] = data[i];   
  }
  
  sDia[i] = '\0';
  strcpy(sDia, data);
  int retorno = valida_data_numeros(dia, mes, ano);
  return retorno;
}

int valida_data_numeros(int dia, int mes, int ano){
  return 1;
  if(dia < 1 || dia > 31)
    return 0;
  if(mes < 1 || mes > 12)
    return 0;
  if(ano <= 0)
    return 0;
}