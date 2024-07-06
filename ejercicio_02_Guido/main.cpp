#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

// Defino la estructura videoJuego
struct videoJuego {
    char titulo[50];
    char genero[20];
};

// Declaro una queue para los juegos
queue<videoJuego> JuegosQueue;
stack<videoJuego> JuegosStack;

// Funcion para buscar un juego por su titulo en la queue
bool buscaJuegoQueue(const char* titulo) {
    queue<videoJuego> tempQueue = JuegosQueue; // Creo una copia temporal de la queue
    while (!tempQueue.empty()) {
        videoJuego juego = tempQueue.front();
        tempQueue.pop();
        if (strcmp(juego.titulo, titulo) == 0) {
            return true;
        }
    }
    return false;
}

// Procedimiento para registrar un juego en la queue
void RegistrarQueue(videoJuego juego) {
    if (JuegosQueue.size() >= 4) {
        cout << "No se pueden registrar mas juegos. Capacidad maxima alcanzada." << endl;
        return;
    }
    if (!buscaJuegoQueue(juego.titulo)) {
        JuegosQueue.push(juego);
        cout << "Juego registrado con exito." << endl;
    } else {
        cout << "El juego ya esta registrado." << endl;
    }
}

// Procedimiento para mostrar juegos segun el genero en la queue
void MostrarQueue(const char* genero) {
    cout << "Juegos del genero " << genero << ":" << endl;
    queue<videoJuego> tempQueue = JuegosQueue; // Creo una copia temporal de la queue
    while (!tempQueue.empty()) {
        videoJuego juego = tempQueue.front();
        tempQueue.pop();
        if (strcmp(juego.genero, genero) == 0) {
            cout << juego.titulo << endl;
        }
    }
}

// Funcion para buscar un juego por su titulo en la stack
bool buscaJuegoStack(const char* titulo) {
    stack<videoJuego> tempStack = JuegosStack; // Creo una copia temporal de la stack
    while (!tempStack.empty()) {
        videoJuego juego = tempStack.top();
        tempStack.pop();
        if (strcmp(juego.titulo, titulo) == 0) {
            return true;
        }
    }
    return false;
}

// Procedimiento para registrar un juego en la stack
void RegistrarStack(videoJuego juego) {
    if (JuegosStack.size() >= 4) {
        cout << "No se pueden registrar mas juegos. Capacidad maxima alcanzada." << endl;
        return;
    }
    if (!buscaJuegoStack(juego.titulo)) {
        JuegosStack.push(juego);
        cout << "Juego registrado con exito." << endl;
    } else {
        cout << "El juego ya esta registrado." << endl;
    }
}

// Procedimiento para mostrar juegos segun el genero en la stack
void MostrarStack(const char* genero) {
    cout << "Juegos del género " << genero << ":" << endl;
    stack<videoJuego> tempStack = JuegosStack; // Crea una copia temporal de la stack
    while (!tempStack.empty()) {
        videoJuego juego = tempStack.top();
        tempStack.pop();
        if (strcmp(juego.genero, genero) == 0) {
            cout << juego.titulo << endl;
        }
    }
}

int main() {
    char opcion;
    char titulo[50];
    char genero[20];
    
    do {
        cout << "Menú:" << endl;
        cout << "1. Registrar juego en Queue" << endl;
        cout << "2. Mostrar juegos por género en Queue" << endl;
        cout << "3. Buscar juego en Queue" << endl;
        cout << "4. Registrar juego en Stack" << endl;
        cout << "5. Mostrar juegos por género en Stack" << endl;
        cout << "6. Buscar juego en Stack" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore(); 
        
        switch(opcion) {
            case '1': {
                videoJuego nuevoJuego;
                cout << "Ingrese el titulo del juego: ";
                cin.getline(nuevoJuego.titulo, 50);
                cout << "Ingrese el genero del juego: ";
                cin.getline(nuevoJuego.genero, 20);
                RegistrarQueue(nuevoJuego);
                break;
            }
            case '2': {
                cout << "Ingrese el genero a mostrar: ";
                cin.getline(genero, 20);
                MostrarQueue(genero);
                break;
            }
            case '3': {
                cout << "Ingrese el titulo del juego a buscar: ";
                cin.getline(titulo, 50);
                if (buscaJuegoQueue(titulo)) {
                    cout << "El juego " << titulo << " esta registrado" << endl;
                } else {
                    cout << "El juego " << titulo << " no está registrado" << endl;
                }
                break;
            }
            case '4': {
                videoJuego nuevoJuego;
                cout << "Ingrese el titulo del juego: ";
                cin.getline(nuevoJuego.titulo, 50);
                cout << "Ingrese el genero del juego: ";
                cin.getline(nuevoJuego.genero, 20);
                RegistrarStack(nuevoJuego);
                break;
            }
            case '5': {
                cout << "Ingrese el genero a mostrar: ";
                cin.getline(genero, 20);
                MostrarStack(genero);
                break;
            }
            case '6': {
                cout << "Ingrese el titulo del juego a buscar: ";
                cin.getline(titulo, 50);
                if (buscaJuegoStack(titulo)) {
                    cout << "El juego " << titulo << " esta registrado en la Stack." << endl;
                } else {
                    cout << "El juego " << titulo << " no esta registrado en la Stack." << endl;
                }
                break;
            }
            case '7': {
                cout << "Saliendo..." << endl;
                break;
            }
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != '7');
    
    return 0;
}

