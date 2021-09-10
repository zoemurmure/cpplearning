#include <memory>
#include <iostream>

using namespace std;

struct destination {
    int id;
    destination() = default;
    destination(int i): id(i) { }
};
struct connection {
    int id;
    connection() = default;
    connection(int i): id(i) { }
};
connection connect(destination *d) {
    cout << "connect: " << d->id << endl;
    return connection(d->id);
}
void disconnect(connection c) {
    cout << "disconnect: " << c.id << endl;
    return;
}
//void end_connection(connection *p) {
//    disconnect(*p);
//}
void f (destination &d) {
    connection c = connect(&d);
    //shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p);});
}

int main() {
    destination d(1);
    f(d);
    return 0;
}