#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "GraphADT.h"
#include "queue.h"

class AdjacencyListGraph : public GraphADT
{
private:
    // class handles a collection of the adjacency list of all the values
    class LinkedListCollection
    {
        int capacity;

    public:
        LinkedList *graph;
        int size;
        LinkedListCollection()
        {
            size = 0;
            graph = new LinkedList[2];
            capacity = 2;
        }
        ~LinkedListCollection()
        {
            if (graph)
            {
                delete[] graph;
                graph = nullptr;
            }
        }
        void addList(int x)
        {

            if (size == capacity)
            {
                resizeUP();
            }
            graph[size] = LinkedList(x);
            ++size;
        }
        void remove(int x)
        {
            for (int i = 0; i < size; ++i)
            {
                if (graph[i].list_head == x)
                {

                    for (int j = i; j < size - 1; ++j)
                    {
                        graph[j] = graph[j + 1];
                    }
                    --size;

                    if (size < capacity / 4)
                    {
                        resizeDown();
                    }
                    return;
                }
            }
        }
        void resizeUP()
        {
            int newCapacity = capacity * 2;
            LinkedList *newGraph = new LinkedList[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                newGraph[i] = graph[i];
            }
            delete[] graph;
            graph = newGraph;
            capacity = newCapacity;
        }
        void resizeDown()
        {
            if (capacity > 2)
            {
                int newCapacity = capacity / 2;
                LinkedList *newGraph = new LinkedList[newCapacity];
                int newSize = (size < newCapacity) ? size : newCapacity;
                for (int i = 0; i < newSize; ++i)
                {
                    newGraph[i] = graph[i];
                }
                delete[] graph;
                graph = newGraph;
                capacity = newCapacity;
                size = newSize;
            }
        }
        bool isPresent(int x) const
        {
            for (int i = 0; i < size; i++)
            {
                if (graph[i].list_head == x)
                    return true;
            }
            return false;
        }
        void add(int x, int y)
        {
            if (!isPresent(x))
                addList(x);
            if (!isPresent(y))
                addList(y);
            for (int i = 0; i < size; i++)
            {

                if (graph[i].list_head == x)
                {
                    graph[i].add(y);
                }
                if (graph[i].list_head == y)
                {
                    graph[i].add(x);
                }
            }
        }
    };

    LinkedListCollection root;

public:
    void AddNode(int v) override
    {
        // TODO: Add a new node v and resize the matrix if your current matrix is almost going to be full.

        root.addList(v);
    }

    void AddEdge(int u, int v) override
    {
        // TODO: Add a new edge between the nodes u and v
        if (!CheckEdge(u, v))
            root.add(u, v); // creates node if not present
    }

    bool CheckEdge(int u, int v) const override
    {
        // TODO: Check whether there is an edge between two nodes u and v
        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head == u)
            {
                if (root.graph[i].is_Present(v))
                    return true;
            }
        }
        return false;
    }

    void RemoveNode(int v) override
    {
        // TODO: Remove a node.
        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].is_Present(v))
            {
                root.graph[i].remove_value(v);
            }
        }
        root.remove(v);
    }

    void RemoveEdge(int u, int v) override
    {
        // TODO: remove an edge
        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head == u)
                root.graph[i].remove_value(v);
            if (root.graph[i].list_head == v)
                root.graph[i].remove_value(u);
        }
    }

    bool CheckPath(int u, int v) const override
    {
        if (!root.isPresent(u) or !root.isPresent(v))
            return false;
        ArrayQueue queue;
        int max = root.graph[0].list_head;

        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head > max)
                max = root.graph[i].list_head;
        }

        bool color[max + 1] = {false};

        queue.enqueue(u);
        color[u] = true;
        while (!queue.empty())
        {
            int popp = queue.dequeue();
            if (popp == v)
                return true; // partial BFS
            int tar = 0;
            for (int i = 0; i < root.size; i++)
            {
                if (root.graph[i].list_head == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i : root.graph[tar])
            {
                if (!color[i])
                {
                    queue.enqueue(i);
                    color[i] = true;
                }
            }
        }
        return false;
    }

    void FindShortestPath(int u, int v) const override
    {

        // TODO: Find the shortest path between the nodes u and v and print it.

        if (!CheckPath(u, v))
        {
            cout << "Cannot Reach u from v\n";
            return;
        }

        ArrayQueue queue;
        int max = root.graph[0].list_head;

        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head > max)
                max = root.graph[i].list_head;
        }
        bool color[max + 1] = {false};
        int parent[max + 1];
        for (int i = 0; i < max + 1; i++)
        {
            parent[i] = -1;
        }
        queue.enqueue(u);
        color[u] = true;

        while (!queue.empty())
        {
            int popp = queue.dequeue();

            int tar = -1;
            for (int i = 0; i < root.size; i++)
            {
                if (root.graph[i].list_head == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i : root.graph[tar])
            {
                if (!color[i])
                {
                    color[i] = true;
                    parent[i] = popp;
                    queue.enqueue(i);
                }
            }
        }
        int control = v;
        LinkedList path;
        path.add(v); // adds to head
        while (control != -1)
        {
            if (parent[control] != -1)
                path.add(parent[control]);
            control = parent[control];
        }
        // cout << "Shortest path from "<<u<<"to "<<v<<" :"<<endl ;
        cout << "Shortest path: ";
        for (int c : path)
            cout << c << " ";
        cout << endl;
        // cout <<"Length: "<<path.size<<endl;
    }

    int FindShortestPathLength(int u, int v) const override
    {
        // TODO: Return the shortest path length between nodes u and v if any such path exists. Otherwise return -1.
        if (!CheckPath(u, v))
        {
            cout << "Cannot Reach u from v\n";
            return -404;
        }

        ArrayQueue queue;
        int max = root.graph[0].list_head;

        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head > max)
                max = root.graph[i].list_head;
        }
        bool color[max + 1] = {false};
        int parent[max + 1];
        for (int i = 0; i < max + 1; i++)
        {
            parent[i] = -1;
        }
        queue.enqueue(u);
        color[u] = true;

        while (!queue.empty())
        {
            int popp = queue.dequeue();

            int tar = -1;
            for (int i = 0; i < root.size; i++)
            {
                if (root.graph[i].list_head == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i : root.graph[tar])
            {
                if (!color[i])
                {
                    color[i] = true;
                    parent[i] = popp;
                    queue.enqueue(i);
                }
            }
        }
        int control = v;
        int count = 0;
        while (control != -1)
        {

            control = parent[control];
            count++;
        }
        return count - 1;
    }

    LinkedList GetNeighbors(int u) const override
    {
        // TODO: Return the list of neighbors.
        LinkedList neighbours;
        int tar = -1;
        for (int i = 0; i < root.size; i++)
        {
            if (root.graph[i].list_head == u)
            {
                tar = i;
                break;
            }
        }
        if(tar == -1){
            neighbours.add(-404);
            return neighbours ;
        }
        for (int i : root.graph[tar])
        {
            neighbours.add(i);
        }
        return neighbours;
    }
};

#endif // ADJACENCY_LIST_GRAPH_H
