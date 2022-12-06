//#include "Bus.hpp"
//
//void Bus::Build()
//{
//    Page * home_page = new Page("Home");
//    pages[home_page->getName()] = home_page;
//    {
//        Button * reserve_btn = new Button();
//        UnitSetting(home_page, reserve_btn, 5, true, false, "BUS RESERVE");
//    }
//}
//
//void Bus::UnitSetting(Page * page, Button * button, int height, bool isM, bool isD, string text)
//{
//    if(isD)
//    {
//        for(int i = (int)page->btn_vec.size() - 1; i >= 0; i--)
//        {
//            if(page->btn_vec[i]->getIsDown())
//            {
//                page->btn_vec[i]->UpdateX(height);
//            }
//        }
//    }
//    button->setPage(page->getName());
//    button->setting(page->x, height, isM, isD);
//    button->setText(text);
//    page->x += button->getX();
//    page->btn_vec.push_back(button);
//}
//
//void Bus::LoadPage(string s)
//{
//    for(Button * b : pages[s]->btn_vec)
//    {
//        b->show();
//    }
//}
//
//void Bus::Start()
//{
//    Build();
//    LoadPage("Home");
//}
//
//void Bus::Exit()
//{
//    for(auto i = pages.begin(); i != pages.end(); i++)
//    {
//        for(Button * b : i->second->btn_vec)
//        {
//            delete b;
//        }
//        delete i->second;
//    }
//}
