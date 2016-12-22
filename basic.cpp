//
// Created by Peiyi Zheng on 12/17/16.
//

#include "basic.h"

vector<int> generate_test_data(int num) {
    vector<int> temp(num);

    for (int i = 0; i < num; ++i) {
        temp[i] = rand();
    }

    return temp;
}

template <typename T>
bool check_sorted_result(vector<T> sorted) {
    bool flag = true;
    for (int i = 1; i < sorted.size(); ++i) {
        if (sorted[i - 1] > sorted[i]) {
            flag = false;
            break;
        }
    }

    return flag;
}

void test_merge_sort_1() {
    int num = rand() % 54321;
    vector<int> temp = generate_test_data(num);
    merge_sort_top_down(temp, 0, temp.size() - 1);
    if (check_sorted_result(temp) == true) {
        cout << "merge sort successes! (top-down version)" << endl;
    }
    else {
        cout << "merge sort fails! (top-down version)" << endl;
    }
}

void test_merge_sort_2() {
    int num = rand() % 54321;
    vector<int> temp = generate_test_data(num);
    merge_sort_bottom_up(temp);
    if (check_sorted_result(temp) == true) {
        cout << "merge sort successes! (bottom-up version)" << endl;
    }
    else {
        cout << "merge sort fails! (bottom-up version)" << endl;
    }
}

void test_quick_sort_1() {
    int num = rand() % 54321;
    vector<int> temp = generate_test_data(num);
    quick_sort_2_ways(temp, 0, temp.size() - 1);
    if (check_sorted_result(temp) == true) {
        cout << "quick sort successes! (2-ways version)" << endl;
    }
    else {
        cout << "quick sort fails! (2-ways version)" << endl;
    }
}

void test_quick_sort_2() {
    int num = rand() % 54321;
    vector<int> temp = generate_test_data(num);
    quick_sort_3_ways(temp, 0, temp.size() - 1);
    if (check_sorted_result(temp) == true) {
        cout << "quick sort successes! (3-ways version)" << endl;
    }
    else {
        cout << "quick sort fails! (3-ways version)" << endl;
    }
}

void test_heap_sort() {
    int num = rand() % 54321;
    vector<int> temp = generate_test_data(num);

    Heap hp(temp);
    temp = hp.heap_sort();
    if (check_sorted_result(temp) == true) {
        cout << "heap sort successes!" << endl;
    }
    else {
        cout << "heap sort fails!" << endl;
    }
}

void test_BST() {
    int num = rand() % 4321;
    vector<int> key_list = generate_test_data(num);
    vector<int> val_list = generate_test_data(num);

    BST* root = new BST(key_list[0], val_list[0]);
    for (int i = 1; i < num; ++i) {
        root->put(key_list[i], val_list[i]);
    }

    cout << "Binary Search Tree Height: " << root->getHeight() << endl;
    bool flag = true;
    for (int i = 0; i < 25; ++i) {
        int idx = rand() % num;
        int res = root->get(key_list[idx]);

        cout << "key: " << key_list[idx] << " expected value: " << val_list[idx] << " return value: " << res << endl;
        if (res != val_list[idx]) {
            cout << "BST test fails! (wrong value)" << endl;
            return;
        }
    }

    if (root->get(-1) != -1) {
        cout << "BST test fails! (wrong key)" << endl;
        return;
    }

    cout << "BST test successes!" << endl;
}