// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
// the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
#include <iostream>
#define COUNT 10
const long long ZERO = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

typedef struct TreeNode
{
    int val;
    TreeNode *left, *right;
} node;

TreeNode *getNode(int x)
{
    TreeNode *p = new TreeNode;
    if (p)
    {
        p->val = x;
        p->left = p->right = nullptr;
        return p;
    }
    return nullptr;
}

struct BTree
{
    TreeNode *root;
};

void initTree(BTree &T) { T.root = nullptr; }

void addNode(TreeNode *&root, TreeNode *p)
{
    if (p != nullptr)
    {
        if (root == nullptr)
        {
            root = p;
            return;
        }
        if (p->val < root->val)
            addNode(root->left, p);
        else
            addNode(root->right, p);
    }
}

void print2Dimensions(node *root, int space)
{
    if (root == nullptr)
        return;

    space += COUNT;

    print2Dimensions(root->right, space);
    std::cout << "\n";

    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->val << "\n";

    print2Dimensions(root->left, space);
}

TreeNode *Lowest_common_ancestor(node *root, node *p, node *q)
{
    if (p == q)
        return q;
    TreeNode *temp = root;
    while (temp)
    {
        if (temp == p || temp == q)
            return q;
        if (p->val < temp->val && q->val < temp->val)
            temp = temp->left;
        else if (p->val < temp->val && q->val > temp->val)
            return temp;
        else if (p->val > temp->val && q->val < temp->val)
            return temp;
        else
            temp = temp->right;
    }
    return nullptr;
}

int main()
{
    BTree T;
    initTree(T);
    TreeNode *a = getNode(11);
    TreeNode *b = getNode(15);
    TreeNode *c = getNode(2);
    TreeNode *d = getNode(1);
    TreeNode *e = getNode(21);
    addNode(T.root, b);
    addNode(T.root, c);
    addNode(T.root, a);
    addNode(T.root, d);
    addNode(T.root, e);
    print2Dimensions(T.root, 0);

    TreeNode *ans = Lowest_common_ancestor(T.root, a, e);
    std::cout << "\n";
    if (ans->val)
        std::cout << ans->val;
    else
        std::cout << "ERROR!";
    return 0;
}