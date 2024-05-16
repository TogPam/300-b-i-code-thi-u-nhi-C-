#include <bits/stdc++.h>
#include <exception>
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=i+1;j<n;j++)
#define cc cout<<
using namespace std;

struct node
{
    int data;
    node *next;
};

struct LinkedList
{
    node *head, *tail;
};

node *getNode(int x)
{
    node *p = new node;
    if(!p)
    {
        cc"Canno allocation!\n";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void initList(LinkedList &ls)
{
    ls.head = ls.tail = NULL;
}

bool isEmpty(LinkedList ls) 
{
    return ls.head == NULL ? 1 : 0;
}

void addHead(LinkedList &ls, int x)
{
    node *p = getNode(x);
    if(isEmpty(ls))
    {
        ls.head = ls.tail = p;
        return;
    }

    p->next = ls.head;
    ls.head = p;
    return;
}

void makeList1(LinkedList &ls1)
{
    addHead(ls1,2);
    addHead(ls1,34);
    addHead(ls1,5);
    addHead(ls1,6);
    addHead(ls1,4);
    addHead(ls1,22);
}

void makeList2(LinkedList &ls2)
{
    addHead(ls2,2);
    addHead(ls2,3);
    addHead(ls2,55);
    addHead(ls2,67);
    addHead(ls2,4);
    addHead(ls2,24);
}

void display(LinkedList ls)
{
    node *p = ls.head;
    while(p!=NULL)
    {
        cc p->data<<"->";
        p=p->next;
    }
    cc"NULL\n";
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b= temp;
}

void LinearSort(node *head)
{
    if(head == NULL) return;
    node *current = head;
    while(current!=NULL)
    {
        node *p = current->next;
        while(p!=NULL)
        {
            if(current->data >= p->data) swap(current->data,p->data);
            p=p->next;
        }
        current = current->next;
    }
}

node *MergeList(node *head1, node *head2)
{
    LinearSort(head1);
    LinearSort(head2);

    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    node *merge = nullptr;

    if(head1->data <= head2->data)
    {
        merge = head1;
        merge->next = MergeList(head1->next,head2);
    }
    else {
        merge = head2;
        merge->next = MergeList(head1,head2->next);
    }
    return merge;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    LinkedList ls1;
    LinkedList ls2;
    initList(ls1);
    initList(ls2);
    makeList1(ls1);
    makeList2(ls2);
    display(ls1);
    display(ls2);

    LinkedList merge;
    initList(merge);
    node *m = MergeList(ls1.head,ls2.head);
    merge.head = m;

    display(merge);

    return 0;
}
