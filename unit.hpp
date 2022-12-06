#pragma once
#include <iostream>
//#include <ncurses.h>
#include <string>
#include "draw.hpp"

using namespace std;

class Unit
{
    // private 변수 목록
private:
    string name;
    bool isButtonT = false;
    bool isTextM = false;
    string text;
    int pointerX;
    int pointerY;
    int x;
    int y;
    int width;
    int height;
    string linkedPage;
    
    // private 함수 목록
private:
    
    // public 변수 목록
public:
    
    // public 함수 목록
public:
    void Draw();
    void setName(string s);
    void setIsButtonT(bool b);
    void setIsTextM(bool b);
    void setText(string s);
    void setPointerX(int n);
    void setPointerY(int n);
    void setX(int n);
    void setY(int n);
    void setWidth(int n);
    void setHeight(int n);
    string getName();
    int getX();
    int getWidth();
    int getY();
    int getHeight();
    int getPointerX();
    int getPointerY();
    string getLicnkedPage();
    
//private:
////    WINDOW *BOARD;
//    string str;
//    int x;
//    int y;
//    int width;
//    int height;
//    bool isMiddle;
//    bool isDown;
//public:
//    virtual void show();
//    virtual void setText(string s);
//    virtual void setting(int x, int height, bool isM, bool isD);
//    int getX();
//    bool getIsDown();
//    void setX(int n);
};
