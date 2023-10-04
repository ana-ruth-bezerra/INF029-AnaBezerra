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
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "AnaBezerra20212160030T1.h"

int isBissexto(int ano){
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int valida_data_numeros(int dia, int mes, int ano){
  if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano <= 0)
    return 0;
  if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    return 0;
  if(mes == 2){
    if(isBissexto(ano)){
      if(dia > 29)
        return 0;
    }else{
      if(dia > 28)
        return 0;
    }
  }
  return 1;
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3], sMes[3], sAno[5];
  int i;

  for(i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];
  }
  if(i == 1 || i == 2){
    sDia[i] = '\0';
  }else{
    dq.valido = 0;
    return dq;
  }

  int j = i + 1;
  i = 0;

  for(; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){
    sMes[i] = '\0';
  }else{
    dq.valido = 0;
    return dq;
  }

  j = j + 1;
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){
    sAno[i] = '\0';
  }else{
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = valida_data_numeros(dq.iDia, dq.iMes, dq.iAno);

  return dq;
}

int q1(char data[]){
  DataQuebrada dataQuebrada = quebraData(data);
  
  if(dataQuebrada.valido)
    return 1;
  else
    return 0;
}

int QuantidadeDeDiasMes(int mes, int ano){
  int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(mes == 2 && isBissexto(ano)){
    return 29;
  }else{
    return diasPorMes[mes];
  }
}

int QuantidadeDeDiasMesAnterior(int mes){
  if(mes < 1 || mes > 12){
    return -1;
  }
  
  int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  return diasPorMes[mes - 1];
}

DiasMesesAnos q2(char datainicial[], char datafinal[]){
  DiasMesesAnos dma;

  int iDiaInicial, iMesInicial, iAnoInicial;
  int iDiaFinal, iMesFinal, iAnoFinal;

  if(sscanf(datainicial, "%d/%d/%d", &iDiaInicial, &iMesInicial, &iAnoInicial) != 3 || 
  sscanf(datafinal, "%d/%d/%d", &iDiaFinal, &iMesFinal, &iAnoFinal) != 3){
    dma.retorno = 2;
    return dma;
  }

  if(q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }
  if(q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }
  if(iAnoFinal < iAnoInicial || (iAnoFinal == iAnoInicial && iMesFinal < iMesInicial) ||
  (iAnoFinal == iAnoInicial && iMesFinal == iMesInicial && iDiaFinal < iDiaInicial)){
    dma.retorno = 4;
    return dma;
  }

  dma.qtdAnos = iAnoFinal - iAnoInicial;
  dma.qtdMeses = iMesFinal - iMesInicial;
  dma.qtdDias = iDiaFinal - iDiaInicial;

  if(dma.qtdMeses < 0){
    dma.qtdAnos--;
    dma.qtdMeses += 12;
  }
  if(dma.qtdDias < 0){
    dma.qtdMeses--;
    int diasNoMesAnterior = 31;
    dma.qtdDias += diasNoMesAnterior;
  }

  dma.retorno = 1;
  return dma;
}

int q3(char texto[], char c, int isCaseSensitive){
  int qtdOcorrencias = 0;
  int i;

  if(!isCaseSensitive){
    if(c >= 'A' && c <= 'Z'){
      c = c - 'A' + 'a';
    }
  }

  int len = strlen(texto);

  for(i = 0; i < len; i++){
    char currentChar = texto[i];

    if(!isCaseSensitive){
      if(currentChar >= 'A' && currentChar <= 'Z'){
        currentChar = currentChar - 'A' + 'a';
      }
    }

    if(currentChar == c){
      qtdOcorrencias++;
    }
  }

  return qtdOcorrencias;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
  int qtdOcorrencias = 0;
  int tamTexto = strlen(strTexto);
  int tamBusca = strlen(strBusca);

  for(int i = 0; i <= tamTexto - tamBusca; i++){
    int j;
    bool encontrou = true;

    for(j = 0; j < tamBusca; j++){
      char charTexto = strTexto[i + j];
      char charBusca = strBusca[j];

      if(charTexto >= 'A' && charTexto <= 'Z'){
        charTexto = charTexto - 'A' + 'a';
      }
      
      if(charBusca >= 'A' && charBusca <= 'Z'){
        charBusca = charBusca - 'A' + 'a';
      }

      if(charTexto != charBusca){
        encontrou = false;
        break;
      }
    }

    if(encontrou){
      posicoes[qtdOcorrencias * 2] = i + 1;
      posicoes[qtdOcorrencias * 2 + 1] = i + tamBusca;
      qtdOcorrencias++;
      i += tamBusca - 1;
    }
  }

  return qtdOcorrencias;
}

int q5(int num) {
    int N = 0;
    
    while (num > 0) {
        int digito = num % 10;
        N = N * 10 + digito;
        num /= 10;
    }
    
    return N;
}

int q6(int numerobase, int numerobusca){
  int qtdOcorrencias = 0;
  int K = numerobase;
  int N = numerobusca;

  if(N == 0){
    if (K == 0){
      return 1;
    }else{
      return 0;
    }
  }

  if(K == 0){
    return 0;
  }

  while(K > 0){
    int tempK = K;
    int tempN = N;
    int ocorrenciaEncontrada = 1;

    while(tempN > 0){
      int digitoK = tempK % 10;
      int digitoN = tempN % 10;
      tempK /= 10;
      tempN /= 10;

      if(digitoK != digitoN){
        ocorrenciaEncontrada = 0;
        break;
      }
    }

    if(ocorrenciaEncontrada){
      qtdOcorrencias++;
    }

    K /= 10;
  }

  return qtdOcorrencias;
}