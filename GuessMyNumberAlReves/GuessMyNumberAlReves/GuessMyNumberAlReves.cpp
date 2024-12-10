#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Joc al reves
void main() {
int number; int tries = 0, guess = 0;
cout << "Joc al reves\n";
cin >> number;
while (guess != number) {
    srand(time(0));
    cout << "Introdueix un numero per que ho adivini l'ordinador: ";
    cout << "Crec que el numero es: " << guess << endl;
    tries++;
}
if (guess == number)
{
    cout << "Ho has fet en " << tries << " intents";
}

}