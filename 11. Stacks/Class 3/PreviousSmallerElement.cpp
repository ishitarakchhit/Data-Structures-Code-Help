#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Approach: using stack, if s.top() < arr[i] then ans[i] = s.top(). if not then pop elemenents from stack until s.top()>arr[i]. push arr[i] in stack in both the cases
void prevSmallerElement(vector<int> &arr, stack<int> &s, vector<int> &ans){

    for (int i=0; i<arr.size(); i++)
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
    vector<int> arr = {2,1,4,5,3};

    vector<int> ans(arr.size());
    stack<int> s;
    s.push(-1);
    printarr(arr);
    prevSmallerElement(arr, s, ans);
    printarr(ans);
    return 0;
}