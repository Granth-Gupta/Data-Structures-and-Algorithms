#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heapArray;

    // Helper functions for heap operations
    void heapifyUp(int index) {
        while (index > 0 && heapArray[index] < heapArray[parent(index)]) {
            std::swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heapArray.size() && heapArray[leftChild] < heapArray[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heapArray.size() && heapArray[rightChild] < heapArray[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor
    Heap() {}

    // Heap operations
    void insert(int value) {
        heapArray.push_back(value);
        heapifyUp(heapArray.size() - 1);
    }

    int extractMin() {
        if (heapArray.empty()) {
            std::cout << "Heap is empty!" << std::endl;
            return -1;
        }

        int min = heapArray[0];
        heapArray[0] = heapArray.back();
        heapArray.pop_back();
        heapifyDown(0);

        return min;
    }

    // Utility functions for index calculations
    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }
};

int main() {
    Heap heap;

    heap.insert(4);
    heap.insert(2);
    heap.insert(6);
    heap.insert(1);
    heap.insert(8);

    std::cout << "Extracted Min: " << heap.extractMin() << std::endl;
    std::cout << "Extracted Min: " << heap.extractMin() << std::endl;

    return 0;
}
