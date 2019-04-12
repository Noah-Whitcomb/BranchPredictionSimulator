// John Gaboriault-Whitcomb
#include "SmithCounter.h"

SmithCounter::SmithCounter(type_int initial_value)
{
    if(initial_value > 3)
    {
        cout << "Smith counter initial value too large.";
        assert(false);
    }
    this->count = initial_value;
}

void SmithCounter::increment()
{
    type_int temp = this->count + 1;
    if(temp > 3)
    {
        return;
    }
    this->count += 1;
}

void SmithCounter::decrement()
{
    type_int temp = this->count - 1;
    if(temp > 3)
    {
        return;
    }
    this->count -= 1;
}

bool SmithCounter::predictTaken()
{
    return this->count >= 2;
}

