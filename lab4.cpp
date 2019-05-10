#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Crear Matriz de caracteres
char** crearMatriz(int);
//Inicializar matriz
void initMatriz(char**,int);
//Imprimir Matriz
void printMatriz(char**,int);
//Liberar Matriz
void liberarMatriz(char**,int);

int main(){

  return 0;
}


//Crear Matriz
char** crearMatriz(int size){
  char** matriz = new char*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new char[size];
  }
}


