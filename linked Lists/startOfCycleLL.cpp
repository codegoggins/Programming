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

Node<int>*detectStartCycle(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        //this simply means no cycle exists
        return nullptr;
    }
    Node<int>*slow=head;
    Node<int>*fast=head;
    Node<int>*entry=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            //means cycle exists
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}

int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
   
    printLL(head);
    return 0;
}