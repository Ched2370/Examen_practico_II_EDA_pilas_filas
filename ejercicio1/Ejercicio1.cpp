/*
#include <iostream>
#include <cstdlib>


Dadas dos matrices de 4x4, matriz1 y matriz2, y una tercera matriz resultado donde 
almacenaremos la suma de las dos matrices. 
a. Arme la funcion cargarMatrix, recibe una matriz y pide carga de números entre 1 a 10.
b. Armar una a función sumarMatrix recibe las dos matrices de entrada y la matriz de 
resultado, y realiza la suma elemento por elemento, en matriz3.
c. Otro procedimiento imprimirMatrix, usado para imprimir cualquier matriz en la consola.
d. En la función main, debes crear las matrices de ejemplo matriz1 y matriz2, y luego acto 
seguido, imprimimos las tres matrices en la consola con la función imprimirMatrix.
e. Un último proceso recibe la matriz3 resultante, remplaza los elementos pares por su 
valor al cuadrado, luego se reutiliza el procedimiento imprimirMatrix.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <ctime>
const int elemento = 4;



void cargarMatrix(int matrix[elemento][elemento]) {
srand(time(0));
    for (int i = 0; i < elemento; ++i) {
        for (int j = 0; j < elemento; ++j) {
            do {


                std::cout << "Ingresa un valor entre 1 y 10 para la posición [" << i << "][" << j << "]: ";



                matrix[i][j] = rand() % 10 + 1;

            } while (matrix[i][j] < 1 || matrix[i][j] > 10);
        }
    }
}


void sumarMatrix(const int matrix1[elemento][elemento], const int matrix2[elemento][elemento], int resultado[elemento][elemento]) {
    for (int i = 0; i < elemento; ++i) {
        for (int j = 0; j < elemento; ++j) {
            resultado[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void reemplazarParesConCuadrado(int matrix[elemento][elemento]) {


    std::queue<int> fila;

    std::stack<int> pila;
    

    for (int i = 0; i < elemento; ++i) {
        for (int j = 0; j < elemento; ++j) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] = matrix[i][j] * matrix[i][j];
            }

            fila.push(matrix[i][j]);
        }
    }

    // Transferir elementos de la fila a la pila
    while (!fila.empty()) {
        pila.push(fila.front());
        fila.pop();
    }

    // Transferir elementos de la pila de nuevo a la matriz
    for (int i = elemento - 1; i >= 0; --i) {
        for (int j = elemento - 1; j >= 0; --j) {


            matrix[i][j] = pila.top();


            pila.pop();
        }
    }
}

void imprimirMatrix(const int matrix[elemento][elemento]) {

    for (int i = 0; i < elemento; ++i) {
        for (int j = 0; j < elemento; ++j) {
            std::cout  << " ["   << matrix[i][j] << "] ";
        }
        std::cout << std::endl;
    }
}




int main() {
    int matriz1[elemento][elemento];
    int matriz2[elemento][elemento];
    int matrizResultado[elemento][elemento];

    std::cout << "Cargar valores para Matriz 1:" << std::endl;
    cargarMatrix(matriz1);
    std::cout << "Cargar valores para Matriz 2:" << std::endl;
    cargarMatrix(matriz2);

    sumarMatrix(matriz1, matriz2, matrizResultado);

    std::cout << "Matriz 1:" << std::endl;
    imprimirMatrix(matriz1);

    std::cout << "Matriz 2:" << std::endl;
    imprimirMatrix(matriz2);

    std::cout << "Matriz Resultadola suma:" << std::endl;


    imprimirMatrix(matrizResultado);

    reemplazarParesConCuadrado(matrizResultado);

    std::cout << "Matriz Resultado Pares del cuadrado" << std::endl;


    imprimirMatrix(matrizResultado);

    return 0;
}
