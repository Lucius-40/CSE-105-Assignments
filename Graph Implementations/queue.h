#pragma once
#include <string>
using namespace std;



class ArrayQueue 
{
private:
    int *data;     // Pointer to dynamically allocated array
    int capacity;  // Maximum number of elements the array can currently hold
    int front_idx; // Index of the front element
    int rear_idx;  // Index of the rear element

public:
    /**
     * Constructor

     */
    ArrayQueue(int initial_capacity = 2)
    {
        data = new int[initial_capacity];
        capacity = initial_capacity;
        front_idx = -1;
        rear_idx = -1;
    }

    /**
     * Destructor - Cleans up any dynamically allocated memory
     */
    ~ArrayQueue()
    {
        delete[] data;
    }

    // Queue interface implementation
    void enqueue(int item)
    {
        if (front_idx == -1)
        {
            front_idx++;
        }
        else if (((rear_idx + 1) % capacity) == front_idx)
            resize(2 * capacity);

        rear_idx = (rear_idx + 1) % capacity;
        data[rear_idx] = item;
    }
    int dequeue()
    {
        try
        {
            if (empty())
                throw "Cannot Remove From Empty Queue\n";
            int t = data[front_idx];
            if (front_idx == rear_idx)
            {
                clear();
                return t;
            }
            front_idx = (front_idx + 1) % capacity;
            int len = size();
            if (len < capacity / 4 and capacity != 2)
                resize(capacity / 2);
            return t;
        }
        catch (const char *s)
        {
            cout << s << endl;
            return -404;
        }
    }
    void clear()
    {
        delete[] data;
        data = new int[2];
        capacity = 2;
        front_idx = -1;
        rear_idx = -1;
    }
    int front()
    {
        try
        {
            if (empty())
                throw "Queue is Empty !\n";
            return data[front_idx];
        }
        catch (const char *s)
        {
            cout << s;
            return -404;
        }
    }
    int back()
    {
        try
        {
            if (empty())
                throw "Queue is Empty !\n";
            return data[rear_idx];
        }
        catch (const char *s)
        {
            cout << s;
            return -404;
        }
    }
    bool empty()
    {
        return front_idx == -1;
    }
    int size()
    {
        if (front_idx == -1)
            return 0;
        if (front_idx == rear_idx)
            return 1;
        if (front_idx < rear_idx)
            return (rear_idx - front_idx + 1);
        return (capacity - front_idx) + (rear_idx + 1);
    }
    string toString()
    {
        if (front_idx == -1)
        {
            return string("< |");
        }
        string que;
        que.append("< ");
        int i = front_idx;
        while (i != rear_idx)
        {
            string s;
            s = to_string(data[i]);
            s.append(" ,");
            que.append(s);
            i = (i + 1) % capacity;
        }
        string s = to_string(data[i]);
        s.append(" |");
        que.append(s);
        return que;
    }

    // Additional method to get the current capacity of the queue
    int getCapacity()
    {
        return capacity;
    }

private:
    void resize(int new_capacity)
    {
        int *temp = new int[new_capacity];

        int i = front_idx, j;
        for (j = 0; j < size(); j++)
        {
            temp[j] = data[i];
            i = (i + 1) % capacity;
        }
        front_idx = 0;
        rear_idx = j - 1;
        delete[] data;
        data = temp;
        capacity = new_capacity;
    }
};
