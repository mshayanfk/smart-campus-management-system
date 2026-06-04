#include "HostelManager.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

HostelManager::HostelManager() {}

HostelManager::~HostelManager() {}

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
}