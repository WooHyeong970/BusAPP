#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "button.hpp"
#include "board.hpp"
//
using namespace std;
//
class Page
{
    // private 변수 목록
private:
    string name;
    int x;
    
    // private 함수 목록
private:
    
    // public 변수 목록
public:
    vector<Board*> boardVec;
    vector<Unit*> unitVec;
    bool isDownBoard;
    
    // public 함수 목록
public:
    Page();
    void deleteBoard();
    void setName(string s);
    void setX(int n);
    int getX();
    string getName();
    
//private:
//    string name;
//public:
////    Page(string s);
//    ~Page();
//    int x = 0;
//    int y = 0;
//    int unitNum = 0;
//    int unitIdx = 0;
//    vector<Button*> btn_vec;
//    string getName();
//    void add();
//    void push(Button * b);
};
