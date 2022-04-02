#include "Chessboard.h"

int main()
{
    int x, y;
    ChessBoard chess_board(15, 10);

    for (int i = 1;; i++) {
        chess_board.print();
        if (i % 2) {
            // get valid input of Black
            while (1) {
                cout << "Black go :" << endl;
                cin >> x >> y;
                x--;
                y--;
                if (x >= 0 && y >= 0 && x < chess_board.h && y < chess_board.w) {
                    chessType t = chess_board.get(x, y);
                    if (t != NONE) {
                        cout << "Invalid input! this cell is not empty,please try again !" << endl;
                    } else
                        break;
                } else {
                    cout << "Invalid input! out of board, please try again !" << endl;
                }
            }
            // play chess and test
            chess_board.changeMan(x, y, BLACK);
            if (chess_board.win(x, y, BLACK)) {
                chess_board.print();
                cout << "Black win!" << endl;
                break;
            }
        } else {
            // get valid input of White
            while (1) {
                cout << " White go : " << endl;
                cin >> x >> y;
                x--;
                y--;
                if (x >= 0 && y >= 0 && x < chess_board.h && y < chess_board.w) {
                    chessType t = chess_board.get(x, y);
                    if (t != NONE) {
                        cout << "Invalid input! this cell is not empty,please try again !" << endl;
                    } else
                        break;
                } else {
                    cout << "Invalid input! out of board, please try again !" << endl;
                }
            }
            // play chess and test
            chess_board.changeMan(x, y, WHITE);
            if (chess_board.win(x, y, WHITE)) {
                chess_board.print();
                cout << "White Win!" << endl;
                break;
            }
        }
    }
    return 0;
}