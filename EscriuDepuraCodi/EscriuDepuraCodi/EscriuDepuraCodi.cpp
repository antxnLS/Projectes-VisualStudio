// Programa: Escriu i Depura codi
// Nom: Anton Volegov
// Data: 27/09/2024

#include <iostream>
using namespace std;


void Exercici1()
{
    //Activitat 1
    bool esMajor;
    int edat; //Inicialitzem variables 
    cout << "Exercici 1.\n";
    cout << "Introdueix la teva edat: ";
    cin >> edat; //Preguntem al usuari que introdueixi un numero
    if (edat >= 18) //Mira si la edat introduida es major o igual a 18
    {
        esMajor = true;
    }
    else
    {
        esMajor = false;
    }
    cout << esMajor << endl;
}
   
void Exercici2()
{
    //Activitat 2
    int num1; //Inicialitzem variables
    cout << "Introdueix un numero: ";
    cin >> num1; 
    if (num1 % 2 == 0)
    {
        cout << "Es par" << endl;
    }
    else
    {
        cout << "No es par" << endl;
    }
}

void Exercici3()
{
    //Activitat 3
    int num2;
    int num2c;
    cout << "Introdueix un numero: ";
    cin >> num2;
    num2c = (7 - num2 % 7) % 7;
    cout << "Falta " << num2c << " unitats per que sigui multiple de 7" << endl;
}

void Exercici4()
{
    //Activitat 4 
    int segons;
    cout << "Introdueix els segons jugats: ";
    cin >> segons;
    
    int hores = segons/3600;
    segons %= 3600;
    
    int minuts = segons / 60;
    segons %= 60;

    cout << "Has jugat " << hores << " hores, " << minuts << " minuts i " << segons << " segons." << endl;
}

void Exercici5()
{
    //Activitat 5
  
    int punt1, punt2;
    cout << "Introdueix la primera puntuacio: ";
    cin >> punt1;
    cout << "Introdueix la segona puntuacio: ";
    cin >> punt2;
    //mes petita, mes gran o igual
    if (punt1 < punt2)
    {
        cout << "La primera es mes petita";
    }
    else if (punt1 > punt2)
    {
        cout << "La primera es mes gran";
    }
    else
    {
        cout << "Les dues puntuacions son iguals";
    }
    cout << endl;
}

void Exercici6()
{
    //Activitat 6
    int posicio;
    cout << "Introdueix la teva posicio: ";
    cin >> posicio;
    if (posicio <= 10) {
        cout << "Has quedat entre els 10 primers!" << endl;
    }
    else if (posicio <= 100) {
        cout << "Has quedat entre els 100 primers!" << endl;
    }
    else if (posicio <= 1000) {
        cout << "Has quedat entre els 1000 primers!" << endl;
    }
    else {
        cout << "Has quedat en una posicio superior a les 1000." << endl;
    }
}
void Exercici7()
{
    //Activitat 7

    int dni, lletra;
    cout << "Quin es el teu dni (00000000A)? ";
    cin >> dni;
    lletra = dni % 23;

    // Array de letras correspondientes
    char letras[] = { 'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D',
                     'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L',
                     'C', 'K', 'E' };

    cout << "La teva lletra es " << letras[lletra] << endl;
}
void Exercici8()
{
            //Activitat 8

            int seleccio;
            char jugarDeNou{};
        act8:
            do
            {
                cout << "Tria una dificultat" << endl;
                cout << "1 - Facil\n";
                cout << "2 - Mitja\n";
                cout << "3 - Dificil\n";
                cout << "Escull la dificultat que vols seleccionar: \n";
                cin >> seleccio;
                if (seleccio == 1)
                {
                    cout << "Estas segur que vols seleccionar la dificultat facil?\n";
                    cout << "Vols jugar de nou? (s/n)\n\n: ";
                    cin >> jugarDeNou;
                }
                else if (seleccio == 2)
                {
                    cout << "Estas segur que vols seleccionar la dificultat mitjana?" << endl;
                    cout << "Vols jugar de nou? (s/n): ";
                    cin >> jugarDeNou;
                }
                else if (seleccio == 3)
                {
                    cout << "Estas segur que vols seleccionar la dificultat dificil?" << endl;
                    cout << "Vols jugar de nou? (s/n): ";
                    cin >> jugarDeNou;
                }
                else {
                    cout << "Eleccio no valida." << endl;
                    goto act8;
                }
            } while (jugarDeNou == 's' || jugarDeNou == 'S');
}
  
int main() 
{
        int codi;
        cout << "Introdueix un numero per seleccionar el programa a executar (1-8)" << endl;
        cin >> codi;

        switch (codi) {
        case 1:
            Exercici1();
            break;
        case 2:
            Exercici2();
            break;
        case 3:
            Exercici3();
            break;
        case 4:
            Exercici4();
            break;
        case 5:
            Exercici5();
            break;
        case 6:
            Exercici6();
            break;
        case 7:
            Exercici7();
            break;
        case 8:
            Exercici8();
            break;
        }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
