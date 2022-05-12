/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
    
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO
    if(head == nullptr){
        
        head = new CUSatellite;
        head->name = satelliteName;
        head->ditanceFromEarth = distance;
        head->numberMessages = 0;
        head->next = nullptr;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
    }else if(previous == ""){
        
        CUSatellite *s = new CUSatellite;
        s->name = satelliteName;
        s->ditanceFromEarth = distance;
        s->numberMessages = 0;
        s->next = head;
        head = s;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
    }else{
        CUSatellite *ptr = head;
        CUSatellite *prev;
        bool found = false;
        while(ptr != nullptr && prev != ptr){
            if(ptr->name == previous){
                prev = ptr;
                found = true;
            }
            ptr = ptr->next;
        }
        if(found != true){
            cout << "Cannot add new node; previous node not found" << endl;
            cout << endl;
        }else{
        
            cout << "adding: " << satelliteName << " (prev: " << prev->name << ")" << endl;
            CUSatellite *newSatellite = new CUSatellite;
            newSatellite->name = satelliteName;
            newSatellite->ditanceFromEarth = distance;
            newSatellite->numberMessages = 0;
            newSatellite->next = prev->next;
            prev->next = newSatellite;
        }
    }
    
    
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){
    // TODO 
    int numSatellites = 6;
    string satellites[] = {"MAVEN", "JUNO", "PIONEER", "GALILEO", "KEPLER", "TESS"};
    int distances[] = {9,4,5,6,10,2};
    head = nullptr;
    CUSatellite *prev = new CUSatellite;
    string previous = prev->name;
    for(int i = 0; i < numSatellites; i++){
        addSatelliteInfo(previous, satellites[i], distances[i]);
        prev = searchForSatellite(satellites[i]);
    }
}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite *ptr = head;
    while(ptr != nullptr && ptr->name != satelliteName){
        ptr = ptr->next;
    }
    
    return ptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {
    // TODO
    if(head != nullptr){
        
        CUSatellite *ptr = searchForSatellite(receiver);
        if(ptr != NULL){
            CUSatellite *count = head;
            while(count != nullptr){
                count->message = "distance of " + count->name + " from earth is " + to_string(count->ditanceFromEarth);
                count->numberMessages++;
                cout << count->name << " [# messages received: " << count->numberMessages << "] received: " << count->message << endl;
                if(count == ptr) break;
                count = count->next;
                
            }

        }else{
            cout << "Satellite not found" << endl;
        }
    }else{
        cout << "Empty list" << endl;
    }
    
    
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->ditanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}

/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
    
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO
    if(head == nullptr){
        
        head = new CUSatellite;
        head->name = satelliteName;
        head->ditanceFromEarth = distance;
        head->numberMessages = 0;
        head->next = nullptr;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
    }else if(previous == ""){
        
        CUSatellite *s = new CUSatellite;
        s->name = satelliteName;
        s->ditanceFromEarth = distance;
        s->numberMessages = 0;
        s->next = head;
        head = s;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
    }else{
        CUSatellite *ptr = head;
        CUSatellite *prev;
        bool found = false;
        while(ptr != nullptr && prev != ptr){
            if(ptr->name == previous){
                prev = ptr;
                found = true;
            }
            ptr = ptr->next;
        }
        if(found != true){
            cout << "Cannot add new node; previous node not found" << endl;
            cout << endl;
        }else{
        
            cout << "adding: " << satelliteName << " (prev: " << prev->name << ")" << endl;
            CUSatellite *newSatellite = new CUSatellite;
            newSatellite->name = satelliteName;
            newSatellite->ditanceFromEarth = distance;
            newSatellite->numberMessages = 0;
            newSatellite->next = prev->next;
            prev->next = newSatellite;
        }
    }
    
    
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){
    // TODO 
    int numSatellites = 6;
    string satellites[] = {"MAVEN", "JUNO", "PIONEER", "GALILEO", "KEPLER", "TESS"};
    int distances[] = {9,4,5,6,10,2};
    head = nullptr;
    CUSatellite *prev = new CUSatellite;
    string previous = prev->name;
    for(int i = 0; i < numSatellites; i++){
        addSatelliteInfo(previous, satellites[i], distances[i]);
        prev = searchForSatellite(satellites[i]);
    }
}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite *ptr = head;
    while(ptr != nullptr && ptr->name != satelliteName){
        ptr = ptr->next;
    }
    
    return ptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {
    // TODO
    if(head != nullptr){
        
        CUSatellite *ptr = searchForSatellite(receiver);
        if(ptr != NULL){
            CUSatellite *count = head;
            while(count != nullptr){
                count->message = "distance of " + count->name + " from earth is " + to_string(count->ditanceFromEarth);
                count->numberMessages++;
                cout << count->name << " [# messages received: " << count->numberMessages << "] received: " << count->message << endl;
                if(count == ptr) break;
                count = count->next;
                
            }

        }else{
            cout << "Satellite not found" << endl;
        }
    }else{
        cout << "Empty list" << endl;
    }
    
    
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->ditanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}

