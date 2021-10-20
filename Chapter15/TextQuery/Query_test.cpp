#include "Query.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("storyDataFile");
    TextQuery tq(in);

    Query q("her");
    auto result1 = q.eval(tq);
    print(cout, result1);

    Query andq = Query("her") & Query("him");
    auto result2 = andq.eval(tq);
    print(cout, result2);

    Query orq = Query("her") | Query("him");
    auto result3 = orq.eval(tq);
    print(cout, result3);

    Query notq = ~Query("her");
    auto result4 = notq.eval(tq);
    print(cout, result4);
    return 0;
}