#pragma once

enum chessType {
    NONE,
    BLACK,
    WHITE
};

class Chessman
{
public:
    chessType type = chessType::NONE;
};
