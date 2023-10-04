#include <stdio.h>

int main(){
  FILE *file;
  char c, str[30], frase[80] = "Este eh um aquivo chamado ";
  char alunos[5][50], mostratxt[50];
  int i, j = 0, cont;

  printf("\tDIGITE UM NOME PARA O ARQUIVO: \n");
  gets(str);

  for(cont = 0; cont < 5; cont ++){
    printf("\nINFORME O NOME DO ALUNO %d: ", cont + 1);
    gets(alunos[cont]);
  }
  if(!(file = fopen(str, "w"))){
    printf("\tERRO! NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
  }
  else{
    for(i = 0; i < 5; i ++){
      strcat(alunos[i], "\n");
      fputs(alunos[i], file);
    }
    fclose(file);
    printf("\tINICIANDO A LEITURA DO ARQUIVO.\n");
    file = fopen(str, "r");
    fgets(mostratxt, 50, file);
    while(!feof(file)){
      printf("%s", mostratxt);
      fgets(mostratxt, 50, file);
    }
    fclose(file);
  }
}