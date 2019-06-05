#include "MapBST.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;
//private methods
void MapBST::erase(string key, box *&node){

}

int MapBST::at(string key, box *node){
    if (node == NULL) {
        cout << "'" << key << "' doesn't exist" << '\n';
        return -1;
    } else {
        if (node->key.compare(key) == 0) { //keys are equal
            return node->val;
        } else if (node->key.compare(key) < 0) {
            at(key, node->right);
        } else {
            at(key, node->left);
        }
    }
}

void MapBST::insert(pair<string, int> entry, box *&node){
    if (node == NULL) {
        // cout << "encontramos un espacio vacio!" << '\n';
        node = new box;
        node->key = entry.first;
        node->val = entry.second;
        _size++;
    } else {
        if (node->key.compare(entry.first) == 0) { //keys are equal
            cout << "'" << entry.first << "' already exists" << '\n';
        } else if (node->key.compare(entry.first) < 0) {
            // cout << "insertando a la izq" << '\n';
            insert(entry, node->right);
        } else {
            // cout << "insertando a la izq" << '\n';
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
    erase(key, root);
}

int MapBST::at(string key){
    at(key, root);
}


int MapBST::size(){
    return _size;
}

bool MapBST::empty(){
    return !_size;
}
