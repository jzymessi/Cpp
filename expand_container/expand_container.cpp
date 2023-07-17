#include <iostream>
#include <vector>
#include "expand_container.hpp"
#include <list>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    expand_container<std::vector<int>> obj1(myVector);
    std::cout << obj1;

    std::list<double> myList = {1.1, 2.2, 3.3, 4.4, 5.5};
    expand_container<std::list<double>> obj2(myList);
    std::cout << obj2;

    return 0;
}

