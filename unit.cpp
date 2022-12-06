#include "unit.hpp"

//void Unit::show()
//{
//    cout << "test\n";
//    mvprintw(0, 0, "+");
//    mvprintw(5, 0, "+");
//    mvprintw(0, 20, "+");
//    mvprintw(5, 20, "+");
//    move(0,1);
//    attron(A_NORMAL);
//    attron(COLOR_PAIR(1));
//    printw("===================");
//    move(5,1);
//    attron(COLOR_PAIR(2));
//    printw("===================");
//    move(6,1);
//    attron(COLOR_PAIR(5));
//    
//    move(10,0);
//    refresh();
    
//    mvprintw(x, 0, "+");
//    mvprintw(x, WIDTH, "+");
//    mvprintw(HEIGHT, 0, "+");
//    mvprintw(HEIGHT, WIDTH, "+");
//    for(int i = 0; i < WIDTH-1; i++)
//        mvprintw(x, i+1, "=");
//    for(int i = 0; i < WIDTH-1; i++)
//        mvprintw(HEIGHT, i+1, "=");
//    mvprintw(x+1, 0, "|");
//    mvprintw(x+1, WIDTH, "|");
//
//    char c[100];
//    strcpy(c, str.c_str());
//    mvprintw(x+2, y+1, c);
//
//    refresh();
//
//    BOARD = newwin(0, 0, 49, 0);
//    wrefresh(BOARD);
//}

//void Unit::setText(string s)
//{
//    str = s;
//}
//
//void Unit::setting(int x, int height, bool isM, bool isD)
//{
//    this->x = x;
//    this->y = 0;
//    this->width = 60;
//    this->height = height;
//    isMiddle = isM;
//    isDown = isD;
//}
//
//bool Unit::getIsDown()
//{
//    return isDown;
//}
void Unit::Draw()
{
    Palette * palette = new Palette();
    
    int temp;
    if(isTextM)
        temp = (y + (width / 2)) - ((int)text.length() / 2);
    else
        temp = 0;
    
//    mvprintw(2, 2, ("x : " + to_string(x)).c_str());
//    mvprintw(3, 2, ("y : " + to_string(y)).c_str());
//    mvprintw(4, 2, ("width : " + to_string(width)).c_str());
//    mvprintw(5, 2, ("height : " + to_string(height)).c_str());
//    mvprintw(6, 2, ("x+(height/2) : " + to_string(x+(height/2))).c_str());
//    mvprintw(7, 2, ("temp : " + to_string(temp)).c_str());
//    mvprintw(8, 2, text.c_str());
//    
//    refresh();
    
    palette->Draw(x, y, width, height, x+(height/2), temp, text);
}

void Unit::setName(string s)
{
    name = s;
}

void Unit::setIsButtonT(bool b)
{
    isButtonT = b;
}

void Unit::setIsTextM(bool b)
{
    isTextM = b;
}

void Unit::setText(string s)
{
    text = s;
}

void Unit::setPointerX(int n)
{
    pointerX = n;
}

void Unit::setPointerY(int n)
{
    pointerY = n;
}

void Unit::setX(int n)
{
    x = n;
}

void Unit::setY(int n)
{
    y = n;
}

void Unit::setWidth(int n)
{
    width = n;
}

void Unit::setHeight(int n)
{
    height = n;
}

string Unit::getName()
{
    return name;
}

int Unit::getX()
{
    return x;
}

int Unit::getWidth()
{
    return width;
}

int Unit::getY()
{
    return y;
}

int Unit::getHeight()
{
    return height;
}

int Unit::getPointerX()
{
    return pointerX;
}

int Unit::getPointerY()
{
    return pointerY;
}

string Unit:get
