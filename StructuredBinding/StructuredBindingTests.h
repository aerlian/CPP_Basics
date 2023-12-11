#pragma once

#include<tuple>
#include <ostream>

namespace SB {
    class Item
    {
    public:
        explicit Item(int age);
        friend std::ostream &operator<<(std::ostream &os, const Item &item);
    private:
        int _age;
    };

    class StructuredBindingTests {
    private:
        bool _b;
        Item _i;
    public:

        StructuredBindingTests(bool b, const Item &i);

        std::tuple<bool, Item> GetPair() const;
    };

    void RunTests();
}