// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
#define ARCHITECTUREPRIOJ2_SMITHCOUNTER_H


#include <stdint.h>
#include <cassert>

class SmithCounter
{
    private:
        uint16_t count;
    public:
        SmithCounter(uint16_t initial_value = 0);
        void increment();
        void decrement();
        uint16_t getCount() {return count;}
};


#endif //ARCHITECTUREPRIOJ2_SMITHCOUNTER_H
