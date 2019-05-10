#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

//Crear Matriz de caracteres
char** crearMatriz(int,int);
//Inicializar matriz
void initMatriz(char**,int,int);
//Imprimir Matriz
void printMatriz(char**,int,int);
//Liberar Matriz
void liberarMatriz(char**&,int);

void resolver(char**,int,int);

//Menu principal
void menu();

int main(){
  bool menuActivo = true;
  int opcionMenu = -1;

  int size = -1;
  int columnas = 0;

  char** matriz = NULL;

  string primeraFila;

  while(menuActivo){
    do{
      menu();
      cin >> opcionMenu;
      switch (opcionMenu) {
        case 1:{//Ejercicio 1
          cout << "Ingrese la primera fila del salón: ";
          cin >> primeraFila;

          cout << "Ingrese la cantidad de columnas: ";
          cin >> columnas;

          cout << endl;

          size = primeraFila.length();


          matriz = crearMatriz(size,columnas);
          initMatriz(matriz,size,columnas);
          //resolver(matriz,size,columnas);
          printMatriz(matriz,size,columnas);
        }
        break;
        case 0://Salir
        break;
        default:
          cout << "Ingrse una opción del menú.\n\n";
        break;
      }
    }while(opcionMenu != 0);
    menuActivo = false;
  }//Salida while del menú principal

  liberarMatriz(matriz,size);

  return 0;
}

//Resolver ejercicio #1
void resolver(char** matriz, int size, int columnas){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < columnas; j++){
      if (j != 0 || j != columnas - 1){
          if (matriz[i-1][j] == '^' && matriz[i-1][j-1] == '^' && matriz[i-1][j+1] == '.'){
              matriz[i][j] = '^';
          }

      }
      if (j == 0 || j == columnas - 1){
          if (j == 0){
              if (matriz[i-1][j] == '^' && matriz[i-1][j+1] == '^'){
                matriz[i][j] = '^';
              }
          }
          if (j == columnas - 1){
              if (matriz[i -1][j] == '^' && matriz[i-1][j-1] == '^'){
                matriz[i][j] = '^';
              }
          }
      }
    }
  }

}

//Crear Matriz
char** crearMatriz(int size, int columnas){
  char** matriz = new char*[size];
  for(int i = 0; i < size; i++){
    matriz[i] = new char[columnas];
  }
  return matriz;
}


//Inicializar matriz
void initMatriz(char** matriz, int size, int columnas){
  //char** nuMatriz = crearMatriz(size);
  //Inicializar azulejos
  for(int i = 0; i < size; i++){
    for(int j = 0; j < columnas; j++){
      matriz[i][j] = '.';
    }
  }
}



//Imprimir matriz
void printMatriz(char** matriz, int size, int columnas){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < columnas; j++){
      cout << " " << matriz[i][j];
    }
    cout << endl;
  }
}


//Liberar matriz
void liberarMatriz(char**& matriz, int columnas){
  for(int i = 0; i < columnas; i++){
    delete[] matriz[i];
    matriz[i] = NULL;
  }
  delete[] matriz;
  matriz = NULL;
}

void menu(){
  cout << "\t\nMENU\n\n"
      << "1 - Ejercicio Trampas\n"
      << "0 - Salir\n"
      << "Seleccione: ";
}
