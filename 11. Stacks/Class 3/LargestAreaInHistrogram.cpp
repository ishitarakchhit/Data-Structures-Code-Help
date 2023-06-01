/*

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/


#include<iostream>
#include<stack>
#include<limits.h>
#include<vector>
using namespace std;


vector<int> prevSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());

    for (int i=0; i<arr.size(); i++)
    {
        
            while(s.top()!=-1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
                ans[i] = s.top();
                s.push(i);
        
    }
    
    return ans;
}


vector<int> nextSmallerElement(vector<int> &arr){

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());

    for (int i = arr.size()-1; i>=0; i--)
    {
        
            while(s.top()!=-1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
                ans[i] = s.top();
                
                    
                s.push(i);        
    }
    
    return ans;
}


//function to find the max area and return answer
//traversing the array of histrogram and extending the line towards left and right and then calculating the area the falls between using width and then finding the area
int findmaxarea(vector<int> &arr){
    int maxarea=INT_MIN;
    vector<int> prev = prevSmallerElement(arr);
    vector<int> next = nextSmallerElement(arr);

    for (int i = 0; i < arr.size(); i++)
    {   if(next[i] == -1){
        next[i] = arr.size();
    }
        int n= next[i];
        int p = prev[i];
        int width = n-p-1;
        int area = width* arr[i];
        maxarea= max(maxarea, area);
    }
    return maxarea;

}

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout<<findmaxarea(arr);
    arr = prevSmallerElement(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<endl<<arr[i];
    }
    

}