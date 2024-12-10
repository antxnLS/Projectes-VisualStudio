// ProjectSFML.cpp
// Nom: Anton Volegov
// Data: 25/10/2024

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(700, 700), "Mosaic"); //Crea una finestra de mida 700 x 700 amb el nom de Mosaic
    window.setFramerateLimit(60); //Posa els maxims frames 60
    
    CircleShape rombe1(50, 4); //Rombe 1
    rombe1.setFillColor(Color(150, 50, 250)); //Posa el color
    rombe1.setOrigin(Vector2f(50, 50)); //Posa el origen de la forma
    rombe1.setPosition(Vector2f(350, 350)); //Posa la posicio 

    CircleShape rombe2(100, 4); //Rombe 2
    rombe2.setFillColor(Color(250, 226, 0)); //Posa el color
    rombe2.setOrigin(Vector2f(100, 100)); //Posa el origen de la forma
    rombe2.setPosition(Vector2f(350, 350)); //Posa la posicio 

    RectangleShape quadrat1(Vector2f(200, 200)); //Quadrat 1
    quadrat1.setFillColor(Color(173, 0, 0)); //Posa el color
    quadrat1.setOrigin(Vector2f(100, 100)); //Posa el origen de la forma
    quadrat1.setPosition(Vector2f(350, 350)); //Posa la posicio 

    CircleShape rombe3(150, 4); //Rombe 3
    rombe3.setFillColor(Color(255, 84, 0)); //Posa el color
    rombe3.setOrigin(Vector2f(150, 150)); //Posa el origen de la forma
    rombe3.setPosition(Vector2f(350, 350)); //Posa la posicio 

    CircleShape rombe4(200, 4); //Rombe 4
    rombe4.setFillColor(Color(0, 164, 255)); //Posa el color
    rombe4.setOrigin(Vector2f(200, 200)); //Posa el origen de la forma
    rombe4.setPosition(Vector2f(350, 350)); //Posa la posicio 

    RectangleShape quadrat2(Vector2f(300, 300)); //Quadrat 2
    quadrat2.setFillColor(Color(25, 168, 0)); //Posa el color
    quadrat2.setOrigin(Vector2f(150, 150)); //Posa el origen de la forma
    quadrat2.setPosition(Vector2f(350, 350)); //Posa la posicio 

    RectangleShape quadrat3(Vector2f(400, 400)); //Quadrat 3
    quadrat3.setFillColor(Color(68, 74, 168)); //Posa el color
    quadrat3.setOrigin(Vector2f(200, 200)); //Posa el origen de la forma
    quadrat3.setPosition(Vector2f(350, 350)); //Posa la posicio 

    CircleShape cercle1(282); //Cercle 1
    cercle1.setFillColor(Color(0, 189, 120)); //Posa el color
    cercle1.setOrigin(Vector2f(282, 282)); //Posa el origen de la forma
    cercle1.setPosition(Vector2f(350, 350)); //Posa la posicio 

    RectangleShape quadrat4(Vector2f(560, 560)); //Quadrat 4
    quadrat4.setFillColor(Color(62, 92, 81)); //Posa la posicio 
    quadrat4.setOrigin(Vector2f(280, 280)); //Posa el origen de la forma
    quadrat4.setPosition(Vector2f(350, 350)); //Posa la posicio 

    while (window.isOpen()) //Mentre la finestra esta oberta
    {
        window.clear(Color(58, 2, 84)); //Posa el color del fons
        quadrat4.rotate(-0.01); //Estableix la rotacio de la forma especificada
        quadrat3.rotate(0.1); //Estableix la rotacio de la forma especificada
        quadrat2.rotate(0.2); //Estableix la rotacio de la forma especificada
        rombe4.rotate(0.3); //Estableix la rotacio de la forma especificada
        rombe3.rotate(0.4); //Estableix la rotacio de la forma especificada
        quadrat1.rotate(0.5); //Estableix la rotacio de la forma especificada
        rombe2.rotate(0.6); //Estableix la rotacio de la forma especificada
        rombe1.rotate(0.7); //Estableix la rotacio de la forma especificada
        window.draw(quadrat4); //Dibuixa la forma especificada
        window.draw(cercle1); //Dibuixa la forma especificada
        window.draw(quadrat3); //Dibuixa la forma especificada
        window.draw(quadrat2); //Dibuixa la forma especificada
        window.draw(rombe4); //Dibuixa la forma especificada
        window.draw(rombe3); //Dibuixa la forma especificada
        window.draw(quadrat1); //Dibuixa la forma especificada
        window.draw(rombe2); //Dibuixa la forma especificada
        window.draw(rombe1); //Dibuixa la forma especificada
        window.display(); //Dibuixa la finestra
    }
    return 0;
}
