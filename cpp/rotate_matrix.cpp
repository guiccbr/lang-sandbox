#include <iostream>
#include <memory>
#include <vector>
#include <string>

template <typename T>
class sq_matrix {
   public:
    const int m;

    sq_matrix(int m) : m(m), storage(new T[m * m]) {}
    T* operator[](int idx) { return &(storage.get()[idx * m]); }

    void rotate_ninety() {
        rotate_ninety(0);
    }

    void rotate_ninety(int layer) {

        int first_elm_idx = 0 + layer;
        int last_elm_idx = m - 1 - layer;

        if (first_elm_idx >= last_elm_idx) {
            return;
        }

        std::cout << "first: " << first_elm_idx << " last: " << last_elm_idx
                  << std::endl;

        for (int i = 0; i < last_elm_idx - first_elm_idx; i++) {
            T aux = (*this)[first_elm_idx][last_elm_idx - i];
            (*this)[first_elm_idx][last_elm_idx - i] =
                (*this)[first_elm_idx + i][first_elm_idx];
            (*this)[first_elm_idx + i][first_elm_idx] =
                (*this)[last_elm_idx][first_elm_idx + i];
            (*this)[last_elm_idx][first_elm_idx + i] =
                (*this)[last_elm_idx - i][last_elm_idx];
            (*this)[last_elm_idx - i][last_elm_idx] = aux;
        }

        rotate_ninety(layer + 1);
    }

   private:
    std::unique_ptr<T[]> storage;
};

std::ostream& operator<<(std::ostream& out, sq_matrix<int>& mat) {
    for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.m; j++) {
            out << mat[i][j] << " ";
        }
        out << std::endl;
    }

    return out;
}

int main(void) {
    sq_matrix<int> m(4);

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[0][3] = 4;
    m[1][0] = 5;
    m[1][1] = 6;
    m[1][2] = 7;
    m[1][3] = 8;
    m[2][0] = 9;
    m[2][1] = 10;
    m[2][2] = 11;
    m[2][3] = 12;
    m[3][0] = 13;
    m[3][1] = 14;
    m[3][2] = 15;
    m[3][3] = 16;

    std::cout << m << std::endl;

    m.rotate_ninety(0);

    std::cout << m << std::endl;

    return 0;
}

