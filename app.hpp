#pragma once
#include <string>
#include <map>
#include "page.hpp"
#include "draw.hpp"

using namespace std;

class BusAPP
{
    // private 변수 목록
private:
    
    // private 함수 목록
private:
//    void Build(); // 모든 page, board, unit 생성 및 배치합니다.
    
    
    // public 변수 목록
public:
    enum { EXCUTE = 0, EXIT } state;
    map<string, Page*> pages;
    
    int pointerIndex;
    string curPage;
    
    // public 함수 목록
public:
    void Start(); // 어플의 시작 화면을 출력합니다.
    void Exit(); // 어플을 종료합니다.
    WINDOW * BOARD;
    
    void test1();
    void test2();
    
    void loadPage(string name); // name에 맞는 페이지를 화면에 출력합니다.
};
