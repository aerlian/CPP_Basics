#include "sjr_map.h"

#include<string>
#include<functional>
#include<iostream>

namespace CM {
    void RunTests(){
        const auto m = sjr_map<MyKey, int>{25};
        m.add({20}, 100);
        int result;
        if (m.try_get({20}, result)){
            std::cout << "result:" << result << std::endl;
        }

        m.add({20}, 200);

        if (m.try_get({20}, result)){
            std::cout << "result:" << result << std::endl;
        }

        m.add({70}, 200);
        if (m.try_get({70}, result)){
            std::cout << "result:" << result << std::endl;
        }

        m.remove({70});

        if (!m.try_get({70}, result)){
            std::cout << "result:" << result << std::endl;
        }

        m.add({70}, 200);
        if (m.try_get({70}, result)){
            std::cout << "result:" << result << std::endl;
        }
    }
} // CM