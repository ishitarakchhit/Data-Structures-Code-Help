/*
[   https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1    ]
Given two array A[0….N-1] and B[0….M-1] of size N and M respectively, representing two numbers such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and B[] = { 2, 1, 4 } represent 123 and 214 respectively. The task is to find the sum of both the numbers.

Example 1:

Input : A[] = {1, 2}, B[] = {2, 1}
Output : 33
Explanation:
N=2, and A[]={1,2}
M=2, and B[]={2,1}
Number represented by first array is 12.
Number represented by second array is 21
Sum=12+21=33
 

Example 2:

Input : A[] = {9, 5, 4, 9}, B[] = {2, 1, 4} 
Output : 9763 
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function calc_Sum() that takes an array (a), sizeOfArray (n), an array (b), sizeOfArray (m), and return the sum . The driver code takes care of the printing.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N + M).
*/
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int i=n-1, j=m-1;
        string ans;
        int digit=0;
        int carry=0;
        int rem;
        while(i>=0 && j>=0){
            rem = a[i--] + b[j--] + carry;
            digit = rem % 10;
            carry = rem /10;
            ans.push_back(digit+'0');
            
        }
        while(i>=0){
            rem = a[i--] + carry;
            digit = rem % 10;
            carry = rem /10;
            ans.push_back(digit+'0');
        }
        while(j>=0){
            rem = b[j--] + carry;
            digit = rem % 10;
            carry = rem /10;
            ans.push_back(digit+'0');
        }
        if(carry){
            ans.push_back(carry + '0');
        }
        
        while(ans[ans.size()-1] == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};


int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
