// Reversing the k nodes of the linked list. //
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
node* reversek(node* &head, int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reversek(nextptr, k);
    }
    return prevptr;
}

int main(){
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    display(head);
    node* newhead = reversek(head, 2);
    display(newhead);
    
    return 0;
}