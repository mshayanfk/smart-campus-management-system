#ifndef HOSTELMANAGER
#define HOSTELMANAGER
#include "HostelBlock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class HostelManager {

    private:
    vector<HostelBlock> hostleblocks;

    public:
    HostelManager();

    ~HostelManager();

    void addBlock(const HostelBlock &block);
    void displayAllBlocks() const;

    void searchBlock(string blockName) const;

    void saveInCSV(ofstream &csvOutputFile);
    void loadFromCSV(ifstream &csvInputFile);

    vector<HostelBlock>& getBlocks();

};


#endif