#include "page.hpp"
//
Page::Page()
{
//    name = s;
    x = 0;
    isDownBoard = false;
}

//Page::~Page()
//{
////    cout << "This is a Page distructor\n";
//}

string Page::getName()
{
    return name;
}

//void Page::push(Button * b)
//{
//    if(btn_vec.empty())
//        btn_vec.push_back(b);
//    else
//    {
//        
//    }
//}

void Page::deleteBoard()
{
    for(Board * b : boardVec)
    {
        b->deleteUnit();
        delete b;
    }
}

void Page::setName(string s)
{
    name = s;
}

void Page::setX(int n)
{
    x = n;
}

int Page::getX()
{
    return x;
}
