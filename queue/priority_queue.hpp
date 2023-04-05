#include<bits/stdc++.h>
using namespace std;

int total=0;
struct node
{
    int n;
    int degree;
    node* parent;
    node *child;
    node *left;
    node *right;
    char mark;
    char c;
};
node* initialiseHeap()
{
    node *fh=NULL;
    return fh;
}
node * createNode(int val)
{
    node *x=new node;
    x->n=val;
    return x;
}

void display(node *h)
{
    node *temp=h;
    if (temp==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
    do
    {
        cout<<temp->n;
        temp=temp->right;
        if (temp!=h) cout<<"-->";
    } while (temp!=h && temp->right!=NULL);
    
}
node* insert(node *h,node *x)
{
    x->degree=0;
    x->parent=NULL;
    x->child=NULL;
    x->left=x;
    x->right=x;
    x->mark='F';
    x->c='N';
    if (h!=NULL)
    {
        if (h->left==NULL)
        {
            x->right=NULL;
            h->left=x;
        }
        else
        {
        (h->left)->right=x;
        x->right=h;
        x->left=h->left;
        h->left=x;
        }
        if (x->n<h->n) h=x;
    }
    else h=x;
    total=total+1;
    return h;
}

void link(node *h,node *y,node *z)
{
    y->left->right=y->right;
    y->right->left=y->left;
    if (z->right==z) h=z;
    y->left=y;
    y->right=y;
    y->parent=z;
    if (z->child==NULL) z->child=y;
    y->right=z->child;
    y->left=(z->child)->left;
    ((z->child)->left)->right=y;
    (z->child)->left=y;
    if (y->n<(z->child)->n)
    z->child=y;
    z->degree++;
}

void consolidate(node *h)
{
    float size=(log(total)/log(2));
    int siz=size;
    int d;
    node *arr[siz+1];
    node *temp;
    for (int i=0;i<=siz;i++)
        arr[i]=NULL;
    node *x=h;
    node *ptr=x;
    do
    {
        ptr=ptr->right;
        d=x->degree;
        while (arr[d]!=NULL)
        {
            temp=arr[d];
            if (x->n>temp->n)
            {
                node *t=x;
                x=temp;
                temp=t;
            }
            if (temp==h) h=x;
            link(h,temp,x);
            if (x->right==x) h=x;
            arr[d]=NULL;
            d++;
        }
        arr[d]=x;
        x=x->right;

    } while (x!=h);
    h=NULL;
    for (int j=0;j<=siz;j++)
    {
        if (arr[j]!=NULL)
        {
            arr[j]->left=arr[j];
            arr[j]->right=arr[j];
            if (h!=NULL)
            {
                (h->left)->right=arr[j];
                arr[j]->right=h;
                arr[j]->left=h->left;
                h->left=arr[j];
                if (arr[j]->n<h->n) h=arr[j];
            }
            else h=arr[j];
        
        if (h==NULL) h=arr[j];
        else if (arr[j]->n<h->n) h=arr[j];
        }
    }
    
}

node* extractMin(node*h)
{
    node *temp=h;
    node *ptr=temp;
    node *x=NULL;
    node *llptr;
    if (temp==NULL) return temp;
    if (temp->child!=NULL) {
        x=temp->child;
        do
        {
            ptr=x->right;
            h->left->right=x;
            x->right=h;
            x->left=h->left;
            h->left=x;
            if (x->n<h->n) h=x;
            x->parent=NULL;
            x=ptr;

        } while (ptr!=temp->child);
        
    }
    (temp->left)->right=temp->right;
    (temp->right)->left=temp->left;
    h=temp->right;
    if (temp==temp->right && temp->child==NULL)
    h=NULL;
    else{
        h=temp->right;
        consolidate(h);
    }
    total--;
    return h;
}
int main()
{
    node *h=initialiseHeap();
    int choice;
    int val;
    while (1)
    {
    cout<<"1.Insert\t2.Extract min\t3.Display\t4.Exit\nChoose  ";
    cin>>choice;
    if (choice==1)
    {
        cin>>val;
        node *newnode=createNode(val);
        h=insert(h,newnode);
    }
    else if (choice==2)
    {
       
        h=extractMin(h);
    }
    else if (choice==3)
        {display(h);
        cout<<endl;
        }
        
    else if (choice==4) break;
    
    }
    return 0;
}
int custom_pq()
{
    cout << "WIP: implement Dijkstra algorithm" << endl;
    return 0;
}