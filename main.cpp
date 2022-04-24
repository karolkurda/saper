#include "SFML/Window.hpp"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MouseController.h"



int main() {
    const int fieldWidth = 100; //szerokosc pola, prosze nie zmieniac
    const int fieldHeight = 100; //wysokosc pola, prosze nie zmieniac
    const int boardWidth = 10; //szerokosc planszy wprowadzamy tutaj
    const int boardHeight = 10; //wysokosc planszy wprowadzamy tutaj


    sf::RenderWindow window(sf::VideoMode(fieldWidth * boardWidth, fieldHeight * boardHeight), "SAPER", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30);

    MinesweeperBoard board(boardWidth, boardHeight, DEBUG); //tutaj zmieniamy tryb
    MSSFMLView view (board);
    MouseController ctrl (view,board);

    ctrl.playbymouse(window);

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                continue;
            }
            if (event.type == sf::Event::Resized) {
                continue;
            }

        }

        window.clear();
        view.draw(window);
        window.display();

    }

    return 0;
}