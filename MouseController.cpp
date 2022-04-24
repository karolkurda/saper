#include "MouseController.h"
#include "MSTextController.h"
#include "MinesweeperBoard.h"

MouseController::MouseController(MSSFMLView &view1 , MinesweeperBoard &board) : view(view1) , board(board) {}

void MouseController::playbymouse(sf::RenderWindow &window)
{


    while (window.isOpen() && board.getGameState() == RUNNING)
    {

        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            int col = event.mouseButton.x/100;
            int row = event.mouseButton.y/100;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    board.revealField(row, col);
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    board.toggleFlag(row, col);
                }
            }

            window.clear();
            view.draw(window);
            window.display();

        }
    }
}
