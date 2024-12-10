// ProgramaVariableTasca.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
 
// Exercici 1
    cout << "Exercici 1\n\n";

    int peus = 0, polzades;
    polzades = 0;
    cout << "Peus: " << peus;
    cout << "\nPolzades: " << polzades << endl;

// Exercici 2
    cout << "\nExercici 2\n\n";
    int var1, var2, var3, var4, var5;
    //No hi ha sortida perque no les hem inicialitzat.

// Exercici 3
    cout << "Exercici 3\n";
    double ftemp, ctemp;
    cout << "\nIntrodueix la temperatura en Fahrenheit: ";
    cin >> ftemp;
    
    ctemp = (ftemp - 32) / 1.8;
    cout << "La temperature introduida en Celsius: ";
    cout << ctemp << endl;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
