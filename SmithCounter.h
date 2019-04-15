// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
#define ARCHITECTUREPRIOJ2_SMITHCOUNTER_H

#define SMITHCOUNTER_BITS 2u

#include <cassert>
#include <iostream>

#include "Util.h"

using namespace std;
class SmithCounter
{
    private:
        type_int count;
    public:
        explicit SmithCounter(type_int initial_value = 0);
        void increment();
        void decrement();
        type_int getCount() const {return count;}
        bool predictTaken(); // return true if taken, false if not
};

#endif //ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
