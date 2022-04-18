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

Node<int>*insertNode(Node<int>*head,int pos,int data){
        Node<int>*newNode=new Node<int>(data);
        int count=0;
        Node<int>*temp=head;

        if(pos==0){
            newNode->next=head;
            head=newNode;
            return head;
        }
        while(temp!=nullptr && count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp!=nullptr){
            Node<int>*a=temp->next;
            temp->next=newNode;
            newNode->next=a;
        }
        return head;
}

int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    head=insertNode(head,2,100);
    printLL(head);
    return 0;
}