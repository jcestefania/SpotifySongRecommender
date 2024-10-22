
#include "analizador.hpp"
#include <set>
#include <map>

Analizador::Analizador(vector<Song>* songss) {
    songs = songss;
}

Analizador::~Analizador() {}

// @author Gabriel y Juan Carlos
vector<string> Analizador::analizarCancionesRec(vector<Song>* songs) { 
    string genero;
    vector<string> generos;
    bool encontrado = false;
    vector<int> posiciones;
    vector<string> cancionesRec;

    // Obtener todos los géneros de las canciones disponibles
    for (Song s : *songs) {
        generos.push_back(s.genero);
    }

    // Solicitar al usuario un género musical que le guste
    cout << "Para poder recomendarte canciones, necesitamos que introduzcas un género musical que te guste (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin >> genero;

    // Validar que el género introducido por el usuario exista en la lista de géneros disponibles
    do {
        encontrado = find(begin(generos), end(generos), genero) != end(generos);
        if (!encontrado) {
            cout << "Género no encontrado. " <<
                "Introduce el nombre de un género musical para que te podamos recomendar canciones que te puedan gustar: \n";
            cin >> genero;
        }
    } while (!encontrado);

    // Obtener las posiciones de las canciones que coinciden con el género seleccionado
    auto it = find(generos.begin(), generos.end(), genero);
    int pos = distance(generos.begin(), it);

    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, generos.end(), genero);
    }

    // Seleccionar aleatoriamente 5 canciones del género seleccionado
    for (int i = 0; i < 5; i++) {
        int j = rand() % posiciones.size();
        string cancionActual = (*songs)[posiciones[j]].nombreCancion;

        // Verificar si la canción actual ya está en cancionesRec
        bool cancionRepetida = false;
        for (string s : cancionesRec) {
            if (s == cancionActual) {
                cancionRepetida = true;
                break;
            }
        }

        // Verificar si ya se seleccionaron todas las canciones disponibles para el género
        if (cancionRepetida && cancionesRec.size() >= posiciones.size()) {
            break;
        }

        // Si la canción está repetida, seleccionar otra posición
        if (cancionRepetida) {
            i--;
            continue;
        }

        cancionesRec.push_back(cancionActual);
    }

    return cancionesRec;
}


// @author Juan Carlos y Gabriel
vector<string> Analizador::analizarArtistasRec(vector<Song>* songs) {
    vector<string> generos;
    string genero;
    bool encontrado = false;

    vector<int> posiciones;
    vector<string> artistasRec;

    // Obtener todos los géneros de las canciones disponibles
    for (Song s : *songs) {
        generos.push_back(s.genero);
    }

    // Solicitar al usuario un género musical que le guste
    cout << "Para poder recomendarte artistas necesitamos que introduzcas un género musical que te guste (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin >> genero;

    // Validar que el género introducido por el usuario exista en la lista de géneros disponibles
do {
    encontrado = find(begin(generos), end(generos), genero) != end(generos);
    if (!encontrado) {
        cout << "Género no encontrado. " <<
            "Introduce el nombre de un género musical para que te podamos recomendar artistas que te puedan gustar: \n";
        cin >> genero;
    }
} while (!encontrado);

// Obtener las posiciones de las canciones que coinciden con el género seleccionado
auto it = find(generos.begin(), generos.end(), genero);
int pos = distance(generos.begin(), it);

while (it != generos.end()) {
    int pos = distance(generos.begin(), it);
    posiciones.push_back(pos);
    it = find(++it, generos.end(), genero);
}

// Obtener los artistas de las canciones que coinciden con el género seleccionado
set<string> artistasSet;
for (int pos : posiciones) {
    artistasSet.insert((*songs)[pos].nombreArtista);
}

// Seleccionar aleatoriamente 3 artistas del género seleccionado
for (int i = 0; i < 3; i++) {
    int j = rand() % artistasSet.size();
    auto it = artistasSet.begin();
    advance(it, j);
    string artistaActual = *it;

    // Verificar si el artista actual ya está en artistasRec
    bool artistaRepetido = false;
    for (string s : artistasRec) {
        if (s == artistaActual) {
            artistaRepetido = true;
            break;
        }
    }

    // Verificar si ya se seleccionaron todos los artistas disponibles para el género
    if (artistaRepetido && artistasRec.size() >= artistasSet.size()) {
        break;
    }

    // Si el artista está repetido, seleccionar otro artista
    if (artistaRepetido) {
        i--;
        continue;
    }

    artistasRec.push_back(artistaActual);
}

return artistasRec;
}
//@author Gabriel y Carlos Arroyo
Rankings Analizador::Rankings1(vector <Song>* songs){
    int opcion; 
    bool encontrado = false;
    vector <Song> canciones;
    string cantante;    
    vector <string> cantantes; 
    vector <int> posiciones;

    // Obtener todos los nombres de los cantantes de las canciones disponibles
    for (Song s : *songs){
        cantantes.push_back(s.nombreArtista);
    }

    // Solicitar al usuario el nombre de un cantante para ver su ranking de canciones más escuchadas
    cout << "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: " << endl;
    cin.ignore();
    getline(cin,cantante);

    // Validar que el cantante introducido por el usuario exista en la lista de cantantes disponibles
    do{
        encontrado = find(begin(cantantes), end(cantantes),cantante) != end(cantantes);
        if(!encontrado){
            cout << "Cantante no encontrado. " <<
                    "Introduce el nombre del cantante para ver su Ranking de canciones más escuchadas: \n";
            cin.ignore();
            getline(cin,cantante);
        }
    }while(!encontrado);
    
    // Obtener las posiciones de las canciones que coinciden con el cantante seleccionado
    auto it = find(cantantes.begin(), cantantes.end(), cantante);

    while (it != cantantes.end()) {
        int pos = distance(cantantes.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, cantantes.end(), cantante);
    }

    Rankings r;
    r.cancioness = canciones;
    r.posiciones = posiciones; 
    r.str = cantante;
    cantantes.clear();
    return r;
}


