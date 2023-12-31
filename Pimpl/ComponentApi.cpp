#include "ComponentApi.h"

// This is where we would bring in and use beefier head files as needed

namespace PI {
    class ComponentApi::Impl {
    private:
        int _location;
    public:
        explicit Impl(int location);
        int getValue();
    };

    ComponentApi::ComponentApi(int location) : _pImpl{std::make_unique<ComponentApi::Impl>(location)} {
    }

    ComponentApi::~ComponentApi() = default; // <--- also needed

    int ComponentApi::getValue() {
        return _pImpl->getValue();
    }

    // implementation of pimpl...
    ComponentApi::Impl::Impl(int location) : _location(location) {}

    int ComponentApi::Impl::getValue() {
        return _location;
    }
} // PI