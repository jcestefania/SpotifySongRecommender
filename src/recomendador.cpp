
#include <iostream>
#include <vector>
#include <algorithm>
#include "recomendador.hpp"

Recomendador* Recomendador::instance = nullptr;

// Constructor de la clase Recomendador
Recomendador::Recomendador(vector<Song> songss) {
    songs = &songss;
}

// Destructor de la clase Recomendador
Recomendador::~Recomendador(){}

// Método estático para obtener la instancia única de Recomendador
Recomendador* Recomendador::getInstance(vector<Song> songs) {
    if (!instance) {
        instance = new Recomendador(songs);
    }
    return instance;
}



// Método para mostrar las canciones recomendadas
//@author Carlos y Gabriel
void Recomendador::mostrarCancionesRec(vector<Song> songs) {
    Analizador a(&songs);
    vector<string> cancionesRec = a.analizarCancionesRec(&songs);
    cout << "--------------------------------\n";
    cout << "CANCIONES RECOMENDADAS\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < cancionesRec.size(); i++) {
        cout << cancionesRec[i] << endl;
        usleep(20000);
    }
}

//@author Gabriel y Juan Carlos
// Método para mostrar los artistas recomendados
void Recomendador::mostrarArtistasRec(vector<Song> songs) {
    Analizador a(&songs);
    vector<string> artistasRec = a.analizarArtistasRec(&songs);
    clearConsole();
    cout << "--------------------------------\n";
    cout << "ARTISTAS RECOMENDADOS\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < artistasRec.size(); i++) {
        cout << artistasRec[i] << endl;
        usleep(20000);
    }
}

//@author Carlos, Gabriel y Juan Carlos
// Método para analizar una canción
void Recomendador::analizarCancion(const vector<Song>& songs) {
    string cancion;
    clearConsole();
    cout << "Introduce el nombre de la canción que quieres analizar: " << endl;
    cin.ignore(); // Ignorar cualquier caracter residual en el buffer de entrada
    getline(cin, cancion);
    usleep(50000);
    clearConsole();

    // Buscar la canción por nombre en el vector songs
    string cancionMinusculas = cancion;
    transform(cancionMinusculas.begin(), cancionMinusculas.end(), cancionMinusculas.begin(), [](unsigned char c) {
        return tolower(c);
    });

    auto it = find_if(songs.begin(), songs.end(), [&](const Song& s) {
        string nombreCancionMinusculas = s.nombreCancion;
        transform(nombreCancionMinusculas.begin(), nombreCancionMinusculas.end(), nombreCancionMinusculas.begin(), [](unsigned char c) {
            return tolower(c);
        });
        return nombreCancionMinusculas.find(cancionMinusculas) != string::npos;
    });

    if (it != songs.end()) {
        const Song& cancionEncontrada = *it;

        cout << "--------------------------------------\n";
        cout << "Datos sobre la canción " << cancionEncontrada.nombreCancion << endl;
        cout << "--------------------------------------\n";
        cout << "Artista: " << cancionEncontrada.nombreArtista << endl;
        cout << "Género: " << cancionEncontrada.genero << endl;
        cout << "Streams Totales: " << cancionEncontrada.streamTotales << endl;
    } else {
        cout << "Canción no encontrada." << endl;
    }
}

//@author Juan Carlos, Gabriel y Carlos
// Método para mostrar los rankings
void Recomendador::mostrarRanking(vector<Song> songs) {
    int opcion;
    Analizador a(&songs);

    cout << "Elige el tipo de Ranking: " << endl;
    cout << "    1. Ranking de canciones por cantante\n";
    cout << "    2. Ranking de canciones por género\n";
    cout << "    3. Ranking de cantantes por género\n";
    cin >> opcion;
    usleep(5000);
    clearConsole();

    switch (opcion) {
        case 1: {
            Rankings r1 = a.Rankings1(&songs);
            cout << "-----------------------------------------------\n";
            cout << "Ranking de canciones de " << r1.str << endl;
            cout << "-----------------------------------------------\n";
            int contadorPosicion = 1; // Inicializar el contador de posición

            for (int i = 0; i < r1.posiciones.size(); i++) {
                r1.cancioness.push_back(songs[r1.posiciones[i]]);
                r1.cancioness[i].posicion = contadorPosicion; // Asignar la posición actualizada
                cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
                contadorPosicion++; // Incrementar el contador de posición
            }

            r1.posiciones.clear();
            r1.cancioness.clear();
            break;
        }
        case 2: {
            Rankings r1 = a.Rankings2(&songs);
            cout << "-----------------------------------------------\n";
            cout << "Ranking de canciones de " << r1.str << endl;
            cout << "-----------------------------------------------\n";
            int contadorPosicion = 1; // Inicializar el contador de posición

            for (int i = 0; i < r1.posiciones.size(); i++) {
                r1.cancioness.push_back(songs[r1.posiciones[i]]);
                r1.cancioness[i].posicion = contadorPosicion; // Asignar la posición actualizada
                cout << r1.cancioness[i].posicion << ". " << r1.cancioness[i].nombreCancion << endl;
                contadorPosicion++; // Incrementar el contador de posición
            }

            r1.posiciones.clear();
            r1.cancioness.clear();
            break;
        }
        case 3: {
            // Ranking de cantantes por género
            vector<pair <string,int> > r3 = a.Rankings3(&songs);
            for (int i = 0; i < r3.size(); i++) {
                cout << i + 1 << ". " << r3[i].first << " Con un total de " << r3[i].second << " streams totales" << endl;
            }
            r3.clear();
            break;
        }
        default: {
            cout << "Opción incorrecta.\n" << endl;
            mostrarRanking(songs);
            break;
        }
    }
}
