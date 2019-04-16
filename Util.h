// John Gaboriault-Whitcomb

#ifndef ARCHITECTUREPRIOJ2_UTIL_H
#define ARCHITECTUREPRIOJ2_UTIL_H

#include <cstdint>
#include <cstdlib>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef uint16_t type_int;

type_int power(type_int base, type_int power);
int log2(int value);

typedef struct
{
    string file_path; // -f
    type_int num_bits_pc; // -p
    type_int num_bits_bhr; // -b
    type_int entries_bht; // -e
} Args;

Args* getArgs(int argc, char** argv);
void runHelp();
void runNoArgs();
void runBadArgs();


#endif //ARCHITECTUREPRIOJ2_UTIL_H
