/*
https://www.codingninjas.com/codestudio/problem-details/move-all-negative-numbers-to-beginning-and-positive-to-end_1112620

You are given an array 'ARR' consisting of 'N' integers. You need to rearrange the array elements such that all negative numbers appear before all positive numbers.

Follow Up:
Can you solve this in O(1) auxiliary space?
Note:

The order of elements in the resulting array is not important.
Example:

Let the array be [1, 2, -3, 4, -4, -5]. On rearranging the array such that all negative numbers appear before all positive numbers we get the resulting array [-3, -5, -4, 2, 4, 1].
Input Format:
The very first line of input contains an integer ‘T’ denoting the number of test cases. 

The first line of every test case contains an integer ‘N’ denoting the number of elements present in the array.

The second line of every test case contains ‘N’ space-separated integers denoting the elements present in the array.
Output Format:
For each test case, “Yes” is printed if the resulting array is correct otherwise “No”.

Output for each test case is printed on a separate line.
*/

#include <bits/stdc++.h> 
using namespace std;


//approach: two pointer approach
#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // Write your code here.
    int start=0;
    int end= nums.size()-1;

    while(start< end){
        if(nums[start]<0){
            start++;
        }
        else{
            swap(nums[start], nums[end--]);
        }
    }

    
    return nums;
}

int main(){
    vector<int> arr= {1, -4, -2 , 5, 3};

    separateNegativeAndPositive(arr);
}