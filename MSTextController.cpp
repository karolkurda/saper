#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

using namespace std;
MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board), view(view){

}
void MSTextController::play() {
    view.display();
    while (board.getGameState() == RUNNING) {
        char choice;
        int row, col;
        cout << "Choose row, then choose column: " << std::endl;
        cin >> row >> col;
        cout << "What do you want to do? \n";
        cout
                << "If you want to reveal the field, type <r>.\nIf you want to flag the field, type <f> \n(Please make sure that you're using lowercase letters): ";
        cin >> choice;

            if (choice == 'r') {
                board.revealField(row, col);
            } else continue;
            board.debug_display();
            view.display();

            if (choice == 'f') {
                board.toggleFlag(row, col);
            } else continue;
            board.debug_display();
            view.display();


        }
        if (board.getGameState() == FINISHED_LOSS) cout << "LOSE" << endl;
        if (board.getGameState() == FINISHED_WIN) cout << "WIN" << endl;
    }
