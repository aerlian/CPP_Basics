#include <iostream>
#include <memory>

#include "Publisher.h"
#include "Subscriber.h"
#include "PubSubTests.h"

namespace PS {
    void RunTests()
    {
        auto publisher = std::make_shared<Publisher>();
        {
            auto s1 = std::make_shared<Subscriber>();
            s1->attach(publisher);

            for(auto i = 0; i < 5; i++)
            {
                publisher->RaiseEvent();
            }
        }
    }
}
