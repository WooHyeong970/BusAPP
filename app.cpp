#include "app.hpp"

void BusAPP::loadPage(string s)
{
    clear();
    if(s != curPage)
    {
        curPage = s;
        pointerIndex = 0;
    }
    
    Palette * palette = new Palette();
    palette->drawOutline(0, 0, 62, 42);
    
//    for(int i = 0; i < 60; i++)
//    {
//        mvprintw(25, i+1, "@");
//    }
//    
    refresh();
    
//    char c1[100];
//    int a = (int)pages[s]->boardVec.size();
//    string str = to_string(a);
//    strcpy(c1, str.c_str());
//    mvprintw(5, 5, c1);
//    refresh();
    
    for(Board * b : pages[s]->boardVec)
    {

//        char c1[100];
//        int a = (int)pages[s]->boardVec.size();
//        string str = to_string(a);
//        strcpy(c1, str.c_str());
//        mvprintw(4, 5, "123");
//        refresh();
//        mvprintw(5, 5, b->getName().c_str());
//        refresh();
        b->drawUnit();
    }
//    
//    mvprintw(25, 2, to_string(pages[s]->unitVec[pointerIndex]->getX()).c_str());
//    mvprintw(26, 2, to_string((pages[s]->unitVec[pointerIndex]->getWidth() / 2)).c_str());
//
    mvprintw(pages[s]->unitVec[pointerIndex]->getPointerX(), pages[s]->unitVec[pointerIndex]->getPointerY(), ">>");
    
        
    refresh();
    
    
    BOARD = newwin(0, 0, 50, 0);
    wrefresh(BOARD);
}

void BusAPP::Start()
{
    state = EXCUTE;
    curPage = "None";
    loadPage("Home");
}

void BusAPP::Exit()
{
    for(auto i = pages.begin(); i != pages.end(); i++)
    {
        i->second->deleteBoard();
        delete i->second;
    }
}

void BusAPP::test1()
{
    mvprintw(5,5,"+");
}

void BusAPP::test2()
{
    mvprintw(6,6,"+");
}
