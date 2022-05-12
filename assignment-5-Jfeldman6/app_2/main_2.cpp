#include "../code_2/WaitlistQueue.hpp"
#include <iostream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Resize" << endl;
    cout << "5. Quit" << endl;
    cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 2)
    {
        freopen(argv[2],"r",stdin);
    }
    
    /* TODO */
    WaitlistQueue queue;
    string input;
    string append;
    string s;
    int newSize;
    bool quit = false;
    while(!quit){
        menu();
        getline(cin,input);
        int in = stoi(input);
        switch(in){
            case 1:
                cout << "Enter the value to add into queue:" << endl;
                getline(cin, append);
                queue.enqueue(append);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << queue.peek() << endl;
                break;
            case 4:
                cout << "Enter the new capacity:" << endl;
                getline(cin,s);
                newSize = stoi(s);
                cout << "Resizing from " << queue.capacity() << " to " << newSize << endl;
                queue.resize(newSize);
                break;
            case 5:
                cout << "Quitting...\nContents of the queue:\n";
                while(queue.peek()!= "<EMPTY QUEUE>"){
                    cout << queue.peek() << endl;
                    queue.dequeue();
                }
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    }
    
    return 0;
}