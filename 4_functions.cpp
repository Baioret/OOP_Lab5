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
	cout << "func1()\n";
	Base obj;
	return obj;
}

Base func2() {
	cout << "func2()\n";
	Base *obj = new Base();
	return *obj;
}

Base* func3() {
	cout << "func3()\n";
	Base* obj = new Base();
	return obj;
}

Base* func4() {
	cout << "func3()\n";
	Base obj;
	return &obj;
}

Base& func5() {
	cout << "func5()\n";
	Base obj;
	return obj;
}

Base& func6() {
	cout << "func6()\n";
	Base *obj = new Base();
	return *obj;
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

	cout << "\n|==============\n\n";

	Base obj1;

	cout << endl;

	obj1 = func1();
	cout << endl;
	obj1 = func2();
	cout << endl;
	obj1 = func3();
	cout << endl;
	obj1 = func4();
	cout << endl;
	obj1 = func5();
	cout << endl;
	obj1 = func6();

	cout << endl;

	cout << "\n|=======5_ptrs=======\n\n";

	unique_ptr<Base> unqObj(new Desc());
	//auto unqObj = make_unique<Desc>;

	cout << endl;

	shared_ptr<Base> shrdObj(new Desc());
	//auto shrdObj = make_shared<Desc>;

	cout << "\n|==============\n\n";
}