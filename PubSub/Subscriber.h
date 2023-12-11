//
// Created by aerlian on 12/10/23.
//

#pragma once

#include <memory>

namespace PS{
    using Subscription = int;
    class Publisher;

    class Subscriber : public std::enable_shared_from_this<Subscriber> {
    private:
        std::weak_ptr<Publisher> _publisher;
        Subscription _token;
    public:
        void attach(const std::shared_ptr<Publisher> &publisher);
        void OnEvent(int value);
        virtual ~Subscriber();
    };
}
