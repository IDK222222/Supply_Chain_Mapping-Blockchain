#ifndef CW111_BLOCK_H
#define CW111_BLOCK_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "transaction.h"

class Block{
private:
    //Block information
    int blockNumber;
    transaction data;
    int hashValue;
    int previousHash;
    time_t timeStamp;
    //Mutators
    void setData(transaction data);
    void setTimeStamp(time_t timeStamp);
    void setBlockNumber(int blockNumber);
    void setHashValue(int hashValue);
    void setPreviousHash(int previousHash);
    //Function to generate a 9 char random number
    int generateHash();
public:
    //Class Constructor
    Block(transaction data, int blockNumber, int previousHash, time_t timeStamp);

    //Getters
    int getBlockNumber()const;
    int getHashValue();
    int getPreviousHash();
    //Prints the block
    void printBlock();
};

#endif //CW111_BLOCK_H
