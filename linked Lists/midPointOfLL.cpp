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

int lengthLL(Node<int>*head){
    if(head==nullptr){
        return 0;
    }
    return 1+lengthLL(head->next);
}


//Using length of LL
Node<int>* midPointLL1(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    int mid=(lengthLL(head)-1)/2;
    Node<int>*temp=head;
    int pos=0;
    while(temp!=nullptr && pos<mid){
       pos++;
       temp=temp->next;
    }
    return temp;
}

//Using two pointers
Node<int>* midPointLL(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node<int>*slow=head;
    Node<int>*fast=head->next;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    cout<<midPointLL(head)->data<<endl;
    cout<<midPointLL1(head)->data<<endl;
    return 0;
}