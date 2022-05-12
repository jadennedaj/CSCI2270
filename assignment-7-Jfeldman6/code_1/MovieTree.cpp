#include "MovieTree.hpp"
#include <iostream>
#include <fstream>


using namespace std;
/* ------------------------Starter Code function---------- */
LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

void preorderTraversalHelper(TreeNode * root) {
	if (root == NULL) 
    {
		return;
	}
    cout << root->titleChar << " ";
    preorderTraversalHelper(root->leftChild);
    preorderTraversalHelper(root->rightChild);
}

void MovieTree::preorderTraversal() {
	preorderTraversalHelper(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* --------------------------Constructor---------------------------- */
MovieTree::MovieTree()
{
    root = NULL;
}

/* --------------------------Destructor---------------------------- */
void helpDelete(LLMovieNode *Node){
    LLMovieNode *temp;
    while(Node != NULL){
        temp = Node->next;
        delete Node;
        Node = temp;
    }
}

void MovieTree::rdelete(TreeNode *node)
{
	//TODO
    
    if(node != NULL){
        if(node->leftChild != NULL){
            rdelete(node->leftChild);
        }
        if(node->rightChild != NULL){
            rdelete(node->rightChild);
        }
        LLMovieNode *temp = node->head;

        while(temp != nullptr){
            LLMovieNode *curr = temp;
            temp = temp->next;
            delete curr;
        }
        delete node;
        //node = nullptr;
    }else{
        return;
    }
}




MovieTree::~MovieTree()
{
	//TODO
    if(root != NULL){
    rdelete(root);
    //delete root;
    }
    
}

/* -------------------------showMovieCollection----------------------------- */
void MovieTree::printMovieInventoryHelper(TreeNode* parent)
{
	//TODO
    if(parent != NULL){
        if (parent->leftChild != NULL) {
            printMovieInventoryHelper(parent->leftChild);
        }

        LLMovieNode* temp = parent->head;
        if(parent->head != NULL){
            cout << "Movies starting with letter: " << parent->titleChar << endl;
            while(temp != NULL) {
            cout << " >> " << temp->title << " " << temp->rating << endl;
            temp = temp->next;
          }
        }
        if (parent->rightChild != NULL) {
            printMovieInventoryHelper(parent->rightChild);
        }
    }
}


void MovieTree::showMovieCollection()
{
	//TODO
    printMovieInventoryHelper(root);
}

/* --------------------------insertMovie---------------------------- */


TreeNode* MovieTree::addHelper(TreeNode *root, TreeNode* parent, int _ranking, string _title, int _year, float _rating)
{
	//TODO
    if(root == NULL){
        TreeNode *tree = new TreeNode();
        LLMovieNode *temp = getLLMovieNode(_ranking, _title, _year, _rating);
        tree->parent = parent;
        tree->head = temp;
        tree->rightChild = NULL;
        tree->leftChild = NULL;
        tree->titleChar = _title[0];
        return tree;
    }else if(_title[0] < root->titleChar){
        root->leftChild = addHelper(root->leftChild, root, _ranking, _title, _year, _rating);
    }else if(_title[0] > root->titleChar){
        root->rightChild = addHelper(root->rightChild, root, _ranking, _title, _year, _rating);
    }else{
        
        LLMovieNode *add = getLLMovieNode(_ranking, _title, _year, _rating);
        
        if(root->head == NULL){
            root->head = add;
        }else if(root->head->title > _title){
            add->next = root->head;
            root->head = add;
        }else{
            LLMovieNode *curr = root->head;
            while(curr->next != NULL && curr->next->title < _title){
                curr = curr->next;
            }
            add->next = curr->next;
            curr->next = add;
        }
    }
    return root;
}
        
                
                
                
      /*  if(_title != ""){
            char letter = _title[0];
            TreeNode * searched = searchCharNode(letter);
            
            if(searched != NULL){
                LLMovieNode *temp = searched->head;
                LLMovieNode *temp2 = NULL;
                LLMovieNode *add = getLLMovieNode(_ranking, _title, _year, _rating);

                if(temp == NULL){
                    temp = add;
                    add->next = NULL;
                    return root;
                }else{
                    while(temp != NULL && add->title > temp->title){
                        temp2 = temp;
                        temp = temp->next;
                    }

                    temp2->next = add;
                    add->next = temp;
                }
            }
        }
    }
    return root;
        
} */


void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	//TODO
    if(ranking <= 0 || title == "" || year <= 0 || rating <= 0)return;
    root = addHelper(root, nullptr, ranking, title, year, rating);
    
    /*if(title != ""){
        char letter = title[0];
        TreeNode * searched = searchCharNode(letter);
    
    
    if(searched != NULL){
        LLMovieNode *temp = searched->head;
        LLMovieNode *temp2 = NULL;
        LLMovieNode *add = getLLMovieNode(ranking, title, year, rating);
        
        if(temp == NULL){
            temp = add;
            add->next = NULL;
            return;
        }else{
            while(temp != NULL && add->title > temp->title){
                temp2 = temp;
                temp = temp->next;
            }
            
            temp2->next = add;
            add->next = temp;
        }
    }else{
        root = addHelper(root, NULL, ranking, title, year, rating);
    }
    }*/
    
}



/* ------------------------removeMovieRecord------------------------------ */
void MovieTree::removeMovieRecord(std::string title)
{
    //TODO
    if(title == "") return;
    TreeNode *search = root;
    search = searchCharHelper(search, title[0]);
    
    if(search == NULL){
        cout << "Movie not found." << endl;
    }else{
        LLMovieNode *curr = search->head;
        LLMovieNode *prev = NULL;
        while(curr != NULL && curr->title != title){
            prev = curr;
            curr = curr->next;
        }
        if(curr){
            if(curr == search->head){
                search->head = curr->next;
                delete curr;
            }else{
                prev->next = curr->next;
                delete curr;
            }
        }else cout << "Movie not found." << endl;
    }
        
        
        
    /*    if(temp->title == title){
            curr = search->head;
            temp = curr->next;
            search->head = temp;
            delete curr;
        }else{
            curr = search->head;
            while(curr != nullptr){
                if(curr->title == title){
                    prev->next = curr->next;
                    delete curr;
                    //search = NULL;
                    return;
                }else{
                    prev = curr;
                    curr = curr->next;
                }
            }
            cout << "Movie not found." << endl;
        }
        
    } */
        
}

/* ------------------------removeBSTNode------------------------------ */
void MovieTree::removeLLnodes(TreeNode* node){
    //TODO
    /*if(node != NULL){
        LLMovieNode *prev = node->head;
        LLMovieNode *curr = node->head->next;
        LLMovieNode *temp = node->head->next;
        while(temp != NULL){
            if(temp->next != NULL){
                curr = temp->next;
                prev->next = curr;
                delete temp;
                temp = curr;
            }else{
                //temp = temp->next;
                prev->next = NULL;
                curr = temp;
                delete curr;
                temp = node->head;
                delete temp;
            }
        }
    }*/
    if(node){
        LLMovieNode *temp = node->head;
        while(temp != NULL){
            delete temp;
            temp = temp->next;
        }
        node->head = NULL;
    }else return;
    
    
    /*if(node){
        LLMovieNode *temp = node->head;
        LLMovieNode *curr = node->head;
        LLMovieNode *prev = node->head;

        while(temp != nullptr){
            if(temp->next->next == nullptr){
                node->head = nullptr;
                delete curr;
                break;
            }
            prev = curr;
            temp = curr->next;
            prev->next = temp->next;
            //node->head = curr;
            delete temp;
        }
        node->head = nullptr;
    }*/
}

TreeNode* MovieTree::getSuccessor(TreeNode* node){
    //TODO
    if(!node->leftChild){
        return node;
    }else{
        return getSuccessor(node->leftChild);
    }
}

TreeNode* MovieTree::removeBSTNodeHelper(TreeNode* node, TreeNode* parentpointer, char titleFirstLetter){
    //TODO
    if(node == NULL) return node;
    
    if(titleFirstLetter < node->titleChar){
        node->leftChild = removeBSTNodeHelper(node->leftChild, node->parent, titleFirstLetter);
    }else if(titleFirstLetter > node->titleChar){
        node->rightChild = removeBSTNodeHelper(node->rightChild, node->parent, titleFirstLetter);
    }else{
        if(node->leftChild == NULL && node->rightChild == NULL){
            return NULL;
        }else if(node->leftChild == NULL){
            TreeNode *Right = node->rightChild;
            removeLLnodes(node);
            delete node;
            return Right;
        }else if(node->rightChild == NULL){
            TreeNode *Left = node->leftChild;
            removeLLnodes(node);
            delete node;
            return Left;
        }
        
        TreeNode *Successor = getSuccessor(node);
        node->titleChar = Successor->titleChar;
        removeLLnodes(node);
        node->rightChild = removeBSTNodeHelper(node->rightChild, node->parent, Successor->titleChar);
    }
    return node;
}

void MovieTree::removeBSTNode(char titleFirstLetter){
    //TODO
    root = removeBSTNodeHelper(root, root->parent, titleFirstLetter);
    /*
    TreeNode * curr = root;
    TreeNode * search = searchCharHelper(curr, titleFirstLetter);
    //removeLLnodes(search);
    TreeNode * next = getSuccessor(search);
    //removeLLnodes(next);
    //rdelete(search);
    
    if(search == nullptr) return;
    if (curr->leftChild == nullptr && curr->rightChild == nullptr)
    {
        // if the node to be deleted is not a root node, then set its
        // parent left/right child to null
        if (curr != root)
        {
            if (search->parent->leftChild == curr) {
                removeLLnodes(search->parent->leftChild);
                search->parent->leftChild = nullptr;
            }
            else {
                removeLLnodes(search->parent->rightChild);
                search->parent->rightChild = nullptr;
            }
        }
        // if the tree has only a root node, set it to null
        else {
            removeLLnodes(curr);
            curr = nullptr;
        }
 
        // deallocate the memory
        delete curr;        
    }
 
    // Case 2: node to be deleted has two children
    else if (curr->leftChild && curr->rightChild)
    {
        // find its inorder successor node
        TreeNode* successor = getSuccessor(curr->rightChild);
 
        // store successor value
        char key = successor->titleChar;
 
        // recursively delete the successor. Note that the successor
        // will have at most one child (right child)
        removeBSTNode(key);
 
        // copy value of the successor to the current node
        curr->titleChar = successor->titleChar;
        
    }
 
    // Case 3: node to be deleted has only one child
    else {
        // choose a child node
        TreeNode* child = (curr->leftChild)? curr->leftChild: curr->rightChild;
 
        // if the node to be deleted is not a root node, set its parent
        // to its child
        if (curr != root)
        {
            if (curr == search->parent->leftChild) {
                removeLLnodes(search->parent->leftChild);
                search->parent->leftChild = child;
                delete child;
            }
            else {
                removeLLnodes(search->parent->rightChild);
                search->parent->rightChild = child;
                delete child;
            }
        }
 
        // if the node to be deleted is a root node, then set the root to the child
        else {
            root = child;
        }
 
        // deallocate the memory
        delete curr;
    }
    */
}



/* --------------------------rightRotation---------------------------- */
void MovieTree::rightRotation(TreeNode* curr)
{
	//TODO
        if(curr == NULL) return;
        TreeNode *PP = curr->parent;
        TreeNode *L = curr->leftChild;
        curr->leftChild = L->rightChild;
    
        if(L->rightChild != NULL){
            L->rightChild->parent = curr;
        }

        L->rightChild = curr;
        curr->parent = L;
        L->parent = PP;

        if(PP != NULL){
            if(PP->leftChild == curr){
               PP->leftChild = L;
            }else{
                PP->rightChild = L;
            }
        }else{
            root = L;
        }
    
}
