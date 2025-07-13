#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst)
    {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c)
    {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        // get, update, min max thrwos error
        if (c == 'F')
        {
            in_file >> val;
            bool t = bst->find(val);
            if (t)
                std ::cout << "Key " << val << " found in BST.\n";
            else
                std ::cout << "Key " << val << " not found in BST.\n";
        }
        else if (c == 'E')
        {
            if (bst->empty())
                std ::cout << "Empty\n";
            else
                std ::cout << "Not Empty \n";
        }
        else if (c == 'I')
        {
            in_file >> val;
            if (bst->insert(val, val))
                std ::cout << "Key " << val << " inserted into BST, BST (Default): ";
            else
                std ::cout << "Insertion failed! Key " << val << " already exists in BST, BST (Default):";

            bst->print('D');
        }
        else if (c == 'M')
        {
            in_file >> str;
            try
            {
                if (str[1] == 'a')
                {
                    std ::cout << "Maximum value: " << bst->find_max() << endl;
                }
                else
                {
                    std ::cout << "Minimum value: " << bst->find_min() << endl;
                }
            }
            catch (runtime_error r)
            {
                std ::cout << r.what();
            }
        }
        else if (c == 'D')
        {
            in_file >> val;
            if (bst->remove(val))
                std ::cout << "Key " << val << " removed from BST, BST (Default): ";
            else
                std ::cout << "Removal failed! Key " << val << " not found in BST, BST (Default):";
            bst->print('D');
        }
        else if (c == 'T')
        {
            in_file >> str;
            if (str[1] == 'r')
                std ::cout << "BST (Pre-order): ";
            if (str[1] == 'n')
                std ::cout << "BST (In-order): ";
            if (str[1] == 'o')
                std ::cout << "BST (Post-order): ";
            bst->print(str[1]);
        }
        else if (c == 'S')
        {
            std ::cout << "Size : " << bst->size() << endl;
        }

        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}
