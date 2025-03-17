// PriorityQueue.h
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

template <typename T>
class PriorityQueue {
private:
    T data[MAX_SIZE];
    int size;

    void heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] <= data[parent]) break;
            std::swap(data[index], data[parent]);
            index = parent;
        }
    }

    void heapify_down(int index) {
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = left;
            if (right < size && data[right] > data[left]) {
                largest = right;
            }
            if (data[index] >= data[largest]) break;
            std::swap(data[index], data[largest]);
            index = largest;
        }
    }

public:
    PriorityQueue() : size(0) {}

    bool empty() const {
        return size == 0;
    }

    void insert(T value) {
        if (size >= MAX_SIZE) {
            throw std::overflow_error("PriorityQueue is full");
        }
        data[size] = value;
        heapify_up(size);
        size++;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("PriorityQueue is empty");
        }
        T maxValue = data[0];
        data[0] = data[size - 1];
        size--;
        heapify_down(0);
        return maxValue;
    }
};

#endif
