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
        cout << RED << "No Hostel Blocks are Available " << endl << RESET;
        return;
    }

    cout << CYAN << "=========================================" << endl;
    cout << "--------- HOSTEL BLOCK RECORDS ----------" << endl;
    cout << "=========================================" << endl << RESET;

    for (const HostelBlock &block : hostelBlocks) {
        block.display();
    }
} 

void HostelManager::searchBlock(string blockName) const {
    bool found = false;

    for (const HostelBlock &block : hostelBlocks) {
        if (block.getBlockName() == blockName) {

            cout << GREEN << "Block Found Successfully " << endl << RESET;
            block.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << RED << "No Block Found With This Name = " << RESET << GREEN << blockName << RESET << endl;
    }
}

void HostelManager::removeBlock(string blockName) {
    bool found = false;
    for (int i = 0; i < hostelBlocks.size(); i++) {
        if (hostelBlocks[i].getBlockName() == blockName) {
            hostelBlocks.erase(hostelBlocks.begin() + i);
            cout << GREEN << "Block Removed Successfully" << endl << RESET;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << RED << "No Block Found With This Name = " << RESET << GREEN << blockName << RESET << endl;
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

    HostelBlock block;
    while (true) {
        block.loadFromCSV(csvInputFile);
        if (csvInputFile.fail() || csvInputFile.eof()) break;
        hostelBlocks.push_back(block);
    }
}

vector<HostelBlock>& HostelManager::getBlocks() {
    return hostelBlocks;
}