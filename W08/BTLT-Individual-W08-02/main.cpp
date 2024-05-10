#include <iostream>
#include <cstring>

using namespace std;

class A {
protected:
    char *m_s;
public:
    A() { m_s = strdup("default"); }
    A(char *s) { m_s = strdup(s); }
    A(const A &a) { m_s = strdup(a.m_s); }
    virtual void prepare() { cout << "A "; }
    void display() {
        prepare();
        cout << m_s << endl;
    }
    virtual ~A() {
        free(m_s);
        m_s = nullptr;
    }
    friend istream& operator >> (istream& is, A& a) {
        char buffer[256];
        is.getline(buffer, sizeof(buffer));
        free(a.m_s);
        a.m_s = strdup(buffer);
        return is;
    }
};


class B : public A {
public:
    B(char *s) : A(s) { }
    B(const B &b) : A(b) { }
    void prepare() { cout << "B "; }
    ~B() {
    }
};

void foo(A *obj1, A obj2) {
    obj1->display();
    obj2.display();
}

int main() {
    B obj1("text");
    A *obj2 = new B(obj1);
    foo(&obj1, *obj2);
    delete obj2;
    cin >> obj1;
    obj1.display();
}