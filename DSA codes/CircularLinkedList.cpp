#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
    }
};
class CircularLinkedList{
    public:
    Node* head;
    CircularLinkedList(){
        head=NULL;
    }
    void insertatHead(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            new_node->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        //now tail is pointing to the last node
        tail->next=new_node;
        new_node->next=head;
        head=new_node;

    }
    void cicular(){
        Node* temp=head;
        for(int i=0;i<15;i++){
            cout<<temp->value<<"->";
            temp=temp->next;

        }
    }
    void insertatTail(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            new_node->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;

    }
    void insertatPosition(int value,int position){
       if(position==0){
        insertatHead(value);
        return;
       }
        Node* temp=head;
        Node* new_node=new Node(value);
        int current=0;
        while(current!=position-1){
            temp=temp->next;
            current++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
      
    }
    void update(int value,int position){
        Node* temp=head;
        Node* new_node=new Node(value);
        int current=0;
        while(current!=position-1){
            temp=temp->next;
        }
        temp->value=value;

    }
    void deleteatHead(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        head=head->next;
        tail->next=head;
        free(temp);
    }
    void deleteatTail(){
        if(head==NULL){
            return;
        }
        Node* tail=head;
        while(tail->next->next!=head){
            tail=tail->next;
        }
        //here tail is pointing to the secondlast node
        Node*temp=tail->next;//node to deleted
        tail->next=head;
        free(temp);

        tail->next=head;
        free(temp);
        
    }
    void display(){
        Node* temp=head;
        do{
            cout<<temp->value<<"->";
            temp=temp->next;
        }while (temp!=head);
        cout<<endl;
        
        
    }


};
int main(){

CircularLinkedList c1;
c1.insertatHead(3);
c1.insertatHead(7);
c1.display();
//c1.cicular();
c1.insertatTail(6);
c1.display();
c1.insertatPosition(1,2);
c1.display();
c1.update(4,1);
c1.display();
c1.deleteatHead();
c1.display();
c1.deleteatTail();
c1.display();
    return 0;
}