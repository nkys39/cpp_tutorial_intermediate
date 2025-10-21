#include "mylib.h"
#include <iostream>

namespace MyLib {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    void print_info() {
        std::cout << "MyLib version 1.0" << std::endl;
    }
}
