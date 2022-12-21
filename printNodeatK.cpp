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


void Printat_K(Node *root, int K)
{
    if(root==NULL)
        return;
    if(K==0)
    {
        cout<<root->key<<" ";
    }    else{
        Printat_K(root->left, K-1);
        Printat_K(root->right, K-1);
    }
}

int main()
{

    int K;
    cout<<"Enter the distance on which you want to print the elements/nodes: ";
    cin>>K;   
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);

    Printat_K(root, K);
}