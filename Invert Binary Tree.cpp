#include <iostream>
#include <vector>
#define COUNT 10
struct Node
{
    int data;
    Node *right, *left;
};

Node *getNode(int x)
{
    Node *p = new Node;
    if (p)
    {
        p->data = x;
        p->left = p->right = NULL;
        return p;
    }
    return nullptr;
}

struct Tree
{
    Node *root;
};

void initTree(Tree &T)
{
    T.root = NULL;
}

int isEmpty(Node *root)
{
    return root == NULL ? 1 : 0;
}

void insertNode(Node *&root, int x)
{
    if (root == NULL)
    {
		root = getNode(x);
        return;
    }
    if (root->data == x)
		return;
    else if (x < root->data)
        insertNode(root->left, x);
    else
        insertNode(root->right, x);
}

Node *makeTreeByVector(Node *&root, std::vector<int> numbers)
{
    if (root!=NULL)
        return nullptr;
    for (int num : numbers)
        insertNode(root, num);
    return root;
}

void print2DTree(Node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;

    print2DTree(root->right, space);

    for (int i = COUNT; i <= space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";

    print2DTree(root->left, space);
}

void swapNode(Node *&root)
{
	Node *temp = root->right;
	root->right = root->left;
	root->left = temp;
}

Node *invertTree(Node *&root)
{
	if(root){	
		swapNode(root);
		invertTree(root->right);
		invertTree(root->left);
	}
	return root;
}

int main()
{
    Tree T;
    initTree(T);
    std::vector<int> numbers = {2, 1, 23, 4, 1, 44, 69};

    T.root = makeTreeByVector(T.root, numbers);

    print2DTree(T.root, 0);

	std::cout<<"After invert Tree\n";
	T.root = invertTree(T.root);
	
    print2DTree(T.root, 0);

    return 0;
}