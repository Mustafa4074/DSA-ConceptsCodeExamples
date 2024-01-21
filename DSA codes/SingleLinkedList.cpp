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
    void insertatHead(Node* &head,int value){
        Node* new_node=new Node(value);
        new_node->next=head;
        head=new_node;
    }
    void insertatTail(Node* &head,int value){
        Node* new_node=new Node(value);
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void insertatPosition(Node* head,int value,int position){
        if(position==0){
            insertatHead(head,value);
            return;
        }
        Node* temp=head;
        Node* new_node=new Node(value); 
        int curr_position=0;
        while(curr_position!=position-1){
            temp=temp->next;
            curr_position++;
        }
        //temp is pointing to position-1
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void updateatPosition(Node* head,int value,int position){
        Node* temp=head;
        int curr_position=0;
        while(curr_position!=position){
            temp=temp->next;
            curr_position++;
        }
        temp->value=value;
    }
    void deleteatHead(Node* &head){
        Node* temp=head;
        head=head->next;
        free(temp);
    }
    void deleteatTail(Node* &head){
        Node* second_last=head;
        while(second_last->next->next!=NULL){
            second_last=second_last->next;
        }
        Node* temp=second_last->next;
        second_last->next=NULL;
        free(temp);
    }
    void deleteatPosition(Node* head,int position){
        if(position==0){
            deleteatHead(head);
            return;
        }
        int curr_position=0;
        Node* prev=head;
        while(curr_position!=position-1){
            prev=prev->next;
            curr_position++;

        }
        //prev is pointing to psition-1
        Node* temp=prev->next;
        prev->next=prev->next->next;
        free(temp);
    }
    void reverse(Node* &head){
        if(head==NULL){
            return;
        }
        reverse(head->next);
        cout<<head->value<<"->";
    }
    Node* reverseAll(Node* &head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        // when this loop end,prev pointing to my last node which is new head
        Node* new_head=prev;
        return new_head;
    
}
Node* reverseRecursively(Node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* new_head=reverseRecursively(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

    void print(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }


int main(){
   // Node* n=new Node(1);
    Node* head=NULL;
    //cout<<n->value<<" "<<n->next;
    insertatHead(head,4);
    insertatHead(head,2);
    print(head);
    insertatTail(head,7);
    print(head);
    insertatPosition(head,3,1);
    print(head);
    updateatPosition(head,5,2);
    print(head);
    deleteatHead(head);
    print(head);
    deleteatTail(head);
    print(head);
    insertatPosition(head,1,1);
    insertatPosition(head,4,3);
    print(head);
    deleteatPosition(head,2);
    print(head);
    reverse(head);
    cout<<"NULL"<<endl;
    head=reverseAll(head);
    print(head);
    head=reverseRecursively(head);
    print(head);

}