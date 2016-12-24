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
    int temp = 0;
    if (left != NULL) {
        temp = max(temp, left->getHeight());
    }

    if (right != NULL) {
        temp = max(temp, right->getHeight());
    }
    return height = 1 + temp;
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

int AVL_Tree::getHeight() {
    return this->height;
}

AVL_Tree::AVL_Tree(int _key, int _val) {
    lchild = rchild = NULL;
    key = _key;
    val = _val;
    height = 1;
}

int avl_getHeight(AVL_Tree* node) {
    if (node == NULL) {
        return 0;
    }

    return node->getHeight();
}

void rightRotate(AVL_Tree*& node) {
    AVL_Tree* temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = 1 + max(avl_getHeight(node->lchild), avl_getHeight(node->rchild));
    temp->height = 1 + max(avl_getHeight(temp->lchild), avl_getHeight(temp->rchild));

    node = temp;
}

void leftRotate(AVL_Tree*& node) {
    AVL_Tree* temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node->height = 1 + max(avl_getHeight(node->lchild), avl_getHeight(node->rchild));
    temp->height = 1 + max(avl_getHeight(temp->lchild), avl_getHeight(temp->rchild));
    node = temp;
}

void leftRightRotate(AVL_Tree*& node) {
    leftRotate(node->lchild);
    rightRotate(node);
}

void rightLeftRotate(AVL_Tree*& node) {
    rightRotate(node->rchild);
    leftRotate(node);
}


void avlInsert(int _key, int _val, AVL_Tree*& node) {
    if (node == NULL)  {
        node = new AVL_Tree(_key, _val);
    }
    else if (_key < node->key) {
        avlInsert(_key, _val, node->lchild);
        if (avl_getHeight(node->lchild) - avl_getHeight(node->rchild) >= 2) {
            if (_key < node->lchild->key) {
                rightRotate(node);
            }
            else {
                leftRightRotate(node);
            }
        }
    }
    else if (_key > node->key) {
        avlInsert(_key, _val, node->rchild);
        if (avl_getHeight(node->rchild) - avl_getHeight(node->lchild) >= 2) {
            if (_key > node->rchild->key) {
                leftRotate(node);
            }
            else {
                rightLeftRotate(node);
            }
        }
    }
    else {
        node->val = _val;
    }

    node->height = 1 + max(avl_getHeight(node->lchild), avl_getHeight(node->rchild));
}

int avlQuery(int _key, AVL_Tree* node) {
    if (_key == node->key) {
        return node->val;
    }
    else if (_key < node->key) {
        if (node->lchild == NULL) {
            return -1;
        }
        return avlQuery(_key, node->lchild);
    }
    else {
        if (node->rchild == NULL) {
            return -1;
        }
        return avlQuery(_key, node->rchild);
    }
}