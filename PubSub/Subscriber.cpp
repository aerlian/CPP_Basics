//
// Created by aerlian on 12/10/23.
//

#include <iostream>
#include <memory>

#include "Publisher.h"
#include "Subscriber.h"

namespace PS{
    void Subscriber::OnEvent(int value) {
        std::cout << value << std::endl;
    }

    void Subscriber::attach(const std::shared_ptr<Publisher> &publisher) {
        _publisher = publisher;
        if (auto lockedPub = _publisher.lock()){
            auto d = shared_from_this();
            _token = lockedPub->Subscribe(d);
        }
    }

    Subscriber::~Subscriber() {
        if (auto lockedPub = _publisher.lock()){
            lockedPub->UnSubscribe(_token);
        }
    }
}
