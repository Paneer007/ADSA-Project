#include <bits/stdc++.h>
using namespace std;

struct node
{
    Edge edge;
    int degree;
    node *parent;
    node *child;
    node *left;
    node *right;
    char mark;
    char c;
};

class Fibonacci_Heap
{
    node *fh;
    int total = 0;

private:
    node *insert(node *h, node *x)
    {
        x->degree = 0;
        x->parent = NULL;
        x->child = NULL;
        x->left = x;
        x->right = x;
        x->mark = 'F';
        x->c = 'N';
        if (h != NULL)
        {
            if (h->left == NULL)
            {
                x->right = NULL;
                h->left = x;
            }
            else
            {
                (h->left)->right = x;
                x->right = h;
                x->left = h->left;
                h->left = x;
            }
            if (x->edge.weight < h->edge.weight)
                h = x;
        }
        else
            h = x;
        total = total + 1;
        return h;
    }

    node *createNode(Edge Child)
    {
        node *x = new node;
        x->edge = Child;
        return x;
    }

    void link(node *h, node *y, node *z)
    {
        y->left->right = y->right;
        y->right->left = y->left;
        if (z->right == z)
            h = z;
        y->left = y;
        y->right = y;
        y->parent = z;
        if (z->child == NULL)
            z->child = y;
        y->right = z->child;
        y->left = (z->child)->left;
        ((z->child)->left)->right = y;
        (z->child)->left = y;
        if (y->edge.weight < (z->child)->edge.weight)
            z->child = y;
        z->degree++;
    }

    void consolidate(node *h)
    {
        float size = (log(total) / log(2));
        int siz = size;
        int d;
        node *arr[siz + 1];
        node *temp;
        for (int i = 0; i <= siz; i++)
            arr[i] = NULL;
        node *x = h;
        node *ptr = x;
        do
        {
            ptr = ptr->right;
            d = x->degree;
            while (arr[d] != NULL)
            {
                temp = arr[d];
                if (x->edge.weight > temp->edge.weight)
                {
                    node *t = x;
                    x = temp;
                    temp = t;
                }
                if (temp == h)
                    h = x;
                link(h, temp, x);
                if (x->right == x)
                    h = x;
                arr[d] = NULL;
                d++;
            }
            arr[d] = x;
            x = x->right;

        } while (x != h);
        h = NULL;
        for (int j = 0; j <= siz; j++)
        {
            if (arr[j] != NULL)
            {
                arr[j]->left = arr[j];
                arr[j]->right = arr[j];
                if (h != NULL)
                {
                    (h->left)->right = arr[j];
                    arr[j]->right = h;
                    arr[j]->left = h->left;
                    h->left = arr[j];
                    if (arr[j]->edge.weight < h->edge.weight)
                        h = arr[j];
                }
                else
                    h = arr[j];

                if (h == NULL)
                    h = arr[j];
                else if (arr[j]->edge.weight < h->edge.weight)
                    h = arr[j];
            }
        }
    }

public:
    Fibonacci_Heap()
    {
        fh = NULL;
    }

    int display()
    {
        node *temp = fh;
        if (temp == NULL)
        {
            throw 505;
        }
        do
        {
            cout << temp->edge.weight;
            temp = temp->right;
            if (temp != fh)
                cout << "-->";
        } while (temp != fh && temp->right != NULL);
        cout << endl;
    }

    void push(Edge val)
    {
        node *newnode = createNode(val);
        fh = insert(fh, newnode);
    }

    Edge top(){
        node *temp = fh;
        Edge tempEdge;
        tempEdge.weight=INT_MAX;
        if (temp == NULL)
        {
            throw 505;
        }
        do
        {
            if(temp->edge.weight<tempEdge.weight){
                tempEdge=temp->edge;
            }
            temp = temp->right;
        } while (temp != fh && temp->right != NULL);
        return tempEdge;
    }

    void pop()
    {
        node *temp = fh;
        node *ptr = temp;
        node *x = NULL;
        node *llptr;
        if (temp == NULL)
            return;
        if (temp->child != NULL)
        {
            x = temp->child;
            do
            {
                ptr = x->right;
                fh->left->right = x;
                x->right = fh;
                x->left = fh->left;
                fh->left = x;
                if (x->edge.weight < fh->edge.weight)
                    fh = x;
                x->parent = NULL;
                x = ptr;

            } while (ptr != temp->child);
        }
        (temp->left)->right = temp->right;
        (temp->right)->left = temp->left;
        fh = temp->right;
        if (temp == temp->right && temp->child == NULL)
            fh = NULL;
        else
        {
            fh = temp->right;
            consolidate(fh);
        }
        total--;
    }
    bool empty(){
        return fh==NULL;
    }
};
