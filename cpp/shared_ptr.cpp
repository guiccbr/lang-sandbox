#include <iostream>
#include <string>
#include <memory>

template <typename T>
class shared_ptr {
    T* ptr = nullptr;
    int* num_instances = nullptr;

   public:
    shared_ptr(T* ptr_) : ptr(ptr_), num_instances(new int) {
        *num_instances = 1;
    }
    ~shared_ptr() {
        (*num_instances)--;
        if (!(*num_instances)) {
            delete ptr;
            delete num_instances;
        }
    }
    shared_ptr(const shared_ptr<T>& other)
        : ptr(other.ptr), num_instances(other.num_instances) {
        (*num_instances)++;
    }
    T* operator->() { return ptr; }
    T operator*() { return *ptr; }

    int use_count() { return *num_instances; }
};

class base {
   public:
    base() { std::cout << "base constructed." << std::endl; }
    virtual ~base() { std::cout << "base destroyed." << std::endl; }
    void print() { std::cout << "I am base." << std::endl; }
};

class derived : public base {
   public:
    derived() { std::cout << "derived constructed." << std::endl; }
    ~derived() { std::cout << "derived destroyed." << std::endl; }
    void print() { std::cout << "I am derived." << std::endl; }
};

int main(void) {

    std::shared_ptr<base> dp(new derived());

    return 0;
}

