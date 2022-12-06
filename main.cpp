#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include "app.hpp"
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

//WINDOW * BOARD;

void Setup();
void Input(BusAPP * bus, Page * cur);
void Build(BusAPP * bus);
Page * CreatePage(BusAPP * bus, stringstream ss);
Board * CreateBoard(Page * page, stringstream ss);
void CreateUnit(Page * page, Board * board, stringstream ss);

Page * curPage = new Page();
Board * curBoard = new Board();

int main(void)
{
    Setup();
    BusAPP * busAPP = new BusAPP();
    Build(busAPP);
    
//    mvprintw(14, 5, to_string((int)busAPP->pages["Home"]->boardVec.size()).c_str());
//    refresh();
    
//    BOARD = newwin(0, 0, 50, 0);
//    wrefresh(BOARD);
    
    busAPP->Start();
    while(busAPP->state != busAPP->EXIT)
    {
        Input(busAPP, curPage);
    }
    busAPP->Exit();
}

/*
 Page List
 - Home
 - Reserve
 - Check
 - Time
 */

void Build(BusAPP * bus)
{
    Page * curPage = new Page();
    Board * curBoard = new Board();
    
    ifstream file("APPSetting.txt");
    
    if(file.is_open())
    {
        string data;
        while(getline(file, data))
        {
            string type;
            stringstream ss;
            ss.str(data);
            ss >> type;
            
            switch (type[0])
            {
                case 'P':
                    curPage = CreatePage(bus, move(ss));
//                    mvprintw(7, 5, curPage->getName().c_str());
//                    refresh();
//                    
//                    mvprintw(8, 5, bus->pages["Home"]->getName().c_str());
//                    refresh();
//                    
//                    curPage->setName("Not Home");
//                    mvprintw(9, 5, curPage->getName().c_str());
//                    refresh();
//                    
//                    mvprintw(10, 5, bus->pages["Home"]->getName().c_str());
//                    refresh();
                    
                    
                    
                    break;
                case 'B':
                    curBoard = CreateBoard(curPage, move(ss));
                    
//                    mvprintw(11, 5, to_string((int)curPage->boardVec.size()).c_str());
//                    refresh();
//
//                    mvprintw(12, 5, to_string((int)bus->pages["Home"]->boardVec.size()).c_str());
//                    refresh();
//
//                    mvprintw(13, 5, curBoard->getName().c_str());
//                    refresh();
                    
                    break;
                case 'U':
                    CreateUnit(curPage, curBoard, move(ss));
                    break;
            }
        }
        file.close();
    }
    else
        cout << "There is not APPSetting.txt file\n";
}

Page * CreatePage(BusAPP * bus, stringstream ss)
{
    Page * page = new Page();
    
    string pageName;
    ss >> pageName;
    page->setName(pageName);
    
    bus->pages[pageName] = page;
    return page;
}

Board * CreateBoard(Page * page, stringstream ss)
{
    Board * board = new Board();
    
    string boardName;
    ss >> boardName;
    board->setName(boardName);
    
    string unitNumber;
    ss >> unitNumber;
    board->setUnitNumber(stoi(unitNumber));
    
    string width;
    ss >> width;
    board->setWidth(stoi(width));
    
    string height;
    int temp;
    ss >> height;
    temp = stoi(height);
    board->setHeight(temp);
    
    string boardPos;
    ss >> boardPos;
    if(boardPos == "t")
    {
        board->isDownBoard = false;
        board->setX(page->getX());
        page->setX(board->getX() + board->getHeight());
    }
    else
    {
        board->isDownBoard = true;
        if(!page->isDownBoard)
            page->isDownBoard = true;
        
        board->setX(42-board->getHeight()-1);
        
        for(Board * bb : page->boardVec)
        {
            if(bb->isDownBoard)
                bb->setX(bb->getX() - board->getHeight());
        }
    }
    
    page->boardVec.push_back(board);
//    board->parentPage = page;
    return board;
}

