#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace sf;
using namespace std;


const double PI = 3.14159265358979323846;

void pifagor(sf::RenderWindow& window, int n, double x0, double y0, double a, double fi, double alpha) {
    if (n == 0) return;


    double x1 = x0 + a * cos(fi);
    double y1 = y0 - a * sin(fi);
    double x2 = x1 - a * sin(fi);
    double y2 = y1 - a * cos(fi);
    double x3 = x0 - a * sin(fi);
    double y3 = y0 - a * cos(fi);
    int b = cos(alpha) * a;
    int c = sin(alpha) * a;
    double x4 = x3 + b * cos(fi + alpha);
    double y4 = y3 - b * sin(fi + alpha);


    Vertex line1[] = { sf::Vertex(sf::Vector2f(x0, y0)), sf::Vertex(sf::Vector2f(x1, y1)) };
    Vertex line2[] = { sf::Vertex(sf::Vector2f(x1, y1)), sf::Vertex(sf::Vector2f(x2, y2)) };
    Vertex line3[] = { sf::Vertex(sf::Vector2f(x2, y2)), sf::Vertex(sf::Vector2f(x3, y3)) };
    Vertex line4[] = { sf::Vertex(sf::Vector2f(x3, y3)), sf::Vertex(sf::Vector2f(x0, y0)) };
    Vertex line5[] = { sf::Vertex(sf::Vector2f(x3, y3)), sf::Vertex(sf::Vector2f(x4, y4)) };
    Vertex line6[] = { sf::Vertex(sf::Vector2f(x2, y2)), sf::Vertex(sf::Vector2f(x4, y4)) };



    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(line3, 2, sf::Lines);
    window.draw(line4, 2, sf::Lines);
    window.draw(line5, 2, sf::Lines);
    window.draw(line6, 2, sf::Lines);


    n--;
    pifagor(window, n, x3, y3, b, fi + alpha, alpha);
    pifagor(window, n, x4, y4, c, fi + alpha - PI / 2, alpha);
    }

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "Pifagor Tree");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        pifagor(window, 15, 450, 400, 100, 0, PI / 4);  // Глубина, координаты, размер, угол, угол крыши

        window.display();
    }

    return 0;
}
