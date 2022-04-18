//VECTORS
//Vectors are just like arrays but with dynamic size,i.e size can be changed as per the requirements
#include<bits/stdc++.h>
using namespace std;

//print vector
//Here also when the vector is passes a copy is created
/*We need to keep in mind that creating a copy of a vector takes O(N) time complexity .So we should not carelessly pass a 
vector.We can avoid this copy creation by using reference operator &.This ensures that while passing a vector the orignal 
vector is passed and a copy is not created. But we should pass using reference only if we don't want any changes in the 
orignal vector.*/

void printVector(vector<int>v){

    for(int i=0;i<v.size();i++){
        //v.size() -: O(1)
        cout<<v[i]<<endl;
    }
}
/*To avoid copy creation we pass vector by reference
void printVector(vector<int> &v){

    for(int i=0;i<v.size();i++){
        //v.size() -: O(1)
        cout<<v[i]<<endl;
    }
}
*/


int main(){

    //In arrays ,once the size is fixed we cannot change it again
    int a[10];
    //But in vctors size can vary
    vector<int>v;
    //taking input in vector
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //Element is inserted at the back of the vector
        v.push_back(x);//T.C :O(1)
    }
    printVector(v);

    //we can also declare vector with a size directly
    vector<int> v1(5);
    //all values are currently declared zero
    printVector(v1);//This prints five zeroes 0 0 0 0 0
    v1.push_back(7);
    printVector(v1);//will print 0 0 0 0 0 7

    //Declaring vector with a particular value
    vector<int> v2(10,3);//vector of size 10 with values 3
    printVector(v2);//prints 3 3 3 3 3 3 3 3 3 3
    
    v2.pop_back();//deletes the last element of the vector  //T.C :O(1)

    /*In arrays we cannot copy the elements directly like this.We can copy the pointers of arrays but those point 
    to the same array and not creating a separate array
    */
    vector<int> v3= v2;//This copying takes O(N) time complexity
    v3.push_back(100);//100 will be added in v3 that is in the copy created of v2
    //No changes will be reflected in v2
    /*Changes will be reflected if we copy like this:
    vector<int> &v3=v2;
    */
}