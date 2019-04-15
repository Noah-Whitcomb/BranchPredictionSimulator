// John Gaboriault-Whitcomb
#include "BranchHistoryRegister.h"

BranchHistoryRegister::BranchHistoryRegister(type_int num_bits, type_int initial_value)
{
    this->num_bits = num_bits;
    this->current_value = initial_value;
}
void BranchHistoryRegister::updateValue(const SmithCounter& smith)
{
    //TODO change this after debugging to simpler statement
    type_int temp = current_value;
    temp = temp << SMITHCOUNTER_BITS;
    temp = temp & smith.getCount();
    current_value = temp;
}
