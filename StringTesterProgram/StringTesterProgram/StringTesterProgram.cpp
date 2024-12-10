// Programa: String Tester Program
// Autor: Anton Volegov
// Data: 04/10/2024


#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Introduir tres paraules
    string string1, string2, string3; //Creem tres variables tipus string
    cout << "Introdueix la primera paraula: ";
    cin >> string1;
    cout << "Introdueix la segona paraula: ";
    cin >> string2;
    cout << "Introdueix la tercera paraula: ";
    cin >> string3;

    //Crea una frase i encadena les tres paraules
    string frase = string1 + " " + string2 + " " + string3;

    //Diu la frase
    cout << "\nLa frase es: " << frase << endl << endl;

    //Conta els caràcters a la frase
    int charCount = frase.length(); //Utilitzem la funcio .length de string per agafar la llargada de la frase
    cout << "La frase te " << charCount << " caracters" << endl << endl;

    //Diu el caràcter a la posició 0
    cout << "El caracter a la posicio 0 es: ";
    cout << frase[0] << endl << endl; //Diu el caracter a la posicio 0, o sigui, el primer caracter 

    //Canviar un caràcter que especifiqui l'usuari
    int posicioChar;
    cout << "A quina posicio vols canviar el caracter?: ";
    cin >> posicioChar;
    string letraChar;
    cout << "Quina lletra vols posar a aquesta posicio?: ";
    cin >> letraChar;
    cout << "Canviant el caracter " << posicioChar << " per " << letraChar << endl; //Missatge que confirma a on ha canviat el caracter
    string canvi = frase.replace(posicioChar, 1, letraChar); //Introdueix una variable anomenada canvi, que utilitza la funció .replace per reemplaçar el caràcter a la posició que desitgi l'usuari, juntament amb quina lletra vol posar en el seu lloc.
    cout << "Ara la frase es: " << frase << endl << endl;

    //Bucle que mostra les posicions dels caracters
    for (int num = 0; num < frase.length(); ++num) //Inicialitzem una variable a 0, si el número és menor que la llargada de la frase, llavors repeteix. Cada vegada que fa un bucle, se suma 1 a la variable.
    {
        cout << "El caracter a la posicio " << num << " es: " << frase[num] << endl; //Diu a quina posició està el caràcter següent
    }
    cout << endl;
    //Buscador de paraula
    string paraulaPerTrobar;
start: //Etiqueta per repetir el programa des de la condició if
    cout << "Introdueix una paraula per buscar-la al text: ";
    cin >> paraulaPerTrobar;
    int finder = frase.find(paraulaPerTrobar); //Utilitzem la funció .find per trobar una paraula
    if (finder != string::npos) //Si la funció no està al final del string llavors diu que s'ha trobat la paraula
    {
        cout << "La sequencia '" << paraulaPerTrobar << "' s'ha trobat, esta a la posicio " << finder << endl;
        goto start; //Repeteix el programa si la paraula es troba
    }
    else
    {
        cout << "La sequencia '" << paraulaPerTrobar << "' no s'ha trobat" << endl << endl; //Diu que la paraula no s'ha trobat
    }

    //Esborrar frase
    while (frase.length() != 0) //Fa un bucle que repeteix fins que la llargada de la frase és 0
    {
        cout << "Frase actual: " << frase << endl;
        int posicio = frase.find_last_of(' '); //Troba l'últim espai de la frase per verificar que està al final
        if (posicio != string::npos) //Si la funció no està al final del string llavors borra l'última paraula
        {
            frase.erase(posicio);
        }
        else
        {
            frase = ""; //Si la funció està al final del string llavors no fes res
        }
    }
    cout << "\nFrase esborrada completament\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
