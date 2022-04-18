#include<bits/stdc++.h>
using namespace std;

//Binary Search can only be applied if the array is sorted
int binarySearch(int*arr,int n,int x){
    int si=0;
    int ei=n-1;
    while(si<=ei){
        int mid=(si+ei)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]>x){
            si=mid;
        }else{
            si=mid+1;
        }
    }
    return -1;
    
}

int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<binarySearch(arr,n,x);
}
