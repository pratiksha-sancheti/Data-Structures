#include "iostream"
#include "stack"
#include "queue"
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;
class node
{
    public:
    node *lchild;
    node *rchild;
    int data;
    node(int data)
    {
        this->data = data;
        lchild=rchild=NULL;
    }
    node()
    {
        lchild=rchild=NULL;
    }
};
class BinaryTree
{
    public:
    node *root;
    BinaryTree()
    {
        this->root=NULL;
    }
    node *createTree()
    {
        int x;
        cin>>x;
        if(x==-1)
            return NULL;
        node *temp = new node(x);
        cout<<"Enter left child of"<<x<<endl;
        temp->lchild = createTree();
         cout<<"Enter right child of"<<x<<endl;
        temp->rchild = createTree();
        return temp;
    }

    void Inorder(node *root)
    {
        if(root==NULL)
            return;
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }
    void Preorder(node *root)
    {
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
    void Postorder(node *root)
    {
        if(root==NULL)
            return;
        Postorder(root->lchild);
        Postorder(root->rchild);
        cout<<root->data<<" ";
    }
    void Inorder_Iterative(node *root)
    {
        stack <node *> st;
        node *temp = root;
        while(temp!=NULL || !st.empty())
        {
            while(temp!=NULL)
            {
                st.push(temp);
                temp = temp->lchild;
            }
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";

            temp = temp->rchild;
        }
    }
    void Preorder_Iterative(node *root)
    {
        stack <node*> st;
        node *temp = root;
        st.push(temp);
        while(!st.empty())
        {
            temp = st.top();
            cout<<temp->data<<" ";
            st.pop();
            if(temp->rchild)
                st.push(temp->rchild);
            if(temp->lchild)
                st.push(temp->lchild);
        }
    }
    void PostOrder_Iterative(node *root)
    {
        stack <node*> st1;
        stack <node*> st2;
        node *temp = root;
        st1.push(root);
        while(!st1.empty())
        {
            temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->lchild)
                st1.push(temp->lchild);
            if(temp->rchild)
                st2.push(temp->rchild);
        }
        while(!st2.empty())
        {
            temp = st2.top();
            cout<<temp->data<<" ";
            st2.pop();
        }
    }
    void BreadthFirst(node *root)
    {
        queue <node*> q;
        node *temp = root;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->lchild)
                q.push(temp->lchild);
            if(temp->rchild)
                q.push(temp->rchild);
        }
    }
    int height(node *root)
    {
        if(root == NULL)
            return 0;
        int left = height(root->lchild);
        int right = height(root->rchild);
        if(left>right)
            return (left + 1);
        else 
            return (right + 1);

    }
};
int main()
{
    BinaryTree bt;
    OJ
    cout<<"Enter root of the tree"<<endl;
    node *root = bt.createTree();
    cout<<"Inorder Traversal"<<endl;
    bt.Inorder(root);
    cout<<"\n PreOrder Traversal"<<endl;
    bt.Preorder(root);
    cout<<"\n PostOrder Traversal"<<endl;
    bt.Postorder(root);
    cout<<"\n Inorder Iterative"<<endl;
    bt.Inorder_Iterative(root);
    cout<<"\n PreOrder Iterative"<<endl;
    bt.Preorder_Iterative(root);
    cout<<"\n Postorder Iterative"<<endl;
    bt.PostOrder_Iterative(root);
    cout<<"\n BreadthFirst Traversal"<<endl;
    bt.BreadthFirst(root);
    cout<<"\n Height Of tree "<<bt.height(root)<<endl;
return 0;   
}