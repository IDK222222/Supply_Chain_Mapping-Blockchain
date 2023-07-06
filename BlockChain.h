//
// Created by Yousef Khalil on 3/24/2022.
//

#ifndef CW111_BLOCKCHAIN_H
#define CW111_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;

class BlockChain {
private:
    //vector to store the Blocks
    vector<Block> blockChain;
    //index
    int i;
    //Stages of the supply chain
    transaction farm;
    transaction packingFactory;
    transaction transporter;
    transaction afterRipening;
    transaction distribution;
    //Mutator
    void setTransactionData() ;
    //Adds blocks
    void addBlock(transaction data);
    //Checks if the chain is valid
    void chainLinked();

public:
    //Constructor
    BlockChain();


};

#endif //CW111_BLOCKCHAIN_H
