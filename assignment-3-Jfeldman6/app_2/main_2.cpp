#include "../code_2/CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.

    // TODO
    int choice;
    string name;
    string prev;
    int distance;
    
    while(choice !=5){
    displayMenu();
    CUSatelliteNetwork list;
    cin >> choice;
    switch(choice){
        case 1:{
            list.loadDefaultSetup();
            list.printNetwork();
        }break;
        case 2:{
            list.printNetwork();
        }break;
        case 3:{
            
            cout << "Enter name of the recipient to receive the message:" << endl;
            cin >> name;
            
            list.transmitInfo(name);
        }break;
        case 4:{
            
            cout << "Enter a new satellite name: " << endl;
            cin >> name;
            cout << "Enter distance of satellite from earth: " << endl;
            cin >> distance;
            cout << "Enter the previous satellite name (or First): " << endl;
            cin >> prev;
            if(list.searchForSatellite(prev) != nullptr || prev == "First"){
                list.addSatelliteInfo(prev, name, distance);
            }else{
                cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
            }
        }break;
        case 5:{
            cout << "Quitting..." << endl;
            cout << "Goodbye!" << endl;
        }break;
        default:{
            cout << "Invalid input" << endl;
        }
        
    }
    }
    
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
