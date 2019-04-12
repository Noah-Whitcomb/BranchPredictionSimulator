// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SIMULATOR_H
#define ARCHITECTUREPRIOJ2_SIMULATOR_H

#include <vector>

#include "SmithCounter.h"

using namespace std;
class Simulator
{
    private:
        vector<SmithCounter> counters;
        void addSmithCounter(uint16_t initial_value);
    public:
        Simulator(int num_counters, uint16_t initial_value);
};


#endif //ARCHITECTUREPRIOJ2_SIMULATOR_H
