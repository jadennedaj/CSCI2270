#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[]){
    Blockchain buffCUoin;

    buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh"); // gives ashutosh 10 on next mine
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl; // ashutosh cannot afford this because it has not been mined yet
    buffCUoin.addTransaction("ashutosh","maciej", 1); // does not go through, cannot afford

    cout << "ashutosh paid asa 1 BFC ... " << endl; // does not go through because mine has not went through
    buffCUoin.addTransaction("ashutosh","asa", 1); 
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa"); // asa gets 10 on next mine, ashutosh now has 10
    buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl; // asa cannot afford because mine has not went through yet
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    cout << "maciej mining third block ... " << endl;
    buffCUoin.minePendingTransactions("maciej");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();
    bool quit = false;
    int ctr = 0;
    while(!quit){
        cout << "======Main Menu======" << endl;
        cout << "1. Add a transaction" << endl;
        cout << "2. Verify Blockchain" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "4. Print transactions" << endl;
        cout << "5. View amount in address" << endl;
        cout << "6. Quit" << endl;
        int option,coins;
        string input;
        cin >> input;
        option = stoi(input);
        string src,dst;
        switch(option){
            case 1:
            cout << "Source: ";
            cin >> src;
            cout << "Destination: ";
            cin >> dst;
            cout << "(You currently have: " << buffCUoin.getBalanceOfAddress(src) << ")\nValue: ";
            cin >> coins;
            buffCUoin.addTransaction(src,dst,coins);
            break;
            case 2:
            if (buffCUoin.isChainValid()) cout << "Chain is valid: SUCCESS\n";
            else cout << "Chain is invalid: FAILURE\n"; 
            break;
            case 3:
            cout << "Enter your miner address: ";
            cin >> src;
            buffCUoin.minePendingTransactions(src);
            break;
            case 4:
            buffCUoin.prettyPrint();
            break;
            case 5:
            cout << "Source: ";
            cin >> src;
            if (src != "BFC" ) cout << src << " currently has " << buffCUoin.getBalanceOfAddress(src) << " BFC.\n";
            else cout << "BFC is not a valid address\n";
            break;
            case 6:
            cout << "Quit.\n";
            quit = true;
            break;
            default:
            cout << "Please select another option (6 to quit)\n";
        }
    }
    return 0;
}