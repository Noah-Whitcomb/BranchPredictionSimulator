// John Gaboriault-Whitcomb
#include "BranchHistoryRegister.h"

BranchHistoryRegister::BranchHistoryRegister(type_int num_bits, type_int initial_value)
{
    this->num_bits = num_bits;
    this->current_value = initial_value;
    this->max_value= power(2, num_bits) - 1;
}
void BranchHistoryRegister::updateValue(bool taken)
{

    type_int returnval = current_value;
    returnval = returnval << 1u;

    type_int temp = taken ? 1 : 0;
    returnval = returnval | temp;
    current_value = returnval & max_value;
}
