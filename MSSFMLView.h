#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"




class MSSFMLView
{
    MinesweeperBoard & board;
public:
    explicit MSSFMLView(MinesweeperBoard & b);

    void draw (sf::RenderWindow & win);
};
