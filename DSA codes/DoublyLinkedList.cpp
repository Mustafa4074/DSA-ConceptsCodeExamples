#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* previous;
    Node* next;
    Node(int data){
        value=data;
        previous=NULL;
        next=NULL;

    }
};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertatHead(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->previous=new_node;
        head=new_node;
        return;
    }
    void insertatTail(int value){
        Node* new_node=new Node(value);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
         tail->next=new_node;
         new_node->previous=tail;
         tail=new_node;
         return;
    }
    void insertatPosition(int value,int position){
        Node* temp=head;
        int current_position=0;
        while(current_position<(position-1)){
            temp=temp->next;
            current_position++;
        }
        //temp will be pointing to the node at (k-1)th position
        Node* new_node=new Node(value);
        new_node->next=temp->next;
        temp->next=new_node; 
        new_node->previous=temp;
        new_node->next->previous=new_node;
        return;

    }
    void deleteatHead(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
            return;
        }
        else{  
        head->previous=NULL;
        free(temp);
        }
    }
    void deleteatTail(){
        if(tail== NULL){
            return;
        }
        Node* temp=tail;
        tail=tail->previous;
        if(tail==NULL){
            head=NULL;
            return;
        }
        else{
            tail->next=NULL;
        }
        free(temp);
        return;
    }
    void deleteatPosition(int position){
        Node* temp=head;
        int current_position=0;
        while(current_position<(position-1)){
            temp=temp->next;
            current_position++;

        }
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        free(temp);
        return;
    }
    void reverse(){
        Node* current=head;
        while(current){
            Node* next=current->next;
            current->next=current->previous;
            current->previous=next;
            current=next;
        }
        Node* new_Head=tail;
        tail=head;
        head=new_Head;
    } 
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"<->";
            temp=temp->next;
        }
        cout<<endl;
    }
 
};
int main(){
    Node* new_node=new Node(2);
    DoublyLinkedList d1;
    d1.head=new_node;
    d1.tail=new_node;
    cout<<d1.head->value<<endl;
    d1.insertatHead(1);
    //d1.deleteatHead();
    //d1.display();
    d1.insertatHead(3);
    d1.insertatHead(4);
    d1.display();
    d1.insertatTail(5);
    d1.insertatTail(6);
    d1.display();
    d1.insertatPosition(10,5);
    d1.display();
    d1.deleteatHead();
    d1.display();
    d1.deleteatTail();
    d1.display();
    d1.deleteatPosition(2);
    d1.display();
    d1.reverse();
    d1.display();



    return 0;

}