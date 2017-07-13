/* 
 * File:   OptionCommand.h
 * Author: ac45145
 *
 * Created on August 27, 2014, 1:49 PM
 */


#ifndef OPTIONCOMMAND_H
#define	OPTIONCOMMAND_H
#include "LinkedList.h"

class MenuAction {
private:
public:

    MenuAction() {
    }
    virtual boolean canExecute() = 0;
    virtual void execute() = 0;
};

class Menu {
private:
    LinkedList<Menu> items;
    Menu * owner;
    String textTop;
    String textBottom;
    MenuAction * action;
public:

    Menu() {
        action = NULL;
    }

    //    Option(Option *owner){
    //        this->owner = owner;
    //        cmd = NULL;
    //    }

    Menu(/*Option *owner, */String textTop, String textBottom) {
        this->textTop = textTop;
        this->textBottom = textBottom;
        //this->owner = owner;
        action = NULL;
    }

    ~Menu() {
        items.clear();
    }

    //    void setOwner(Option *owner){
    //        this->owner = owner;
    //    }

    void addMenuItem(Menu *menuItem) {
        if (menuItem != NULL) {
            items.add(menuItem);
            menuItem->owner = this;
        }
    }

    LinkedList<Menu> getOptions() {
        return items;
    }

    void setCommand(MenuAction * cmd) {
        this->action = cmd;
    }

    MenuAction * getCommand() {
        return action;
    }

    void setTextBottom(String textBottom) {
        this->textBottom = textBottom;
    }

    String getTextBottom() const {
        return textBottom;
    }

    void setTextTop(String textTop) {
        this->textTop = textTop;
    }

    String getTextTop() const {
        return textTop;
    }

};

#endif	/* OPTIONCOMMAND_H */

