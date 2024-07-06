#include "header.hpp"

bool buscaJuego(queue<VideoJuego>& juegos, string titulo) {
    queue<VideoJuego> copia = juegos;
    while (!copia.empty()) {
        if (copia.front().getTitulo() == titulo) {
            return true;
        }
        copia.pop();
    }
    return false;
}


void registrar(queue<VideoJuego> &juegos, VideoJuego juego) {
    if (!buscaJuego(juegos, juego.getTitulo())) {
        if (juegos.size() < 4) {
            juegos.push(juego);
        } else {
            cout << "Memoria llena." << endl;
        }
    } else {
        cout << "El juego ya esta registrado." << endl;
    }
}

void mostrarJuego(queue<VideoJuego> &juegos, string genero) {
    queue<VideoJuego> copia = juegos;
    while (!copia.empty()) {
        if (copia.front().getGenero() == genero) {
            cout << "Titulo: " << copia.front().getTitulo() << endl;
        }
        copia.pop();
    }
}