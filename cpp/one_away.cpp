#include <cmath>
#include <cstring>
#include <iostream>

bool one_way(const char *a, const char *b) {

    int len_a = strlen(a);
    int len_b = strlen(b);

    // Return false if there are more than two insertions or deletions.
    if (abs(len_a - len_b) > 1) {
        return false;
    }

    // Check replaces
    if (len_a == len_b) {

        const char *pa = a;
        const char *pb = b;
        int num_changes = 0;

        while ((*pa) != '\0' && (*pb) != '\0') {
            if ((*pa) != (*pb)) {
                num_changes++;
                if (num_changes > 1)
                    return false;
            }
            pa++;
            pb++;
        }

        return true;
    }

    // Check insertions
    const char *pl = a;
    const char *ps = b;
    if (len_a < len_b) {
        pl = b;
        ps = a;
    }

    int num_changes = 0;

    while ((*pl) != '\0') {
        if ((*pl) == (*ps)) {
            pl++;
            if ((*ps) != '\0')
                ps++;
        } else {
            num_changes++;
            pl++;
            if (num_changes > 1) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    const char *a = "DPPP";
    const char *b = "PPPP";

    bool res = one_way(a, b);

    std::cout << "Strings \"" << a << "\" and \"" << b << "\" are";
    if (!res)
        std::cout << " NOT";
    std::cout << " one-edit" << std::endl;

    return 0;
}

