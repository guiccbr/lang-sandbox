#include <iostream>
#include <vector>

int find_magic_not_distinct(std::vector<int> &array, int begin, int end)
{
    int magic = -1;

    if (end < begin) {
        return magic;
    }

    int middle = (end + begin) / 2;

    // Magic number has been found
    if (array[middle] == middle) {
        magic = middle;
    }

    // Middle element is lower than middle index. There might be a magic number
    // in the ranges [begin, array[midle]] and [middle+1, end]
    else if (array[middle] < middle) {
        if (array[middle] >= begin) {
            magic = find_magic_not_distinct(array, begin, array[middle]);
        }
        magic =
            std::max(magic, find_magic_not_distinct(array, middle + 1, end));
    }

    // Middle element is higher than middle index. There might be a magic
    // number in the ranges [array[middle], end] or [0, middle - 1]
    else if (array[middle] > middle) {
        if (array[middle] <= end) {
            magic = find_magic_not_distinct(array, array[middle], end);
        }
        magic =
            std::max(magic, find_magic_not_distinct(array, begin, middle - 1));
    }

    return magic;
}

int find_magic_not_distinct(std::vector<int> &array)
{
    find_magic_not_distinct(array, 0, array.size() - 1);
}

int find_magic(std::vector<int> &array)
{

    int magic = -1;

    // Since the array is sorted we can use an adapted binary search to
    // optimize the complexity of the problem.
    int begin = 0;
    int end = array.size() - 1;

    while (end >= begin) {

        int middle = (begin + end) / 2;

        // Element has been found
        if (array[middle] == middle) {
            magic = middle;
            break;
        }
        // If the element exists, it is on the left
        else if (array[middle] > middle) {
            end = middle - 1;
        }
        // If the element exists, it is on the right
        else if (array[middle] < middle) {
            begin = middle + 1;
        }
    }

    return magic;
}

int main(void)
{
    std::vector<int> array({1, 1, 3, 4, 4, 1, 1, 1});
    // std::vector<int> array({-5, -4, 2, 4, 5, 8, 12, 20});
    // std::vector<int> array({-5, -4, -2, 1, 2, 3, 4, 7});

    int magic_idx = find_magic_not_distinct(array);

    if (magic_idx == -1) {
        std::cout << "The given array does not have a magic number"
                  << std::endl;
    } else {
        std::cout << "Magic number found: " << magic_idx << std::endl;
    }
}

