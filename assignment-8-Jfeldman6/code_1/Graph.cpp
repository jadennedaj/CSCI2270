#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addVertex(string name){
    //TODO
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
            cout << vertices[i]->name << " found." << endl;
        }
    }
    
    if(found == false){
        vertex *vert = new vertex;
        vert->name = name;
        vertices.push_back(vert);
    }
    
}

void Graph::addEdge(string v1, string v2){
    //TODO
    for(unsigned int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->name == v1) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->name == v2 && i != j) {
                    adjVertex adjV, adjV2;
                    adjV.v = vertices[j];
                    adjV2.v = vertices[i];
                    vertices[i]->adj.push_back(adjV);
                    vertices[j]->adj.push_back(adjV2);
                }
            }
        }
    }

    
}

void Graph::displayEdges(){
    //TODO
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " --> ";
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    //TODO
    vertex *start;
    for(int i = 0; i < vertices.size(); i++){
        vertices[i]->visited = false;
        if(vertices[i]->name == sourceVertex){
            start = vertices[i];
        }
    }
    
    cout << "Starting vertex (root): " << start->name << "-> ";
    start->visited = true;
    queue<vertex*> queue;
    queue.push(start);
    vertex *temp;
    while(!queue.empty()){
        temp = queue.front();
        queue.pop();
        for(int i = 0; i < temp->adj.size(); i++){
            if(!temp->adj[i].v->visited){
                temp->adj[i].v->visited = true;
                temp->adj[i].v->distance = temp->distance + 1;
                queue.push(temp->adj[i].v);
                cout << temp->adj[i].v->name << "(" << temp->adj[i].v->distance << ") ";
            }
        }
    }
    cout << endl << endl;
}

int Graph::findShortestPathBetweenBuildings(string source, string dest) {
    //TODO

    // Need to find the source vertex since we only have it's key 'src'
    // A pointer for source vertex
    //vetrex *_source;
    vertex *_dest;
    vertex *Start;
    int _destD;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == source)
        {
            Start = vertices[i];
        }
    }

    Start->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the source vertex
    q.push(Start);

    vertex *n;

    // standard BFS
    while(!q.empty()){

        n = q.front();
        q.pop();
        
        for(int i=0; i < n->adj.size(); i++) {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
            if (n->adj[i].v->visited == false) {
                n->adj[i].v->distance = n->distance + 1;
                n->adj[i].v->previous = n;
                n->adj[i].v->visited = true;
                q.push(n->adj[i].v);
                //cout << n->adj[i].v->name << endl;
            }
            if (n->adj[i].v->name == dest){
                _dest = n->adj[i].v;
                _destD = _dest->distance;
        }

    }
    }
    for(int j = 0; j < _destD + 1; j++){
        cout << _dest->name << endl;
        _dest = _dest->previous;
    }
                    
    cout << "Shortest Path Distance: " << _destD << endl;
    return 0;
}
    
    
