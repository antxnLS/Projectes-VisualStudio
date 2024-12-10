#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace sf;

class Obstacle {
public:
    RectangleShape shape;

    Obstacle(float x, float height) {
        shape.setSize(Vector2f(50, height));
        shape.setFillColor(Color::Green);
        shape.setPosition(x, 0);
    }

    void move(float dx) {
        shape.move(dx, 0);
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // Semilla para aleatoriedad

    float speed = 10.0f;
    float obstacleSpeed = -5.0f;
    RenderWindow window(VideoMode(2560, 1440), "Flappy Bird Clone");
    window.setFramerateLimit(60);

    RectangleShape player(Vector2f(50, 50));
    player.setFillColor(Color::Red);
    player.setOrigin(Vector2f(25, 25));
    player.setPosition(Vector2f(50, 720)); // Centrado verticalmente

    std::vector<Obstacle> obstacles;
    float gap = 300.0f; // Espacio entre los obstáculos

    // Generar obstáculos iniciales
    for (int i = 0; i < 5; ++i) {
        float height = rand() % (720 - static_cast<int>(gap)); // Altura aleatoria
        obstacles.emplace_back(1280 + i * 400, height); // Espaciado entre obstáculos
    }

    while (window.isOpen())
    {
        player.rotate(1.5f);
        player.move(Vector2f(0, 6));

        window.clear(Color::Black);

        // Manejo de entrada
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            player.move(0, -speed);
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            player.move(0, speed);
        }

        // Mover y dibujar obstáculos
        for (auto& obstacle : obstacles) {
            obstacle.move(obstacleSpeed);
            window.draw(obstacle.shape);
        }

        // Reposicionar obstáculos que salieron de la pantalla
        if (!obstacles.empty() && obstacles.front().shape.getPosition().x < -50) {
            float height = rand() % (720 - static_cast<int>(gap)); // Nueva altura aleatoria
            obstacles.erase(obstacles.begin()); // Eliminar el obstáculo de la izquierda
            obstacles.emplace_back(1280, height); // Añadir nuevo obstáculo
        }

        window.draw(player);
        window.display();
    }

    return 0;
}
