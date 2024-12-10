#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para transform()

using namespace std;

// Función para seleccionar el color de acuerdo al número de la ruleta
string obtenerColor(int numero) {
    if (numero == 0) return "verde";
    if ((numero >= 1 && numero <= 10) || (numero >= 19 && numero <= 28))
        return (numero % 2 == 0) ? "negro" : "rojo";
    else
        return (numero % 2 == 0) ? "rojo" : "negro";
}

int main() {
    srand(time(0)); // Inicializamos la semilla para la generación de números aleatorios

    int opcion, apuestaNumero;
    string apuestaColor;
    double saldo = 100.0; // Saldo inicial del jugador
    double cantidadApostada;

    cout << "¡Bienvenido a la ruleta!" << endl;
    cout << "Comienzas con un saldo de 100 euros." << endl;

    while (saldo > 0) {
        cout << "\nSaldo actual: " << saldo << " euros." << endl;

        cout << "¿Cuánto dinero deseas apostar? ";
        cin >> cantidadApostada;

        // Validar que la cantidad apostada no sea mayor que el saldo disponible
        if (cantidadApostada > saldo) {
            cout << "No tienes suficiente saldo para realizar esta apuesta." << endl;
            continue;
        }
        else if (cantidadApostada <= 0) {
            cout << "La cantidad apostada debe ser mayor que 0." << endl;
            continue;
        }

        cout << "¿Qué tipo de apuesta deseas realizar?" << endl;
        cout << "1. Apostar a un número (0-36)" << endl;
        cout << "2. Apostar a un color (rojo/negro/verde)" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Introduce el número al que quieres apostar (0-36): ";
            cin >> apuestaNumero;
            if (apuestaNumero < 0 || apuestaNumero > 36) {
                cout << "Número inválido." << endl;
                continue;
            }
        }
        else if (opcion == 2) {
            cout << "Introduce el color al que quieres apostar (rojo/negro/verde): ";
            cin >> apuestaColor;

            // Convertir la entrada a minúsculas para evitar problemas de mayúsculas/minúsculas
            transform(apuestaColor.begin(), apuestaColor.end(), apuestaColor.begin(), ::tolower);

            // Validar que el color sea válido
            if (apuestaColor != "rojo" && apuestaColor != "negro" && apuestaColor != "verde") {
                cout << "Color inválido." << endl;
                continue;
            }
        }
        else {
            cout << "Opción inválida." << endl;
            continue;
        }

        int numeroRuleta = rand() % 37; // Genera un número aleatorio entre 0 y 36
        string colorRuleta = obtenerColor(numeroRuleta);

        cout << "La ruleta ha caído en el número " << numeroRuleta << " (" << colorRuleta << ")." << endl;

        // Verificar el resultado de la apuesta
        if (opcion == 1) { // Apuesta al número
            if (numeroRuleta == apuestaNumero) {
                cout << "¡Felicidades! Has ganado la apuesta al número." << endl;
                saldo += cantidadApostada * 35; // Pago 35 a 1 por apuesta directa al número
            }
            else {
                cout << "Lo siento, has perdido la apuesta al número." << endl;
                saldo -= cantidadApostada;
            }
        }
        else if (opcion == 2) { // Apuesta al color
            if (colorRuleta == apuestaColor) {
                cout << "¡Felicidades! Has ganado la apuesta al color." << endl;
                saldo += cantidadApostada; // Pago 1 a 1 por apuesta al color
            }
            else {
                cout << "Lo siento, has perdido la apuesta al color." << endl;
                saldo -= cantidadApostada;
            }
        }

        // Verificar si el jugador quiere continuar o retirarse
        if (saldo > 0) {
            char continuar;
            cout << "\n¿Deseas seguir jugando? (s/n): ";
            cin >> continuar;
            if (continuar == 'n' || continuar == 'N') {
                cout << "Te retiras con un saldo de " << saldo << " euros." << endl;
                break;
            }
        }
        else {
            cout << "Te has quedado sin saldo. ¡Gracias por jugar!" << endl;
        }
    }

    return 0;
}
