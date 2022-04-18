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

//Iterative Code To find Length
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

//Recursive Code To find Length
int LengthLLRec(Node<int>*head){
    if(head==nullptr){
        return 0;
    }
    return 1+LengthLLRec(head->next);
}


int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    cout<<lengthLL(head)<<endl;
    cout<<LengthLLRec(head)<<endl;

    return 0;
}