/* 
 * File:   Message.h
 * Author: Gilcésar Ávila
 *
 * Created on October 7, 2014, 10:04 PM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#include <Arduino.h>
#include <ArduinoJson.h>

JsonObject& createMessage(JsonBuffer& jsonBuffer);


//#include <LinkedList.h>
//
//struct Header{
//    uint8_t id;
//    uint8_t length;
//};
//
//class Message{
//    Header header;
//    void *data;
//    void *head;
//private:
//    boolean canAdd(uint8_t sizeOfValue);
//public:
//    
//    Message(uint8_t id, uint8_t length);
//    void add(int32_t value);
//    void add(float value);
//    void add(String value);
//    
//    uint32_t* getUI32Values();
//    float* getFloatValues();
//    String getStringValue();
//};



#endif	/* MESSAGE_H */

