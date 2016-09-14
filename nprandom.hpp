#ifndef NPRANDOM_HPP
#define NPRANDOM_HPP

#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

namespace nprandom {

static std::mt19937 rng;

void seed() {
    rng = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}

void seed(int seed_value) {
    rng = std::mt19937(seed_value);
}

template <class T>
T randint(T limit_value) {
    std::uniform_int_distribution<T> dist(0, limit_value-1);
    return dist(rng);
}

template <class T>
T rand() {
    std::uniform_real_distribution<> urd(0, 1);
    return urd(rng);
}

template <class T>
std::vector<double> rand(T num) {
    std::vector<double> ret(num);
    for(size_t i=0;i<num;++i) {
        ret[i] = rand<double>();
    }
    return ret;
}

template <class T>
void shuffle(std::vector<T>& vec) {
    std::random_shuffle(vec.begin(), vec.end());
}

}


#endif
