#include <memory>
#include <unordered_map>
#include <mutex>

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
        std::mutex _mutex;
    public:
        Subscription Subscribe(const std::shared_ptr<Subscriber> sub);
        void UnSubscribe(const Subscription &token);
        void RaiseEvent();
    };
}
