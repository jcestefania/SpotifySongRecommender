#ifndef ANALIZADOR_HPP
#define ANALIZADOR_HPP

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include "main.hpp"

//@author Gabriel, Carlos y Juan Carlos 

// Definición de la estructura Rankings
typedef struct {
    vector<Song> cancioness;   
    vector<int> posiciones;    
    string str;                
} Rankings;

// Clase abstracta database que contendrá el vector songs
class database {
protected:
    vector<Song>* songs;  
};

// Clase Analizador que hereda de la clase database
class Analizador : public database {
public:
    // Constructor de la clase Analizador
    Analizador(vector<Song>* songs);

    // Destructor de la clase Analizador
    ~Analizador();

    // Método para analizar canciones recursivamente
    vector<string> analizarCancionesRec(vector<Song>* songs);

    // Método para analizar artistas 
    vector<string> analizarArtistasRec(vector<Song>* songs);

    // Método para obtener el Ranking 1 y devuelve un Ranking
    Rankings Rankings1(vector<Song>* songs);

    // Método para obtener el Ranking 2 y devuelve un Ranking
    Rankings Rankings2(vector<Song>* songs);

    // Método para obtener el Ranking 3 y devuelve un vector de pares de cadenas y enteros
    vector<pair <string, int> > Rankings3(vector<Song>* songs);
};
//Método para limpiar la consola(se usará en todos los ficheros, ya que analizador.hpp está incluido en ellos)
void clearConsole();

#endif // !ANALIZADOR_HPP