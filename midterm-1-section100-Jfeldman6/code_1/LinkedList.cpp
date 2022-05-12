/*#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "LinkedList.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
    
}

Node* SLL::search(int sKey){

    Node* crawler = head;

    while( crawler != nullptr && crawler->key != sKey){
        crawler = crawler->next;
    }

    return crawler;

}

void SLL::displayList(){
    if(head){
        Node* crawler = head;
        while( crawler != nullptr ){
            cout << crawler->key << "->";
            crawler = crawler->next;
        }
        cout << "END" << endl;
    }
    else
        cout << "Empty linked list" << endl;
}


void SLL::insertAtHead(int newValue){
    // Always insert new node at the beginning of list
    Node* newNode = new Node;
    newNode->key = newValue;
    newNode->next = head;
    head = newNode;
}



void SLL::moveEvenToArray(int* &arr, int &length){
    // TODO
    Node *prev = nullptr;
    Node *temp = head;
    length = 0;
    while(temp != nullptr){
        if(temp->key%2 == 0){
            length++;
        }
        prev = temp;
        temp = temp->next;
    }
    //length = count;
    temp = head;
    prev = nullptr;
    arr = new int[length];
    int i = 0;
    /*if(head->key % 2 != 0){
        head = head->next;
        temp = head;
    }else{*/
/*    while(temp != nullptr){
        if(temp->key % 2 == 0){
            arr[i] = temp->key;
            i++;
            deleteNode(temp->key);
        }
        prev = temp;
        temp = temp->next;
    }
    }


void SLL::deleteNode(int num) 

{
    // TODO: Complete this function
    Node *temp;
    Node *prev = head;
    Node *curr = head;
    
    //temp = searchForSatellite(satelliteName);
    
    if(temp ==  nullptr){
        cout << "Satellite does not exist." << endl;
        
    }else if(temp == head){
        if(head->next == nullptr){
            head = head->next;
            //curr->next = nullptr;
            //cout << "Deleting: " << curr->name << endl;
            delete curr;
            curr = head;
        }else{
            //cout << "Deleting: " << curr->name << endl;
            delete curr;
            //curr = head;
            head = head->next;
        }
    }else{
        while(curr != nullptr){
            if(curr->key == num){
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
                break;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    
    
}
*/

#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "LinkedList.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
    
}

Node* SLL::search(int sKey){

    Node* crawler = head;

    while( crawler != nullptr && crawler->key != sKey){
        crawler = crawler->next;
    }

    return crawler;

}

void SLL::displayList(){
    if(head){
        Node* crawler = head;
        while( crawler != nullptr ){
            cout << crawler->key << "->";
            crawler = crawler->next;
        }
        cout << "END" << endl;
    }
    else
        cout << "Empty linked list" << endl;
}


void SLL::insertAtHead(int newValue){
    // Always insert new node at the beginning of list
    Node* newNode = new Node;
    newNode->key = newValue;
    newNode->next = head;
    head = newNode;
}



void SLL::moveEvenToArray(int* &arr, int &length){
    // TODO
    Node *prev = nullptr;
    Node *temp = head;
    length = 0;
    while(temp != nullptr){
        if(temp->key%2 == 0){
            length++;
        }
        prev = temp;
        temp = temp->next;
    }
    //length = count;
    temp = head;
    prev = nullptr;
    arr = new int[length];
    int i = 0;
    /*if(head->key % 2 != 0){
        head = head->next;
        temp = head;
    }else{*/
    while(temp != nullptr){
        if(temp->key % 2 == 0){
            arr[i] = temp->key;
            i++;
        }/*else{
            prev->next = temp->next;
            delete temp;
        }*/
        
        //i++;
        prev = temp;
        temp = temp->next;
    }
    }
    //arr = array;

