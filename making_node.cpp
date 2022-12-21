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

//-----------------------------------Sum of all Nodes------------------------

int SumOfNodes(TreeNode<int>*root)
{
    queue<TreeNode<int>*> PendingNodes;
    PendingNodes.push(root);
    int Sum=root->data;
    while(PendingNodes.size()!=0)
    {
        //TreeNode<int>*front = PendingNodes.front();
        PendingNodes.pop();
        for(int i =0; i<root->children.size(); i++)
        {
            PendingNodes.push(root->children[i]);
            Sum+=root->children[i]->data;
        }
        root=PendingNodes.front();
    }
    cout<<Sum;
}

//------------------------------------------------------Maximum value node----------------------------------------

TreeNode<int>* maxNode(TreeNode<int> *root)
{
    if(root==nullptr)
    {
        return nullptr;
    }

    int max_node = root->data;
    TreeNode<int>* result = root;

    for(int i =0;i<root->children.size(); i++)
    {
        TreeNode<int> *temp = maxNode(root->children[i]);

        if(max_node<temp->data)
        {
            max_node = temp->data;
            result = temp;
        }
    }
    return result;
}

//--------------------------------------------------Height of tree------------------------------------------------

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    int height{0};
    for(int i =0; i<root->children.size(); i++)
    {
        int max_height = getHeight(root->children[i]);
        if(max_height>=height){
            height=max_height;
        }
    }
    return height+1;
}


//-------------------------------------------------Depth of tree------------------------------------------------------------

int Depth_Tree(TreeNode<int> *root, TreeNode<int>*Node)
{
    if(root==NULL)
    {
        return 0;
    }

    int depth{0};
    for(int i =0; i<root->children.size(); i++)
    {
        int current_depth{0};
        if(Node==root)
        {
            
            depth = current_depth;
        }
        else{
            current_depth = Depth_Tree(root->children[i], Node);
        }
    }
    return depth+1;
}


//------------------------------------------------------Printing all nodes at particular depth-------------------------------------------


void PrintNodes_atDepth(TreeNode<int>*root, int k)//k is depth at which we have to find all nodes and then print them
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i =0; i<root->children.size(); i++)
    {
        PrintNodes_atDepth(root->children[i], k-1);
    }
}


//-------------------------------------------Print all leaf nodes----------------------------------------------------


int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    int MaxLeaves{0};
    if(root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
        return 1;
    }

    for(int i =0; i<root->children.size(); i++)
    {
        MaxLeaves+=getLeafNodeCount(root->children[i]);
    }
    return MaxLeaves;
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