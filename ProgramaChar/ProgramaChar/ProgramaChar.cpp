// ProgramaChar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

	#include <iostream>
    #include <string>
 	using namespace std;
 	
    int main( )
 	{
        string day;
        day = "Dilluns";

		char symbol1, symbol2, symbol3;
		cout << "Enter two initials, without any periods:\n";
 		cin >> symbol1 >> symbol2;
 		cout << "The two initials are:\n";
 		cout << symbol1 << symbol2 << endl;
 		cout << "Once more with a space:\n";
 		symbol3 = ' ';
 		cout << symbol1 << symbol3 << symbol2 << endl;
 		cout << "That's all.";
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
