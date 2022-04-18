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
    Node<int>*temp=head;
    int len=0;
    while(temp!=nullptr){
       len++;
       temp=temp->next;
    }
    return len;
}

Node<int>* deleteNodeRec(Node<int>*head,int i){
    if(head==nullptr){
        return nullptr;
    }
    if(i==0){
        //delete head
        Node<int>*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    if(i > lengthLL(head)){
        cout<<"Value of i invalid"<<endl;
        return head;
    }
    Node<int>*smallHead=deleteNodeRec(head->next,i-1);
    head->next=smallHead;
    return head; 
}


int main(){
    Node<int>*head=takeInput();
    printLL(head);
    cout<<endl;
    head=deleteNodeRec(head,2);
    printLL(head);
    return 0;
}