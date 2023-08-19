#include <stdio.h>
float somar(float x, float y);
float multiplicar(float z, float x, float y);
float dividir(float k, float y);

int main(){
  float x, y;
  printf("Digite dois valores: \n");
  scanf("%f%f", &x, &y);
  float m = somar(x, y);
  printf("%f", m);
}

float somar(float x, float y){
  float z = x + y;
  return multiplicar(z, x, y);
}

float multiplicar(float z, float x, float y){
  float k = z * x;
  float r = dividir(k, y);
  return r;
}

float dividir(float k, float y){
  float m = k / y;
  return m;
}