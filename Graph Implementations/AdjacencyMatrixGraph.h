#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#include "GraphADT.h"
#include "linkedList.h"
#include "queue.h"

class AdjacencyMatrixGraph : public GraphADT
{
private:
    // TODO: Consider necessary private members as per your discretion
    class Matrix
    {

    public:
        int *nodes;
        int **matrix;
        int max;
        int size; // no. of nodes
        int capacity;

        Matrix()
        {
            nodes = new int[2];
            capacity = 2;
            size = 0;
            max = -2147483648;
            matrix = new int *[2];
            for (int i = 0; i < capacity; i++)
            {
                matrix[i] = new int[2];
            }
            for (int i = 0; i < capacity; i++)
            {
                for (int j = 0; j < capacity; j++)
                    matrix[i][j] = 0;
            }
        }

        void add(int x)
        {
            // resizeUp();
            nodes[size++] = x;
        }

        void remove(int x)
        {
            for (int i = 0; i < size; i++)
            {
                if (nodes[i] == x)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        nodes[j - 1] = nodes[j];
                    }
                    size--;
                    break;
                }
            }
            // resizeDown();
        }

        bool isPresent(int x) const
        {
            for (int i = 0; i < size; i++)
                if (nodes[i] == x)
                    return true;

            return false;
        }
        void addEdge(int x, int y)
        {
            if (!isPresent(x))
            {
                add(x);
            }
            if (!isPresent(y))
            {
                add(y);
            }
            int target_x, target_y;
            for (int i = 0; i < size; i++)
            {
                if (nodes[i] == x)
                    target_x = i;
                if (nodes[i] == y)
                    target_y = i;
            }
            matrix[target_x][target_y] = matrix[target_y][target_x] = 1;
        }

        void removeEdge(int x, int y)
        {
            if (!(isPresent(x) and isPresent(y)))
                return;

            int target_x, target_y;
            for (int i = 0; i < size; i++)
            {
                if (nodes[i] == x)
                    target_x = i;
                if (nodes[i] == y)
                    target_y = i;
            }
            matrix[target_x][target_y] = matrix[target_y][target_x] = 0;
        }

        void removeNode(int x)
        {
            int target = -1;
            for (int i = 0; i < size; i++)
            {
                if (nodes[i] == x)
                {
                    target = i;
                    break;
                }
            }
            if (target == -1)
                return;

            // need to remv row and col from matirx
            for (int i = target + 1; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    matrix[i - 1][j] = matrix[i][j];
                }
            }
            for (int i = target + 1; i < size; i++)
            {
                for (int j = 0; j < size ; j++)
                {
                    matrix[j][i - 1] = matrix[j][i];
                }
            }
            for (int i = target + 1; i < size; i++) {
                nodes[i - 1] = nodes[i];
            }
            size--;
        }

        void resizeUp()
        {

            int newCapacity = capacity * 2;

            int *temp = new int[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                temp[i] = nodes[i];
            }
            delete[] nodes;
            nodes = temp;

            int **tempmatrix = new int *[newCapacity];

            for (int i = 0; i < newCapacity; i++)
            {
                tempmatrix[i] = new int[newCapacity];
                for (int j = 0; j < newCapacity; j++)
                {
                    tempmatrix[i][j] = 0;
                    if (i < size && j < size)
                        tempmatrix[i][j] = matrix[i][j];
                }
            }
            for (int i = 0; i < capacity; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = tempmatrix;

            capacity = newCapacity;
        }

        void resizeDown()
        {

            int newCapacity = capacity / 2;

            int *temp = new int[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                temp[i] = nodes[i];
            }
            delete[] nodes;
            nodes = temp;

            int **tempmatrix = new int *[newCapacity];

            for (int i = 0; i < newCapacity; ++i)
            {
                tempmatrix[i] = new int[newCapacity];
                for (int j = 0; j < newCapacity; ++j)
                {
                    tempmatrix[i][j] = 0;
                    if (i < size && j < size)
                        tempmatrix[i][j] = matrix[i][j];
                }
            }
            for (int i = 0; i < capacity; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = tempmatrix;

            capacity = newCapacity;
        }

        bool check_edge(int x, int y) const
        {
            if (!(isPresent(x) and isPresent(y)))
                return false;
            int target_x, target_y;
            for (int i = 0; i < size; i++)
            {
                if (nodes[i] == x)
                    target_x = i;
                if (nodes[i] == y)
                    target_y = i;
            }
            if (matrix[target_x][target_y] == 1)
                return true;
            return false;
        }
        ~Matrix()
        {
            for (int i = 0; i < capacity; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] nodes;
        }
    };
    Matrix graph;

    void resizeMatrix()
    {
        // TODO: you need to resize your matrix when you will less data or more data
        if (graph.size == graph.capacity)
            graph.resizeUp();
        if (graph.size < graph.capacity / 4 and graph.capacity != 2)
            graph.resizeDown();
    }

public:
    void AddNode(int v) override
    {
        // TODO: Add a new node v and resize the matrix if your current matrix is almost going to be full.
        graph.add(v);
        resizeMatrix();
    }

    void AddEdge(int u, int v) override
    {
        // TODO: Add a new edge between the nodes u and v
        graph.addEdge(u, v);
        resizeMatrix();
    }

    bool CheckEdge(int u, int v) const override
    {
        // TODO: Check whether there is an edge between two nodes u and v
        return graph.check_edge(u, v);
    }

    void RemoveNode(int v) override
    {
        // TODO: Remove a node.
        graph.removeNode(v);
        resizeMatrix();
    }

    void RemoveEdge(int u, int v) override
    {
        // TODO: remove an edge
        graph.removeEdge(u, v);
    }


    bool CheckPath(int u, int v) const override
    {
        // TODO: Return true if there is a path between nodes u and v. Otherwise return false
        if (!graph.isPresent(u) or !graph.isPresent(v))
            return false;

        ArrayQueue queue;
        int max = graph.nodes[0];
        for (int i = 0; i < graph.size; i++)
        {
            if (graph.nodes[i] > max)
                max = graph.nodes[i];
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
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.nodes[i] == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.matrix[tar][i] == 1)
                {
                    if (!color[graph.nodes[i]])
                    {
                        queue.enqueue(graph.nodes[i]);
                        color[graph.nodes[i]] = true;
                    }
                }
            }
        }
        return false;
    }

    void FindShortestPath(int u, int v) const override
    {
        // TODO: Find the shortest path between the nodes u and v and print it.
        if (!CheckPath(u, v))
            return;

        ArrayQueue queue;
        int max = graph.nodes[0];
        for (int i = 0; i < graph.size; i++)
        {
            if (graph.nodes[i] > max)
                max = graph.nodes[i];
        }
        bool color[max + 1] = {false};
        int parent[max + 1];
        for (int j = 0; j < max + 1; j++)
        {
            parent[j] = -1;
        }
        queue.enqueue(u);
        color[u] = true;

        while (!queue.empty())
        {
            int popp = queue.dequeue();
            int tar = 0;
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.nodes[i] == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.matrix[tar][i] == 1)
                {
                    if (!color[graph.nodes[i]])
                    {
                        queue.enqueue(graph.nodes[i]);
                        color[graph.nodes[i]] = true;
                        parent[graph.nodes[i]] = popp;
                    }
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
        cout << "Shortest path: ";
        for (int c : path)
            std::cout << c << " ";
        cout << endl;
       
        // cout <<"Length: "<<path.size<<endl;
    }

    int FindShortestPathLength(int u, int v) const override
    {
        // TODO: Return the shortest path length between nodes u and v if any such path exists. Otherwise return -1.

        // TODO: Find the shortest path between the nodes u and v and print it.
        if (!CheckPath(u, v))
            return -404;

        ArrayQueue queue;
        int max = graph.nodes[0];
        for (int i = 0; i < graph.size; i++)
        {
            if (graph.nodes[i] > max)
                max = graph.nodes[i];
        }
        bool color[max + 1] = {false};
        int parent[max + 1];
        for (int j = 0; j < max + 1; j++)
        {
            parent[j] = -1;
        }
        queue.enqueue(u);
        color[u] = true;

        while (!queue.empty())
        {
            int popp = queue.dequeue();
            int tar = 0;
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.nodes[i] == popp)
                {
                    tar = i;
                    break;
                }
            }
            for (int i = 0; i < graph.size; i++)
            {
                if (graph.matrix[tar][i] == 1)
                {
                    if (!color[graph.nodes[i]])
                    {
                        queue.enqueue(graph.nodes[i]);
                        color[graph.nodes[i]] = true;
                        parent[graph.nodes[i]] = popp;
                    }
                }
            }
        }

        int control = v;
        int count = 0 ;
        //LinkedList path;
        //path.add(v); // adds to head
        while (control != -1)
        {
            control = parent[control];
            count ++ ;
        }
        return count - 1;
      
    }
    LinkedList GetNeighbors(int u) const override
    {
        // TODO return a list of neighbors of node u
        LinkedList neighbor ;
        int tar = -1 ;
        for ( int i = 0 ; i < graph.size ; i++){
            if( u == graph.nodes[i]) tar = i ;
        }
        if( tar == -1){
            neighbor.add(-404);
            return neighbor ;
        }
        for ( int i = 0 ; i < graph.size; i++){
            if(graph.matrix[tar][i]==1)neighbor.add(graph.nodes[i]);
        }
        return neighbor ;
    }
};

#endif // ADJACENCY_MATRIX_GRAPH_H
