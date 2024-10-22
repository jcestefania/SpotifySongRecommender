#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//@author Carlos

// Definición de la estructura Song
typedef struct {
    int posicion;
    string nombreArtista;
    string nombreCancion;
    int diasTop10;
    int posicionMax;
    int streamMax;
    int streamTotales;
    string genero;
} Song;

// Declaración de la función menu
int menu();

// Declaración de la función cargaDatos
void cargaDatos(vector<Song>& songs);



#endif // !MAIN_HPP