#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
    
};
/*class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    
};*/
void insertatHead(Node* &head,int value){
        Node* new_node=new Node(value);
            new_node->next=head;
            head=new_node;
    }
    void display(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insertatTail(Node* &head,int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        
    }
Node* merge(Node* &head1,Node* &head2){
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* dummy_node=new Node(-1);
    Node* ptr3=dummy_node;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->value<ptr2->value){
            ptr3->next=ptr1;
            ptr1=ptr1->next;

        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummy_node->next;
}
Node* mergeRecursively(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* result;
    /*if(head1->value<head2->value){
        result=head1;
        result->next=mergeRecursively(head1->next, head2);
    }*/
     if(head1->value<head2->value){
        result=head1;
        result->next=mergeRecursively(head1->next, head2);
    }
     else {
        result = head2;
        result->next = mergeRecursively(head1->next, head2->next);
    }
    return result;
}
int main(){
    //LinkedList l1;
   Node* head1=NULL;
   Node* head2=NULL;
   int arr1[]={1,4,5,7};
   int n1=sizeof(arr1)/sizeof(arr1[0]);
   int arr2[]={2,3,6};
   int n2=sizeof(arr2)/sizeof(arr2[0]);
   for(int i=0;i<n1;i++){
    insertatTail(head1,arr1[i]);
   }
   
   for(int i=0;i<n2;i++){
    insertatTail(head2,arr2[i]);
   }
   display(head1);
   display(head2);
   Node* new_head=merge(head1,head2);
   display(new_head);
   Node* new_head_recursive=mergeRecursively(head1,head2);
   display(new_head_recursive);

}
