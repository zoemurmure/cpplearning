#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> grades{"F", "D", "C", "B", "A", "A++"};
    string grade;
    int score;
    
    while (cin >> score) {
        if (score < 60) {
            grade = grades[0];
        } else {
            grade = grades[(score-50)/10];
            if (score != 100) {
               if (score % 10 > 7) {
                    grade += "+";
                } else if (score % 10 < 3) {
                    grade += "-";
                }
            }
        }
        cout << grade << endl;
    }
    return 0;
}
