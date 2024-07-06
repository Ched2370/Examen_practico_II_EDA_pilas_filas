#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// Defino la estructura videoJuego
struct videoJuego {
    char titulo[50];
    char genero[20];
};

// Declaro una queue para los juegos
queue<videoJuego> JuegosQueue;

// Funcion para buscar un juego por su titulo en la queue
bool buscaJuego(const char* titulo) {
    queue<videoJuego> tempQueue = JuegosQueue;
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
void Registrar(videoJuego juego) {
    if (JuegosQueue.size() >= 4) {
        cout << "No se pueden registrar mas juegos. Capacidad maxima alcanzada." << endl;
        return;
    }
    if (!buscaJuego(juego.titulo)) {
        JuegosQueue.push(juego);
        cout << "Juego registrado con exito." << endl;
    } else {
        cout << "El juego ya esta registrado." << endl;
    }
}

// Procedimiento para mostrar juegos segun el genero en la queue
void Mostrar(const char* genero) {
    cout << "Juegos del genero " << genero << ":" << endl;
    queue<videoJuego> tempQueue = JuegosQueue; 
    while (!tempQueue.empty()) {
        videoJuego juego = tempQueue.front();
        tempQueue.pop();
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
        cout << "Menu:" << endl;
        cout << "1. Registrar juego" << endl;
        cout << "2. Mostrar juegos por genero" << endl;
        cout << "3. Buscar juego" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); 
        
        switch(opcion) {
            case '1': {
                videoJuego nuevoJuego;
                cout << "Ingrese el titulo del juego: ";
                cin.getline(nuevoJuego.titulo, 50);
                cout << "Ingrese el genero del juego: ";
                cin.getline(nuevoJuego.genero, 20);
                Registrar(nuevoJuego);
                break;
            }
            case '2': {
                cout << "Ingrese el genero a mostrar: ";
                cin.getline(genero, 20);
                Mostrar(genero);
                break;
            }
            case '3': {
                cout << "Ingrese el titulo del juego a buscar: ";
                cin.getline(titulo, 50);
                if (buscaJuego(titulo)) {
                    cout << "El juego " << titulo << " esta registrado." << endl;
                } else {
                    cout << "El juego " << titulo << " no esta registrado." << endl;
                }
                break;
            }
            case '4': {
                cout << "Saliendo..." << endl;
                break;
            }
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != '4');
    
    return 0;
}

