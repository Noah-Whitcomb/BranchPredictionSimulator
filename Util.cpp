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

Args* getArgs(int argc, char** argv)
{
    if(argc == 1)
    {
        runNoArgs();
    }
    Args* args = new Args;
    for(size_t i = 1; i<argc; i++)
    {
        if(strcmp(argv[i],"-f") == 0)
        {
            args->file_path = argv[i+1];
            i++;
        }
        else if(strcmp(argv[i], "-p") == 0)
        {
            char* temp;
            int num = strtol(argv[i+1], &temp, 0);
            if (temp == argv[i+1] || *temp)
            {
                runBadArgs();
                delete args;
                return nullptr;
            }
            args->num_bits_pc = num;
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
    printf("[-f]   The next line is the file to be used for input\n");
    printf("[-p]   The next line is the number of bits from the program counter used to index the list of smith\n");
    printf("\tcounters. This is also used to calculate the size of the smith counter list.");
}

void runNoArgs()
{
    printf("No arguments supplied. Use [-h] for help.");
}

void runBadArgs()
{
    printf("Bad command line arguments, try again.");
}