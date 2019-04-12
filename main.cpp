#include <iostream>
#include <fstream>

#include "Simulator.h"

#define PATH "C:\\Users\\crisc\\CLionProjects\\ArchitecturePrioj2\\BranchPredictionSimulator\\branch_trace.dat"

using namespace std;
int main()
{
    ifstream input_file;
    input_file.open(PATH);
    if(!input_file)
    {
        cout << "Could not open test file. Try again.";
        return 0;
    }

    Simulator sim = Simulator(32);

    uint32_t address;
    string taken;
    while(input_file >> address >> taken)
    {

    }




    return 0;
}