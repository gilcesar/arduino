/* 
 * File:   Message.cpp
 * Author: Gilcésar Ávila
 *
 * Created on October 7, 2014, 10:04 PM
 */

#include <Message.h>

//JsonObject& createMessage(JsonBuffer& jsonBuffer) {
//  JsonObject& root = jsonBuffer.createObject();
//
//  JsonArray& analogValues = root.createNestedArray("analog");
//  for (int pin = 0; pin < 6; pin++) {
//    int value = analogRead(pin);
//    analogValues.add(value);
//  }
//
//  JsonArray& digitalValues = root.createNestedArray("digital");
//  for (int pin = 0; pin < 14; pin++) {
//    int value = digitalRead(pin);
//    digitalValues.add(value);
//  }
//
//  return root;
//}


//#include <Arduino.h>
//
//Message::Message(uint8_t id, uint8_t length) {
//    header.id = id;
//    header.length = length;
//    head = data = malloc(length + 1);
//    memset(data, 0, length + 1);
//}
////private
//
//boolean Message::canAdd(uint8_t sizeOfValue) {
//
//}
//
////public
//
//void Message::add(int32_t value) {
//    if (canAdd(sizeof (uint32_t))) {
//        memcpy(data, &value, sizeof (uint32_t));
//        data += sizeof (uint32_t);
//    }
//}
//
//void Message::add(float value) {
//    if (canAdd(sizeof (float))) {
//        memcpy(data, &value, sizeof (float));
//        data += sizeof (float);
//    }
//}
//
//void Message::add(String value) {
//    if (canAdd(sizeof (value.length()))) {
//        memcpy(data, &value, value.length());
//        data += sizeof (value.length());
//    }
//}
//
//uint32_t* Message::getUI32Values() {
//    return NULL;
//}
//float* Message::getFloatValues() {
//    return NULL;
//}
//
//String Message::getStringValue() {
//    return "";
//}


