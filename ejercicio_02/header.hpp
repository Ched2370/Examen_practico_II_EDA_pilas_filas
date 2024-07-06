#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct VideoJuego {
  private:
    string titulo;
    string genero;
  public:
    VideoJuego(string ti, string ge) : titulo(ti), genero(ge) {};

    void setTitulo(string ti) { titulo = ti; };
    void setGenero(string ge) { genero = ge; };

    string getTitulo() { return titulo; };
    string getGenero() { return genero; };
};

bool buscaJuego(queue<VideoJuego>& juegos, string titulo);
void registrar(queue<VideoJuego> &juegos, VideoJuego juego);
void mostrarJuego(queue<VideoJuego> &juegos, string genero);

#include "funsiones.cpp"
#endif