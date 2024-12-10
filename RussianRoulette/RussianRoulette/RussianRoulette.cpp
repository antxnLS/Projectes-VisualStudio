// RussianRoulette.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int number, guess;
    char jugarDeNou;
    do
    {
    cout << "Choose a number (1-6)" << endl;
    cin >> guess;
    srand(time(0));
    number = rand() % 6 + 1;
    if (guess == number)
    {
        cout << "Has muerto" << endl;
    }
    else if (guess !=number)
    {
        cout << "Estas vivo, el numero era: " << number << endl;
    }
    
    } while (true);
}