//

#include <iostream>

#include "Subscriber.h"
#include "Publisher.h"

namespace PS{
    Subscription Publisher::Subscribe(const std::shared_ptr<Subscriber> sub) {
        auto token = nextToken();
        std::lock_guard<std::mutex> guard(_mutex);
        _subs.insert({token, sub});
        return token;
    }

    void Publisher::UnSubscribe(const Subscription &sub) {
        std::lock_guard<std::mutex> guard(_mutex);
        _subs.erase(sub);
    }

    void Publisher::RaiseEvent()
    {
        static auto i = 0;
        std::lock_guard<std::mutex> guard(_mutex);
        for(auto &s : _subs)
        {
            if (auto lockedSub = s.second.lock())
            {
                lockedSub->OnEvent(i++);
            }
            else{
                std::cout << "Subscriber absent" << std::endl;
            }
        }
    }
}


