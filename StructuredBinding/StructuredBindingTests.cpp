#include "StructuredBindingTests.h"
#include<iostream>

namespace SB {
    Item::Item(int age) : _age(age) {}

    std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << item._age;
        return os;
    }

    std::tuple<bool, Item> StructuredBindingTests::GetPair() const {
        return std::make_tuple(_b, _i);
    }

    StructuredBindingTests::StructuredBindingTests(bool b, const Item &i) : _b(b), _i(i) {}

    void RunTests() {
        const auto sb = StructuredBindingTests{true, Item{100}};
        auto [x, y] = sb.GetPair();
        std::cout << x << " " << y << '\n';
    }
}
