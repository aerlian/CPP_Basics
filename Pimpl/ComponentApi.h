#pragma once

#include <memory>

namespace PI {
    class ComponentApi {
    public:
        ComponentApi(int location);
        ~ComponentApi(); //<-- need to add this or compilation error
        int getValue();
    private:
        class Impl;
        std::unique_ptr<Impl> _pImpl;
    };
} // PI
