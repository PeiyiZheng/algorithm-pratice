//
// Created by Peiyi Zheng on 12/17/16.
//
#include "basic.h"

void merge_top_down(vector<int>& input, int left, int mid, int right) {
    vector<int> temp(right - left + 1);

    for (int i = left, j = 0; i <= right; ++i, ++j) {
        temp[j] = input[i];
    }

    int _mid = mid - left, _right = right - left;
    for (int i = 0, j = _mid + 1, k = left; k <= right; ++k) {
        if (i > _mid) {
            input[k] = temp[j++];
        }
        else if (j > _right) {
            input[k] = temp[i++];
        }
        else if (temp[i] < temp[j]) {
            input[k] = temp[i++];
        }
        else {
            input[k] = temp[j++];
        }
    }
}
void merge_sort_top_down(vector<int>& input, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + ((right - left) >> 1);
    merge_sort_top_down(input, left, mid);
    merge_sort_top_down(input, mid + 1, right);
    merge_top_down(input, left, mid, right);
}
