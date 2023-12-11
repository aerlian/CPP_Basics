#include "RangeTests.h"

#include<iostream>
#include<vector>
#include<ranges>   // new header!

namespace RNG {
    void RunRanges() {
        const std::vector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        auto even = [](int i) { return 0 == i % 2; };

        using namespace std::views;
        auto rv = reverse(drop(filter(numbers, even), 1));
        for (auto &i: rv)
            std::cout << i << ' ';
    }
}
