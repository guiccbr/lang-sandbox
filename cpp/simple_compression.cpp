#include <string>
#include <iostream>

std::string compress(const std::string &str) {

    std::string comp_str = "";

    char curr = str[0];
    int curr_count = 1;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == curr) {
            curr_count++;
        } else {
            comp_str.push_back(curr);
            comp_str.append(std::to_string(curr_count));
            curr = str[i];
            curr_count = 1;
        }
    }

    comp_str.push_back(curr);
    comp_str.append(std::to_string(curr_count));

    if (comp_str.size() > str.size()) {
        comp_str = str;
    }

    return comp_str;
}

int main(int argc, char **argv) {

    std::string str = "";

    std::cout << "Type the string you want to compress:" << std::endl;
    std::cin >> str;

    std::string comp_str = compress(str);

    std::cout << "Input string: \"" << str << "\"" << std::endl;
    std::cout << "Compressed string: \"" << comp_str << "\"" << std::endl;

    return 0;
}

