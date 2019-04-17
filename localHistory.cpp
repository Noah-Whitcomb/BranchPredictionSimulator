#include <iostream>
#include <fstream>

#include "Simulator.h"

#define PATH "C:\\Users\\crisc\\CLionProjects\\ArchitecturePrioj2\\BranchPredictionSimulator\\branch_trace.dat"

using namespace std;
int main(int argc, char** argv)
{
    Args* args = getArgs(argc, argv);
    if(args == nullptr)
    {
        return 0;
    }

    Simulator sim = Simulator(args->file_path, args->num_bits_bhr, args->entries_bht);

    delete args;

    sim.runSim();

    return 0;
}