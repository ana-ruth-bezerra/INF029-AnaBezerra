#define p_escola_H
#define p_escola_H

typedef struct dma{
	char dataCompleta[11];
  int dia;
  int mes;
	int ano; 
}Data;

typedef struct dados_aluno{
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  struct dados_aluno *prox;
}Aluno;

typedef struct dados_professor{
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  struct dados_professor *prox;
}Professor;

typedef struct dados_disciplina{
  char nome[50];
  char *codigo;
  char *semestre;
  Professor **professor;
  struct dados_disciplina *prox;
}Disciplina;

int inserirAluno(Aluno** inicio);
int excluirAluno(Aluno** inicio);
void listarAlunos(Aluno** inicio);
int inserirProfessor(Professor** inicio);
int excluirProfessor(Professor** inicio);
void listarProfessor(Professor** inicio);
int inserirDisciplina(Disciplina** inicio);
int excluirDisciplina(Disciplina** inicio);
void listarDisciplina(Disciplina** inicio);
int menuGeral();
int menuAluno();
int menuProfessor();
int menuDisciplina();
int validar_data(char data[]);
int valida_data_numeros(int dia, int mes, int ano);
int geraMatricula();
void finalizarEscola(Aluno* inicio);
void mainAluno(Aluno** inicioListaAluno);
void mainProfessor(Professor** inicioListaProfessor);
void mainDisciplina(Disciplina** inicioListaDisciplina);