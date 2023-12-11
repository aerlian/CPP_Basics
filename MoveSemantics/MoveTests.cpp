#include "MoveTests.h"
#include <memory>
#include <string>
#include <vector>

namespace MoveTestsNs {
    Item::Item(int value, std::unique_ptr<std::vector<int>> &intList) : _value(value), _intList(std::move(intList)) {}

    void MoveTests(){
        auto list1 = std::make_unique<std::vector<int>>(std::vector<int>{1, 3, 5, 7});
        auto i1 = Item{2, list1};
        Item i2{1, list1};
    }
}