// @author Gabriel, Carlos y Juan Carlos
Rankings Analizador::Rankings2(vector <Song>* songs){
    int opcion; 
    bool encontrado = false;
    vector <Song> canciones;
    string genero; 
    vector <string> generos;
    vector <int> posiciones;

    // Obtener todos los géneros de las canciones disponibles
    for (Song s : *songs){
        generos.push_back(s.genero);
    }

    // Solicitar al usuario un género musical para ver el ranking de canciones más escuchadas
    cout << "Introduce un género para ver el Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin.ignore();
    getline(cin,genero);

    // Verificar que el género introducido por el usuario exista en la lista de géneros disponibles
    do{
        encontrado = find(begin(generos), end(generos),genero) != end(generos);
        if(!encontrado){
            cout << "Género no encontrado. " <<
                    "Introduce el nombre del género para ver su Ranking de canciones más escuchadas (RAP, POP, INDIE, SOUL o COUNTRY): \n";
            cin.ignore();
            getline(cin,genero);
        }
    }while(!encontrado);

    // Obtener las posiciones de las canciones que coinciden con el género seleccionado
    auto it = find(generos.begin(), generos.end(), genero);

    while (it != generos.end()) {
        int pos = distance(generos.begin(), it);
        posiciones.push_back(pos);
        it = find(++it, generos.end(), genero);
    }

    Rankings r;
    r.cancioness = canciones;
    r.posiciones = posiciones; 
    r.str = genero;
    return r;
}


// @author Juan Carlos y Carlos
vector<pair<string, int> > Analizador::Rankings3(vector<Song>* songs) {
    int opcion;
    bool encontrado = false;
    vector<string> generos;
    string genero;

    // Obtener todos los géneros de las canciones disponibles
    for (Song s : *songs) {
        generos.push_back(s.genero);
    }

    // Solicitar al usuario un género musical para ver el ranking de artistas más escuchados
    cout << "Introduce un género para ver el Ranking de artistas más escuchados (RAP, POP, INDIE, SOUL o COUNTRY): " << endl;
    cin.ignore();
    getline(cin, genero);

    // Verificar que el género introducido por el usuario exista en la lista de géneros disponibles
    do {
        encontrado = find(begin(generos), end(generos), genero) != end(generos);
        if (!encontrado) {
            cout << "Género no encontrado. " <<
                "Introduce el nombre del género para ver su Ranking de artistas más escuchados (RAP, POP, INDIE, SOUL o COUNTRY): \n";
            cin.ignore();
            getline(cin, genero);
        }
    } while (!encontrado);

    // Crear un mapa para almacenar los conteos de artistas por género
    map<string, int> artistCounts;

    // Contar la cantidad de veces que aparece cada artista en el género seleccionado
    for (Song s : *songs) {
        if (s.genero == genero) {
            artistCounts[s.nombreArtista]++;
        }
    }

    // Convertir el mapa en un vector de pares (artista, conteo) para poder ordenarlo
    vector<pair <string, int> > artistRanking(artistCounts.begin(), artistCounts.end());

    // Ordenar el vector en orden descendente según los conteos
    sort(artistRanking.begin(), artistRanking.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    return artistRanking;
}
//Definición de clearConsole, mencionada en comentario de analizador.hpp
void clearConsole(){ 
    system("printf \"\\033c\""); 
} 