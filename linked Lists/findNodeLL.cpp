#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>*next;

    //consructor
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
    Node<int>*head=nullptr,*tail=nullptr;
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
     delete temp;
 }

bool isPresent(Node<int>*head,int data){
    if(head==nullptr){
        return false;
    }
    if(head->data==data){
        return true;
    }else{
        return isPresent(head->next,data);
    }
}

int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    cout<<isPresent(head,100);
}