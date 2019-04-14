#include <iostream>
#include <fstream>

#include "BranchHistoryTable.h"

#define PATH "C:\\Users\\crisc\\CLionProjects\\ArchitecturePrioj2\\BranchPredictionSimulator\\branch_trace.dat"

using namespace std;
int main()
{
    BranchHistoryTable sim = BranchHistoryTable(PATH, 2);

    sim.runSim();

    return 0;
}