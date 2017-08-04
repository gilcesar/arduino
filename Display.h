/* 
 * File:   Display.h
 * Author: Gilcesar Avila
 *
 * Created on 27 de Agosto de 2014, 10:56
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal.h>
#include <LinkedList.h>
#include <Logger.h>


enum Key {
    KEY_NONE, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_SELECT
};

class KeyListener {
public:
    virtual void onKeyPress(Key pressed) = 0;
};

class Display {
private:
    LiquidCrystal* lcd;
    //LinkedList<KeyListener> keyListeners;
    
    KeyListener* keyListener;
    Key lastKeyPressed;
public:

    Display();

    ~Display();

    void processKey();
    
    void setListener(KeyListener* listener);
    //void addListener(KeyListener& listener);

    Key getKey();

    void printUp(boolean clear, int col, const char * __fmt, ...);
    void printUp(boolean clear, const char * __fmt, ...);
    void printUp(int col, const char * __fmt, ...);
    void printUp(const char * __fmt, ...);

    void printDown(boolean clear, int col, const char * __fmt, ...);
    void printDown(boolean clear, const char * __fmt, ...);
    void printDown(int col, const char * __fmt, ...);
    void printDown(const char * __fmt, ...);

    void clearTop();

    void clearBottom();

    void clear();
} ;



#endif /* DISPLAY_H */

