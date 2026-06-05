#include "HostelManager.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

HostelManager::HostelManager() {}

HostelManager::~HostelManager() {}

void HostelManager::addBlock(const HostelBlock &block) {
    hostelBlocks.push_back(block);
}

void HostelManager::displayAllBlocks() const {

    if (hostelBlocks.empty()) {
        cout << "No Hostel Blocks are Available " << endl;
        return;
    }

    cout << "=========================================" << endl;
    cout << "--------- HOSTEL BLOCK RECORDS ----------" << endl;
    cout << "=========================================" << endl;

    for (const HostelBlock &block : hostelBlocks) {
        block.display();
    }
} 

void HostelManager::searchBlock(string blockName) const {
    bool found = false;

    for (const HostelBlock &block : hostelBlocks) {
        if (block.getBlockName() == blockName) {

            cout << "Block Found Successfully " << endl;
            block.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No Block Found With This Name = " << blockName << endl;
    }
}

void HostelManager::saveInCSV(ofstream &csvOutputFile) const {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not opened for writing!");
    }

    for (const HostelBlock &block : hostelBlocks) {
        block.saveInCSV(csvOutputFile);
    }
}

void HostelManager::loadFromCSV(ifstream &csvInputFile) {

    if (!csvInputFile.is_open()) {
        throw runtime_error("File not opened for reading!");
    }

    hostelBlocks.clear();

    while (!csvInputFile.eof()) {
        HostelBlock block;
        block.loadFromCSV(csvInputFile);

        if (csvInputFile.fail()) {
            break;
        }

        hostelBlocks.push_back(block);
    }
}


vector<HostelBlock>& HostelManager::getBlocks() {
    return hostelBlocks;
}