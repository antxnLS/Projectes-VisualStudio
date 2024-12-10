// RepasExamenSistemaPuntuacio.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

struct Jugador{ //Creem una estructura amb el nom del jugador i la seva puntuacio
    string nom;
    int punt;
};

int main()
{
   
    Jugador jugadors[3] = { //Fem un array de jugadors
        {"Anna", 50},
        {"Marc", 70},
        {"Joan", 60}
    };

    for (int i = 0; i < 3; i++) { //Mostrar jugadors
        cout << jugadors[i].nom << " " << jugadors[i].punt << "\n";
    }

    Jugador millorJugador = jugadors[0];
    for (int i = 0; i < 3; i++) { //Va mirant els jugadors i actualitza el millor jugador quan es troba una puntuacio mes alta que el jugador passat
        if (jugadors[i].punt > millorJugador.punt )
        {
            millorJugador = jugadors[i];
        }
    }
    cout << "\nEl jugador amb la puntuacio mes alta es: " << millorJugador.nom << " amb " << millorJugador.punt << " punts\n"; //Diu qui es el jugador amb la puntuacio mes alta
}