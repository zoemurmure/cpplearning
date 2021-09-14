#ifndef FOLDER_H
#define FOLDER_H
#include <set>
#include "Message.h"
class Message;

class Folder {
    friend class Message;
    friend void swap(Folder&, Folder&);
    friend void swap(Message&, Message&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator= (const Folder&);
    ~Folder();
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*> msgs;
    void add_to_Msg(const Folder&);
    void remove_from_Msg();    
};
void swap(Folder&, Folder&);


#endif