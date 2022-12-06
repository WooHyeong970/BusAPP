#pragma once
#include <vector>
#include "unit.hpp"
//#include "page.hpp"

using namespace std;

class Board
{
    // private 변수 목록
private:
    int unitNumber;
    int x;
    int width;
    int height;
    string name;
    
    // private 함수 목록
private:
    
    
    // public 변수 목록
public:
    vector<Unit*> unitVec;
    bool isDownBoard;
//    Page * parentPage;
    
    // public 함수 목록
public:
    void deleteUnit();
    void drawUnit();
    void setName(string s);
    void setX(int n);
    void setWidth(int n);
    void setHeight(int n);
    void setUnitNumber(int n);
    int getUnitNumber();
    int getWidth();
    int getHeight();
    string getName();
    int getX();
};
