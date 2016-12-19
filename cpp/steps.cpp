#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> in) {

    out << "[";

    if(in.size() > 0) {
        out << in[0];
    }

    for(int i = 1; i < in.size(); i++) {
        out << ", " << in[i];
    }

    out << "]";

    return out;
}

// This is just a brute force way
int num_ways(int stairs_size, int hop_size) {

    // Base case
    if (stairs_size < 0) return 0;
    if (stairs_size == 0) return 1;

    // For stairs_size greater than 2
    int n = 0;
    for(int i = 1; i<=hop_size; i++) {
        n += num_ways(stairs_size - i, hop_size);
    }

    return n;
}

// With memoization
int num_ways(int stairs_size, int hop_size, std::vector<int> &storage)
{
    if (stairs_size < 0)
        return 0;

    if (stairs_size == 0) {
        return 1;
    }

    if (storage[stairs_size] == 0) {
        for (int i = 1; i <= hop_size; i++) {
            storage[stairs_size] +=
                num_ways(stairs_size - i, hop_size, storage);
        }
    }

    return storage[stairs_size];
}

int main(void) {

    std::vector<int> res(3);

    std::cout << "Type the stairs size: ";
    std::cin >> res[0];

    std::cout << "Type maximum hop size: ";
    std::cin >> res[1];

    std::vector<int> storage(res[0]+1, 0);

    res[2] = num_ways(res[0], res[1], storage);

    std::cout << "storage = " << storage << std::endl;
    std::cout << "[stair size, hop size, num ways] = " << res << std::endl;

}

