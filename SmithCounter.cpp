// John Gaboriault-Whitcomb
#include "SmithCounter.h"

SmithCounter::SmithCounter(uint16_t initial_value)
{
    if(initial_value > 3)
    {
        assert(true);
    }
    this->count = initial_value;
}

void SmithCounter::increment()
{
    uint8_t temp = this->count + 1;
    if(temp > 3)
    {
        return;
    }
    this->count += 1;
}

void SmithCounter::decrement()
{
    uint8_t temp = this->count - 1;
    if(temp > 3)
    {
        return;
    }
    this->count -= 1;
}


