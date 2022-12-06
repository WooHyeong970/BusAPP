#include "board.hpp"

void Board::deleteUnit()
{
    for(Unit * u : unitVec)
        delete u;
}

void Board::drawUnit()
{
    for(int i = 0; i < unitNumber; i++)
    {
        unitVec[i]->setX(x);
        unitVec[i]->setY((width / unitNumber) * i+1);
        unitVec[i]->setPointerX(x+(height/2));
        unitVec[i]->setPointerY(unitVec[i]->getY()+1);
        unitVec[i]->Draw();
    }
}

void Board::setName(string s)
{
    name = s;
}

void Board::setX(int n)
{
    x = n;
}

void Board::setWidth(int n)
{
    width = n;
}

void Board::setHeight(int n)
{
    height = n;
}

void Board::setUnitNumber(int n)
{
    unitNumber = n;
}

int Board::getUnitNumber()
{
    return unitNumber;
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

string Board::getName()
{
    return name;
}

int Board::getX()
{
    return x;
}
