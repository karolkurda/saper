#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"
#include "MSBoardTextView.h"


class MSSFMLView
{

    MinesweeperBoard & board;
    sf::Texture t0, t1, t2, t3, t4, t5, t6, t7, t8, tflag, tmine, tunrevealed;
    sf::Sprite s0, s1, s2, s3, s4, s5, s6, s7, s8, sflag, smine, sunrevealed;
    sf::Font font;
    sf::Text win,lose;

public:


    void draw (sf::RenderWindow &window);

    explicit MSSFMLView(MinesweeperBoard &board);


};
