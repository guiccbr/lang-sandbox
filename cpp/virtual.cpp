#include <iostream>
#include <string>
#include <memory>

class base {
   public:
    base() { std::cout << "base constructed." << std::endl; }
    virtual ~base() { std::cout << "base destroyed." << std::endl; }
    virtual void print() { std::cout << "I am base." << std::endl; }
};

class derived : public base {
   public:
    derived() { std::cout << "derived constructed." << std::endl; }
    ~derived() { std::cout << "derived destroyed." << std::endl; }
    void print() { std::cout << "I am derived." << std::endl; }
};

int main(void) {
    derived *b = new derived();

    b->print();
    delete b;

    return 0;
}

