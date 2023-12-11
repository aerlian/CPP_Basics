#pragma once

#include <memory>

namespace MoveTestsNs {
    class Item
    {
    public:
        Item(int value, std::unique_ptr<std::vector<int>> &intList);
    public:

    private:
        int _value;
        std::unique_ptr<std::vector<int>> _intList;
    public:
    };

    void MoveTests();
}


