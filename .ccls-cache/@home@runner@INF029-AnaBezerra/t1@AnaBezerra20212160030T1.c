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

#include "AnaBezerra20212160030T1.h"

typedef struct quebraData{
  char dd[3], mm[3], aaaa[5];
  int dia, mes, ano, valido;
}qData;

int isBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

qData quebraData(char data[]){
  qData dq;
  char sDia[3], sMes[3], sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.dia = atoi(sDia);
  dq.mes = atoi(sMes);
  dq.ano = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
  int datavalida = 0;
  int dia, mes, ano;
  
  
  //quebrar a string data em strings sDia, sMes, sAno

  qData dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0)
    return 0;

  if (strlen(data) >= 8) { // Verifica se a data tem pelo menos 8 caracteres (dd/mm/aaaa)
        if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
            if ((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)) {
                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
                    datavalida = 0;
                } else if (mes == 2) {
                    if (isBissexto(ano)) {
                        datavalida = (dia <= 29);
                    } else {
                        datavalida = (dia <= 28);
                    }
                } else {
                    datavalida = 1; // A data é válida
                }
            }
        }
    }

  
  printf("%s\n", data);

  if(datavalida)
    return 1;
  else
    return 0;
}