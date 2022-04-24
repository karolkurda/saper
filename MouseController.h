#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"
#include "MSTextController.h"
#include "MSBoardTextView.h"

#ifndef SAPER_MOUSECONTROLLER_H
#define SAPER_MOUSECONTROLLER_H


class MouseController {
MSSFMLView &view;
MinesweeperBoard &board;
public:
    explicit MouseController(MSSFMLView &view1, MinesweeperBoard &board);
    void playbymouse(sf::RenderWindow &window);
};


#endif //SAPER_MOUSECONTROLLER_H
