/*
https://www.codingninjas.com/codestudio/problems/left-rotate-an-array-by-one_5026278

Rajesh loves Supriya and wants to propose to Supriya but Supriya is an Array lover and asked Rajesh a problem which is as follows:-

Given an array "ARR' containing 'N' elements, rotate this array Left by once means to shift all elements by one place to the left and move the first element to the last position in the array.

As Rajesh is very bad at array he asks you to help him as he loves her so much.

Example:

Input: 'N' = 5, 'ARR' = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

We moved the 2nd element to the 1st position and 3rd element to the 2nd position and 4th element to the 3rd position and 5th element to the 4th position and move 0th element to the 5th position.
*/

#include<iostream>
#include<vector>
using namespace std;

//function to leftrotate an array by one element 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int key= arr[0];                                         //to store the first element of array into variable key

    for(int i=0; i<arr.size()-1; i++){                       // to shift elements of array by one 
        arr[i]= arr[i+1];
    }
    arr[arr.size()-1]= key;                                   //to store key into the last index of the array
    return arr;
    
}


int main(){
    vector <int> arr= {1,2,3,4,5,6,7,8,9};

    rotateArray(arr, arr.size());
   
}