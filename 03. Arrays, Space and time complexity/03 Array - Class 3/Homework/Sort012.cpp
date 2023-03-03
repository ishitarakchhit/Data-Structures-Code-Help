/*
[https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?leftPanelTab=0]
Sort an array which has elements 0, 1 and 2 while traversing the array only once
*/

//Solution
//always keeping the left pointer at 0 or just one place after 0 and always keeping the right pointer at 2 or just one place left to 2 so that whenever mid pointer encounters a 0 it can swap the value with left pointer and whenever it encounters a 2 it can swap the value with the right pointer.

#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n)
{
    int left=0, mid=0, right=n-1;
    
    while(mid<=right){
        if(arr[mid]==0){
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else 
        {
            swap(arr[right], arr[mid]);
            right--;
        }
    }
    
   
}
 
 //alternate solution
 //count all the 0s, 1s and 2s and store all of them sequencially in the array.
/*
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int count0=0; 
    int count1=0;
    int count2=0;
 
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            count0++;
        else if (arr[i]==1)
            count1++;
        else 
            count2++;        
    }
    
    int i=0;
    int num=0;
    
    while(i<n){
        if(i==count0)
            num=1;
        if(i==count0+count1)
            num=2;
        arr[i]=num;
        i++;
    }
}
*/