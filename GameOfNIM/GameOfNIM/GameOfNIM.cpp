// GameOfNIM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    int numInicial, numResposta, torn = 1, jugador = 1; //Declaracio variables
    cout << "Introdueix un numero pel qual comencar: ";  //Demana el numero inicial
    cin >> numInicial; //Llegeix el numero introduit pel usuari


    while (numInicial > 0) //Comprova si s'esta jugant
    {
        cout << "Torn " << torn << ": (Jugador " << jugador << ")" << endl; // Diu el torn i el jugador actual
        cout << "Introdueix un numero (1 o 2): "; //Demana que el jugador introdueixi un 1 o 2
        cin >> numResposta; //Llegeix el numero del jugador
        if (numResposta <= 2 && numResposta >= 1) //Si la resposta es correcta, o sigui, que el numero es un 1 o un 2
        {
            numInicial = numInicial - numResposta; //Resta el numero proporcionat pel usuari
            cout << "Ara el numero es: " << numInicial << endl; //Diu quin es el numero despres de la resta
        }
        else //Si la resposta no es correcta
        {
            cout << "Numero incorrecte, ha de ser un 1 o un 2" << endl; //Diu que el numero es incorrecte
            continue; //Trenca el bucle per retornar al if
        }

        torn++; //Augmenta el valor del torn
        if (jugador == 1) //Si era el torn del jugador 1, llavors canvia el torn al jugador 2
        {
            jugador = 2; //Canvia el torn al jugador 2
        }
        else if (jugador == 2) //Si era el torn del jugador 2, llavors canvia el torn al jugador 1
        {
            jugador = 1; //Canvia el torn al jugador 1
        }
    }
    if (jugador == 2) //Si al final el jugador es l'1, dir que ha guanyat
    {
        cout << "Ha guanyat el jugador 1"; //Diu que ha guanyat el jugador 1
    }
    else if (jugador == 1) //Si al final el jugador es el 2, dir que ha guanyat
    {
        cout << "Ha guanyat el jugador 2"; //Diu que ha guanyat el jugador 2
    }
}