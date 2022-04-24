#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "MinesweeperBoard.h"


class MSBoardTextView {

    MinesweeperBoard &board;
public:

    void display();
    explicit MSBoardTextView(MinesweeperBoard &board);



};

#endif //SAPER_MSBOARDTEXTVIEW_H
