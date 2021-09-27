#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include "Folder.h"
class Folder;
class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string &std = " "):
        contents(std) { }
    Message(const Message&);
    Message& operator= (const Message&);
    Message(Message&&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder*);
    void remFolder(Folder*);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);

};

void swap(Message&, Message&);



#endif