void CreateUnit(Page * page, Board * board, stringstream ss)
{
    Unit * unit = new Unit();
    
    string unitName;
    ss >> unitName;
    unit->setName(unitName);
    
    string unitType;
    ss >> unitType;
    if(unitType == "b")
        unit->setIsButtonT(true);
    
    string textPos;
    ss >> textPos;
    if(textPos == "m")
        unit->setIsTextM(true);
    
    unit->setWidth(board->getWidth() / board->getUnitNumber());
    unit->setHeight(board->getHeight());
    
    string text;
    string temp;
    while(ss >> text) temp += text + " ";
    temp.pop_back();
    unit->setText(temp);
    
    if(unitType == "b")
    {
        page->unitVec.push_back(unit);
    }
    board->unitVec.push_back(unit);
}

//
void Setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    start_color();
    curs_set(0);
    
    
    
//    for(int i = 0; i < 29; i++)
//    {
//        mvprintw(0,i+1,"=");
//    }
//
//    for(int i = 0; i < 29; i++)
//    {
//        mvprintw(10,i+1,"=");
//    }
//
//    for(int i = 0; i < 9; i++)
//    {
//        mvprintw(i+1,0,"|");
//    }
//
//    for(int i = 0; i < 9; i++)
//    {
//        mvprintw(i+1,30,"|");
//    }
//
//    mvprintw(0,0,"+");
//    mvprintw(0,30,"+");
//    mvprintw(10,0,"+");
//    mvprintw(10,30,"+");
//    mvprintw(3,3,"BUS RESERVE");
//    refresh();
//
//    BOARD[2] = newwin(0, 0, 23, 0);
//    wrefresh(BOARD[2]);
}
//
//
//    BOARD[0] = newwin(10, 40, 1, 1);
//    mvprintw(0, 0, "yes");
//    refresh();
////    BOARD[1] = newwin(3, 3, 6, 6);
//    BOARD[2] = newwin(0, 0, 23, 0);
////    BOARD[3] = newwin(5, 8, 5, 8);
//
//    box(BOARD[0], 0, 0);
////    box(BOARD[1], 0, 0);
//    wrefresh(BOARD[0]);
////    wrefresh(BOARD[1]);
//    wrefresh(BOARD[2]);
//
////    wrefresh(BOARD[1]);
////    box(BOARD[2], 0, 0);
////    wrefresh(BOARD[2]);
////    box(BOARD[3], 0, 0);
////    wrefresh(BOARD[3]);
//
//
//
////    int i;
////    int starty, startx;
////
////    starty = 0;
////    for (i = 0; i < 2; i++) {
////        startx = i * SQ_WIDTH;
////        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
////    }
////
////    starty = SQ_HEIGHT;
////    for (i = 2; i < 4; i++) {
////        startx = (1 - i) * SQ_WIDTH;
////        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
////    }
////
////    starty = 2 * SQ_HEIGHT;
////    for (i = 20; i < 30; i++) {
////        startx = (i - 20) * SQ_WIDTH;
////        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
////    }
////
////
////    create_board();
////    box(BOARD[0], 0, 0);
////    wrefresh(BOARD[0]);
////    box(BOARD[1], 0, 0);
////    wrefresh(BOARD[1]);
////    box(BOARD[2], 0, 0);
////    wrefresh(BOARD[2]);
////    box(BOARD[3], 0, 0);
////    wrefresh(BOARD[3]);
////    box(BOARD[4], 0, 0);
////    wrefresh(BOARD[4]);
////    box(BOARD[5], 0, 0);
////    wrefresh(BOARD[5]);
////    box(BOARD[6], 0, 0);
////    wrefresh(BOARD[6]);
////    box(BOARD[7], 0, 0);
////    wrefresh(BOARD[7]);
////    box(BOARD[8], 0, 0);
////    wrefresh(BOARD[8]);
////    box(BOARD[9], 0, 0);
////    wrefresh(BOARD[9]);
//
////    refresh();
//
//    attron(A_BOLD);
//    init_pair(1, COLOR_RED, COLOR_BLACK);
//    init_pair(2, COLOR_BLUE, COLOR_BLACK);
//    init_pair(3, COLOR_WHITE, COLOR_BLACK);
//    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
//    init_pair(5, COLOR_GREEN, COLOR_BLACK);
//    init_pair(6, COLOR_CYAN, COLOR_BLACK);
//    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
//}
//
void Input(BusAPP * bus, Page * cur)
{
    keypad(stdscr, TRUE);
    
    string nextPage;
    
//    mvprintw(30, 2, to_string((int)(cur->unitVec.size()-1)).c_str());
//    refresh();
    
    int len = (int)bus->pages[bus->curPage]->unitVec.size();
    
    int c = getch();
    switch(c)
    {
        case KEY_LEFT:
        case KEY_UP:
            nextPage = bus->curPage;
            bus->pointerIndex--;
            if(bus->pointerIndex < 0)
                bus->pointerIndex = len - 1;
            break;
        case KEY_RIGHT:
        case KEY_DOWN:
            nextPage = bus->curPage;
            bus->pointerIndex++;
            if(bus->pointerIndex == len)
                bus->pointerIndex = 0;
            break;
        case KEY_ENTER:
            break;
        default:
            break;
    }
    bus->loadPage(nextPage);
}
//
//// g++ main.cpp Bus.cpp page.cpp button.cpp unit.cpp -o APP -lcurses -Wall -Werror -std=c++17
//
//void create_board(void)
//{
//    int i;
//    int starty, startx;
//
//    starty = 0;
//    for (i = 0; i < 10; i++) {
//        startx = i * SQ_WIDTH;
//        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
//    }
//
//    starty = SQ_HEIGHT;
//    for (i = 10; i < 20; i++) {
//        startx = (19 - i) * SQ_WIDTH;
//        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
//    }
//
//    starty = 2 * SQ_HEIGHT;
//    for (i = 20; i < 30; i++) {
//        startx = (i - 20) * SQ_WIDTH;
//        BOARD[i] = newwin(SQ_HEIGHT, SQ_WIDTH, starty, startx);
//    }
//
//
//    /* put border on each window and refresh */
//
//    for (i = 0; i < 40; i++) {
//        draw_square(i);
//    }
//}
//
//void draw_square(int sq)
//{
//    switch (sq) {
////    case 14:                    /* revive square */
////        wborder(BOARD[sq], '#', '#', '#', '#', '#', '#', '#', '#');
////        break;
////
////    case 25:                    /* stop square */
////        box(BOARD[sq], 'X', 'x');
////        break;
////
////    case 26:                    /* water square */
////        box(BOARD[sq], 'O', 'o');
////        break;
////
////    case 27:                    /* 3-move square */
////        box(BOARD[sq], '3', '3');
////        break;
////
////    case 28:                    /* 2-move square */
////        box(BOARD[sq], '2', '2');
////        break;
//
//    default:
//        box(BOARD[sq], 0, 0);
//    }
//
////    wrefresh(BOARD[sq]);
//}

