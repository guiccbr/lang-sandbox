#include <cstdio>
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> & v) {

    out << "[";

    if (v.size() > 0) {
        out << v[0];
    }

    for (int i = 1; i < v.size(); i++) {
        out << ", " << v[i];
    }

    out << "]";

    return out;
}

void merge(std::vector<int> &a, std::vector<int> &b)
{
    int i = a.size() - 1; // Highest element in a not transferred to the result
    int k = b.size() - 1; // Highest element in b not transferred to the result

    // Resize a in order to fit a + b
    a.resize(a.size() + b.size());
    int j =
        a.size() - 1; // Stores the final highest sorted elements (exclusive)

    while (j >= 0) {
        if (i >= 0 && a[i] > b[k]) {
            a[j] = a[i];
            i--;
        } else if (k >= 0) {
            a[j] = b[k];
            k--;
        }
        j--;
    }
}

int main(void)
{
    std::vector<int> a = {1, 3, 8, 9, 12, 13, 14};
    std::vector<int> b = {1, 1, 2, 4, 5, 6};

    merge(a, b);

    std::cout << a << std::endl;

    return 0;
}

