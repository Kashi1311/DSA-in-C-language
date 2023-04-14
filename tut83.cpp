// Detection and Removal of cycle in a Linked List //
// Floyd's Algorithm or Hare and Tortoise Algorithm //
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

void makecycle(node* &head, int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removalcycle(node* &head){
    node* fast=head;
    node* slow=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    makecycle(head, 3);
    cout<<detectcycle(head)<<endl;
    removalcycle(head);
    cout<<detectcycle(head)<<endl;
    display(head);
    
    return 0;
}