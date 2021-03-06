//
// Created by Peiyi Zheng on 12/17/16.
//

#ifndef ALGORITHM_BASIC_H
#define ALGORITHM_BASIC_H

#endif //ALGORITHM_BASIC_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> generate_test_data(int);

template <typename T>
bool check_sorted_result(vector<T>);

void merge_sort_top_down(vector<int>&, int, int);
void merge_sort_bottom_up(vector<int>&);

void quick_sort_2_ways(vector<int>&, int, int);
void quick_sort_3_ways(vector<int>&, int, int);

class Heap {
public:
    Heap() {}
    Heap(vector<int>&);
    void sink(int);
    void swim(int);
    void insert(int);
    int remove();
    vector<int> heap_sort();
private:
    int n;
    vector<int> data;
};

class BST {
public:
    BST();
    BST(int, int);
    void put(int, int);
    int get(int);
    int getHeight();
private:
    int key, val;
    int height;
    BST *left, *right;
};

class AVL_Tree {
public:
    AVL_Tree() {};
    AVL_Tree(int, int);
    int getHeight();
    int key, val, height;
    AVL_Tree *lchild, *rchild;
};

void rightRotate(AVL_Tree*& node);
void leftRotate(AVL_Tree*& node);
void leftRightRotate(AVL_Tree*& node);
void rightLeftRotate(AVL_Tree*& node);
void avlInsert(int _key, int _val, AVL_Tree*& node);
int avlQuery(int _key, AVL_Tree* node);
void test_AVL();


// test cases
void test_merge_sort_1();
void test_merge_sort_2();
void test_quick_sort_1();
void test_quick_sort_2();
void test_heap_sort();
void test_BST();