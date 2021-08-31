#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
    friend class Window_mgr;
    //friend void Window_mgr::clear(ScreenIndex);
public:
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd),
                                    contents(ht*wd, c) { }
    Screen(pos ht, pos wd): height(ht), width(wd), 
                            contents(ht*wd, ' ') { }

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    pos size() const;
    Screen &display(std::ostream &os) {
        do_display(os); return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os); return *this;
    }

    Screen &move(pos r, pos c);    
    Screen &set(char);
    Screen &set(pos, pos, char);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &os) const { os << contents; }
};

inline
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen::pos
Screen::size() const {
    return height * width;
}

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width+c] = ch;
    return *this;
}

#endif