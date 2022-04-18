//Remove duplicates from sorted LL
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
  public:
  T data;
  Node<T>*next;

  //constructor
  Node(T data){
      this->data=data;
      next=nullptr;
  }
};

Node<int>*takeInput(){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    if(data==-1){
        return nullptr;
    }
    Node<int>*head=nullptr;
    Node<int>*tail=nullptr;
    while(data!=-1){
         Node<int>*newNode=new Node<int>(data);
         if(head==nullptr){
           head=newNode;
           tail=newNode;
         }else{
           tail->next=newNode;
           tail=tail->next;
         }
         cin>>data;
    }
    return head;
}


void printLL(Node<int>*head){

    if(head==nullptr){
        return;
    }
    Node<int>*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void removeDuplicates(Node<int>*head){

   if(head==nullptr || head->next==nullptr){
       //no elements or single element in LL so simply return
       return;
   }
   Node<int>*curr=head;
   while(curr!=nullptr){
      if(curr->next!=nullptr && curr->data==curr->next->data){
              Node<int>*next_next=curr->next->next;
              Node<int>*nodeToDelete=curr->next;
              delete(nodeToDelete);
              curr->next=next_next;
      }
      else{
          curr=curr->next;
      }    
   }
}

int main(){
   Node<int>*head=takeInput();
   printLL(head);
   removeDuplicates(head);
   printLL(head);
   
}