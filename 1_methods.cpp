#include <iostream>

using namespace std;

class ClassA
{
public:

    ClassA() {
        cout << "ClassA()\n";
    }

    virtual ~ClassA() {
        cout << "~ClassA()\n";
    }

    void foo() {
        cout << "ClassA foo()\n";
    }

    virtual void fooVirtual() {
        cout << "ClassA fooVirtual()\n";
    }

};

class ClassB : public ClassA
{
public:

    ClassB() {
        cout << "ClassB()\n";
    }

    ~ClassB() {
        cout << "~ClassB()\n";
    }

    void foo() { // перекрытие
        cout << "ClassB foo()\n";
    }

    void fooVirtual() override { // переопределение
        cout << "ClassB fooVirtual()\n";
    }
};

void methods() {

    cout << "\n|=======1_methods=======\n\n";

    ClassA* obj1 = new ClassB();
    cout << endl;
    ClassA* obj2 = new ClassA();
    cout << endl;
    ClassB* obj3 = new ClassB();

    cout << endl;

    obj1->foo();
    obj2->foo();
    obj3->foo();

    cout << endl;

    obj1->fooVirtual();
    obj2->fooVirtual();
    obj3->fooVirtual();

    cout << endl;

    delete obj1;
    cout << endl;
    delete obj2;
    cout << endl;
    delete obj3;
}
