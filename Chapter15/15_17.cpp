class B {
public:
    B();
    B(const B&) = delete;
};

class D : public B {

};


int main() {

    return 0;
}