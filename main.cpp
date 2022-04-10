#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"


int main()
{
    MinesweeperBoard board (2, 2, GameMode::EASY);
    board.debug_display();
    MSBoardTextView view (bofdsard);
    MSTextController ctrl (board, view );

    ctrl.play();
}
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(7, 4, DEBUG);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora

    // symulujemy rozgrywkę
    board.toggleFlag(0,0);
    board.revealField(2,3);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;
}
*/