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
        void deleteNode(node *root,int x)
        {
            if(root==NULL)
            {
                cout<<x<<" Not Found"<<endl;
                return;
            }
            node *temp=root;
            node *prev=NULL;
            while(temp!=NULL)
            {
                prev=temp;
                if(x > temp->data)
                    temp = temp->rchild;
                else if(x<root->data)
                    temp=temp->lchild;
                if(temp->data ==x)
                {
                    cout<<x<<" Found!!"<<endl;
                    if(temp->lchild==NULL && temp->rchild==NULL)
                    {
                        if(prev->lchild==temp)
                            prev->lchild=NULL;
                        else
                            prev->rchild=NULL;
                        delete temp;
                        cout<<"Deleted"<<endl;
                        return;
                    }
                    if(temp->lchild==NULL || temp->rchild==NULL)
                    {
                        if(temp->lchild==NULL)
                        {
                            if(prev->lchild==temp)
                                prev->lchild=temp->rchild;
                            else 
                                prev->rchild=temp->rchild;
                            delete temp;
                            cout<<"Deleted"<<endl;
                            return;
                        }
                        else 
                        {
                            if(prev->lchild==temp)
                                prev->lchild = temp->lchild;
                            else 
                                prev->rchild = temp->lchild;
                            delete temp;
                            cout<<"Deleted"<<endl;
                            return;
                        }
                    }
                    else
                    {
                        node *temp2 = temp->rchild;
                        if(temp2->lchild==NULL)
                        {
                            temp->data = temp2->data;
                            temp->rchild=temp2->rchild;
                            delete temp2;
                            cout<<"Deleted"<<endl;
                            return;
                        }
                        while(temp2->lchild!=NULL)
                        {
                            prev = temp2;
                            temp2 = temp2->lchild;
                        }
                        temp->data = temp2->data;
                        prev->lchild = NULL;
                        delete temp2;
                        cout<<"Deleted!!"<<endl;
                        return;
                    }
                }
            }
        }
};
int main()
{
    //OJ;
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
                bst.deleteNode(root,x);
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