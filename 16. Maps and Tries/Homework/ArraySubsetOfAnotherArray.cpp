/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.
 

Example 1:

Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:

Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubset() which takes the array a1[], a2[], its size n and m as inputs and return "Yes" if arr2 is subset of arr1 else return "No" if arr2 is not subset of arr1.

 

Expected Time Complexity: O(max(n,m))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n,m <= 105
1 <= a1[i], a2[j] <= 106
*/

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> map;
    
    //mapping all elements of array a1 with their frequencies
    for(int i=0; i<n; i++){
        map[a1[i]] ++;
    }
    
    //check if current element exists in map or not, if it exists reduce its freq by one
    for(int i=0; i<m; i++){
        if(map[a2[i]]== 0)
            return "No";
        else
            map[a2[i]]--;
    }
    return "Yes";
}