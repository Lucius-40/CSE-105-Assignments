#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

using std::vector;

class Heap
{
    int capacity;
    int *heapArray;
    int currentSize;

public:
    Heap(int capacity = 10)
    {
        heapArray = new int[capacity];
        currentSize = 0;
    }
    Heap(vector<int> v)
    {
        int l = v.size();
        capacity = l + 5;
        heapArray = new int[capacity];
        currentSize = l;

        for (int i = 0; i < l; i++)
        {
            heapArray[i] = v[i];
        }

        for (int i = l / 2 - 1; i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

    ~Heap()
    {
        delete[] heapArray;
    }

    int size()
    {
        return currentSize;
    }

    void insert(int n)
    {
        if (currentSize >= capacity)
        {
            throw std::runtime_error("Heap is full");
            return;
        }

        heapArray[currentSize] = n;
        heapify(currentSize);
        currentSize++;
    }

    void heapify(int index)
    {
        // heapify te 1 based index use kori
        // so if our index is 4, heapify index is 5 -> p2
        // our ind = 5-> heapicy ind = 6 -> p3

        while (index > 0 && heapArray[index] > heapArray[(index - 1) / 2])
        {
            std::swap(heapArray[index], heapArray[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void deleteKey()
    {
        if (currentSize == 0)
        {
            std::cout << "Empty heap" << std::endl;
            return;
        }

        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        maxHeapify(0);
    }

    void maxHeapify(int index)
    {

        int l, r, largest;

        l = (index + 1) * 2 - 1;
        r = (index + 1) * 2;
        // 0 -> 1, 2
        // 1 -> 3, 4
        // 2 -> 5, 6

        if (l < currentSize && heapArray[l] > heapArray[index])
        {
            largest = l;
        }
        else
        {
            largest = index;
        }

        if (r < currentSize && heapArray[r] > heapArray[largest])
        {
            largest = r;
        }

        if (largest != index)
        {
            std::swap(heapArray[index], heapArray[largest]);

            maxHeapify(largest);
        }
    }

    int getMax()
    {
        if (currentSize == 0)
        {
            throw std::runtime_error("Heap is empty");
        }

        return heapArray[0];
    }
};

void heapsort(vector<int> &v)
{
    Heap heap(v);
    v.clear();
    while (heap.size() > 0)
    {
        v.push_back(heap.getMax());
        heap.deleteKey();
    }
}

#endif