#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
// 还没实现 >>

template <std::size_t weight, std::size_t height> class Screen;
template <std::size_t weight, std::size_t height>
std::ostream& operator<<(std::ostream&, Screen<weight, height>&);

template <std::size_t weight, std::size_t height>
class Screen {
    friend std::ostream& operator<<<weight, height>(std::ostream&, Screen&);
public:
    Screen() = default;
    Screen(std::string s): content(s) { }
private:
    std::string content;
};

template <std::size_t weight, std::size_t height>
std::ostream& operator<<(std::ostream &os, Screen<weight, height> &s) {
    os << s.content;
    return os;
} 




#endif