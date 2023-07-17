#ifndef __EXPAND_CONTAINER_HPP__
#define __EXPAND_CONTAINER_HPP__
#include <iostream>
#include <ostream>
#include <vector>

template<typename Container>
class expand_container {
public:
    expand_container(Container& container) : container_(container) { }

    friend std::ostream& operator<< (std::ostream& out, const expand_container& obj) {
        for (const auto& item : obj.container_) {
            out << item << std::endl;
        }
        return out;
    }

private:
    Container& container_;
};


#endif