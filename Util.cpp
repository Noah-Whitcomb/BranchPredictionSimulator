// John Gaboriault-Whitcomb

#include "Util.h"

type_int power(type_int base, type_int power)
{
    type_int return_val = 1;
    for(type_int i = 0; i<power; i++)
    {
        return_val = return_val*base;
    }
    return return_val;
}
