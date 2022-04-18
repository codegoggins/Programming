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


//print function
void printLL(Node<int>*head){
     if(head==nullptr){
         return;
     }
     Node<int>*temp=head;
     while(temp!=nullptr){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     delete temp;
}

//take LL input function
Node<int>*takeInput(){
    int data;
    cout<<"Enter data :"<<endl;
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

//Iterative function to calculate length of Linked List
int lengthLL(Node<int>*head){
    if(head==nullptr){
        return 0;
    }
    Node<int>*temp=head;
    int len=0;
    while(temp!=nullptr){
       len++;
       temp=temp->next;
    }
    return len;
}

//Iterative method for bubble Sort
Node<int>* bubbleSortLL(Node<int>*head){
  if(head==nullptr){
      return nullptr;
  }
  for(int i=0;i<lengthLL(head);i++){
      
      Node<int>*curr=head,*prev=nullptr;

      while(curr!=nullptr && curr->next!=nullptr){

          if(curr->data > curr->next->data){
              //First case:When curr is not head
              if(prev!=nullptr){
                  Node<int>*temp=curr->next->next;
                  curr->next->next=curr;
                  prev->next=curr->next;
                  curr->next=temp;
                  prev=prev->next;
              }
              else{
                  //curr node is head
                  head=curr->next;
                  curr->next=head->next;
                  head->next=curr;
                  prev=head;
              }

          }else{
              //increment the pointers
              prev=curr;
              curr=curr->next;
          }
      }
  }
  return head;
}

int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    Node<int>*head1=bubbleSortLL(head);
    printLL(head1);
    delete head;
    delete head1;
    return 0;
}