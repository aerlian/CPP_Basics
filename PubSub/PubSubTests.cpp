#include <iostream>
#include <memory>
#include <thread>

#include "Publisher.h"
#include "Subscriber.h"
#include "PubSubTests.h"

namespace PS {
    void RunPublisherLoop(std::shared_ptr<Publisher> &&pub){
        auto i = 0;
        while(i < 10){
            pub->RaiseEvent();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            ++i;
        }
        std::cout << "RunPublisherLoop" << std::endl;
    }

    void RunTests()
    {
        auto publisher = std::make_shared<Publisher>();
        auto s1 = std::make_shared<Subscriber>();
        s1->attach(publisher);

        auto publisherThread = std::thread{RunPublisherLoop, std::move(publisher)};
        std::this_thread::sleep_for(std::chrono::seconds(5));

        s1.reset();
        std::cout << "RunTests exiting" << std::endl;
        publisherThread.join();
    }
}
