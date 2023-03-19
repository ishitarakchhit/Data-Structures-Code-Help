#include <bits/stdc++.h> 
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                 swap(arr[j], arr[j+1]);
            }            
        }
        
    }
}


/*optimised code*/
/*


#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    bool swapped;
    // Write your code here.
    for(int i=0; i<n-1; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                 swap(arr[j], arr[j+1]);
                 swapped = true;
            }            
        }
        if(swapped == false)
            break;
    }
}



*/