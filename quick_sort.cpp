//
// Created by Peiyi Zheng on 12/18/16.
//
#include "basic.h"

void quick_sort_2_ways(vector<int>& input, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = input[left];
    int i = left + 1, j = right;

    while (true) {
        while (i < right && input[i] < mid) ++i;
        while (j > left && input[j] > mid) --j;

        if (i >= j) {
            break;
        }

        swap(input[i], input[j]);
    }

    swap(input[left], input[j]);
    quick_sort_2_ways(input, left, j - 1);
    quick_sort_2_ways(input, j + 1, right);
}

void quick_sort_3_ways(vector<int>& input, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = input[left];
    int i = left + 1, lt = left, gt = right;

    while (i <= gt) {
        if (input[i] < mid) {
            swap(input[i++], input[lt++]);
        }
        else if (input[i] > mid) {
            swap(input[i], input[gt--]);
        }
        else {
            ++i;
        }
    }
    quick_sort_3_ways(input, left, lt - 1);
    quick_sort_3_ways(input, gt + 1, right);
}