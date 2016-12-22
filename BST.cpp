//
// Created by Peiyi Zheng on 12/22/16.
//
#include "basic.h"

BST::BST() {
    left = right = NULL;
    height = 1;
}

BST::BST(int _key, int _val) {
    key = _key;
    val = _val;
    height = 1;
    left = right = NULL;
}

int BST::getHeight() {
    height = 1;

    if (left != NULL) {
        height += left->getHeight();
    }

    if (right != NULL) {
        height += right->getHeight();
    }
    return height;
}

void BST::put(int _key, int _val) {
    if (_key < key) {
        if (left == NULL) {
            left = new BST(_key, _val);
        }
        else {
            left->put(_key, _val);
        }
    }
    else if(_key > key) {
        if (right == NULL) {
            right = new BST(_key, _val);
        }
        else {
            right->put(_key, _val);
        }
    }
    else {
        val = _val;
    }
}

int BST::get(int _key) {
    if (_key == key) {
        return val;
    }
    else if (_key < key) {
        if (left == NULL) {
            return -1;
        }
        return left->get(_key);
    }
    else {
        if (right == NULL) {
            return -1;
        }
        return right->get(_key);
    }
}



