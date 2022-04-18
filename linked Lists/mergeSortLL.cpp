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
        return;
    }
    Node<int>*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node<int>*midLL(Node<int>*head){
    if(head==nullptr || head->next!=nullptr){
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

Node<int>*mergeTwoSortedLL(Node<int>*head1,Node<int>*head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2=nullptr){
        return head1;
    }
    Node<int>*ans=new Node<int>(-1);
    Node<int>*temp=ans;

    while(head1!=nullptr && head2!=nullptr){
        if(head1->data < head2->data){
            temp->next=head1;
            temp=head1;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            temp=head2;
            head2=head2->next;
        }
    }
    while(head1!=nullptr){
        temp->next=head1;
        temp=head1;
        head1=head1->next;
    }
    while(head2!=nullptr){
           temp->next=head2;
            temp=head2;
            head2=head2->next;
    }
    ans=ans->next;
    return ans;
}

Node<int>* mergeSortLL(Node<int>*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    //divide the LL in two parts
    Node<int>*mid=midLL(head);
    Node<int>*left=head;
    Node<int>*right=mid->next;
    mid->next=nullptr;

    //recursive calls on both halves
    left=mergeSortLL(left);
    right=mergeSortLL(right);

    Node<int>*result=mergeTwoSortedLL(left,right);

    return result;
}

int main(){
  Node<int>*head=takeInput();
  printLL(head);
  cout<<endl;
  printLL(mergeSortLL(head));
}