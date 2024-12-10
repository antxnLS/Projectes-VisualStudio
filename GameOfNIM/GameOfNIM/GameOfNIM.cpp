// GameOfNIM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    int numInicial, numResposta, turns = 1, jugador = 1;
    cout << "Introdueix un numero per cual comencar: ";
    cin >> numInicial;


    while (numInicial > 0)
    {
        cout << "Turn " << turns << ": (Jugador " << jugador <<")" << endl;
        cout << "Introdueix un numero (1 o 2): ";
        cin >> numResposta;
        if (numResposta <= 2 && numResposta >= 1 )
        {
            numInicial = numInicial - numResposta;
        }
        cout << "Ara el numero es: " << numInicial << endl;
        turns++;
        if (jugador == 1)
        {
            jugador = 2;
        }
        else if (jugador == 2)
        {
            jugador = 1;
        }
    }
    if (jugador == 2)
    {
        cout << "Ha guanyat el jugador 1";
    }
    else if (jugador == 1)
    {
        cout << "Ha guanyat el jugador 2";
    }
    //while bla bla bla

    //turns = turns % 2; //Si es pot dividir entre 2, = 0, si no = 1
    /*
    if (turns % 2 == 0)
    {
        cout << "Ha guanyat el jugador 1";
    }
    else if (turns % 2 == 1)
    {
        cout << "Ha guanyat el jugador 2";
    }
    */
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
