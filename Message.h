/* 
 * File:   Message.h
 * Author: ac45145
 *
 * Created on October 7, 2014, 10:04 PM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

struct Header{
    uint16_t id;
    uint16_t length;
};

struct Message{
    Header header;
    char *data;
};

#endif	/* MESSAGE_H */

