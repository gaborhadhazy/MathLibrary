#include <iostream>
#include "./Include/Math.h"
int main() {
    Math::BaseMath t1;
    int lcm = t1.GCD(2, 2, 10);
    std::cout << "lmc: " << lcm << '\n';
}
