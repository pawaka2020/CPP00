#include "Person.hpp"
#include <iostream>

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}

void Person::doSomething() {
    std::cout << name << " is doing something!" << std::endl;
    foo();
    bar();
}

void Person::foo() {
    std::cout << name << " is doing foo!" << std::endl;
}

void Person::bar() {
    std::cout << name << " is doing bar!" << std::endl;
}
