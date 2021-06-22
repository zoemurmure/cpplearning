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
        grade = (score < 60) ? grades[0] : grades[(score-50)/10];
        if (score > 60 && score != 100) {
            grade += (score%10 > 7) ? "+" : ((score%10 < 3) ? "-" : "");
        }
        cout << grade << endl;
    }
    return 0;
}
