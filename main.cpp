#include <iostream>
#include <fstream>

#include "Simulator.h"

#define PATH "C:\\Users\\crisc\\CLionProjects\\ArchitecturePrioj2\\BranchPredictionSimulator\\branch_trace.dat"

using namespace std;
int main()
{
    Simulator sim = Simulator(PATH, 2, 3);

    sim.runSim();

    return 0;
}