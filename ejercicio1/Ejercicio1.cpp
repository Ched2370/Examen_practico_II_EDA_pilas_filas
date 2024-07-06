#include <iostream>
#include <cstdlib>
#include <ctime>

/* Dadas dos matrices de 4x4, matriz1 y matriz2, y una tercera matriz resultado donde 
almacenaremos la suma de las dos matrices. 
a. Arme la funcion cargarMatrix, recibe una matriz y pide carga de números entre 1 a 10.
b. Armar una a función sumarMatrix recibe las dos matrices de entrada y la matriz de 
resultado, y realiza la suma elemento por elemento, en matriz3.
c. Otro procedimiento imprimirMatrix, usado para imprimir cualquier matriz en la consola.
d. En la función main, debes crear las matrices de ejemplo matriz1 y matriz2, y luego acto 
seguido, imprimimos las tres matrices en la consola con la función imprimirMatrix.
e. Un último proceso recibe la matriz3 resultante, remplaza los elementos pares por su 
valor al cuadrado, luego se reutiliza el procedimiento imprimirMatrix.*/
const int espacio = 4;

void cargarMatrix(int matrix[espacio][espacio]) {
    
    srand(time(0)); // Inicializar con numero aleatorio para las matrices que sean de menores a 10. 
    for (int i = 0; i < espacio; ++i) {
        for (int j = 0; j < espacio; ++j) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
    /*
    //matriz para leerlo paso a paso
     for (int i = 0; i < espacio; ++i) {
        for (int j = 0; j < espacio; ++j) {
            if(matrix[i][j] < 10){ 
            std::cout << "ingrese la posiciones: [" << i << "][" << j << "] " << std::endl;
            std::cin >> matrix[i][j];
            }else{
                std::cout << "ingrese una matriz menor a 10: "<< std::endl;
            }
        }
    }
    */
    /*
    for (int i = 0; i < espacio; ++i) {
        for (int j = 0; j < espacio; ++j) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
    */
}

// Función para sumar dos matrices
void sumarMatrix(const int matrix1[espacio][espacio], const int matrix2[espacio][espacio], int resultado[espacio][espacio]) {


    for (int i = 0; i < espacio; ++i) {

        for (int j = 0; j < espacio; ++j) {
            resultado[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Función para imprimir una matriz
void imprimirMatrix(const int matrix[espacio][espacio]) {

    for (int i = 0; i < espacio; ++i) {
        for (int j = 0; j < espacio; ++j) {


            std::cout << "[ " << matrix[i][j] << " ]";
        }
        std::cout << std::endl;
    }
}

// Función para reemplazar los elementos pares por su valor al cuadrado
void reemplazarParesConCuadrado(int matrix[espacio][espacio]) {

    std::cout << "Funcion remplazar pares" << std::endl;
    for (int i = 0; i < espacio; ++i) {

        for (int j = 0; j < espacio; ++j) {
            if (matrix[i][j] % 2 == 0) {

                
                matrix[i][j] = matrix[i][j] * matrix[i][j];

            }
        }
    }
}
int main() {
    int matriz1[espacio][espacio];

    int matriz2[espacio][espacio];

    //imprime el valor del resultado de la suma
    int matrizResultado[espacio][espacio];

    cargarMatrix(matriz1);
    cargarMatrix(matriz2);
    sumarMatrix(matriz1, matriz2, matrizResultado);

    std::cout << "Matriz 1:" << std::endl;


    imprimirMatrix(matriz1);

    std::cout << "Matriz 2:" << std::endl;

    imprimirMatrix(matriz2);

    std::cout << "Matriz Suma:" << std::endl;
    imprimirMatrix(matrizResultado);


    reemplazarParesConCuadrado(matrizResultado);

    std::cout << "Matriz Resultado de pares al cuadrado:" << std::endl;

    imprimirMatrix(matrizResultado);

    return 0;
}
