#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

bool hasCycle(Node *head)
{
    unordered_set<Node *> visited;

    Node *current = head;
    while (current != nullptr)
    {
        if (visited.find(current) != visited.end())
        {
            return true; // Cycle found
        }
        visited.insert(current);
        current = current->next;
    }
    return false; // No cycle
}

int main()
{
    // Creating linked list: 1 → 2 → 3 → 4 → (back to 2)
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Creating a cycle
    head->next->next->next->next = head->next; // 4 points back to 2

    if (hasCycle(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