/*
 * Simple ncurses form example with fields that actually behaves like fields.
 *
 * How to run:
 *    gcc -Wall -Werror -g -pedantic -o test fields_magic.c -lform -lncurses
 */
//#include <ncurses.h>
//#include <form.h>
//#include <assert.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//
////static FORM *form;
//static FIELD *fields[5];
//static WINDOW *win_body, *win_form;
////
/////*
//// * This is useful because ncurses fill fields blanks with spaces.
//// */
////static char* trim_whitespaces(char *str)
////{
////    char *end;
////
////    // trim leading space
////    while(isspace(*str))
////        str++;
////
////    if(*str == 0) // all spaces?
////        return str;
////
////    // trim trailing space
////    end = str + strnlen(str, 128) - 1;
////
////    while(end > str && isspace(*end))
////        end--;
////
////    // write new null terminator
////    *(end+1) = '\0';
////
////    return str;
////}
////
////static void driver(int ch)
////{
////    int i;
////
////    switch (ch) {
////        case KEY_F(2):
////            // Or the current field buffer won't be sync with what is displayed
////            form_driver(form, REQ_NEXT_FIELD);
////            form_driver(form, REQ_PREV_FIELD);
////            move(LINES-3, 2);
////
////            for (i = 0; fields[i]; i++) {
////                printw("%s", trim_whitespaces(field_buffer(fields[i], 0)));
////
////                if (field_opts(fields[i]) & O_ACTIVE)
////                    printw("\"\t");
////                else
////                    printw(": \"");
////            }
////
////            refresh();
////            pos_form_cursor(form);
////            break;
////
////        case KEY_DOWN:
////            form_driver(form, REQ_NEXT_FIELD);
////            form_driver(form, REQ_END_LINE);
////            break;
////
////        case KEY_UP:
////            form_driver(form, REQ_PREV_FIELD);
////            form_driver(form, REQ_END_LINE);
////            break;
////
////        case KEY_LEFT:
////            form_driver(form, REQ_PREV_CHAR);
////            break;
////
////        case KEY_RIGHT:
////            form_driver(form, REQ_NEXT_CHAR);
////            break;
////
////        // Delete the char before cursor
////        case KEY_BACKSPACE:
////        case 127:
////            form_driver(form, REQ_DEL_PREV);
////            break;
////
////        // Delete the char under the cursor
////        case KEY_DC:
////            form_driver(form, REQ_DEL_CHAR);
////            break;
////
////        default:
////            form_driver(form, ch);
////            break;
////    }
////
////    wrefresh(win_form);
////}
//
//int main()
//{
////    int ch;
//
//    initscr();
//    noecho();
//    cbreak();
//    keypad(stdscr, TRUE);
//
//    win_body = newwin(24, 80, 0, 0);
//    assert(win_body != NULL);
//    box(win_body, 0, 0);
//    win_form = derwin(win_body, 20, 78, 3, 1);
//    assert(win_form != NULL);
//    box(win_form, 0, 0);
//    mvwprintw(win_body, 1, 2, "Press F1 to quit and F2 to print fields content");
//
//    fields[0] = new_field(1, 10, 0, 0, 0, 0);
//    fields[1] = new_field(1, 40, 0, 15, 0, 0);
//    fields[2] = new_field(1, 10, 2, 0, 0, 0);
//    fields[3] = new_field(1, 40, 2, 15, 0, 0);
//
//    fields[4] = NULL;
////    assert(fields[0] != NULL && fields[1] != NULL && fields[2] != NULL && fields[3] != NULL);
////
////    set_field_buffer(fields[0], 0, "label1");
////    set_field_buffer(fields[1], 0, "val1");
////    set_field_buffer(fields[2], 0, "label2");
////    set_field_buffer(fields[3], 0, "val2");
//
////    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
////    set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
////    set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
////    set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
////
////    set_field_back(fields[1], A_UNDERLINE);
////    set_field_back(fields[3], A_UNDERLINE);
////
////    form = new_form(fields);
////    assert(form != NULL);
////    set_form_win(form, win_form);
////    set_form_sub(form, derwin(win_form, 18, 76, 1, 1));
////    post_form(form);
////
////    refresh();
////    wrefresh(win_body);
////    wrefresh(win_form);
////
////    while ((ch = getch()) != KEY_F(1))
////        driver(ch);
////
////    unpost_form(form);
////    free_form(form);
////    free_field(fields[0]);
////    free_field(fields[1]);
////    free_field(fields[2]);
////    free_field(fields[3]);
////    delwin(win_form);
////    delwin(win_body);
////    endwin();
////
////    return 0;
//}
