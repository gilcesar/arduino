/* 
 * File:   Display.h
 * Author: Gilcesar Avila
 *
 * Created on 27 de Agosto de 2014, 10:56
 */

#include <Display.h>
//#include <stdio.h>

Display::Display() {
    lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
    lcd->begin(16, 2);
    //keyListeners = new LinkedList<KeyListener>();
    //Logger.info(" ");
    Log.info("LCD Inicializado!");
}

Display::~Display() {
    //delete lcd;
    //delete keyListener;
}

void Display::setListener(KeyListener* listener) {
    this->keyListener = listener;
}

//void Display::addListener(KeyListener& listener){
//    this->keyListeners.add(&listener);
//}

void Display::processKey() {
    //int key = analogRead(0);
    Key key = getKey();
    if (keyListener != NULL && key != KEY_NONE) {
        keyListener->onKeyPress(key);
    }

    //    if (!keyListeners.isEmpty() && key != KEY_NONE) {
    //        while(keyListeners.hasNext()){
    //            keyListeners.next()->onKeyPress(key);
    //        }
    //    }
    if (key != KEY_NONE) {
        Log.log(DEBUG, "Key Pressed=%d", key);
    }
}

Key Display::getKey() {
    int key = analogRead(0);

    if (key < 50) return KEY_RIGHT;
    if (key < 150) return KEY_UP;
    if (key < 350) return KEY_DOWN;
    if (key < 500) return KEY_LEFT;
    if (key < 700) return KEY_SELECT;
    return KEY_NONE;
}

void Display::printUp(boolean clear, int col, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(clear, true, col, __fmt, ap);
}

void Display::printUp(int col, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(true, true, col, __fmt, ap);
}

void Display::printUp(boolean clear, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(clear, true, 0, __fmt, ap);
}

void Display::printUp(const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(true, true, 0, __fmt, ap);
}

void Display::printDown(boolean clear, int col, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(clear, false, col, __fmt, ap);
}

void Display::printDown(int col, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(true, false, col, __fmt, ap);
}

void Display::printDown(boolean clear, const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(clear, false, 0, __fmt, ap);
}

void Display::printDown(const char * __fmt, ...) {
    va_list ap;
    va_start(ap, __fmt);
    print(true, false, 0, __fmt, ap);
}

void Display::print(boolean clear, boolean up, int col, const char * __fmt, va_list ap) {
    if (up && clear) {
        lcd->setCursor(0, 0);
        lcd->print("                ");
    }
    if (!up && clear) {
        lcd->setCursor(0, 1);
        lcd->print("                ");
    }
    char tmp[256];
    char str[17];
    memset(tmp, 0, 256);
    memset(str, 0, 17);
    vsprintf(tmp, __fmt, ap);
    strncpy(str, tmp, strlen(tmp)>(16 - col) ? (16 - col) : strlen(tmp));

    lcd->setCursor(col, up ? 0 : 1);
    lcd->print(str);
    if (strlen(tmp) > 16) {
        Log.warn("Texto maior que o suportado pelo o display max=16");
        Log.warn(tmp);
    }
    va_end(ap);
}

void Display::clearTop() {
    printUp("                ");
}

void Display::clearBottom() {
    printDown("                ");
}

void Display::clear() {
    lcd->clear();
}
