#include "Block.h"

//Class Constructor
Block::Block(transaction data, int blockNumber, int previousHash, time_t timeStamp) {

    setData(data);
    //generating hash value
    setHashValue(generateHash());
    setBlockNumber(blockNumber);
    setPreviousHash(previousHash);
    setTimeStamp(timeStamp);

};

//Getters and Setters
void Block::setData(transaction data) {
    Block::data = data;
};

void Block::setTimeStamp(time_t timeStamp) {
    Block::timeStamp = timeStamp;
};

int Block::getBlockNumber() const {
    return blockNumber;
};

void Block::setBlockNumber(int blockNumber) {
    Block::blockNumber = blockNumber;
};

int Block::getHashValue() {
    return hashValue;
};

void Block::setHashValue(int hashValue) {
    Block::hashValue = hashValue;
};

int Block::getPreviousHash() {
    return previousHash;
};

void Block::setPreviousHash(int previousHash) {
    //IF statement to make sure the first blocks previous hash is equal to its hash
    if (Block::blockNumber > 0) {
        Block::previousHash = previousHash;
    } else {
        Block::previousHash = Block::hashValue;
    }
};
//end of getters and setters

//generates a random 9 char number
int Block::generateHash() {
    return rand() % 999999999 + 111111111;
};

//Prints the Block
void Block::printBlock() {
    cout << blockNumber << endl << hashValue << endl << previousHash << endl << put_time(
            reinterpret_cast<const tm *>(timeStamp), "%d-%m-%Y %H-%M-%S") << endl << "ID:" << data.id << "||"
         << "Name:" << data.name << "||" << "Type:" << data.type << "||" << "Location:" << data.location << endl
         << endl;
};
