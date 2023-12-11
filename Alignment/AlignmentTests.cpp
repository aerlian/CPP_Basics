#include "AlignmentTests.h"

#include<iostream>
#include<memory>
#include<cstddef>

namespace AT
{
    struct T1
    {
        char a;
        int b;
        char c;
        std::max_align_t padding;
    };

    struct T2
    {
        char a;
        char b;
        int c;
    };

    struct T3
    {
        void *p;
    };

    struct T4
    {
        std::unique_ptr<int> p;
    };

    struct VertexBeforePadding {
        float x, y, z;
        float r, g, b;
        float u, v;
    };

    struct VertexAfterPadding {
        float x, y, z;
        float r, g, b;
        float u, v;

        // Pad with std::max_align_t to ensure 64-byte alignment
        std::max_align_t padding;
    };

    void RunTests()
    {
//        std::cout << sizeof(T1) << std::endl;
//        std::cout << sizeof(T2) << std::endl;
//        std::cout << sizeof(T3) << std::endl;
//        std::cout << sizeof(T4) << std::endl;

        std::cout << sizeof(VertexBeforePadding) << std::endl;
        std::cout << sizeof(VertexAfterPadding) << std::endl;
    }
}
