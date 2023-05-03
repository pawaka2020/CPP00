#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
private:
    std::string name;
    int age;

    void foo();
    void bar();

public:
    Person(std::string name, int age);
    void doSomething();
};

#endif /* PERSON_HPP */
