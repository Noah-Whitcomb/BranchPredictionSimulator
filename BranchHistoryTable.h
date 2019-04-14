// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_BRANCHHISTORYTABLE_H
#define ARCHITECTUREPRIOJ2_BRANCHHISTORYTABLE_H

#include <vector>
#include <fstream>
#include <bitset>

#include "SmithCounter.h"

using namespace std;
class BranchHistoryTable
{
    private:
        vector<SmithCounter> counters;
        void addSmithCounter(uint16_t initial_value);
        type_int power(type_int base, type_int power);
        string file_path;
        type_int num_bits;
        uint64_t num_branches;
        uint64_t branches_taken;
        uint64_t taken_correctly_predicted;
        uint64_t branches_not_taken;
        uint64_t not_taken_corrently_predicted;
    public:
        BranchHistoryTable(string file_path, type_int num_bits, uint16_t initial_value = 0);
        void incNumBranches() {num_branches++;}
        void incBranchesTaken() {branches_taken++;}
        void incTakenCorrectPrediction() {taken_correctly_predicted++;}
        void incBranchesNotTaken() {branches_not_taken++;}
        void incNotTakenCorrectPrediction() {not_taken_corrently_predicted++;}
        void runSim();
        void predictBranch(type_int address, bool taken);
        type_int getIndex(type_int address, type_int numBits);
        void wrapUp();

};


#endif //ARCHITECTUREPRIOJ2_BRANCHHISTORYTABLE_H
