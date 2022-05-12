/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*       This class uses a linked-list of CUSatellite nodes to      */
/*       represent communication paths between Satellites           */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUSatelliteNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 *   between the Satellite previous and the Satellite that follows it in the network.
 * @param previous - name of the Satellite that comes before the new Satellite
 * @param SatelliteName - name of the new Satellite 
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     

    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: populates the network with the predetermined CUSatellites
 * @param none
 * @return none
 */
void CUSatelliteNetwork::loadDefaultSetup()
{

    deleteEntireNetwork();
    // TODO: Copy-paste your solution from Assignment 3
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
 * Purpose: Search the network for the specified Satellite and return a pointer to that node
 * @param SatelliteName - name of the Satellite to look for in the network
 * @return pointer to node of SatelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    // TODO: Copy-paste your solution from Assignment 3
    CUSatellite *ptr = head;
    while(ptr != nullptr && ptr->name != satelliteName){
        ptr = ptr->next;
    }
    
    return ptr;
    
}

/*
 * Purpose: Relay a message through the linked list until the specified Satellite
 * @param string receiver - name of the Satellite 
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: prints the current list in an organized manner
 * @param none
 * @return none

 */
void CUSatelliteNetwork::printNetwork() 
{
    /* finished. do not touch. */
    cout << "== CURRENT PATH ==" << endl;

    if (head)
    {
        CUSatellite* temp = head;
        
        while (temp)
        {
            cout << temp->name << "(" << temp->ditanceFromEarth << ") -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    else
    {
        cout << "nothing in path";
    }

    cout << endl << "===" << endl;


}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the Satellite in the network with the specified name.
 * @param SatelliteName - name of the Satellite to delete in the network
 * @return none
 */
void CUSatelliteNetwork::deleteCUSatellite(string satelliteName) 

{
    // TODO: Complete this function
    CUSatellite *temp;
    CUSatellite *prev = head;
    CUSatellite *curr = head;
    
    temp = searchForSatellite(satelliteName);
    
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
            if(curr->name == satelliteName){
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

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.

 * @param: none
 * @return: none
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    CUSatellite *curr = head;
    CUSatellite *prev = head;
    
    while(curr != nullptr){
        if(head->next == nullptr){
            head = nullptr;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
        prev->next = nullptr;
        head = curr;
        delete prev;
    }

}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUSatelliteNetwork::detectLoop() 
{
    // TODO: Complete this function
    
    CUSatellite *curr = head;
    CUSatellite *next1 = head;
    
    while(next1 != nullptr && next1->next != nullptr && curr != nullptr){
        curr = curr->next;
        next1 = next1->next->next;
        
        if(curr == next1){
            return true;
            break;
        }
        
    }
    
    return false; 
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
* @param SatelliteName - name of the Satellite to loop back to
* returns the last node before loop creation (to break the loop)
*/
CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{
    // TODO: Complete this function
    CUSatellite *loop;
    CUSatellite *temp = searchForSatellite(satelliteName);
    CUSatellite *found = head;
    CUSatellite *curr = head;
    
    if(head == nullptr) return head;
    if(temp == nullptr){
        while(curr->next != nullptr){
            curr = curr->next;
        }
        loop = curr;
        
    }else{
        while(curr != nullptr){
            //if(curr->name == satelliteName){
               // found = curr;
            //}
            if(curr->next == nullptr){
                loop = curr;
                //curr->next = found;
                //break;
            }
            curr = curr->next;
        }
        loop->next = temp;
    }
    
    return loop;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 * @param: start_index, end_index - indices of start node and the end node
 * @return: none
 */
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    // TODO: Complete this function
    
    CUSatellite *curr = head;
    CUSatellite *tail = head;
    CUSatellite *S = head;
    CUSatellite *prevS;
    CUSatellite *E = head;
    CUSatellite *nextE = head;
    int tot = -1;
    
    if(isEmpty()){
        return;
    }else{
    while(curr != nullptr){
        tail = curr;
        curr = curr->next;
        tot++;
    }
    if(start < 0 || start >= tot){
        cout << "Invalid end index" << endl;
        return;
    }else if(end < 0 || end >= tot){
        cout << "Invalid end index" << endl;
        return;
    }else if(start > end){
        cout << "Invalid indicies" << endl;
        return;
    }else{
        int start1 = 0;
        curr = head;
        while(start1 < start){
            prevS = curr;
            //cout << curr->name << endl;
            curr = curr->next;
            start1++;
        }
        
        int end1 = 0;
        while(end1 < end+1){
            E = nextE;
            nextE = nextE->next;
            end1++;
        }
        if(E == tail){
            return;
        }else if(curr == head){
            tail->next = curr;
            E->next = nullptr;
            head = nextE;
        }else{
            prevS->next = nextE;
            tail->next = curr;
            E->next = nullptr;
        }
    }
    }
}
/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    // TODO: Complete this function
    
    
}