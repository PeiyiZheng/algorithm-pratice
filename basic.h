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

// test cases
void test_merge_sort_1();
void test_merge_sort_2();
void test_quick_sort_1();
void test_quick_sort_2();