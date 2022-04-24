#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board) {

    if (!t0.loadFromFile("0.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t1.loadFromFile("1.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t2.loadFromFile("2.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t3.loadFromFile("3.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t4.loadFromFile("4.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t5.loadFromFile("5.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t6.loadFromFile("6.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t7.loadFromFile("7.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!t8.loadFromFile("8.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!tflag.loadFromFile("flag.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!tmine.loadFromFile("mine.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if (!tunrevealed.loadFromFile("u.png")) {
        std::cerr << "erorr tekstury.png" << std::endl;
        abort();
    }
    if(!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "error font.ttf" << std::endl;
        abort();
    }



    win.setFont(font);
    win.setString("you win");

    win.setPosition((board.getBoardWidth()*100)/2.5f,(board.getBoardHeight()*100)/2.5f);
    win.setOrigin(win.getLocalBounds().width/2.0f,win.getLocalBounds().height/2.0f);
    win.setFillColor(sf::Color::Green);
    win.setCharacterSize(70);


    lose.setFont(font);
    lose.setString("you lose");

    lose.setPosition((board.getBoardWidth()*100)/2.5f,(board.getBoardHeight()*100)/2.5f);
    lose.setOrigin(lose.getLocalBounds().width/2.0f,lose.getLocalBounds().height/2.0f);
    lose.setFillColor(sf::Color::Red);
    lose.setCharacterSize(70);


    s0.setTexture(t0);
    s1.setTexture(t1);
    s2.setTexture(t2);
    s3.setTexture(t3);
    s4.setTexture(t4);
    s5.setTexture(t5);
    s6.setTexture(t6);
    s7.setTexture(t7);
    s8.setTexture(t8);
    sflag.setTexture(tflag);
    smine.setTexture(tmine);
    sunrevealed.setTexture(tunrevealed);
    }
    void MSSFMLView::draw(sf::RenderWindow &window) {
        float x = 100, y = 100;
        for (int row = 0; row < board.getBoardHeight(); row++) {
            for (int col = 0; col < board.getBoardWidth(); col++) {
                s0.setPosition(x * col, y * row);
                s1.setPosition(x * col, y * row);
                s2.setPosition(x * col, y * row);
                s3.setPosition(x * col, y * row);
                s4.setPosition(x * col, y * row);
                s5.setPosition(x * col, y * row);
                s6.setPosition(x * col, y * row);
                s7.setPosition(x * col, y * row);
                s8.setPosition(x * col, y * row);
                sflag.setPosition(x * col, y * row);
                smine.setPosition(x * col, y * row);
                sunrevealed.setPosition(x * col, y * row);
                if(board.getGameState()==FINISHED_LOSS)window.draw(lose);
                if(board.getGameState()==FINISHED_WIN)window.draw(win);

                switch (board.getFieldInfo(row, col)) {
                                case ' ':
                                    window.draw(s0);
                                    break;
                                case '1':
                                    window.draw(s1);
                                    break;
                                case '2':
                                    window.draw(s2);
                                    break;
                                case '3':
                                    window.draw(s3);
                                    break;
                                case '4':
                                    window.draw(s4);
                                    break;
                                case '5':
                                    window.draw(s5);
                                    break;
                                case '6':
                                    window.draw(s6);
                                    break;
                                case '7':
                                    window.draw(s7);
                                    break;
                                case '8':
                                    window.draw(s8);
                                    break;
                                case 'x':
                                    window.draw(smine);
                                    break;
                                case '_':
                                    window.draw(sunrevealed);
                                    break;
                                case 'F':
                                    window.draw(sflag);
                                    break;
                            }
                        }
                    }
                }