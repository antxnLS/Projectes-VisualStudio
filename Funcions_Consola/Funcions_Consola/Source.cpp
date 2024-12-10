#include <iostream>
#include <cmath>

using namespace std;

int factorial()
{
    int num, num2 = 1; //Inicialitzem les variables
    cout << "Introdueix un numero: "; //Li diu al usuari que introdueixi un numero
    cin >> num; //L'usuari introdueix un numero
    cout << "El factorial de " << num << " es: "; 

    for (int i = 1; i <= num; i++) {
        num2 *= i; //La variable es multiplica per i, i almaçena tots els numeros des de 1 a i

        if (i < num) { 
            cout << i << " * "; //Diu el numero i posa el signe de multiplicacio fins arribar al ultim numero
        }
        else {
            cout << i << " = " << num2 << endl;
        }
    }
    return num2;
}

void primer()
{

    bool esPrimer = true; //Inicialitzem el boolea com a true per defecte
    int num; //Inicialitzem una variable per que l'usuari posi un numero

    cout << "Introdueix un numero: "; //Li diu al usuari que introdueixi un numero
    cin >> num; //L'usuari introdueix un numero
    double sqrt_of_n = sqrt(num); //Creem una variable de tipus double per posar el resultat de la arrel del numero introduit pel usuari

    if (num < 2) { //Si el numero es mes petit que 2, sabem que no es primer
        esPrimer = false; //
    }

    for (int i = 2; i <= sqrt_of_n; i++) { //Comprovem si el numero es divisible per qualsevol nombre entre 2 i sqrt(num)
        if (num % i == 0) { //Mira si el residu del numero es 0
            esPrimer = false; //Si troba un divisor, el numero no es primer
            break; //Sortim del bucle ja que no cal continuar comprovant mes divisors
        }
    }

    if (esPrimer == true) {
        cout << "Es primer" << endl; //Si es primer, 
    }
    else {
        cout << "No es primer" << endl;
    }
}