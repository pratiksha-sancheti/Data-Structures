#include "iostream"
#include "stack"
#include "queue"
#define OJ                            \
    freopen("input1.txt", "r", stdin); \
    freopen("output1.txt", "w", stdout);
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
class BinarySearchTree
{
    public:
        node *root;

        BinarySearchTree()
        {
            this->root=NULL;
        }
        node *createTree(node *root,int x)
        {
            if(!root)
            {
                root = new node(x);
                return root;
            }
            if(x > root->data)
                root->rchild = createTree(root->rchild,x);
            if(x<root->data)
                root->lchild = createTree(root->lchild,x);
            return root;
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

        void search(node *root,int x)
        {
            if(root==NULL)
            {
                cout<<x<<" Not Found"<<endl;
                return;
            }
            while(root->lchild!=NULL && root->rchild!=NULL)
            {
                if(x > root->data)
                    root = root->rchild;
                else if(x<root->data)
                    root=root->lchild;
                if(root->data ==x)
                {
                    cout<<x<<" Found!!"<<endl;
                    return;
                }
            }
            cout<<x<<" Not Found!!"<<endl;
        }
        node *deleteNode(node *root,int x)
        {
            if(root==NULL)
            {
                cout<<x<<" Not Found"<<endl;
                return NULL;
            }
            node *temp=root;
            while(temp->lchild!=NULL && temp->rchild!=NULL)
            {
                if(x > temp->data)
                    temp = temp->rchild;
                else if(x<root->data)
                    temp=temp->lchild;
                if(temp->data ==x)
                {
                    cout<<x<<" Found!!"<<endl;
                    if(temp->lchild==NULL && temp->rchild==NULL)
                    {
                        
                        delete temp;
                        //root=NULL;
                        cout<<"Deleted"<<endl;
                        return root;
                    }
                    
                }
            }
        }
};
int main()
{
    OJ;
    BinarySearchTree bst;
    node *root=NULL;
    int x;
    cout<<"Enter root of tree"<<endl;
    cin>>x;
    root=bst.createTree(root,x);
    bool decision=true;
    int choice;
    while(decision)
    {
        cout<<"0.Exit 1.Insert 2.Inorder 3.Preorder"<<endl;
        cout<<"4.Search 5.Delete"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter number of nodes to insert in BST"<<endl;
                int m;
                cin>>m;
                while (m--)
                {
                    cout<<"Enter data to insert in tree"<<endl;
                    cin>>x;
                    bst.createTree(root,x);
                }
                break;
            case 2:
                cout<<"Inorder"<<endl;
                bst.Inorder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Preorder"<<endl;
                bst.Preorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Enter element to be searched"<<endl;
                cin>>x;
                bst.search(root,x);
                break;
            case 5:
                cout<<"Enter element to be deleted"<<endl;
                cin>>x;
                root = bst.deleteNode(root,x);
                cout<<"Inorder"<<endl;
                bst.Inorder(root);
                cout<<endl;
                break;
            case 0:
                cout<<"Bye!!"<<endl;
                decision=false;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;

        }
    }
return 0;
}