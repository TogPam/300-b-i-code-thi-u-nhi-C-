// Given a binary tree, determine if it is height-balanced
#include <iostream>
using namespace std;
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

    space += 10;

    print2Dimensions(root->right, space);
    std::cout << "\n";

    for (int i = 10; i < space; i++)
        std::cout << " ";
    std::cout << root->val << "\n";

    print2Dimensions(root->left, space);
}

int maxDepth(node *root)
{
    if (root == nullptr)
        return 0;
    int maxL = maxDepth(root->left);
    int maxR = maxDepth(root->right);

    return (maxL > maxR ? maxL : maxR) + 1;
}

bool isBalanced(node *root)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;

    int maxL = maxDepth(root->left);
    int maxR = maxDepth(root->right);

    if (abs(maxL - maxR) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
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
    if (isBalanced(T.root))
        cout << "\nBalanced!\n";
    else
        cout << "\nNot Balanced\n";
    return 0;
}