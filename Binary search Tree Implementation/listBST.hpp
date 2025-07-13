#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    void clear(Node *p)
    {
        if (p->left == nullptr and p->right == nullptr)
        {
            delete p;
            return;
        }
        if (p->left)
            clear(p->left);
        if (p->right)
            clear(p->right);
        delete p;
    }
    Node *min_node(Node *head)
    {
        if (head == nullptr)
            throw std::runtime_error("Empty Tree\n");
        Node *temp = head;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    Node *remove(Node *head, Key key)
    {
        if (head->key > key)
            head->left = remove(head->left, key);
        else if (head->key < key)
            head->right = remove(head->right, key);
        else
        {
            // key found , nopw what dos
            if (head->left == nullptr and head->right == nullptr)
            {
                delete head;
                return nullptr;
            }
            else if (head->right == nullptr)
            {
                Node *temp = head;
                head = head->left;
                delete temp;
                return head;
            }
            else if (head->left == nullptr)
            {
                Node *temp = head;
                head = head->right;
                delete temp;
                return head;
            }
            else
            {
                Node *temp = min_node(head->right);
                head->key = temp->key;
                head->value = temp->value;
                head->right = remove(head->right, temp->key);
            }
        }
        return head;
    }
    void preorder_traversal(Node *head) const
    {
        if (head == nullptr)
            return;
        std ::cout << "(" << head->key << ":" << head->value << ") ";
        preorder_traversal(head->left);
        preorder_traversal(head->right);
    }
    void inorder_traversal(Node *head) const
    {
        if (head == nullptr)
            return;
        inorder_traversal(head->left);
        std ::cout << "(" << head->key << ":" << head->value << ") ";
        inorder_traversal(head->right);
    }
    void postorder_traversal(Node *head) const
    {
        if (head == nullptr)
            return;
        postorder_traversal(head->left);
        postorder_traversal(head->right);
        std ::cout << "(" << head->key << ":" << head->value << ") ";
    }
    void default_traversal(Node *head) const
    {

        if (head == nullptr)
            return;
        std ::cout << " (" << head->key << ":" << head->value ;
        // std :: cout <<"(";
        if (head->left or head->right)
        {
          
            if (head->right and !head->left)
            {
                std::cout << " ()";
                default_traversal(head->right);
            }
            else
            {
                default_traversal(head->left);
                default_traversal(head->right);
            }
        }

        std ::cout << ")";
    }

    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear();
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        if (find(key))
            return false;
        node_count++;
        Node *temp = new Node(key, value);
        // temp->value = value ;
        // temp->key = key ;
        temp->left = temp->right = nullptr;
        if (root == nullptr)
        {
            root = temp;
        }
        else
        {
            Node *t = root, *prev = nullptr;
            while (t != NULL)
            {
                prev = t;
                if (t->key > key)
                    t = t->left;
                else
                    t = t->right;
            }
            if (prev->key > key)
                prev->left = temp;
            else
                prev->right = temp;
        }
        return true;
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        if (find(key))
        {
            root = remove(root, key);
            node_count--;
            return true;
        }

        else
            return false;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic

        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->key == key)
                return true;
            if (temp->key > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic

        if (find(key) == false)
        {

            throw std::runtime_error("Key not found\n");
        }
        Node *temp = root;
        while (temp->key != key)
        {
            if (temp->key > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return temp->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        if (find(key) == false)
        {

            throw std::runtime_error("Key not found\n");
        }
        Node *temp = root;
        while (temp->key != key)
        {
            if (temp->key > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        temp->value = value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic
        if (root != nullptr)
            clear(root);
        node_count = 0;
        root = nullptr;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        return root == nullptr;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if (root == nullptr)
            throw std::runtime_error("Empty Tree\n");
        Node *temp = root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if (root == nullptr)
            throw std::runtime_error("Empty Tree\n");
        Node *temp = root;
        while (temp->right != NULL)
            temp = temp->right;
        return temp->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
        if (traversal_type == 'D' or traversal_type == 'd')
        {
            default_traversal(root);
            std ::cout << std::endl;
        }
        else if (traversal_type == 'I' or traversal_type == 'i' or traversal_type == 'n')
        {
            inorder_traversal(root);
            std ::cout << std::endl;
        }
        else if (traversal_type == 'P' or traversal_type == 'p' or traversal_type == 'r')
        {
            preorder_traversal(root);
            std ::cout << std::endl;
        }
        else if (traversal_type == 'O' or traversal_type == 'o')
        {
            postorder_traversal(root);
            std ::cout << std::endl;
        }
    }
};

#endif // LISTBST_H