// SLL.hpp - interface file (header file)
#ifndef SLL_H
#define SLL_H
using namespace std;
struct Node{
    int key;
    Node *next;
};

class SLL{
    private:
        Node* head;

    public:
        SLL(); // constructor declaration
        SLL(int demo); // if called with integer value of 1, 2, 3, or 4, one of the default lists 
                       // will be generated
        ~SLL(); // destructor declaration

        Node* search(int sKey);
        // Precondition: sKey parameter is a int type

        // Postcondition:  if found, returns a pointer to the node containing sKey value.
        // If not found, returns a null pointer.

        void displayList();
        // Precondition: the head node is defined.

        // Post condition: display the key values of the entire list, starting with
        // first node and ending with last node.

        void insertAtHead(int newValue);
        // Precondition: afterMe is a valid pointer to a node in the linked list.
        // newValue is a valid int.

        // Postcondition: a new node is created and newValue is stored as its key.
        // The new node is added after node containing afterMe.

        void moveEvenToArray(int* &arr, int &length);
        // Precondition: arr is a pointer passed by reference to an int type array.

        // Postconditions: 
        // 1) arr points to a dynamically allocated array only containing even values from linked list
        // 2) all even nodes are removed from the linked list object
    
    
    void deleteNode(int num);
};
#endif
