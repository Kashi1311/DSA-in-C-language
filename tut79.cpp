// Deletion in a Linked list //
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertatHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertatTail(node* &head, int val){                               // here we are taking pointer head by reference and data in a node as val in the function given //
    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;                                                  // if there is not a single not in our linked list then simply add the node n //
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        return false;
    }
    temp = temp->next;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteathead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletionatN(node* &head, int val){
    if(head==NULL){
        return;
    }
    
    if(head->next==NULL){
        deleteathead(head);
    }

    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main(){
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatHead(head,4);
    display(head);
    cout<<search(head, 5);
    cout<<endl;
    deletionatN(head, 3);
    deleteathead(head);
    display(head);
    return 0;
}