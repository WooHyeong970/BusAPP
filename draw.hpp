#pragma once
#include <string>
#include <vector>
#include <ncurses.h>
//#include "unit.hpp"

using namespace std;

class Palette
{
public:
//    WINDOW * BOARD;
    void Draw(int x, int y, int width, int height, int textX, int textY, string text);
    void drawOutline(int x, int y, int width, int height);
//    void drawPointer(int index, vector<Unit*> unitVec);
};
