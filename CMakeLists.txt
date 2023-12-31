cmake_minimum_required(VERSION 3.23)
project(CPP_Basics)

set(CMAKE_CXX_STANDARD 23)

add_executable(CPP_Basics main.cpp MoveSemantics/MoveTests.cpp MoveSemantics/MoveTests.h StructuredBinding/StructuredBindingTests.cpp StructuredBinding/StructuredBindingTests.h Ranges/RangeTests.cpp Ranges/RangeTests.h Dictionary/Custom/sjr_map.cpp Dictionary/Custom/sjr_map.h Alignment/AlignmentTests.cpp Alignment/AlignmentTests.h PubSub/PubSubTests.cpp PubSub/PubSubTests.h PubSub/Publisher.cpp PubSub/Publisher.h PubSub/Subscriber.cpp PubSub/Subscriber.h Pimpl/ComponentApi.cpp Pimpl/ComponentApi.h Pimpl/PimplClient.cpp Pimpl/PimplClient.h)
