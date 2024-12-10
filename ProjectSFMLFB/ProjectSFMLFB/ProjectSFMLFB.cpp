// ProjectSFML.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

int main()
{
    float speed = 10.0f;
    RenderWindow window(VideoMode(2560, 1440), "The title");
    window.setFramerateLimit(60);
    
    RectangleShape rect(Vector2f(50, 50));
    rect.setFillColor(Color::Red);
    rect.setOrigin(Vector2f(25, 25));
    rect.setPosition(Vector2f(50, 50));

    while (window.isOpen())
    {
        rect.rotate(1.5f);
        rect.move(Vector2f(0.05, 6));

        window.clear(Color::Black);
        window.draw(rect);
        window.display();

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            rect.move(0, -speed);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            rect.move(-speed, 0);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            rect.move(0, +speed);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            rect.move(+speed, 0);
        }
    }

    return 0;
}
