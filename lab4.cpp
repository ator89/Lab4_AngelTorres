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

//Menu principal
void menu();

int main(){
  bool menuActivo = true;
  int opcionMenu = -1;

  int size = -1;
  int cantidadFilas = 0;

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

          cout << "Ingrese la cantidad de filas: ";
          cin >> cantidadFilas;

          cout << endl;

          size = primeraFila.length();


          matriz = crearMatriz(size);
          initMatriz(matriz,size,primeraFila);
          printMatriz(matriz,size);
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
  char** nuMatriz = crearMatriz(size);

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      matriz[i][j] = fila[i];

      if(fila[i] == '.' && fila[i+1] == '.' ){
      for(int t = 0; t < size; t++){
        matriz[i][j] = 'x';
      }}

    }
  }

  for(int i = 0; i < size; i++){
    if(fila[i] == '.' && fila[i+1] == '.'){
      for(int j = 0; j < size; j++ ){
        for(int k = 0; k < size; k++){
          matriz[i][j] = '.';
        }
      }
    }//end if
  }//end for i
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

void menu(){
  cout << "\t\nMENU\n\n"
      << "1 - Ejercicio Trampas\n"
      << "0 - Salir\n"
      << "Seleccione: ";
}
