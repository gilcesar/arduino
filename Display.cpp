/* 
 * File:   Display.h
 * Author: Gilcesar Avila
 *
 * Created on 27 de Agosto de 2014, 10:56
 */

#include <Display.h>

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

void Display::setListener(KeyListener* listener){
    this->keyListener = listener;
}

//void Display::addListener(KeyListener& listener){
//    this->keyListeners.add(&listener);
//}
void Display::processKey() {
    //int key = analogRead(0);
    Key key = getKey();
    if(keyListener != NULL && key != KEY_NONE){
        keyListener->onKeyPress(key);
    }
    
//    if (!keyListeners.isEmpty() && key != KEY_NONE) {
//        while(keyListeners.hasNext()){
//            keyListeners.next()->onKeyPress(key);
//        }
//    }
    if(key != KEY_NONE){
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
    if(clear){
        clearTop();
    }
    
    char tmp[128];
    char str[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    strncpy(str, tmp, sizeof(tmp)>(16-col)? (16-col) : sizeof(tmp));
    lcd->setCursor(col, 0);
    lcd->print(str);
    //Log.log(DEBUG, "Display.Up=%s", tmp);
    va_end(ap);
    
}

void Display::printUp(int col, const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printUp(false, col, tmp);
    va_end(ap);
}

void Display::printUp(boolean clear, const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printUp(clear, 0, tmp);
    va_end(ap);
}

void Display::printUp(const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printUp(false, 0, tmp);
    va_end(ap);
}

void Display::printDown(boolean clear, int col, const char * __fmt, ...) {
    if(clear){
        clearBottom();
    }
    char tmp[128];
    char str[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);

    lcd->setCursor(col, 1);
    vsprintf(tmp, __fmt, ap);
    strncpy(str, tmp, sizeof(tmp)>(16-col)? (16-col) : sizeof(tmp));
    lcd->setCursor(col, 1);
    lcd->print(str);
    va_end(ap);
}

void Display::printDown(int col, const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printDown(false, col, tmp);
    va_end(ap);
}

void Display::printDown(boolean clear, const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printDown(clear, 0, tmp);
    va_end(ap);
}

void Display::printDown(const char * __fmt, ...) {
    char tmp[17];
    va_list ap;
    va_start(ap, __fmt);
    vsprintf(tmp, __fmt, ap);
    printDown(false, 0, tmp);
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
