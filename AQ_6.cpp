#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool checkDuplicates(Node *root, unordered_set<int> &seen)
{
    if (root == nullptr)
        return false;

    // If value already exists ⇒ duplicate found
    if (seen.find(root->data) != seen.end())
    {
        return true;
    }

    // Insert current node value
    seen.insert(root->data);

    // Recursively check left and right subtrees
    return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

int main()
{
    /* Example Tree:
            5
           / \
          3   8
         / \
        2   3  <-- duplicate
    */

    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(3); // duplicate value

    unordered_set<int> seen;

    if (checkDuplicates(root, seen))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
