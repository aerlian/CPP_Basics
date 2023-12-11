#include <memory>
#include <unordered_map>

#pragma once

namespace PS {
    using Subscription = int;

    class Subscriber;

    class Publisher {
    private:
        Subscription nextToken(){
            static int token = -1;
            return ++token;
        }
        std::unordered_map<Subscription, std::weak_ptr<Subscriber>> _subs;
    public:
        Subscription Subscribe(const std::shared_ptr<Subscriber> sub);
        void UnSubscribe(const Subscription &token);
        void RaiseEvent();
    };
}
