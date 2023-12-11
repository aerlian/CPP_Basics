//
#include "Subscriber.h"
#include "Publisher.h"

namespace PS{
    Subscription Publisher::Subscribe(const std::shared_ptr<Subscriber> sub) {
        auto token = nextToken();
        _subs.insert({token, sub});
        return token;
    }

    void Publisher::UnSubscribe(const Subscription &sub) {
        _subs.erase(sub);
    }

    void Publisher::RaiseEvent()
    {
        static auto i = 0;
        for(auto &s : _subs)
        {
            if (auto lockedSub = s.second.lock())
            {
                lockedSub->OnEvent(i++);
            }
        }
    }
}


