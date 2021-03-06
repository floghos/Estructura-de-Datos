#include "MapBST.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

box * MapBST::predecesor(box *node) {
	box *result;
	string key = node->key;
	box *currentNode = node->left; //going once to the left child
	while (currentNode->right != NULL) { //then ALL the way to the right
		currentNode = currentNode->right;
	} //now currentNode will have a reference to "node"'s predecesor
	result->key = currentNode->key;
	result->val = currentNode->val;
	erase(currentNode->key, currentNode);
	return result;
}

void MapBST::erase(string key, box *&node){ // WIP
	if (node->left != NULL) {
		box *aux = predecesor(node); //get a copy of this node's predecesor
		node->key = aux->key;
		node->val = aux->val;
	} else if (node->right != NULL) {
		box *aux = node->right;
		delete node;
		node = aux;
	} else {
		box *aux = node->right;
		delete node;
		node = aux;
	}
}

int MapBST::at(string key, box *node){
    if (node == NULL) {
        // cout << "'" << key << "' doesn't exist" << '\n';
        return -1;
    } else {
        if (node->key.compare(key) == 0) { //keys are equal
            return node->val;
        } else if (node->key.compare(key) < 0) {
            return at(key, node->right);
        } else {
            return at(key, node->left);
        }
    }
}

void MapBST::insert(pair<string, int> entry, box *&node){
    if (node == NULL) {
        node = new box;
        node->key = entry.first;
        node->val = entry.second;
        _size++;
    } else {
		if (node->key.compare(entry.first) == 0) { //keys are equal
		    // cout << "'" << entry.first << "' already exists" << '\n';
		} else if (node->key.compare(entry.first) < 0) {
		    insert(entry, node->right);
		} else {
		    insert(entry, node->left);
		}

    }
}

// public methods
MapBST::MapBST() {
    root = NULL;
}

void MapBST::insert(pair<string, int> entry){
    insert(entry, root);
    // std::cout << (root == NULL) << '\n';
}

void MapBST::erase(string key){
	box *temp = root;
	while (temp->key.compare(key) != 0) { //looking for the entry to be erased
		if (temp->key.compare(key) < 0) {
            temp = temp->right;
        } else {
			temp = temp->left;
        }
	}
    erase(key, temp);
}

int MapBST::at(string key){
    return at(key, root);
}


int MapBST::size(){
    return _size;
}

bool MapBST::empty(){
    return !_size;
}
