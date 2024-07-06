#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <conio.h>

using namespace std;

struct galletaLetra {
    char figuraLetra;
    char sabor[10];
};

void precargarPila(stack<galletaLetra> &pila) {
    galletaLetra galletas[8] = {
        {'A', "limon"},
        {'B', "chocolate"},
        {'C', "naranja"},
        {'D', "limon"},
        {'E', "chocolate"},
        {'F', "naranja"},
        {'G', "chocolate"},
        {'I', "naranja"}
    };

    for(int i = 0; i < 8; i++) {
        pila.push(galletas[i]);
    }
}

bool buscarLetra(stack<galletaLetra> pila, char letra) {
    letra = tolower(letra);
    while(!pila.empty()) {
        if(tolower(pila.top().figuraLetra) == letra) {
            return true;
        }
        pila.pop();
    }
    return false;
    
    cout << " " << endl;
}

void pasarALaFila(stack<galletaLetra> &pila, queue<galletaLetra> &filaAEI, queue<galletaLetra> &filaBDFG) {
    while(!pila.empty()) {
        galletaLetra galleta = pila.top();
        pila.pop();
        if(galleta.figuraLetra == 'A' || galleta.figuraLetra == 'E' || galleta.figuraLetra == 'I') {
            filaAEI.push(galleta);
        } else if(galleta.figuraLetra == 'B' || galleta.figuraLetra == 'D' || galleta.figuraLetra == 'F' || galleta.figuraLetra == 'G') {
            filaBDFG.push(galleta);
        }
    }
    cout << " " << endl;
}

void mostrarFila(queue<galletaLetra> fila) {
    while(!fila.empty()) {
        galletaLetra galleta = fila.front();
        cout << "Letra: " << galleta.figuraLetra << ", Sabor: " << galleta.sabor << endl;
        fila.pop();
    }
    
    cout << " " << endl;
}

void mostrarChocolates(queue<galletaLetra> fila) {
    while(!fila.empty()) {
        galletaLetra galleta = fila.front();
        fila.pop();
        if(strcmp(galleta.sabor, "chocolate") == 0) {
            cout << "Letra: " << galleta.figuraLetra << ", Sabor: " << galleta.sabor << endl;
        }
    }
    
    cout << " " << endl;
}

int main() {
    stack<galletaLetra> pila;
    queue<galletaLetra> filaAEI;
    queue<galletaLetra> filaBDFG;

    precargarPila(pila);

    char letraBuscar;
    cout << "Ingrese la letra a buscar: ";
    cin >> letraBuscar;
    if(buscarLetra(pila, letraBuscar)) {
        cout << "La letra " << letraBuscar << " fue encontrada." << endl;
    } else {
        cout << "La letra " << letraBuscar << " no fue encontrada." << endl;
    }

    pasarALaFila(pila, filaAEI, filaBDFG);

    cout << "Galletas en la fila AEI (vocales):" << endl;
    mostrarFila(filaAEI);

    cout << "Galletas BDFG (consonantes) de chocolate:" << endl;
    mostrarChocolates(filaBDFG);

	getch();
    return 0;
}

