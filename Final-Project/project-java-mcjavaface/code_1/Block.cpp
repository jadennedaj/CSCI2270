#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    previousHash = _previousHash;
}

vector<Transaction> Block::getTransactions(){
    return transactions;
}

string Block::getPreviousHash(){
    return previousHash;
}

string Block::calculateHash() {
    return sha256(toString());
}

void Block::mineBlock(unsigned int difficulty) {
    bool mined = 0;
    string zeroes = "";
    for (unsigned int i = 0; i<difficulty;i++){
        zeroes += '0';
    }
    while(!mined){
        if (calculateHash().substr(0,difficulty) == zeroes) mined = true;
        else nonce++;
    }
     cout << calculateHash() << endl;
}

string Block::toString(){
    stringstream data;
    data << "Nonce: " << nonce << "\nTransactions:\n";
    for (unsigned int i = 0; i <transactions.size();i++){
        data << transactions[i].toString() << endl;
    }
    data << "Previous hash: " << previousHash << endl;
    data << "Timestamp: " << timestamp << endl;
    return data.str();
}