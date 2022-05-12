#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    int srcVal = getBalanceOfAddress(src);
    if (srcVal >= coins){
        Transaction n(src,dst,coins);
        pending.push_back(n);
        if (src != "BFC") cout << src << "'s transaction added to pending\n";
    } else cout << src << " is too broke for the transaction with " << dst << ".\n";
}

bool Blockchain::isChainValid() { 
    bool valid = false;
    for (int i = 2; i < chain.size();i++){
        // cout << chain[i].getPreviousHash() << endl;
        // cout << chain[i-1].calculateHash() << endl;
        if (chain[i].getPreviousHash() == chain[i-1].calculateHash() && chain[i].getPreviousHash()[0] == '0'){ // if (chain[i].getPreviousHash() == chain[i-1].calculateHash() && chain[i].getPreviousHash()[0] == '0') {
            valid = true;
        } else{ 
            cout << "Invalid Blockchain: " << chain[i].getPreviousHash() << " is not equal to " << chain[i-1].calculateHash() << endl;
            return false;
        }
    }
    // if (!valid) cout << chain[2].getPreviousHash();
    return valid;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    addTransaction("BFC",minerAddress,0); // add 0 to minerAddress just in case it is not found, does not modify values;
    // if (isChainValid()){
        Block newBlock(pending,time(nullptr),getLatestBlock().calculateHash());
        newBlock.mineBlock(difficulty);
        pending.clear();
        chain.push_back(newBlock);
        addTransaction("BFC",minerAddress,miningReward); // new "genesis"
        return true;
    // } else {
    //     cout << "Invalid blockchain\n";
    //    return false; 
    // }
}

int Blockchain::getBalanceOfAddress(string address) {
    if (address == "BFC") return 99999999; //BFC is to generate coin, needs to be infinite
    int balance = 0;
    for (unsigned int i = 0; i < chain.size();i++){ //traversal of blocks
        for (unsigned int j = 0; j < chain[i].getTransactions().size();j++){ //traversal of transactions within a block
            if (balance >= 0){
                if(chain[i].getTransactions()[j].getReceiver() == address) {
                    balance += chain[i].getTransactions()[j].getAmount();
                }
                if (chain[i].getTransactions()[j].getSender() == address){
                    balance -= chain[i].getTransactions()[j].getAmount();
                }
            } else balance = 0;
        }
    }
    return balance;
}

void Blockchain::prettyPrint() {
    for (unsigned int i = 0; i < chain.size();i++){//traversal of blocks
        for (unsigned int j = 0; j < chain[i].getTransactions().size(); j++){ //traversal of transactions within a block
            cout << chain[i].getTransactions()[j].toString() << endl;
        }
    }
}