#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

//Crear Matriz de caracteres
char** crearMatriz(int);
//Inicializar matriz
void initMatriz(char**,int);
//Imprimir Matriz
void printMatriz(char**,int);
//Liberar Matriz
void liberarMatriz(char**&,int);

void validar(char**,int);

int main(){
  int size = -1;
  char** matriz = NULL;
  string fila;
  char cadena[10];

  cout << "Ingrese la primera fila del salón: ";
  cin >> cadena;

  
  for(int i = 0; i < 10; i++){
    cout << cadena[i];
  }

  matriz = crearMatriz(10);
  initMatriz(matriz,10);
  printMatriz(matriz,10);
  liberarMatriz(matriz,10);

  return 0;
}

void validar(char** matriz, int size){
  
  char** nuevaMatriz = crearMatriz(size);
  
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if( j -1 < 0){
        
      }
      if(matriz[i][j+1] == '.' && matriz[i][j] == '.'){
         cout << "seguro";
          nuevaMatriz[i][j] = '.';
      }else{
        nuevaMatriz[i][j] = '^';
      }
    }
  }
  
  

}

//Crear Matriz
char** crearMatriz(int size){
  char** matriz = new char*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new char[size];
  }
  return matriz;
}

//Inicializar matriz
void initMatriz(char** matriz, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      matriz[i][j] = '.';
    }
  }
}

//Imprimir matriz
void printMatriz(char** matriz, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      cout << " " << matriz[i][j];
    }
    cout << endl;
  }  
}

//Liberar matriz
void liberarMatriz(char**& matriz, int size){
  for(int i = 0; i < size; i++){
    delete[] matriz[i];
    matriz[i] = NULL;
  }
  delete[] matriz;
  matriz = NULL;
}
