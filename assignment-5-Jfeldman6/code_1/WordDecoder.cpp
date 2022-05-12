 #include <iostream>
#include "WordDecoder.hpp"
#include <vector>


using namespace std;


WordDecoder::WordDecoder()
{
    // TODO. Initialize all variables required
    stackHead = nullptr;
}

WordDecoder::~WordDecoder()
{
    //TODO. Free up to avoid memory leaks
    Letter* temp = stackHead;
    while(temp != NULL) {
    delete temp;
    temp = temp->next;
  }
  stackHead = NULL;
}

bool WordDecoder::isEmpty()
{
    // TODO. Checking if stack is empty
    if (stackHead == NULL) {
        return true;
    }
    return false;
}

void WordDecoder::push(string letter)
{
    //TODO Perform push operation stack
    Letter* temp = new Letter;
    temp->letter = letter;
    temp->next = stackHead;
    stackHead = temp;
}

void WordDecoder::pop()
{
    //TODO Perform pop operation stack
    if (!isEmpty()) {
        Letter* temp = new Letter;
        temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }else{
        cout << "Stack empty, cannot pop a letter." << endl;
    }
}


Letter* WordDecoder::peek()
{
    //TODO Perform peek operation stack
    if (!isEmpty()) {
        return stackHead;
    }else{
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
}

void WordDecoder::evaluate(string* s, int size)
{
    /* TODO:
    1. Push to stack if lette rin string not a ")"
    2. If ")" comes, then pop until "(", store somewhere. Put letters back to the stack in reverse order of pop.
    3. Finally, the elements are stored in reverse, so print in reverse order. */
    
    Letter* temp = stackHead;
    
    for(int i = 0; i < size; i++){
        if(s[i] != ")" ){
            push(s[i]);
        }else{
            vector<string> eval;
            while(peek()->letter != "("){
                eval.push_back(peek()->letter);
                pop();
            }
            pop();
            for(int j = 0; j < eval.size(); j++){
                push(eval[j]);
            }
        }
    }
    string answer = "";
    
    while(!isEmpty()){
        answer = peek()->letter + answer;
        pop();
    }
    
    cout << "The decoded word: " << answer << endl;
}
