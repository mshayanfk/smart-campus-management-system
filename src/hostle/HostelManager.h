#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H
#include "HostelBlock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class HostelManager {

    private:
    vector<HostelBlock> hostelBlocks;

    public:
    HostelManager();

    ~HostelManager();

    void addBlock(const HostelBlock &block);
    void displayAllBlocks() const;

    void searchBlock(string blockName) const;

    void removeBlock(string blockName);

    void saveInCSV(ofstream &csvOutputFile) const;
    void loadFromCSV(ifstream &csvInputFile);

    vector<HostelBlock>& getBlocks();

};


#endif