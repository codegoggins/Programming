#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>*next;

    Node(T data){
      this->data=data;
      next=nullptr;
    }
};

Node<int>*takeInput(){
    int data;
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
}

void printReverseLL(Node<int>*head){
    if(head==nullptr){
        return;
    }
    printReverseLL(head->next);
    cout<<head->data<<" ";
}

int main(){
  Node<int>*head=takeInput();
  printReverseLL(head);
}