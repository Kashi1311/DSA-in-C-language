// Merge 2 sorted Linked Lists. //
// Recursive way //
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

node* mergerecursive(node* head1, node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){                          // Base condition //
        return head1;
    }

    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergerecursive(head1->next, head2);          // Recursive Way //
    }
    else{
        result = head2;
        result->next = mergerecursive(head1, head2->next);          // Recursive Way //
    }
    return result;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};
    for(int i=0;i<4;i++){
        insertatTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertatTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newhead = mergerecursive(head1, head2);
    display(newhead);

    return 0;
}