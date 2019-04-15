// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H
#define ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H

#include "SmithCounter.h"
#include "Util.h"

class BranchHistoryRegister
{
    private:
        type_int current_value;
        type_int num_bits;
        type_int max_value;
    public:
        explicit BranchHistoryRegister(type_int num_bits, type_int initial_value = 0);
        void updateValue(bool taken);
        type_int getValue() {return current_value;}
        type_int getNumBits() {return num_bits;}

};


#endif //ARCHITECTUREPRIOJ2_BRANCHHISTORYREGISTER_H
