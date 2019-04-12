// John Gaboriault-Whitcomb
#ifndef ARCHITECTUREPRIOJ2_SIMULATOR_H
#define ARCHITECTUREPRIOJ2_SIMULATOR_H

#include <vector>

#include "SmithCounter.h"

using namespace std;
class Simulator
{
    private:
        vector<SmithCounter> counters;
        void addSmithCounter(uint16_t initial_value);
        uint64_t num_branches;
        uint64_t branches_taken;
        uint64_t taken_correctly_predicted;
        uint64_t branches_not_taken;
        uint64_t not_taken_corrently_predicted;
    public:
        Simulator(int num_counters, uint16_t initial_value = 0);
        void incNumBranches() {num_branches++;}
        void incBranchesTaken() {branches_taken++;}
        void incTakenCorrectPrediction() {taken_correctly_predicted++;}
        void incBranchesNotTaken() {branches_not_taken++;}
        void incNotTakenCorrectPrediction() {not_taken_corrently_predicted++;}

};


#endif //ARCHITECTUREPRIOJ2_SIMULATOR_H
