#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//approach: stack, push -1 initially then traverse the array from right to left and then compare if top element is smaller than current array element or not if yes then modify ans[i] = s.top() if not then pop all elements from stack until s.top() is becomes smaller then current array element. Push current array element in stack in both the cases
void nextSmallerElement(vector<int> &arr, stack<int> &s, vector<int> &ans){

    for (int i = arr.size()-1; i>=0; i--)
    {
        if(s.top() < arr[i]){
            ans[i] = s.top();
            s.push(arr[i]);
        }
        else{
            while(s.top() >= arr[i]){
                s.pop();
            }
                ans[i] = s.top();
                s.push(arr[i]);
        }
    }
    
    
}


//function to print the array
void printarr(vector<int> arr){
    cout<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    vector<int> arr = {2,1,4,5,1,3};

    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);
    printarr(arr);
    nextSmallerElement(arr, s, ans);
    printarr(ans);
    return 0;
}