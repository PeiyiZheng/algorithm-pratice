//
// Created by Peiyi Zheng on 12/19/16.
//
#include "basic.h"

// max heap

void Heap::sink(int pos) {
    while ((pos << 1) <= this->n) {
        int next = pos << 1;
        if (next < this->n && this->data[next] < this->data[next + 1]) {
            ++next;
        }

        if (this->data[next] <= this->data[pos]) {
            break;
        }
        swap(this->data[next], this->data[pos]);
        swap(next, pos);
    }
}

void Heap::swim(int pos) {
    while (pos > 1 && (this->data[pos] > this->data[pos >> 1])) {
        swap(this->data[pos], this->data[pos >> 1]);
        pos >>= 1;
    }
}

void Heap::insert(int val) {
    if (this->data.size() - 1 == this->n) {
        this->data.push_back(val);
        ++this->n;
    }
    else {
        this->data[++this->n] = val;
    }

    this->swim(this->n);
}

int Heap::remove() {
    int res = this->data[1];
    swap(this->data[1], this->data[this->n--]);
    this->sink(1);
    return res;
}

Heap::Heap(vector<int>& vec) {
    this->data.reserve(vec.size() + 1);
    for (int i = 0; i < data.size(); ++i) {
        data[i + 1] = vec[i];
    }

    this->n = (int)vec.size();
    for (int i = this->n >> 1; i >= 1; --i) {
        this->sink(i);
    }
}

vector<int> Heap::heap_sort() {
    while (this->n > 1) {
        swap(this->data[1], this->data[this->n--]);
        this->sink(1);
    }
    return this->data;
}