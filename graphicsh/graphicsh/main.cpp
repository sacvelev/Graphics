#include <SFML/Graphics.hpp>
#include <cmath>

// Константа для перевода градусов в радианы
const double PI = 3.14159265358979323846;

// Функция для рисования фрактала Пифагора
void pifagor(sf::RenderWindow& window, int n, int x0, int y0, double a, double fi, double alpha) {
    if (n == 0) return;

    // Вычисляем координаты вершин квадрата
    int x1 = x0 + a * cos(fi);
    int y1 = y0 - a * sin(fi);
    int x2 = x1 + a * cos(fi + PI / 2);
    int y2 = y1 - a * sin(fi + PI / 2);
    int x3 = x0 + a * cos(fi + PI / 2);
    int y3 = y0 - a * sin(fi + PI / 2);

    // Рисуем квадрат (домик)
    sf::Vertex line1[] = { sf::Vertex(sf::Vector2f(x0, y0)), sf::Vertex(sf::Vector2f(x1, y1)) };
    sf::Vertex line2[] = { sf::Vertex(sf::Vector2f(x1, y1)), sf::Vertex(sf::Vector2f(x2, y2)) };
    sf::Vertex line3[] = { sf::Vertex(sf::Vector2f(x2, y2)), sf::Vertex(sf::Vector2f(x3, y3)) };
    sf::Vertex line4[] = { sf::Vertex(sf::Vector2f(x3, y3)), sf::Vertex(sf::Vector2f(x0, y0)) };

    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(line3, 2, sf::Lines);
    window.draw(line4, 2, sf::Lines);

    // Вычисляем новые параметры для рекурсивного вызова
    double a_new = a * cos(alpha); // Новый размер домика
    double fi_left = fi + alpha;   // Угол для левого домика
    double fi_right = fi - alpha;  // Угол для правого домика

    // Рекурсивно рисуем домики на крышах
    pifagor(window, n - 1, x2, y2, a_new, fi_left, alpha);
    pifagor(window, n - 1, x3, y3, a_new, fi_right, alpha);
}

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pifagor Tree");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Рисуем фрактал Пифагора
        pifagor(window, 10, 400, 500, 100, 0, PI / 4);  // Глубина, координаты, размер, угол, угол крыши

        window.display();
    }

    return 0;
}
