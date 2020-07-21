#include "iostream"
using namespace std;
class node {
    public:
        int data;
        node *next;

};
class LinkedList{
    node *head;

    public:
        node *createHead(int n)
        {
            node *head = new node();
            head->data=n;
            head->next=NULL;
            return head;
        }
        void printList(node *n)
        {
            while(n!=NULL)
            {
                cout<<n->data<<" ";
                n=n->next;
            }
        }
        void insertData(node **head,int n)
        {
            node *temp = new node();
            temp->data=n;
            temp->next = *head;
            *head=temp;
        }
        void append(node *head,int n)
        {
            node *temp=new node();
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            node *insert = new node();
            insert->data=n;
            insert->next=NULL;
            temp->next=insert;
        }
        int countNode(node *n)
        {
            int count=0;
            /*while(n!=NULL)
            {
                count++;
                n = n->next;
            }*/
            for(n;n!=NULL;n=n->next)
                count++;
            return count;
        }
        void search(node *temp,int n)
        {
            int flag=0;
            while(temp!=NULL)
            {
                if(temp->data==n)
                {
                    cout<<"Found!!"<<endl;
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
        }
        void deleteNode(node **head,int n)
        {
            node *temp = *head;
            
            node *prev;
            prev=temp;
            if(temp->data==n)
            {
                *head = temp->next;
                delete temp;
                cout<<"Deleted"<<endl;
                return;
            }
            prev=temp;
            temp=temp->next;
            int flag=0;
            
            while(temp!=NULL)
            {
                if(temp->data==n)
                {
                    prev->next=temp->next;
                    delete temp;
                    cout<<"Deleted!!"<<endl;
                    flag=1;
                }
                temp=temp->next;
                prev = prev->next;
            }
            if(flag==0)
                cout<<"Not Found!!"<<endl;
        }
        void updateData(node *head,int n,int update)
        {
            node *temp;
            temp=head;
            int flag=0;
            while(temp!=NULL)
            {
                if(temp->data==n)
                {
                    temp->data = update;
                    cout<<"Updated!!"<<endl;
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
        }
        void DeleteList(node **head)
        {
            node *temp;
            node *curr = *head;
            while(curr!=NULL)
            {
                temp = curr->next;
                delete curr;
                curr = temp;
            }
            *head=NULL;
        }
};
int main()
{
    
    int n;
    node *head;
    cout<<"Enter number to create LL"<<endl;
    cin>>n;
    LinkedList l;
    head = l.createHead(n);
    int choice;
    bool decision=true;
    while(decision)
    {
        cout<<"0.Exit 1.Insert data 2.Count 3.Print"<<endl;
        cout<<"4.Append 5.Search 6.Delete 7.Update 8.Delete List"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter number to insert in LL"<<endl;
                cin>>n;
                l.insertData(&head,n);
                break;
            case 2:
                cout<<"Count = "<<l.countNode(head)<<endl;
                break;
            case 3:
                l.printList(head);
                cout<<endl;
                break;
            case 4:
                cout<<"Enter data to be added at end of list"<<endl;
                cin>>n;
                l.append(head,n);
                break;
            case 5:
                cout<<"Enter data to be searched"<<endl;
                cin>>n;
                l.search(head,n);
                break;
            case 6:
                cout<<"Enter data to be deleted"<<endl;
                cin>>n;
                l.deleteNode(&head,n);
                break;
            case 7:
                int update;
                cout<<"Enter the value to be updated"<<endl;
                cin>>n;
                cout<<"Enter updated value"<<endl;
                cin>>update;
                l.updateData(head,n,update);
                break;
            case 8:
                l.DeleteList(&head);
                l.printList(head);
                break;
            case 0:
                decision=false;
                break;
            
            default:
                cout<<"Invalid"<<endl;
                break;
        }
    }
return 0;
}