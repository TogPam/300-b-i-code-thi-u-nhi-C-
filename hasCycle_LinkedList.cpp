// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached
// again by continuously following the next pointer. Internally, pos is used to denote
// the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.
#include <iostream>
#include <vector>
using namespace std;
const long long ZERO = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

typedef struct node
{
    int val;
    node *next;
};

node *getNode(int x)
{
    node *p = new node;
    if (p)
    {
        p->val = x;
        p->next = nullptr;
        return p;
    }
    return nullptr;
}
const int MAX_STEP = 2;
bool hasCycle(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    node *slow = head;
    node *fast = head->next;

    while (slow != nullptr)
    {
        int step = 0;
        while (fast != nullptr)
        {
            if (slow == fast)
                return true;
            fast = fast->next;
            step++;
            if (step == MAX_STEP)
                break;
        }
        slow = slow->next;
    }
    return false;
}

int main()
{
    // test in website: https://leetcode.com/problems/linked-list-cycle/description/
    return 0;
}