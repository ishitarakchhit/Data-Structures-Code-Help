/*
[   https://leetcode.com/problems/majority-element/     ]

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
*/

#include<iostream>
#include<vector>
using namespace std;


    int majorityElement(vector<int>& nums) {
        for(int i=0; i< nums.size(); i++){
            if(nums[i]== 1000000001){
                continue;
            }
            int element = nums[i];
            int count=0;

            for(int j=i; j<nums.size(); j++){

                if(nums[j]== element){
                    nums[j]= 1000000001;
                    count++;
                }
                if(count> nums.size()/2)
                    return element;
            }
        }
        return 0;
    }



int main(){
    vector<int> arr={1,2,3,4,5,6,7,1,1,1,1,1,1};

    cout<<majorityElement(arr);

}