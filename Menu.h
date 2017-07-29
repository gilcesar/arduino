/* 
 * File:   OptionCommand.h
 * Author: ac45145
 *
 * Created on August 27, 2014, 1:49 PM
 */


#ifndef OPTIONCOMMAND_H
#define OPTIONCOMMAND_H


#include <LinkedList.h>

//class MenuAction {
//public:
//    virtual boolean canExecute() = 0;
//    virtual void execute() = 0;
//};


//void my_int_func(int x)
//{
//    printf( "%d\n", x );
//}
//
//
//
//int main()
//{
//    void (*foo)(int);
//    /* the ampersand is actually optional */
//    foo = &my_int_func;
//
//    return 0;
//}


class Menu {
private:
    LinkedList<Menu> items;
    String text;
    //MenuAction *action;
    typedef void (*ActionFunc)(int);
    ActionFunc action;
    int param;
public:

    Menu();

    Menu(String text);

    ~Menu();

    void addItem(Menu item);
    LinkedList<Menu> getItems();

    //void setAction(MenuAction &action);
//    MenuAction getAction();
    
    void setAction(ActionFunc af, int p);
    void execute();

    void setText(String text);
    String getText();

};

#endif /* OPTIONCOMMAND_H */

