#include "BlockChain.h"
//Constructor
BlockChain::BlockChain() {
    setTransactionData();
    BlockChain::addBlock(farm);
    BlockChain::addBlock(packingFactory);
    BlockChain::addBlock(transporter);
    BlockChain::addBlock(afterRipening);
    BlockChain::addBlock(distribution);
    BlockChain::chainLinked();
}
//Sets the supply chain data
void BlockChain::setTransactionData() {
    farm.id = 15435435;
    farm.name = "Homegrown Farms";
    farm.location = "Lot 32, Lingkaran Mutiara Hills, Taman Tasik Semenyih, 43500 Semenyih, Selangor, Malaysia";
    farm.type = "farm";

    packingFactory.id = 2234324;
    packingFactory.name = "Banana Packing Factory";
    packingFactory.type = "Packing";
    packingFactory.location = " No. 1, Jalan Plumbum 1, Kawasan Perindustrian Sungai Purun, 43500 Semenyih, Selangor";

    transporter.id = 3324324;
    transporter.type = "Transportation";

    afterRipening.id = 4234324;
    afterRipening.name = "ACSI.LLC ";
    afterRipening.type = "Ripening Room";
    afterRipening.location = "79 Jalan Landak Kawan, Johor Bahru,80250 Johor,Malaysia";

    distribution.id = 5234324;
    distribution.name = "Lotus Tesco";
    distribution.type = "Distribution";
    distribution.location = "No. 1, Jalan TPS 1/1, Taman Pelangi Semenyih, 43500 Semenyih, Selangor";
}
//Adds a block and pushes it to the back of the vector
void BlockChain::addBlock(transaction data) {
    blockChain.begin();
    i = blockChain.size();
    auto t = time(0);
    auto tm = *localtime(&t);
    int previousHash = blockChain.size() > 0 ? blockChain.back().getHashValue() : 0;
    Block banana = *new Block(data, i, previousHash, reinterpret_cast<time_t>(&tm));
    blockChain.push_back(banana);
    banana.printBlock();
}
//Checks if the chain is valid
void BlockChain::chainLinked() {
    int r;
    for (r = 1; r <= 3; r++) {
        if (blockChain.at(r).getPreviousHash() != blockChain.at(r - 1).getHashValue()) {

            cout << "Block Number:" << blockChain.at(r).getBlockNumber()
                 << "Hash Value does not match Block Number:" << blockChain.at(r - 1).getBlockNumber()
                 << "previous hash value" << endl;

        }
    }
    cout << "The Block chain is valid" << endl;

}

