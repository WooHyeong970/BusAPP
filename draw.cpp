#include "draw.hpp"

void Palette::drawOutline(int x, int y, int width, int height)
{
    // 사각 꼭지점
    mvprintw(x,y,"+");
    mvprintw(x,y+width-1,"+");
    mvprintw(x+height-1,y,"+");
    mvprintw(x+height-1,y+width-1,"+");

    // 윗변 그리기
    for(int i = 0; i < width-2; i++)
        mvprintw(x,y+i+1,"=");

    // 아랫변 그리기
    for(int i = 0; i < width-2; i++)
        mvprintw(x+height-1,y+i+1,"=");

    // 좌측변 그리기
    for(int i = 0; i < height-2; i++)
        mvprintw(x+i+1,y,"|");

    // 우측변 그리기
    for(int i = 0; i < height-2; i++)
        mvprintw(x+i+1,y+width-1,"|");
    
    
}

void Palette::Draw(int x, int y, int width, int height, int textX, int textY, string text)
{
    char c[100];
    strcpy(c, text.c_str());
    mvprintw(textX, textY, text.c_str());
    refresh();
    drawOutline(x, y, width, height);
    
//    refresh();
//    
//    BOARD = newwin(0, 0, 50, 0);
//    wrefresh(BOARD);
}
