#include <iostream>
#include "nprandom.hpp"
#include <vector>

template <class T>
class has_iterator {
private:
    template <class U>
    static constexpr bool check(typename U::iterator*)
    { return true; }
    template <class U>
    static constexpr bool check(...)
    { return false; }
public:
    static const bool value = check<T>(nullptr);
};

template <class InputIterator>
void print(InputIterator first, InputIterator last){
    std::cout << "[";
    while(first != last){
        std::cout << *first << ", ";
        std::advance(first, 1);
    }
    std::cout << "]" << std::endl;
}

template <class HAS_ITER,
          typename std::enable_if<has_iterator<HAS_ITER>::value>::type* = nullptr>
void print(const HAS_ITER& x){
    print(std::begin(x), std::end(x));
}

template <class PRIMITIVE,
          typename std::enable_if<!has_iterator<PRIMITIVE>::value>::type* = nullptr>
void print(const PRIMITIVE& x){
    std::cout << x << std::endl;
}


int main() {
    nprandom::seed();
    for(int i=0;i<10;++i) {
        std::cout << nprandom::randint(10) << std::endl;
    }
    std::vector<double> rv = nprandom::rand(10);
    print(rv);
    nprandom::shuffle(rv);
    print(rv);
}
