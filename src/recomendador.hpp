#ifndef RECOMENDADOR_HPP
#define RECOMENDADOR_HPP

#include "analizador.hpp"

//@author Carlos 
class Recomendador : public database {
private:
    static Recomendador* instance;  // Variable estática para la instancia única

    // Constructor privado de Recomendador
    Recomendador(vector<Song> songs);

    // Destructor privado de Recomendador
    ~Recomendador();

public:
    // Método estático para obtener la instancia única
    static Recomendador* getInstance(vector<Song> songs);

    // Resto de métodos públicos
    void analizarCancion(const vector<Song>& songs);
    void mostrarRanking(vector<Song> songs);
    void mostrarCancionesRec(vector<Song> songs);
    void mostrarArtistasRec(vector<Song> songs);
};

#endif // !RECOMENDADOR_HPP
