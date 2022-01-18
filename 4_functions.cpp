#include <iostream>

using namespace std;

class Base
{
public:
	Base() {
		cout << "Base()\n";
	}

	Base(Base* obj) {
		cout << "Base(Base* obj)\n";
	}

	Base(Base& obj) {
		cout << "Base(Base& obj)\n";
	}

	~Base() {
		cout << "~Base()\n";
	}
};

class Desc : public Base
{
public:
	Desc() {
		cout << "Desc()\n";
	}

	Desc(Desc* obj) {
		cout << "Desc(Desc* obj)\n";
	}

	Desc(Desc& obj) {
		cout << "Desc(Desc& obj)\n";
	}

	~Desc() {
		cout << "~Desc()\n";
	}
};

void func1(Base obj) {
	cout << "func1(Base obj)\n";
}

void func2(Base* obj) {
	cout << "func2(Base* obj)\n";
}

void func3(Base& obj) {
	cout << "func3(Base& obj)\n";
}


Base func1() {
	// Base *obj = new Base();
	// return *obj;
	cout << "func1()\n";
	Base obj;
	return obj;
}

Base* func2() {
	// Base obj;
	// return &obj;
	cout << "func2()\n";
	Base* obj = new Base();
	return obj;
}

Base& func3() {
	// Base *obj = new Base();
	// return *obj;
	cout << "func3()\n";
	Base obj;
	return obj;
}


void functions() {

	cout << "\n|=======4_functions=======\n\n";

	Base objB;
	Desc objD;

	Base* objBB = new Base();
	Base* objBD = new Desc();
	Desc* objDD = new Desc();

	cout << endl;

	func1(objB);
	func3(objB);

	cout << endl;

	func1(objD);
	func3(objD);

	cout << endl;

	func1(objBB);
	func2(objBB);

	cout << endl;

	func1(objBD);
	func2(objBD);

	cout << endl;

	func1(objDD);
	func2(objDD);

	cout << endl;

	delete objBB;
	delete objBD;
	delete objDD;

	cout << endl;

	Base obj1;
	Base obj2;
	Base obj3;

	cout << endl;

	obj1 = func1();
	cout << endl;
	obj2 = func2();
	cout << endl;
	obj3 = func3();

	cout << endl;
}