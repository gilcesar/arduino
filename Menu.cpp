/* 
 * File:   OptionCommand.h
 * Author: ac45145
 *
 * Created on August 27, 2014, 1:49 PM
 */

#include <Menu.h>

Menu::Menu() {
    items = LinkedList<Menu>();
}

Menu::Menu(String text) {
    this->text = text;
}

Menu::~Menu() {
    items.clear();
}

void Menu::addItem(Menu item) {
    items.add(item);
}

LinkedList<Menu> Menu::getItems() {
    return items;
}

//void Menu::setAction(MenuAction &action) {
//    this->action = &action;
//}

void Menu::setAction(ActionFunc af, int i){
    this->action = af;
    this->param = i;
}
void Menu::execute(){
    action(this->param);
}

//MenuAction Menu::getAction() {
//    return &action;
//}

void Menu::setText(String text) {
    this->text = text;
}

String Menu::getText(){
    return this->text;
}

