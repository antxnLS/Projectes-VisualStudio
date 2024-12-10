#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void main() { //Posem void en canvi de int per no haver de posar return al final del programa
    int number; int tries = 0, guess = 0; //Inicialitzem variables
    srand(time(0)); //Utilitzem una funcio de la llibreria cstdlib
    number = rand() % 100 + 1; //Assignem un nombre aleatori a la variable number, que esta entre 1 i 100
    while (guess != number) { //Mentre el nombre indicat no sigui el nombre secret, llavors fes el bucle
        cout << "Adivina el nombre: ";
        cin >> guess; //Intentem adivinar el nombre
        tries++; //Li afegim 1 a intents per contar quants intents hem fet
        if (guess > number) { //Si el nombre adivinat es mes gran, llavors diu que es mes gran
            cout << "El nombre es massa gran" << endl; 
        }
        else if (guess < number) { //Si el nombre adivinat es mes petit, llavors diu que es mes petit
            cout << "El nombre es massa petit" << endl; 
        } 
    }
    cout << "Ho has fet en " << tries << " intents" << endl; //Indica a quants intents hem adivinat el nombre
}