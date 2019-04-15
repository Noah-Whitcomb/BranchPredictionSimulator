// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H
#define ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H

#include "SmithCounter.h"

class BranchHistoryRegister
{
    private:
        type_int current_value;
        type_int num_bits;
    public:
        BranchHistoryRegister(type_int num_bits, type_int initial_value = 0);
        void updateValue(const SmithCounter& smith);
        type_int getValue() {return current_value;}

};


#endif //ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H
