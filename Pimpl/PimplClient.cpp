#include <iostream>

#include "PimplClient.h"
#include "ComponentApi.h"

namespace PIC {
    void RunTests(){
        auto cApi = PI::ComponentApi(10);

        auto v = cApi.getValue();
        std::cout << v << std::endl;
    }
}
