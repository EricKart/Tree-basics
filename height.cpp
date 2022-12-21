#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int heightOfTree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(heightOfTree(root->left), heightOfTree(root->right));
}

int main()
{
   
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);

    cout<<heightOfTree(root);
}