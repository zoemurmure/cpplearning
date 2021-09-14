#include <iostream>
#include "Folder.h"
using namespace std;

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    for (auto m : lhs.msgs) {
        m->remFolder(&lhs);
    }
    for (auto m : rhs.msgs) {
        m->remFolder(&rhs);
    }
    swap(lhs.msgs, rhs.msgs);
    for (auto m : lhs.msgs) {
        m->addFolder(&lhs);
    }
    for (auto m : rhs.msgs) {
        m->addFolder(&rhs);
    }
}

void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

void Folder::remMsg(Message *m) {
    msgs.erase(m);
}

Folder::~Folder() {
    remove_from_Msg();
}

void Folder::add_to_Msg(const Folder &f) {
    for (auto m : f.msgs) {
        m->save(*this);
    }
}

void Folder::remove_from_Msg() {
    for (auto m : msgs) {
        m->remove(*this);
    }
    msgs.clear();
}

Folder::Folder(const Folder &f): msgs(f.msgs) {
    add_to_Msg(f);
}

Folder& Folder::operator= (const Folder &rhs) {
    remove_from_Msg();
    msgs = rhs.msgs;
    add_to_Msg(rhs);
    return *this;
}