#include <iostream>
#include <string>

using namespace std;

class A
{
public:

    A() {
        cout << "A()\n";
    }

    virtual ~A() {
        cout << "~A()\n";
    }

    void foo() {
        cout << "From A foo()\n";
        foo2();
    }

    virtual void foo2() {
        cout << "A foo2()\n";
    }
};

class B : public A
{
public:

    B() {
        cout << "B()\n";
    }

    ~B() {
        cout << "~B()\n";
    }

    void foo() {
        cout << "B foo()\n";
    }

    void foo2() {
        cout << "B foo2()\n";
    }
};

void some_examples()
{
    cout << "\n|=======3_some_examples=======\n\n";

    A* obj = new B();
    B* obj2 = new B();

    cout << endl;

    obj->foo();
    obj2->foo();

    cout << endl;

    obj->foo2();
    obj2->foo2();

    cout << endl;

    delete obj;
    delete obj2;
}