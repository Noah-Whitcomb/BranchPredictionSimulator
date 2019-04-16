// John Gaboriault-Whitcomb
#include "Simulator.h"

Simulator::Simulator(string file_path, type_int num_bits_bhr, type_int entries_bht, type_int initial_value)
{
    this->num_bits_pc = log2(entries_bht);
    this->num_bits_bhr = num_bits_bhr;
    this->entries_bht = entries_bht;
    if(this->num_bits_pc < 0) assert(false);
    this->total_bits = this->num_bits_bhr + this->num_bits_pc;
    if(total_bits > 16)
    {
        cout << "number of bits too high" << endl;
        assert(false);
    }
    this->file_path = file_path;
    this->num_branches = 0;
    this->branches_taken = 0;
    this->taken_correctly_predicted = 0;
    this->branches_not_taken = 0;
    this->not_taken_corrently_predicted = 0;

    // set up smith counters
    type_int num_counters = power(2, total_bits);
    for(size_t i = 0; i<num_counters; i++)
    {
        addSmithCounter(initial_value);
    }

    for(size_t i = 0; i<this->entries_bht; i++)
    {
        bht.emplace_back(BranchHistoryRegister(num_bits_bhr));
    }

}

void Simulator::addSmithCounter(type_int initial_value)
{
    counters.emplace_back(SmithCounter(initial_value));
}

type_int Simulator::getIndex(type_int address, type_int& bht_index)
{
    // get bits from pc
    type_int index = address >> 2u;
    type_int operand = power(2, num_bits_pc) - 1;

    index = index & operand;
    bht_index = index;
    // get entry at index in bht
    type_int bht_val = bht[index].getValue();

    //append bits from pc to bhr_val
    index = index << num_bits_bhr;
    index = index | bht_val;
    return index;
}

void Simulator::runNextLine(type_int address, bool taken)
{
    incNumBranches();

    //bitset<16> x(address);
    type_int bht_index;
    type_int index = getIndex(address, bht_index);
    //cout << index << " ";
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
    bht[bht_index].updateValue(taken);
}

void Simulator::wrapUp()
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

void Simulator::runSim()
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
        runNextLine(address, did_take);
    }
    input_file.close();

    wrapUp();
}
