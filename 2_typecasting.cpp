#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:

    Animal() {
        cout << "Animal()\n";
    }

    ~Animal() {
        cout << "~Animal()\n";
    }

    virtual string classname() {
        return "Animal";
    }

    virtual bool isA(string who) {
        return (who == "Animal");
    }
};

class Cat : public Animal
{
public:

    Cat() {
        cout << "Cat()\n";
    }

    ~Cat() {
        cout << "~Cat()\n";
    }

    string classname() {
        return "Cat";
    }

    bool isA(string who) {
        return (who == "Cat" || Animal::isA(who));
    }

    void purr() {
        cout << "The cat is purring.\n";
    }
};

class PersianCat : public Cat
{
public:

    PersianCat() {
        cout << "PersianCat()\n";
    }

    ~PersianCat() {
        cout << "~PersianCat()\n";
    }

    string classname() {
        return "PersianCat";
    }

    bool isA(string who) {
        return (who == "PersianCat" || Cat::isA(who));
    }
};

class Dog : public Animal
{
public:

    Dog() {
        cout << "Dog()\n";
    }

    ~Dog() {
        cout << "~Dog()\n";
    }

    string classname() {
        return "Dog";
    }

    bool isA(string who) {
        return (who == "Dog" || Animal::isA(who));
    }

    void bark() {
        cout << "Watch out, the dog is barking.";
    }
};

void typecasting()
{
    srand(time(0));

    cout << "\n|=======2_typecasting=======\n\n";

    Animal* zoo[10];

    int x;

    for (int i = 0; i < 10; i++)
    {
        x = rand();

        if (x % 3 == 0)
            zoo[i] = new Cat();
        else if (x % 3 == 1)
            zoo[i] = new PersianCat();
        else
            zoo[i] = new Dog();

        cout << "\n";
    }

    // =====unsafe typecasting=====

    for (int i = 0; i < 10; i++)
        if (zoo[i]->classname() == "Cat" || zoo[i]->classname() == "PersianCat")
            ((Cat*)zoo[i])->purr();

    cout << endl;

    for (int i = 0; i < 10; i++)
        if (zoo[i]->isA("Cat"))
            ((Cat*)zoo[i])->purr();

    cout << endl;

    // =====dynamic_cast=====

    for (int i = 0; i < 10; i++)
        if (dynamic_cast<Cat*>(zoo[i]) != NULL)
            dynamic_cast<Cat*>(zoo[i])->purr();
}