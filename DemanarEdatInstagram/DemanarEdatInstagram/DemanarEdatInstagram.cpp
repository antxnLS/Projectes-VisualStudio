//DemanarEdatInstagram.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Exercici 1. Demanar a l'usuari l'edat i indicar a quin any pots entrar a instagram resta quan falta per 16
//Exercici 2. Demani l'any actual i l'any de naixement per tal de calcular l'edat.

#include <iostream>
using namespace std;

int main()
{
    int edat;
    int any;
    int anyNaixement;

    cout << "Exercici 1.\n";
    cout << "Introdueix la teva edat: ";
    cin >> edat;
    
    if (edat >= 16)
    {
        cout << "Pots utilitzar Instagram";
    }
    else
    {
        edat = 16 - edat;
        cout << "Et falten " << edat << " anys per poder utilitzar Instagram" << endl;
    }

    cout << "Exercici 2.\n";
    cout << "Introdueix l'any actual: ";
    cin >> any;
    cout << "El teu any de naixement: ";
    cin >> anyNaixement;
    edat = any - anyNaixement;
   
    if (edat >= 16)
    {
        cout << "Tens " << edat << " anys, per tant pots utilitzar Instagram";
    }
    else
    {
        cout << "Tens " << edat << " anys, per tant no pots utilitzar Instagram";

    }
    return 0;


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
