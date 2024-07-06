#include "header.hpp"

int main() {
    queue<VideoJuego> Juegos;
    int opc;

    do {
        cout << "Seleccione una opcion: " << endl;
        cout << "1. Registrar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------" << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1: {
                string titulo, genero;
                cout << "\nIngrese el titulo del juego: ";
                getline(cin, titulo);
                cout << "Ingrese el genero del juego: ";
                getline(cin, genero);
                VideoJuego juego(titulo, genero);
                registrar(Juegos, juego);
                break;
            }
            case 2: {
                string genero;
                cout << "\nIngrese el genero a mostrar: ";
                getline(cin, genero);
                mostrarJuego(Juegos, genero);
                break;
            }

            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida, vuelva a intentar." << endl;
                break;
        }
        cout << "----------------------" << endl;
        cout << endl;
    } while (opc != 0);

    cin.get();
    return 0;
}
