// John Gaboriault-Whitcomb
#include "BranchHistoryTable.h"

BranchHistoryTable::BranchHistoryTable(string file_path, type_int num_bits, type_int initial_value)
{
    if(num_bits > 16)
    {
        cout << "number of bits too high" << endl;
        assert(false);
    }
    this->num_bits = num_bits;
    this->file_path = file_path;
    this->num_branches = 0;
    this->branches_taken = 0;
    this->taken_correctly_predicted = 0;
    this->branches_not_taken = 0;
    this->not_taken_corrently_predicted = 0;

    type_int num_counters = power(2, num_bits);
    for(int i = 0; i<num_counters; i++)
    {
        addSmithCounter(initial_value);
    }
}

void BranchHistoryTable::addSmithCounter(type_int initial_value)
{
    this->counters.emplace_back(SmithCounter(initial_value));
}

type_int BranchHistoryTable::getIndex(type_int address, type_int numBits)
{
    type_int index = address >> 2u;
    type_int operand = power(2, numBits) - 1;

    index = index & operand;
    return index;
}

void BranchHistoryTable::predictBranch(type_int address, bool taken)
{
    incNumBranches();

    //bitset<16> x(address);
    type_int index = getIndex(address, this->num_bits);
    //cout << "number in binary: " << x << " index from program:" << index << endl;
    if(counters[index].predictTaken() && taken)
    {
        incTakenCorrectPrediction();
    }
    else if(!counters[index].predictTaken() && !taken)
    {
        incNotTakenCorrectPrediction();
    }

    if(taken)
    {
        incBranchesTaken();
        counters[index].increment();
    }
    else
    {
        incBranchesNotTaken();
        counters[index].decrement();
    }
}

void BranchHistoryTable::wrapUp()
{
    cout << "Number of branches: " << num_branches << endl;
    cout << "Number of branches taken: " << branches_taken << endl;
    cout << "Number taken branches correctly predicted: " << taken_correctly_predicted << endl;
    cout << "Number of branches not taken: " << branches_not_taken << endl;
    cout << "Number not taken branches correctly predicted: " << not_taken_corrently_predicted << endl;
    double correct_predictions = taken_correctly_predicted + not_taken_corrently_predicted;
    double correct_rate = correct_predictions/num_branches;
    cout << "Overall rate of correct predictions: " << correct_rate << "%" << endl;
}

void BranchHistoryTable::runSim()
{
    ifstream input_file;
    input_file.open(file_path);
    if(!input_file)
    {
        cout << "Could not open test file. Try again.";
        return;
    }

    type_int address;
    string taken;
    while(input_file >> address >> taken)
    {
        bool did_take;
        if(taken == "T")
        {
            did_take = true;
        }
        else if(taken == "N")
        {
            did_take = false;
        }
        else assert(false);
        predictBranch(address, did_take);
    }
    input_file.close();

    wrapUp();
}

type_int BranchHistoryTable::power(type_int base, type_int power)
{
    type_int return_val = 1;
    for(type_int i = 0; i<power; i++)
    {
        return_val = return_val*base;
    }
    return return_val;
}
