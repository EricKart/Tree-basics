#include<bits/stdc++.h>
using namespace std;

template <typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T data)
    {
        this->data = data;
    }

};

//------------------------------------------taking input depth wise--------------------------------------------------------------------------------
// TreeNode<int>* takeInput(){
//     cout<<"Enter the root data: ";
//     int RootData{0};
//     cin>>RootData;
//     TreeNode<int> * root = new TreeNode<int>(RootData);
//     cout<<endl;
//     cout<<"Enter the how many children it has: ";
//     int n{0};
//     cin>>n;
//     for(int i =0; i<n; i++)
//     {
//         TreeNode<int> *child = takeInput();
//         root->children.push_back(child);
//     }
//     return root;
// }

//---------------------------------------------------------taking input BFS--------------------------------

TreeNode<int>* takeInputLevelWise()
{
    int rootData{0};
    cout<<"Enter data of root: ";
    cin>>rootData;
    cout<<endl;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i =0; i<numchild; i++)
        {
            int childData{0};
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//-------------------Printing depth wise---------------------------------------------------------

void PrintTree(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    for(int i =0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<< " ";
    }
    cout<<endl;
    for(int i =0; i<root->children.size(); i++)
    {
        PrintTree(root->children[i]);
    }
}

//--------------------printing level wise-----------------

void PrintingLevelWise(TreeNode<int>*root)
{
    queue<TreeNode<int>*> PendingNodes;
    PendingNodes.push(root);

    while(PendingNodes.size()!=0)
    {
        TreeNode<int>*front = PendingNodes.front();
        cout<<front->data<<":";
        PendingNodes.pop();
        for(int i =0; i<root->children.size(); i++)
        {
            PendingNodes.push(root->children[i]);
            if(root->children.size()-1!=i)
            {
                cout<<root->children[i]->data<<",";
            }
            else{
                cout<<root->children[i]->data;
            }
        }
        cout<<endl;
        root=PendingNodes.front();
    }
}


//-------------count nodes---------------------------------------

int CountNodes(TreeNode<int>*root)
{
    int CountResult{1};
    for(int i =0; i<root->children.size(); i++)
    {
        CountResult+=CountNodes(root->children[i]);
    }
    return CountResult;
}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(10);
    // TreeNode<int> *node1 = new TreeNode<int>(20);
    // TreeNode<int> *node2 = new TreeNode<int>(5);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = takeInputLevelWise();
    PrintTree(root);
    PrintingLevelWise(root);
    cout<<"Total number of nodes are in this tree is: ";
    cout<<CountNodes(root);
}