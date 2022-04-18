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
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>*head){
    if(head==nullptr){
        return ;
    }
    Node<int>*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node<int>*midPointLL(Node<int>*head){
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

Node<int>*reverseLL(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node<int>*prev=nullptr,*curr=head,*next;

    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}


bool palindromeLL(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        return true;
    }
    Node<int>*mid=midPointLL(head);
    Node<int>*head1=mid->next;
    mid->next=nullptr;
    head1=reverseLL(head1);
    

    Node<int>*t1=head,*t2=head1;
    while(t1!=nullptr && t2!=nullptr){
        if(t1->data!=t2->data){
            return false;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return true;
}

int main(){
Node<int>*head=takeInput();
if(palindromeLL(head)){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}
}