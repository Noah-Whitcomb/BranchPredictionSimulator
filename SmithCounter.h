// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
#define ARCHITECTUREPRIOJ2_SMITHCOUNTER_H

#define SMITHCOUNTER_BITS 2u

#include <stdint.h>
#include <cassert>
#include <iostream>

typedef uint16_t type_int;

using namespace std;
class SmithCounter
{
    private:
        type_int count;
    public:
        SmithCounter(type_int initial_value = 0);
        void increment();
        void decrement();
        type_int getCount() const {return count;}
        bool predictTaken(); // return true if taken, false if not
};

#endif //ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
