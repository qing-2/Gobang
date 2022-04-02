#include "Chessman.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class ChessBoard {
public:
    ChessBoard(int w, int h);
    ~ChessBoard();

    chessType get(int x, int y);
    bool win(int x, int y, chessType opponent);
    bool changeMan(int x, int y, chessType opponent);

    int w, h; // 宽度=列数，高度=行数

    Chessman* table = nullptr;

    void print();
};