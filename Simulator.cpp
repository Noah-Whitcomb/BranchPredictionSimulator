// John Gaboriault-Whitcomb
#include "Simulator.h"

Simulator::Simulator(int num_counters, uint16_t initial_value);
{
    
}

void Simulator::addSmithCounter(uint16_t initial_value)
{
    this->counters.emplace_back(SmithCounter(initial_value));
}
