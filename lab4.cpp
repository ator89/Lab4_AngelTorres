#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

//Crear Matriz de caracteres
char** crearMatriz(int);
//Inicializar matriz
void initMatriz(char**,int,string);
//Imprimir Matriz
void printMatriz(char**,int);
//Liberar Matriz
void liberarMatriz(char**&,int);

void validar(char**,int);

int main(){
  int size = -1;
  int length = 0;
  
  char** matriz = NULL;
  
  string fila;

  cout << "Ingrese la primera fila del salón: ";
  cin >> fila;
  
  cout << endl;

  size = fila.length();


  matriz = crearMatriz(size);
  initMatriz(matriz,size,fila);
  printMatriz(matriz,size);
  liberarMatriz(matriz,size);

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
void initMatriz(char** matriz, int size, string fila){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      //matriz[i][j] = fila[i];
    }
  }

  for(int i = 0; i < size; i++){
    if(fila[i] == '.' && fila[i+1] == '.'){
      cout << "Seguro\n";
      matriz[i][i++] = 'o';
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
