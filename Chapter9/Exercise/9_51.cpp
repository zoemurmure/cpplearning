#include <string>
#include <vector>
#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;
using std::istream; using std::ostream;

const string alps{"qwertyuiopasdfghjklzxcvbnm"
                "QWERTYUIOPASDFGHJKLZXCVBNM"};
const string sep{" /\\,-"};

class Date {
    friend ostream &print(ostream&, const Date&);
public:
    Date() = default;
    Date(const int y, const int m, const int d):
        year(y), month(m), day(d) { }
    Date(const string&);
private:
    unsigned year;
    unsigned month;
    unsigned day;
    static const vector<string> months;
};

ostream &print(ostream &out, const Date &d) {
    out << "Year: " << d.year 
         << " Month: " << d.month
         << " Day: " << d.day;
    return out;
}

const vector<string>Date::months{"Jan", "Feb", "Mar", "Apr", "May",
    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Date::Date(const string &s) {
    auto pos = s.find_first_of(alps);
    if (pos != string::npos) {
        for (auto i = 0; i < months.size(); ++i) {
            if (months.at(i) == s.substr(pos, 3)) {
                month = i + 1;
                break;
            }
        }
    } else {
        month = std::stoi(s);
    }
    pos = s.find_first_of(sep);
    day = std::stoi(s.substr(++pos));
    pos = s.find_first_of(sep, pos);
    year = std::stoi(s.substr(++pos));
}

int main() {
    //Date myDate("1/1/1900");
    Date myDate("Jan 1,1900");
    print(cout, myDate);

    return 0;
}