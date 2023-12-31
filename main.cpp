#include "MoveSemantics/MoveTests.h"
#include "StructuredBinding/StructuredBindingTests.h"
#include "Ranges/RangeTests.h"
#include "Dictionary/Custom/sjr_map.h"
#include "Alignment/AlignmentTests.h"
#include "PubSub/PubSubTests.h"
#include "Pimpl/PimplClient.h"

int main() {
//    MoveTestsNs::MoveTests();
//    SB::RunTests();
//    RNG::RunRanges();
//    CM::RunTests();
//    AT::RunTests();
//    PS::RunTests();
        PIC::RunTests();
    return 0;
}
