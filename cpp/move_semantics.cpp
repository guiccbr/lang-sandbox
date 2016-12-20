#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

// TODO: WIP

class widget {
  public:
    const size_t num_elems = 1000000;

    // Default constructor
    widget() : m_ptr(new int[num_elems]) {
        std::cout << "Default constructor" << std::endl;
    };

    // Default destructor
    ~widget() {
        delete[] m_ptr;
        std::cout << "Default destructor" << std::endl;
    }

    // Copy constructor. Needed since there is a pointer to a heap location
    // This will be called to construct an object with data from other object,
    // for example:
    //
    // widget a(b);
    // widget a = b; // Even though this looks like an assignment, it is not
    //               // because a is not initialized.
    //
    widget(const widget &other) : m_ptr(new int[num_elems]) {
        memcpy(m_ptr, other.m_ptr, sizeof(int) * num_elems);
        std::cout << "Copy constructor" << std::endl;
    }

    // Assignment operator. Needed since there is a pointer to a heap location
    // This will be called to copy data from the rightand side object to the
    // leftside object when both have already been instantiated. For example:
    //
    // widget a, b;
    // a = b;
    //
    widget &operator=(const widget &other) {

        // We need to check this otherwise we would make an unecessary copy.
        if (this != &other) {
            memcpy(m_ptr, other.m_ptr, sizeof(int) * num_elems);
        }
        std::cout << "Assignment operator" << std::endl;
        return *this;

    }


    // Move constructor.
    widget(widget &&other) {

        std::cout << "Move constructor" << std::endl;

        this->m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    // Move operator.
    widget &operator=(widget &&other) {

        std::cout << "Move operator" << std::endl;

        if (this != &other) {
            delete[] this->m_ptr;
            this->m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

        return *this;
    }

    int &operator[](int i) {
        return m_ptr[i];
    }

  private:
    int *m_ptr;
};

widget create_widget() {

    widget w;

    w[0] = -1;

    return w;
}

int main(void) {

    widget a;

    widget b(create_widget());

    std::cout << "a: " << a[0] << std::endl;
    std::cout << "b: " << b[0] << std::endl;

    return 0;
}

