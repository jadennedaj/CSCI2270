#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

void aOrder(MovieNode* node);
void addMovie(MovieNode* root,MovieNode* node);
MovieNode* findNode(MovieNode* root, string title);
void removeTree(MovieNode* ptr);
void query(MovieNode* root, float rating, int year);
void avgRate(MovieNode* root, MovieNode* avg);
void printLevelNodesHelper(MovieNode * curr, int level);

MovieTree::MovieTree() {
    //TODO
    root = nullptr;
}

MovieTree::~MovieTree() {
    //TODO
    removeTree(root);
}

void MovieTree::printMovieInventory() {
    //TODO
    if(root != nullptr){
        aOrder(root);
    }else{
        cout << "Tree is Empty. Cannot print." << endl;
    }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
    //TODO
    MovieNode *node = new MovieNode;
    node->ranking = ranking;
    node->title = title;
    node->year = year;
    node->rating = rating;
    if(root != nullptr){
        addMovie(root, node);
    }else{
        root = node;
    }
        
}

void MovieTree::findMovie(string title) {
    //TODO
    MovieNode* found = findNode(root, title);
    if(found != NULL) {
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << found->ranking << endl;
        cout << "Title  :" << found->title << endl;
        cout << "Year   :" << found->year << endl;
        cout << "Rating :" << found->rating << endl;
    }else{
    cout << "Movie not found." << endl;
  }
}

void MovieTree::queryMovies(float rating, int year) {
    //TODO
    if(root != nullptr){
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        query(root, rating, year);
    }else{
        cout << "Tree is Empty. Cannot query Movies." << endl;
    }
}

void MovieTree::averageRating() {
    //TODO
    if (root != NULL) {
        float average = 0.0;
        MovieNode* avg = new MovieNode;
        avg->ranking = 0;
        avg->title = "";
        avg->year = 0;
        avg->rating = 0;
        avgRate(root, avg);
        average = avg->rating / avg->year;
        cout << "Average rating:" << average << endl;
        removeTree(avg);
      }else{
        cout << "Average rating:0.0" << endl;
      }
    
}

void MovieTree::printLevelNodes(int level) {
    //TODO
    MovieNode * curr = root;
    if(root == NULL){ //if the tree is empty exit it
        return;
    }
    else if(level == 0){ //print the root's title
        cout << "Movie: " << curr->title << " (" << curr->rating << ")" << endl;
    }
    else{
        printLevelNodesHelper(curr, level);
    }
    
}




// Recursive helpers

void aOrder(MovieNode* node){

    if (node != nullptr){
        aOrder(node->left);
        cout << "Movie: " << node->title << " (" << node->rating << ")" << endl;
        aOrder(node->right);
    }
}

void addMovie(MovieNode* root, MovieNode* node){
    if (root != nullptr){
        if (node->title <= root->title){
            if (root->left != nullptr){
                addMovie(root->left, node);
            }
            else{
                root->left = node;
            }
            
        }
        else if (node->title[0] >= root->title[0])
        {
            if (root->right != nullptr){
                addMovie(root->right, node);
            }
            else{
                root->right = node;
            }
        }
    }
}

MovieNode* findNode(MovieNode* root, string title) {
  bool found = false;
  MovieNode* parent = root;
  while (!found) {
    if (title == parent->title) {
      found = true;
      return parent;
    }
    if (parent->left == NULL && parent->right == NULL) {
      found = true;
      return NULL;
    }
    if (parent->title >= title) {
      parent = parent->left;
    } else if (parent->title <= title) {
      parent = parent->right;
    }
  }
  return NULL;
}

void removeTree(MovieNode* ptr){
    if(ptr != nullptr){
        if(ptr->left != nullptr){
            removeTree(ptr->left);
        }
        if(ptr->right != nullptr){
            removeTree(ptr->right);
        }
        delete ptr;
    }
}

void query(MovieNode* root, float rating, int year) {
    if(root != nullptr){
      if (root->rating >= rating && root->year > year) {
        cout << root->title << " (" << root->year << ") " << root->rating << endl;
      }
      if (root->left != NULL) {
        query(root->left, rating, year);
      }
      if (root->right != NULL) {
        query(root->right, rating, year);
      }
    }
}

void avgRate(MovieNode* root, MovieNode* avg) {
  avg->year++;
  avg->rating += root->rating;
  if (root->left != NULL) {
    avgRate(root->left, avg);
  }
  if (root->right != NULL) {
    avgRate(root->right, avg);
  }
}

void printLevelNodesHelper(MovieNode * curr, int level) {
    if (curr != NULL) {
        printLevelNodesHelper(curr->left, level - 1); 
        if (level == 0) {
          cout << "Movie: " << curr->title << " (" << curr->rating << ")" << endl;
        } 
        printLevelNodesHelper(curr->right, level - 1);
      }
}