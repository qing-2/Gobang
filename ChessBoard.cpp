#include "ChessBoard.h"

ChessBoard::ChessBoard(int w, int h)
{
    this->w = w;
    this->h = h;

    table = (Chessman*)malloc(sizeof(Chessman) * w * h);

    for (int i = 0; i < w * h; i++) {
        table[i].type = chessType::NONE;
    }
}

ChessBoard::~ChessBoard()
{
    if (table != nullptr) {
        free(table);
        table = nullptr;
    }
}

chessType ChessBoard::get(int x, int y)
{
    return table[x * w + y].type;
}

void ChessBoard::print()
{
    cout << left << setw(3) << ' ';
    for (int i = 1; i <= w; i++) {
        cout << left << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < h; i++) {
        cout << left << setw(3) << i + 1;
        for (int j = 0; j < w; j++) {
            chessType t = get(i, j);
            if (t == BLACK) {
                cout << left << setw(3) << 'B';
            } else if (t == WHITE) {
                cout << left << setw(3) << 'W';
            } else if (t == NONE) {
                cout << left << setw(3) << '*';
            }
        }
        printf("\n");
    }
}

bool ChessBoard::changeMan(int x, int y, chessType t)
{
    if (table[x * w + y].type == NONE) {
        table[x * w + y].type = t;
        return true;
    } else {
        return false;
    }
}

// in 4 directions to test whether 5 chesses of the same color connected into a line
bool ChessBoard::win(int x, int y, chessType t)
{
    // every test is from left to right
    int contin = 0; // the continous chess number

    // in a row
    for (int i = -4, index; i < 5; i++) {
        if (y + i > w)
            return false;
        else if (y + i < 0)
            continue;
        else {
            index = x * w + y + i;
            if (table[index].type == t) {
                contin++;
                // cout << "contin=" << contin << endl;
            } else {
                contin = 0;
            }
        }
        if (contin == 5) {
            return true;
        }
    }
    // in a column
    for (int i = -4, index; i < 5; i++) {
        if (x + i > h)
            return false;
        else if (x + i < 0)
            continue;
        else {
            index = (x + i) * w + y;
            if (table[index].type == t) {
                contin++;
                // cout << "contin=" << contin << endl;
            } else {
                contin = 0;
            }
        }
        if (contin == 5) {
            return true;
        }
    }
    // left up to right down
    for (int i = -4, index; i < 5; i++) {
        if (x + i > h || y + i > w)
            return false;
        else if (x + i < 0 || y + i < 0)
            continue;
        else {
            index = (x + i) * w + y + i;
            if (table[index].type == t) {
                contin++;
                // cout << "contin=" << contin << endl;
            } else {
                contin = 0;
            }
        }
        if (contin == 5) {
            return true;
        }
    }
    // left down to right up
    for (int i = -4, index; i < 5; i++) {
        if (x + i > h || y - i < 0) // right overflow
            return false;
        else if (x + i < 0 || y - i > w) // left overflow
            continue;
        else {
            index = (x + i) * w + y - i;
            if (table[index].type == t) {
                contin++;
                // cout << "contin=" << contin << endl;
            } else {
                contin = 0;
            }
        }
        if (contin == 5) {
            return true;
        }
    }
    return false;
}