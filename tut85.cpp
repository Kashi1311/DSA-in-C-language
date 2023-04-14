// Deletion in Linked List //
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertatHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev=n;
    }
    head = n;
}
void deleteathead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deletionatN(node* &head, int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }

    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;

    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete temp;
} 

void insertatTail(node* &head, int val){                               
    node* n = new node(val);
    
    if(head==NULL){
        insertatHead(head,val);
        return;                                                  
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
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
        cout<<temp->data<<"-><-";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    display(head);
    insertatHead(head,5);
    display(head);
    deletionatN(head,4);
    display(head);
    deleteathead(head);
    display(head);
    
    return 0;
}