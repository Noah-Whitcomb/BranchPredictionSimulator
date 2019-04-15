// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SIMULATOR_H
#define ARCHITECTUREPRIOJ2_SIMULATOR_H

#include <vector>
#include <fstream>
#include <bitset>

#include "SmithCounter.h"
#include "Util.h"
#include "BranchHistoryRegister.h"

using namespace std;
class Simulator
{
    private:
        vector<SmithCounter> counters;
        BranchHistoryRegister* bhr;
        void addSmithCounter(uint16_t initial_value);
        string file_path;
        type_int num_bits_pc;
        type_int num_bits_bhr;
        type_int total_bits;
        uint64_t num_branches;
        uint64_t branches_taken;
        uint64_t taken_correctly_predicted;
        uint64_t branches_not_taken;
        uint64_t not_taken_corrently_predicted;
    public:
        ~Simulator();
        Simulator(string file_path, type_int num_bits_smith_counter, type_int num_bits_bhr, uint16_t initial_value = 0);
        void incNumBranches() {num_branches++;}
        void incBranchesTaken() {branches_taken++;}
        void incTakenCorrectPrediction() {taken_correctly_predicted++;}
        void incBranchesNotTaken() {branches_not_taken++;}
        void incNotTakenCorrectPrediction() {not_taken_corrently_predicted++;}
        void runSim();
        void runNextLine(type_int address, bool taken);
        type_int getIndex(type_int address);
        void wrapUp();

};


#endif //ARCHITECTUREPRIOJ2_SIMULATOR_H
