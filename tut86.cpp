// Append last k nodes of a Linked List //
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

void insertatTail(node* &head, int val){                               
    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;                                                  
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

int length(node *head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* kappend(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail=head;

    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newtail = tail;
        }
        if(count==l-k+1){
            newhead = tail;
        }
        tail=tail->next;
        count++;
    }
    
    newtail->next=NULL;
    tail->next=head;

    return newhead;

}

int main(){
    node* head=NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertatTail(head,arr[i]);
    }
    display(head);

    node* newhead = kappend(head, 3);
    display(newhead);

    return 0;
}