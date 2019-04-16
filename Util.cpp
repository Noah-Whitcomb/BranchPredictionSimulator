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

int log2(int value)
{
    int result = 0;
    const int limit  = 100;

    while (value > 1 && result < limit)
    {
        value = value >> 1u;
        result ++;
    }
    if (value == 1)
        return result;
    else
        return -result;
}

Args* getArgs(int argc, char** argv)
{
    if(argc == 1)
    {
        runNoArgs();
        return nullptr;
    }
    if(argc != 5)
    {
        runBadArgs();
        return nullptr;
    }
    Args* args = new Args;
    for(size_t i = 1; i<argc; i++)
    {
        if(strcmp(argv[i],"-f") == 0)
        {
            args->file_path = argv[i+1];
            i++;
        }
        else if(strcmp(argv[i], "-b") == 0)
        {
            char* temp;
            int num = strtol(argv[i+1], &temp, 0);
            if (temp == argv[i+1] || *temp)
            {
                runBadArgs();
                delete args;
                return nullptr;
            }
            args->num_bits_bhr = num;
            i++;
        }
        else if(strcmp(argv[i], "-h") == 0)
        {
            runHelp();
            delete args;
            return nullptr;
        }
        else
        {
            runBadArgs();
            delete args;
            return nullptr;
        }
    }
}

void runHelp()
{
    printf("The following command line argument are needed for this program:\n");
    printf("[-f]   The next argument is the file to be used for input\n");
    printf("[-b]   The next argument is the number of bits to be used in the branch history register. This is\n");
    printf("\talso used to calculate the size of the smith counter list (it is based on the total number of bits\n");
    printf("\tfrom the pc and bhr)\n");
}

void runNoArgs()
{
    printf("No arguments supplied. Use [-h] for help.");
}

void runBadArgs()
{
    printf("Bad command line arguments, try again.");
}