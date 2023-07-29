/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :




 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)

 

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105
*/

    //function to place element in heap
    void placeinheap(vector<int> &a, int i, int n){
        while(i>0){
            if(a[(i-1)/2] < a[i])
                swap(a[(i-1)/2] , a[i]);
            i = (i-1)/2;
        }
    }

    //function to heapify the given vector
    void heapify(vector<int> &a, int n){
        for(int i=1; i<n; i++){
            placeinheap(a, i, n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // we have created a new vector with concatenated values
        for(int i=0; i<m; i++){
            a.push_back(b[i]);
        }
        
        //to heapify the vector
        heapify(a, n+m);
        
        return a;
    }
