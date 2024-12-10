// ProjecteCount.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{

int i = 0;

//Counting forward 0 1 2 3 4 5 6 7 8 9
while (i <= 9)
{
cout << i;
cout << " ";
i = i + 1;
}
cout << endl;
//Counting backward 9 8 7 6 5 4 3 2 1 0

i = 9;
while (i >= 0)
{
	cout << i; 
	cout << " ";
	i = i - 1;
}
cout << endl;
//Counting by fives 0 5 10, 50
i = 0;
while (i <= 50)
{
	cout << i;
	cout << " ";
	i = i + 5;
}
//Counting with null statements 0 1 2 3 4 5 6 7 8 9

//Counting with nested for loops 0.0 0.1 0.2, 4.0 4.1 4.2
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
