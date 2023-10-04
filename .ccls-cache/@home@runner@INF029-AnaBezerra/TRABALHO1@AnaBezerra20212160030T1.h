// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Ana Ruth Bezerra
//  email: an.bezerra@gmail.com
//  Matrícula: 20212160030
//  Semestre: 2023.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#define AnaBezerra20212160030T1_H
#define AnaBezerra20212160030T1_H

typedef struct DQ{
  int iDia, iMes, iAno, valido; // 0 se inválido, e 1 se válido 
}DataQuebrada;

typedef struct Qtd{
  int qtdDias, qtdMeses, qtdAnos, retorno;
}DiasMesesAnos;

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);
int isBissexto(int ano);
int valida_data_numeros(int dia, int mes, int ano);
int QuantidadeDeDiasMes(int mes, int ano);
int QuantidadeDeDiasMesAnterior(int mes);

//#endif AnaBezerra20212160030T1_H