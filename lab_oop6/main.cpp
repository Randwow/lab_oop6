//
//  main.cpp
//  lab_oop6
//
//  Created by Nikita Makeev on 10/30/20.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
class Mammal {
 public:
  const virtual string getDescription() const = 0;
    virtual ~Mammal(){}
};
 
class Animal : public Mammal {
 public:
  const virtual string getDescription() const {
    return "This is an Animal.";
  };
};
 
class Dog : public Animal {
 public:
  const virtual string getDescription() const {
    return "This is a dog.";
  };
};
 
class Cow : public Animal {
 public:
  const virtual string getDescription() const {
    return "This is a cow.";
  };
};
 
class Human : public Mammal {
 public:
  const virtual string getDescription() const {
    return "I am a human.";
  };
};
 
Mammal *newRandomMammal() {
  switch (rand() % 3) {
    case 0: return new Human();
    case 1: return new Dog();
    case 2: return new Cow();
  }
  return new Animal;
}
 
int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; ++i) {
    Mammal *mammal = newRandomMammal();
    cout << mammal->getDescription() << endl;
    delete mammal;
  }
}
